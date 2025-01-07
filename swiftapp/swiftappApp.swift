//
//  swiftappApp.swift
//  swiftapp
//
//  Created by Laxmee Medli on 18/10/24.
//

import SwiftUI
import Smartech
import SmartPush
import UserNotifications
import UserNotificationsUI
import SmartechAppInbox
import SmartechNudges


@main
struct swiftappApp: App {
    @UIApplicationDelegateAdaptor(AppDelegate.self) var appDelegate
    
    var body: some Scene {
        WindowGroup {
            ContentView()
                .onOpenURL { url in
                    print("urlopened===>", url)
                    let app = UIApplication.shared
                                        let options: [UIApplication.OpenURLOptionsKey: Any] = [:] // Customize if needed
                                        let handledBySmartech = Smartech.sharedInstance().application(app, open: url, options: options)
                    print("handledBySmartech===>", handledBySmartech)

                                        if !handledBySmartech {
                                            // Handle the URL manually if not handled by Smartech
                                            print("URL not handled by Smartech, handling manually.")
                                        }
                }
                    
//                .onAppear {
//                                    // Example of interacting with SceneDelegate, if needed
//                                    if let scene = UIApplication.shared.connectedScenes.first as? UIWindowScene,
//                                       let sceneDelegate = scene.delegate as? SceneDelegate {
//                                        // Call a method or access properties in SceneDelegate
//                                        sceneDelegate.scene(<#UIScene#>, openURLContexts: <#Set<UIOpenURLContext>#>)
//
//                                    }
//                                }
            
        }
    }
}



//class SceneDelegate : NSObject, UIWindowSceneDelegate  {
//
//    var window: UIWindow?
//    
//    func scene(_ scene: UIScene, willConnectTo session: UISceneSession, options connectionOptions: UIScene.ConnectionOptions) {
//        if let urlContext = connectionOptions.urlContexts.first {
//                let url = urlContext.url
//                let handledBySmartech = Smartech.sharedInstance().application(UIApplication.shared, open: url, options: [:])
//                if(!handledBySmartech) {
//                    //This url should be handled by the app.
//                }
//        }
//    }
//        
//    func scene(_ scene: UIScene, openURLContexts URLContexts: Set<UIOpenURLContext>) {
//        if let urlContext = URLContexts.first {
//                let url = urlContext.url
//                let handledBySmartech = Smartech.sharedInstance().application(UIApplication.shared, open: url, options: [:])
//                if(!handledBySmartech) {
//                    //This url should be handled by the app.
//                }
//        }
//    }
//
//    
//}

class AppDelegate : NSObject, UIApplicationDelegate, SmartechDelegate, UNUserNotificationCenterDelegate, HanselActionListener,HanselEventsListener{
    func onActionPerformed(action: String!) {
        
    }
    
    
    func fireHanselEventwithName(eventName: String, properties: [AnyHashable : Any]?) {
        
//        Smartech.sharedInstance().trackEvent(eventName, andPayload: properties)
    }
    
    func application(_ application: UIApplication,
                     didFinishLaunchingWithOptions launchOptions: [UIApplication.LaunchOptionsKey: Any]?) -> Bool {
        Smartech.sharedInstance().initSDK(with: self, withLaunchOptions: launchOptions)
        Smartech.sharedInstance().setDebugLevel(.verbose)
        Hansel.enableDebugLogs()
        UNUserNotificationCenter.current().delegate = self
        SmartPush.sharedInstance().registerForPushNotificationWithDefaultAuthorizationOptions()
//        SmartPush.sharedInstance().registerForPushNotification(authorizationOptions: [.alert, .badge, .sound])
        Smartech.sharedInstance().trackAppInstallUpdateBySmartech()
//        let hanselActionsHandler = HanselActionsHandler()
          
          
        //Register the instance with this line:
//        Hansel.registerHanselActionListener(action: "action name", listener: hanselActionsHandler)
        HanselTracker.registerListener(self);

        
        //App Inbox --------------------------------------------------------
        
        var appInboxCategoryArray: [SMTAppInboxCategoryModel]?
        appInboxCategoryArray = []
        appInboxCategoryArray = SmartechAppInbox.sharedInstance().getCategoryList()
        
        var appInboxArray: [SMTAppInboxMessage]?
        appInboxArray = []
        appInboxArray = SmartechAppInbox.sharedInstance().getMessageWithCategory(appInboxCategoryArray as? NSMutableArray)


        func refreshInboxDataSourceWithCategory() {
            appInboxArray = []
            appInboxArray = SmartechAppInbox.sharedInstance().getMessageWithCategory(appInboxCategoryArray as? NSMutableArray)

            DispatchQueue.main.async {
                //Refresh table View
            }
        }


        print("App has launched successfully")
        return true
    }
//
//    func application(_ app: UIApplication, open url: URL, options: [UIApplication.OpenURLOptionsKey : Any] = [:]) -> Bool {
//        let handleBySmartech = Smartech.sharedInstance().application(app, open: url, options: options);
//        if(!handleBySmartech) {
//            //Handle the url by the app
//        }
//        return true;
//    }
    
    func application(_ application: UIApplication, didRegisterForRemoteNotificationsWithDeviceToken deviceToken: Data) {
      SmartPush.sharedInstance().didRegisterForRemoteNotifications(withDeviceToken: deviceToken)
    }
    
    
    
    func application(_ application: UIApplication, didFailToRegisterForRemoteNotificationsWithError error: Error) {
      SmartPush.sharedInstance().didFailToRegisterForRemoteNotificationsWithError(error)
    }
    
    //MARK:- UNUserNotificationCenterDelegate Methods
    func userNotificationCenter(_ center: UNUserNotificationCenter, willPresent notification: UNNotification, withCompletionHandler completionHandler: @escaping (UNNotificationPresentationOptions) -> Void) {
      SmartPush.sharedInstance().willPresentForegroundNotification(notification)
      completionHandler([.alert, .badge, .sound])
    }
        
    func userNotificationCenter(_ center: UNUserNotificationCenter, didReceive response: UNNotificationResponse, withCompletionHandler completionHandler: @escaping () -> Void) {
      DispatchQueue.main.asyncAfter(deadline: .now() + 0.5) {
            SmartPush.sharedInstance().didReceive(response)
      }
      
      completionHandler()
    }
    func application(_ application: UIApplication, didReceiveRemoteNotification userInfo: [AnyHashable : Any], fetchCompletionHandler completionHandler: @escaping (UIBackgroundFetchResult) -> Void) {
        SmartPush.sharedInstance().didReceiveRemoteNotification(userInfo, withCompletionHandler: completionHandler)
    }
    
    
    // MARK: - Smartech Delegate Methods

    func handleDeeplinkAction(withURLString deeplinkURLString: String, andNotificationPayload notificationPayload: [AnyHashable : Any]?) {
        print("SMTLogger: handleDeeplinkActionWithURLString")
        print("SMTLogger: Deeplink URL: \(deeplinkURLString)")
        print("SMTLogger: Deeplink URL====?:" ,deeplinkURLString)
        NotificationCenter.default.post(name: NSNotification.Name("DeepLinkReceived"), object: deeplinkURLString)

        print("SMTLogger: NotificationPayload: \(String(describing: notificationPayload))")
    }

   
       
    }
