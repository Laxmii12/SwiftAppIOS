//import SwiftUI
//import Smartech
//import SmartechAppInbox
//import WebKit
//import SmartechNudges
//
//struct ContentView: View {
//    @State private var deeplinkURLString: String?
//    @State private var isNavigatingToURL = false
//
//    var body: some View {
//        NavigationView {
//            VStack {
//                Image(systemName: "globe")
//                    .imageScale(.large)
//                    .foregroundStyle(.tint)
//
//                // NavigationLink to navigate to CustomHomePageView
//                NavigationLink(destination: HomePageView()) {
//                    Text("Go to the home page!")
//                        .font(.title)
//                        .padding()
//                        .background(Color.gray.opacity(0.2))
//                        .cornerRadius(10)
//                }
//                .buttonStyle(PlainButtonStyle()) // To remove default styling
//
//                // NavigationLink to dynamically navigate to any URL
//                if let urlString = deeplinkURLString, let url = URL(string: urlString) {
//                    NavigationLink(destination: WebView(url: url), isActive: $isNavigatingToURL) {
//                        EmptyView() // Hidden view, used to trigger navigation
//                    }
//                }
//            }
//            .onReceive(NotificationCenter.default.publisher(for: NSNotification.Name("DeepLinkReceived"))) { notification in
//                if let url = notification.object as? String {
//                    handleDeepLink(urlString: url)
//                }
//            }
//        }
//        .padding()
//        .onAppear {
//            setupSmartech() // Setup Smartech when the view appears
//        }
//    }
//
//    // Handle deep link navigation
//    func handleDeepLink(urlString: String) {
//        print("Handling deep link with URL: \(urlString)")
//        
//        // Set the URL string received from the deep link
//        deeplinkURLString = urlString
//        isNavigatingToURL = true // Trigger navigation to the WebView with the URL
//    }
//
//    // Smartech related setup
//    func setupSmartech() {
//        let appInboxController = SmartechAppInbox.sharedInstance().getViewController()
//
//        Smartech.sharedInstance().login("LaxmeeMedliSwift")
//        Hansel.getUser()?.setUserId("LaxmeeMedliSwiftHansel")
//        Hansel.getUser()?.putAttribute(25, forKey: "age")
//
//
//        let profilePushDictionary = ["NAME": "Laxmee Medli", "EMAIL": "abc@xyz.com", "AGE": "21", "MOBILE": "9898989898"]
//        Smartech.sharedInstance().updateUserProfile(profilePushDictionary)
//
//        let payloadDictionary = [
//            "product_id": "1329",
//            "screen_name": "ContentView",
//            "brand": "Polo"
//        ]
//        Smartech.sharedInstance().trackEvent("Product Viewed", andPayload: payloadDictionary)
//    }
//}
//
//// WebView for displaying URL content
//struct WebView: UIViewRepresentable {
//    let url: URL
//
//    func makeUIView(context: Context) -> WKWebView {
//        return WKWebView()
//    }
//
//    func updateUIView(_ uiView: WKWebView, context: Context) {
//        let request = URLRequest(url: url)
//        uiView.load(request)
//    }
//}
//
//// Custom Home Page View
//struct CustomHomePageView: View {
//    var body: some View {
//        Text("Welcome to the Home Page")
//            .font(.largeTitle)
//            .padding()
//    }
//}
//
//// Preview
//#Preview {
//    ContentView()
//}
import SwiftUI
import SmartechNudges

struct ContentView: View {
    @State private var gridData = [
        ["Item 1", "Item 2", "Item 3"],
        ["Item 4", "Item 5", "Item 6"],
        ["Item 7", "Item 8", "Item 9"]
    ]

    @State private var banners = ["Banner 1", "Banner 2", "Banner 3"].shuffled()
    @State private var layoutOrder = Int.random(in: 0...1)

    var body: some View {
        VStack {
            if layoutOrder == 0 {
                createTableView()
                createBanners()
            } else {
                createBanners()
                createTableView()
            }
        }
        .onAppear {
            shuffleData()
        }
    }

    func shuffleData() {
        gridData = gridData.map { $0.shuffled() } // Shuffle elements within each row
        banners.shuffle()
        layoutOrder = Int.random(in: 0...1)
    }

    @ViewBuilder
    func createTableView() -> some View {
        VStack {
            Text("Dynamic TableView")
                .font(.headline)
                .padding(.bottom, 10)

            ForEach(0..<gridData.count, id: \.self) { rowIndex in
                HStack(spacing: 20) {
                    ForEach(0..<gridData[rowIndex].count, id: \.self) { columnIndex in
                        HanselWrapperView(
                            uniqueKey: "tableView_row_\(rowIndex)_col_\(columnIndex)",
                            content: {
                                Text(gridData[rowIndex][columnIndex])
                                    .frame(width: 100, height: 50)
                                    .background(Color.blue)
                                    .cornerRadius(12)
                                    .foregroundColor(.white)
                                    .font(.system(size: 18))
                                    .padding(4)
                            }
                        )
                    }
                }
                .padding(.bottom, 10)
            }
        }
        .background(Color.brown)
        .cornerRadius(12)
        .padding()
    }

    @ViewBuilder
    func createBanners() -> some View {
        VStack {
            Text("Dynamic Banners")
                .font(.headline)
                .padding(.bottom, 10)

            ScrollView(.vertical) {
                VStack(spacing: 15) {
                    ForEach(banners.indices, id: \.self) { index in
                        HanselWrapperView(
                            uniqueKey: "banner_\(index)",
                            content: {
                                Text(banners[index])
                                    .padding()
                                    .frame(maxWidth: .infinity, minHeight: 100)
                                    .background(Color.green)
                                    .cornerRadius(10)
                                    .foregroundColor(.white)
                            }
                        )
                    }
                }
                .padding()
            }
        }
    }
}

struct HanselWrapperView<Content: View>: UIViewRepresentable {
    let uniqueKey: String
    let content: Content

    init(uniqueKey: String, @ViewBuilder content: () -> Content) {
        self.uniqueKey = uniqueKey
        self.content = content()
    }

    func makeUIView(context: Context) -> UIView {
        let hostingController = UIHostingController(rootView: content)
        let containerView = UIView()
        containerView.addSubview(hostingController.view)

        hostingController.view.translatesAutoresizingMaskIntoConstraints = false
        NSLayoutConstraint.activate([
            hostingController.view.leadingAnchor.constraint(equalTo: containerView.leadingAnchor),
            hostingController.view.trailingAnchor.constraint(equalTo: containerView.trailingAnchor),
            hostingController.view.topAnchor.constraint(equalTo: containerView.topAnchor),
            hostingController.view.bottomAnchor.constraint(equalTo: containerView.bottomAnchor)
        ])

        Hansel.setHanselIndexFor(containerView, withIndex: uniqueKey)
        return containerView
    }

    func updateUIView(_ uiView: UIView, context: Context) {
        // No updates required for this wrapper
    }
}




