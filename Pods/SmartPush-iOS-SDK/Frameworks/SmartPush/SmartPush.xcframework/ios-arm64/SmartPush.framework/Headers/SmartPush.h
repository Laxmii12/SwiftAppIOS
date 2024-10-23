//
//  SmartPush.h
//  SmartPush
//
//  Created by Netcore Solutions on 17/02/21.
//  Copyright © 2021 Netcore Solutions. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UserNotifications/UserNotifications.h>
#import <UserNotificationsUI/UserNotificationsUI.h>

#import <SmartPush/SMTNotificationServiceExtension.h>
#import <SmartPush/SMTCustomNotificationViewController.h>

//! Project version number for SmartPush.
FOUNDATION_EXPORT double SmartPushVersionNumber;

//! Project version string for SmartPush.
FOUNDATION_EXPORT const unsigned char SmartPushVersionString[];

// In this header, you should import all the public headers of your framework using statements like #import <SmartPush/PublicHeader.h>

static NSString * _Nonnull const kSMTNotificationReceivedIdentifier = @"SmartechNotificationReceived";

typedef NS_ENUM(NSUInteger, SMTPushLogLevel) {
    SMTPushLogLevelVerbose = 1,
    SMTPushLogLevelDebug = 2,
    SMTPushLogLevelInfo = 3,
    SMTPushLogLevelWarn = 4,
    SMTPushLogLevelError = 5,
    SMTPushLogLevelFatal = 6,
    SMTPushLogLevelNone = 7,
};

NS_ASSUME_NONNULL_BEGIN

@interface SmartPush : NSObject

@property (nonatomic, copy, readonly) NSString *appGroup;

/**
 @brief This method returns the SmartechPushNotification instance.
 
 @return The SmartechPushNotification instance object.
 */
+ (instancetype)sharedInstance;

- (void)initSDKWithLaunchOptions:(NSDictionary * _Nullable)launchOptions;

/**
 @brief This method is for registering for push notification with APNS using default configuration.
 
 @discussion You need to call this method if you want to show the push notification permission. By default the SDK will support sound, alert & badge.
 
 You can use the below code.
 
 @code
 [[SmartechPushNotification registerForPushNotificationWithDefaultAuthorizationOptions];
 @endcode
 */
- (void)registerForPushNotificationWithDefaultAuthorizationOptions;

/*!
 @brief This method is for registering for push notification with APNS.
 
 @discussion When you call this method you will see the push notification permission alert.
 
 You can use the below code.
 
 @code
 UNAuthorizationOptions options = (UNAuthorizationOptionSound | UNAuthorizationOptionAlert | UNAuthorizationOptionBadge);
 [[SmartechPushNotification registerForPushNotificationWithAuthorizationOptions:options];
 @endcode
 
 @remark You don't need to call.
 
 @code
 [[UIApplication sharedApplication] registerForRemoteNotifications];
 @endcode
 
 @param options The notification authorization constant like alert, badge, sound etc.
 */
- (void)registerForPushNotificationWithAuthorizationOptions:(UNAuthorizationOptions)options;

/**
 @brief This method is for capturing the device token that the app will receive from Apple Push Notification Service (APNS). The method will send the device token to Smartech backend.
 
 @discussion This method should be called inside the didRegisterForRemoteNotificationsWithDeviceToken: method of UIApplication class.
 
 You can use the below code.
 
 @code
 [[SmartechPushNotification didRegisterForRemoteNotificationsWithDeviceToken:deviceToken];
 @endcode
 
 @param deviceToken The unique device token recieved from APNS.
 */
- (void)didRegisterForRemoteNotificationsWithDeviceToken:(NSData *)deviceToken;

/**
 @brief This method is used for capuring the error that may occur if the app was unable to register your device with APNS or if your app is not properly configured for remote notifications.
 
 @discussion This method should be called inside the didRegisterForRemoteNotificationsWithDeviceToken: method of UIApplication class.
 
 You can use the below code.
 
 @code
 [[SmartechPushNotification didFailToRegisterForRemoteNotificationsWithError:error];
 @endcode
 
 @param error An NSError object that encapsulates information why registration did not succeed. The app can choose to display this information to the user.
 */
- (void)didFailToRegisterForRemoteNotificationsWithError:(NSError *)error;

/**
 @brief This method to process incoming remote notifications for your app.
 
 @discussion This method should be called inside the didReceiveRemoteNotification:fetchCompletionHandler method of UIApplication class.
 
 You can use the below code.
 
 @code
 [[SmartechPushNotification didReceiveRemoteNotification:userInfo];
 @endcode
 
 @param userInfo A dictionary that contains information related to the remote notification, potentially including a badge number for the app icon, an alert sound, an alert message to display to the user, a notification identifier, and custom data.
 */
- (void)didReceiveRemoteNotification:(NSDictionary *)userInfo withCompletionHandler:(void(^)(UIBackgroundFetchResult bgFetchResult))completionBlock;

/**
 @brief The method will be called on the delegate only if the application is in the foreground. The application can choose to have the notification presented as a sound, badge, alert and/or in the notification list.
 
 @discussion This method should be called inside the userNotificationCenter:willPresentNotification:withCompletionHandler method of UIApplication class.
 
 You can use the below code.
 
 @code
 [[SmartechPushNotification willPresentForegroundNotification:notification];
 @endcode
 
 @param notification The notification object that is about to be delivered.
 */
- (void)willPresentForegroundNotification:(UNNotification *)notification;

/**
 @brief The method will be called on the delegate when the user responded to the notification by opening the application, dismissing the notification or choosing a UNNotificationAction.
 
 @discussion This method should be called inside the userNotificationCenter:didReceiveNotificationResponse:withCompletionHandler method of UIApplication class.
 
 You can use the below code.
 
 @code
 [[SmartechPushNotification didReceiveNotificationResponse:response];
 @endcode
 
 @param response The user’s response to the notification. This object contains the original notification and the identifier string for the selected action.
 */
- (void)didReceiveNotificationResponse:(UNNotificationResponse *)response;

/**
 @brief The method will be called to get the total notiFication badge count.
 
 You can use the below code.
 
 @code
 [[SmartechPushNotification getNotificationBadgeCount];
 @endcode
 
 @return NSInteger The notificaiton badge count.
 */
- (NSInteger)getNotificationBadgeCount;


#pragma mark - GDPR Methods

/**
 @brief This method is used to opt push notifications.
 
 @discussion If you call this method then we will opt in or opt out the user of recieving push notifications.
 
 You can use the below code.
 
 @code
 [[SmartechPushNotification sharedInstance] optPushNotification:NO];
 @endcode
 
 @param isOpted Boolean variable to set tracking.
 */
- (void)optPushNotification:(BOOL)isOpted;

/**
 @brief This method is used to get the current status of opt push notification.
 
 @discussion If you call this method you will get the current status of the tracking which can be used to render the UI at app level.
 
 You can use the below code.
 
 @code
 [[SmartechPushNotification sharedInstance] hasOptedPushNotification];
 @endcode
 
 @return BOOL The current status of opt push notifications.
 */
- (BOOL)hasOptedPushNotification;

/**
 @brief This method is used to check is the notification is from Smartech or not.
 
 @param userInfo The notification payload.
 
 @return BOOL If YES then notification is from Smartech.
 */
- (BOOL)isNotificationFromSmartech:(NSDictionary *)userInfo;

@end

NS_ASSUME_NONNULL_END
