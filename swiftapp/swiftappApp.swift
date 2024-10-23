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



//struct swiftappApp: App {
//    @UIApplicationDelegateAdaptor(AppDelegate.self) var appDelegate
//    var body: some Scene {
//        WindowGroup {
//            ContentView()
//        }
//    }
//}

@main

class AppDelegate : NSObject, UIApplicationDelegate, SmartechDelegate, UNUserNotificationCenterDelegate{
    func application(_ application: UIApplication,
                     didFinishLaunchingWithOptions launchOptions: [UIApplication.LaunchOptionsKey: Any]?) -> Bool {
        Smartech.sharedInstance().initSDK(with: self, withLaunchOptions: launchOptions)
        Smartech.sharedInstance().setDebugLevel(.verbose)
        UNUserNotificationCenter.current().delegate = self
        SmartPush.sharedInstance().registerForPushNotificationWithDefaultAuthorizationOptions()
//        SmartPush.sharedInstance().registerForPushNotification(authorizationOptions: [.alert, .badge, .sound])
        Smartech.sharedInstance().trackAppInstallUpdateBySmartech()
//        HanselTracker.registerListener(listener);

        
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
    
    func application(_ application: UIApplication, didRegisterForRemoteNotificationsWithDeviceToken deviceToken: Data) {
      SmartPush.sharedInstance().didRegisterForRemoteNotifications(withDeviceToken: deviceToken)
    }
    func application(_ app: UIApplication, open url: URL, options: [UIApplication.OpenURLOptionsKey : Any] = [:]) -> Bool {
            let handleBySmartech = Smartech.sharedInstance().application(app, open: url, options: options)
            if !handleBySmartech {
                // Handle the URL within the app
            }
            return true
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

    //--------------Nudges---------

   
//    
    }
