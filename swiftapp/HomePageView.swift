import SwiftUI
import Smartech
import SmartechAppInbox

struct HomePageView: View {
    
    // State variable to store messages
    @State private var inboxMessages: [SMTAppInboxMessage] = []

    var body: some View {
        NavigationStack {
            VStack {
                Text("Home Page")
                    .font(.largeTitle)
                    .padding()
                    .onAppear {
                        // Example
                        var eventData = [String: Any]()

                        // Attributes
                        eventData["arn_number"] = "arn12345"
                        eventData["name"] = "John Doe"
                        eventData["email"] = "john.doe@example.com"
                        eventData["mobile"] = "9876543210"

                        // Payload
                        var payload = [String: Any]()
                        payload["deep_link"] = "https://yourapp.com/deeplink"
                        payload["transaction_initiate_date"] = "2024-10-21 10:30:00" // Date in YYYY-MM-dd HH:mm:ss format
                        payload["revenue"] = 0 // Integer
                        payload["conversion"] = 0 // Integer
                        eventData["payload"] = payload

                        // Track event
                        Smartech.sharedInstance().trackEvent("distributor login", andPayload: eventData)

                        
                        // Fetch inbox messages
                        fetchInboxMessages()
                    }
                
                // Displaying fetched inbox messages
                List(inboxMessages, id: \.self) { message in
                    Text(message.categoryName ?? "No Title")
                }
                
                // Navigation link to ProductsPageView
                NavigationLink(destination: ProductsPageView()) {
                    Text("Go to Products Page")
                        .font(.headline)
                        .foregroundColor(.blue)
                        .padding()
                        .background(Color.gray.opacity(0.2))
                        .cornerRadius(10)
                }
            }
        }
    }
    
    // Function to fetch inbox messages and store them in the array
    func fetchInboxMessages() {
        let messages = SmartechAppInbox.sharedInstance().getMessages(SMTAppInboxMessageType.all)
        
        if let messages = messages as? [SMTAppInboxMessage] {
            // Store the fetched messages in the inboxMessages array
            self.inboxMessages = messages
            print("Fetched \(messages.count) messages.")
        } else {
            print("Failed to fetch messages")
        }
    }
}
