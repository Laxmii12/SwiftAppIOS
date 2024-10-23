import SwiftUI
import Smartech
import SmartechAppInbox
import WebKit

struct ContentView: View {
    @State private var deeplinkURLString: String?
    @State private var isNavigatingToURL = false

    var body: some View {
        NavigationView {
            VStack {
                Image(systemName: "globe")
                    .imageScale(.large)
                    .foregroundStyle(.tint)

                // NavigationLink to navigate to CustomHomePageView
                NavigationLink(destination: HomePageView()) {
                    Text("Go to the home page!")
                        .font(.title)
                        .padding()
                        .background(Color.gray.opacity(0.2))
                        .cornerRadius(10)
                }
                .buttonStyle(PlainButtonStyle()) // To remove default styling

                // NavigationLink to dynamically navigate to any URL
                if let urlString = deeplinkURLString, let url = URL(string: urlString) {
                    NavigationLink(destination: WebView(url: url), isActive: $isNavigatingToURL) {
                        EmptyView() // Hidden view, used to trigger navigation
                    }
                }
            }
            .onReceive(NotificationCenter.default.publisher(for: NSNotification.Name("DeepLinkReceived"))) { notification in
                if let url = notification.object as? String {
                    handleDeepLink(urlString: url)
                }
            }
        }
        .padding()
        .onAppear {
            setupSmartech() // Setup Smartech when the view appears
        }
    }

    // Handle deep link navigation
    func handleDeepLink(urlString: String) {
        print("Handling deep link with URL: \(urlString)")
        
        // Set the URL string received from the deep link
        deeplinkURLString = urlString
        isNavigatingToURL = true // Trigger navigation to the WebView with the URL
    }

    // Smartech related setup
    func setupSmartech() {
        let appInboxController = SmartechAppInbox.sharedInstance().getViewController()

        Smartech.sharedInstance().login("LaxmeeMedliSwift")

        let profilePushDictionary = ["NAME": "Laxmee Medli", "EMAIL": "abc@xyz.com", "AGE": "21", "MOBILE": "9898989898"]
        Smartech.sharedInstance().updateUserProfile(profilePushDictionary)

        let payloadDictionary = [
            "product_id": "1329",
            "screen_name": "ContentView",
            "brand": "Polo"
        ]
        Smartech.sharedInstance().trackEvent("Product Viewed", andPayload: payloadDictionary)
    }
}

// WebView for displaying URL content
struct WebView: UIViewRepresentable {
    let url: URL

    func makeUIView(context: Context) -> WKWebView {
        return WKWebView()
    }

    func updateUIView(_ uiView: WKWebView, context: Context) {
        let request = URLRequest(url: url)
        uiView.load(request)
    }
}

// Custom Home Page View
struct CustomHomePageView: View {
    var body: some View {
        Text("Welcome to the Home Page")
            .font(.largeTitle)
            .padding()
    }
}

// Preview
#Preview {
    ContentView()
}
