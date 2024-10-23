//
//  Smartech.h
//  Smartech
//
//  Created by Netcore Solutions on 28/01/19.
//  Copyright © 2019 Netcore Solutions. All rights reserved.
//

#import <UIKit/UIKit.h>
#import <UserNotifications/UserNotifications.h>
#import <UserNotificationsUI/UserNotificationsUI.h>
#import <CoreLocation/CoreLocation.h>
#import <WebKit/WebKit.h>

//! Project version number for Smartech.
FOUNDATION_EXPORT double SmartechVersionNumber;

//! Project version string for Smartech.
FOUNDATION_EXPORT const unsigned char SmartechVersionString[];

// In this header, you should import all the public headers of your framework using statements like
// #import <Smartech/PublicHeader.h>

#import <Smartech/SMTServiceOperation.h>
#import <Smartech/SMTBaseRequest.h>
#import <Smartech/SMTAppInboxSettings.h>

NS_ASSUME_NONNULL_BEGIN

static NSString *kSmartechPartnerParameter = @"ncPartnerParameter";

@class SmartechHandler;

typedef NS_ENUM(NSUInteger, SMTLogLevel) {
    SMTLogLevelVerbose = 1,
    SMTLogLevelDebug = 2,
    SMTLogLevelInfo = 3,
    SMTLogLevelWarn = 4,
    SMTLogLevelError = 5,
    SMTLogLevelFatal = 6,
    SMTLogLevelNone = 7,
};

@protocol SmartechDelegate <NSObject>

@optional


/**
 @brief This is Smartech SDK's delegate method for deeplink handling along with custom payload. This delegate method will be triggered when the user clicks the push notification or deeplink
 
 @param deeplinkURLString - Deeplink string that is passed on push nofitication or in-app message click.
 @param customPayload - Contains the custom payload passed from the Smartech panel.
 */
- (void)handleDeeplinkActionWithURLString:(NSString *)deeplinkURLString andCustomPayload:(NSDictionary *_Nullable)customPayload;

/**
 @brief This is Smartech SDK's delegate method for sharing whole notification payload
 
 @param deeplinkURLString - Deeplink string that is passed on push nofitication or in-app message click.
 @param notificationPayload - Contains whole payload of notification.
 */
- (void)handleDeeplinkActionWithURLString:(NSString *)deeplinkURLString andNotificationPayload:(NSDictionary *_Nullable)notificationPayload;

@end

@protocol SMTAppWebViewDelegate <NSObject>

/**
 @brief This delegate method will be triggered when the auto-track is not enabled from web app page.
 
 @param message - The script message received from webpage.
 */
- (void)handleAppWebViewEvent:(WKScriptMessage *)message;

@end


@interface Smartech : NSObject

@property (nonatomic, copy, readonly) NSString *appGroup;
@property (nonatomic, weak, readonly) id <SmartechDelegate> delegate;
@property (nonatomic, strong, readonly) SmartechHandler *smartechHandler;
@property (nonatomic, assign) BOOL appDidBecomeVisible;
@property (nonatomic, weak) id <SMTAppWebViewDelegate> smtAppWebViewDelegate;

#pragma mark - SDK Init Methods

/**
 @brief This method returns the Smartech instance.
 
 @return The Smartech instance object.
 */
+ (instancetype)sharedInstance;

/**
 @brief This method is for intialiazing the Smartech SDK.
 
 @discussion You need to call this method inside your app delegates didFinishLaunchingWithOptions: method.
 
 You can use the below code.
 
 @code
 [Smartech sharedInstance] initSDKWithDelegate:self];
 @endcode
 
 @param delegate The Smartech delegate.
 @param launchOptions The launch option dictionary.
 */
- (void)initSDKWithDelegate:(id <SmartechDelegate>)delegate withLaunchOptions:(NSDictionary * _Nullable)launchOptions;

#pragma mark - Debugging Methods

/**
 @brief Set the debug logging level
 
 @discussion Set using SMTLogLevel enum values or the corresponding int values.
 
 SMTLogLevelVerbose     - enables all logging.
 SMTLogLevelDebug       - enables verbose debug logging.
 SMTLogLevelInfo        - enables minimal information related to SDK integration.
 SMTLogLevelWarn        - enables warning information related to SDK integration.
 SMTLogLevelError       - enables errorn information related to SDK integration.
 SMTLogLevelFatal       - enables crash information related to SDK integration.
 SMTLogLevelNone        - turns off all SDK logging.
 
 You can use the below code.
 
 @code
 [[Smartech sharedInstance] setDebugLevel:SMTLogLevelNone];
 @endcode
 
 @param level The debug level to set.
 */
- (void)setDebugLevel:(SMTLogLevel)level;


#pragma mark - Event Tracking Methods

/**
 @brief This method is used to track app install event.
 
 @discussion This method should be called by the developer to track the app install event to Smartech.
 
 You can use the below code.
 
 @code
 [[Smartech sharedInstance] trackAppInstall];
 @endcode
 */
- (void)trackAppInstall;

/**
 @brief This method is used to track app update event.
 
 @discussion This method should be called by the developer to track the app updates event to Smartech.
 
 You can use the below code.
 
 @code
 [[Smartech sharedInstance] trackAppUpdate];
 @endcode
 */
- (void)trackAppUpdate;

/**
 @brief This method is used to track app install or update event by Smartech SDK itself.
 
 @discussion This method should be called by the developer to track the app install or update event by Smartech SDK itself. If you are calling this method then you should not call trackAppInstall or trackAppUpdate method.
 
 You can use the below code.
 
 @code
 [[Smartech sharedInstance] trackAppInstallUpdateBySmartech];
 @endcode
 */
- (void)trackAppInstallUpdateBySmartech;

/**
 @brief This method is used to track custom event done by the user.
 
 @discussion This method should be called by the developer to track any custom activites that is performed by the user in the app to Smartech backend.
 
 You can use the below code.
 
 @code
 NSDictionary *payloadDictionary = @{};
 [[Smartech sharedInstance] trackEvent:@"Event Name" andPayload:payloadDictionary];
 @endcode
 
 @param eventName The event name to be tracked.
 @param payloadDictionary The payload as dictionary which has event related parameters
 */
- (void)trackEvent:(NSString * _Nonnull)eventName andPayload:(NSDictionary * _Nullable)payloadDictionary;

/**
 @brief This method is used to send login event to Smartech backend.
 
 @discussion This method should be called only when the app gets the user's identity or when the user does a login activity in the application.
 
 You can use the below code.
 
 @code
 [[Smartech sharedInstance] login:@"Your Primary Key Configured In Smartech Panel"];
 @endcode
 
 @param userIdentity The user's primary key as configured in the Smartech Panel.
 */
- (void)login:(NSString *)userIdentity;

/**
 @brief This method would logout the user and clear identity on Smartech backend.
 
 @discussion This method should be called only when the user log out of the application.
 
 You can use the below code.
 
 @code
 [[Smartech sharedInstance] logoutAndClearUserIdentity:YES];
 @endcode
 
 @param clearUserIdentity Yes or No.
 */
- (void)logoutAndClearUserIdentity:(BOOL)clearUserIdentity;

/**
 @brief This method would set the user identity locally and with all subsequent events this identity will be send.
 
 @discussion This method should be called only when the user gets the identity.
 
 You can use the below code.
 
 @code
 [[Smartech sharedInstance] setUserIdentity:@"Your Primary Key Configured In Smartech Panel"];
 @endcode
 
 @param userIdentity The user identity.
 */
- (void)setUserIdentity:(NSString *)userIdentity;

/**
 @brief This method would get the user identity that is stored in the SDK.
 
 @discussion This method should be called to get the user's identity.
 
 You can use the below code.
 
 @code
 [[Smartech sharedInstance] getUserIdentity];
 @endcode
 
 @return NSString The user identity saved in the SDK.
 */
- (NSString *)getUserIdentity;

/**
 @brief This method would clear the identity that is stored in the SDK.
 
 @discussion This method will clear the user's identity by removing it from.
 
 You can use the below code.
 
 @code
 [[Smartech sharedInstance] clearUserIdentity];
 @endcode
 */
- (void)clearUserIdentity;

/**
 @brief This method is used to update the user profile.
 
 @discussion This method should be called by the developer to update all the user related attributes to Smartech.
 
 You can use the below code.
 
 @code
 NSDictionary *payloadDictionary = @{};
 [[Smartech sharedInstance] updateUserProfile:payloadDictionary];
 @endcode
 
 @param payloadDictionary The payload as dictionary which has event related parameters
 */
- (void)updateUserProfile:(NSDictionary *)payloadDictionary;


#pragma mark - GDPR Methods

/**
 @brief This method is used to opt tracking.
 
 @discussion If you call this method then we will opt in or opt out the user of tracking.
 
 You can use the below code.
 
 @code
 [[Smartech sharedInstance] optTracking:NO];
 @endcode
 
 @param isOpted Boolean variable to set tracking.
 */
- (void)optTracking:(BOOL)isOpted;

/**
 @brief This method is used to get the current status of opt tracking.
 
 @discussion If you call this method you will get the current status of the tracking which can be used to render the UI at app level.
 
 You can use the below code.
 
 @code
 [[Smartech sharedInstance] hasOptedTracking];
 @endcode
 
 @return BOOL The current status of opt tracking
 */
- (BOOL)hasOptedTracking;

/**
 @brief This method is used to opt in-app messages.
 
 @discussion If you call this method then we will opt in or opt out the user of in-app messages.
 
 You can use the below code.
 
 @code
 [[Smartech sharedInstance] optInAppMessage:YES];
 @endcode
 
 @param isOpted Boolean variable to set in-app messages.
 */
- (void)optInAppMessage:(BOOL)isOpted;

/**
 @brief This method is used to get the current status of opt in-app messages.
 
 @discussion If you call this method you will get the current status of the opt in-app messages which can be used to render the UI at app level.
 
 You can use the below code.
 
 @code
 [[Smartech sharedInstance] hasOptedInAppMessage];
 @endcode
 
 @return BOOL The current status of opt push notifications.
 */
- (BOOL)hasOptedInAppMessage;


#pragma mark - Location Methods

/**
 @brief This method is used to set the user's location to the SDK.
 
 @discussion You need to call this method to set location which will be passed on the Smartech SDK.
 
 You can use the below code.
 
 @code
 CLLocationCoordinate2D c2D = CLLocationCoordinate2DMake(lat, lon);
 [[Smartech sharedInstance] setUserLocation:c2D];
 @endcode
 
 @param location The user's locations to be passed with the events.
 */
- (void)setUserLocation:(CLLocationCoordinate2D)location;


#pragma mark - Helper Methods

/**
 @brief This method is used to get the app id used by the Smartech SDK.
 
 @discussion If you call this method you will get the app id used by the Smartech SDK.
 
 You can use the below code.
 
 @code
 [[Smartech sharedInstance] getAppId];
 @endcode
 
 @return NSString The app id used by Smartech SDK.
 */
- (NSString *)getAppId;

/**
 @brief This method is used to get the device push token used by Smartech SDK.
 
 @discussion If you call this method you will get the device push token which is used for sending push notification.
 
 You can use the below code.
 
 @code
 [[Smartech sharedInstance] getDevicePushToken];
 @endcode
 
 @return NSString The device push token.
 */
- (NSString *)getDevicePushToken;

/**
 @brief This method is used to get the device unique id used by Smartech SDK.
 
 @discussion If you call this method you will get the device unique id which is used to identify a device on Smartech.
 
 You can use the below code.
 
 @code
 [[Smartech sharedInstance] getDeviceGuid];
 @endcode
 
 @return NSString The unique device id.
 */
- (NSString *)getDeviceGuid;

/**
 @brief This method is used to get the current Smartech SDK version.
 
 @discussion If you call this method you will get the current Smartech SDK version used inside the app.
 
 You can use the below code.
 
 @code
 [[Smartech sharedInstance] getSDKVersion];
 @endcode
 
 @return NSString The current Smartech SDK version.
 */
- (NSString *)getSDKVersion;

/**
 @brief This method is used to get the ncExternalIdentity of the current device user.
 
 @discussion If you call this method you will get the ncExternalIdentity of the current device user.

 @return NSString - the ncExternalIdentity.
*/
- (NSString *)getNCExternalIdentity;

/**
 @brief This method is used to get all the partner parameters.

 @discussion If you call this method you will get the partner parameter that you will need to send to any third party SDK's.
 
 @return NSDictionary - the partner parameters
*/
- (NSDictionary *)getPartnerParameters;

/**
 @brief This method is used to get all the partner parameters in JSON string.

 @discussion If you call this method you will get the partner parameter that you will need to send to any third party SDK's.
 
 @return NSString - the partner parameter string
*/
- (NSString *)getPartnerParametersString;

/**
 @brief This method is used to set the device advertiser id to be shared with Smartech backend.
 
 @discussion The developer needs to handle capturing of advertised id and then pass it to the SDK which will send it to the backend.
 
 You can use the below code.
 
 @code
 [[Smartech sharedInstance] setDeviceAdvertiserId:@""];
 @endcode
 */
- (void)setDeviceAdvertiserId:(NSString *)advertiserId;

/**
 @brief This method is used to manually process events.
 
 @discussion If you call this method the Smartech SDK will start the processing immediately.
 
 You can use the below code.
 
 @code
 [[Smartech sharedInstance] processEventsManually];
 @endcode
 */
- (void)processEventsManually;

/**
 @brief This method is used to print all the Smartech related values stored in NSUserDefault.
 
 @discussion If you call this method you will be able to get all the Smartech related values stored in NSUserDefault.
 
 You can use the below code.
 
 @code
 [[Smartech sharedInstance] getSmartechStoredPreference];
 @endcode
 */
- (NSDictionary *)getSmartechStoredPreference;

/**
 @brief This method is used to get the a URL after adding Smartech attribution parameters.
 
 @discussion This method should be called by the developer if you want to track attribution from your app to your website. Your website should be integrated with Smartech JavaScript Library. When you call the method we will add the query parameters to the provided NSURL.
 
 You can use the below code.
 
 @code
 NSURL *deeplinkURL = [NSURL URLWithString:@"https://netcoresmartech.com/"];
 NSURL *smartechAttributedURL = [[Smartech sharedInstance] getSmartechAttributedURL:deeplinkURL];
 @endcode
 
 @param deeplinkURL The url to which the attribution is to be added.
 @return NSURL The complete URL with the Smartech attribution parameter.
 */
- (NSURL *)getSmartechAttributedURL:(NSURL *)deeplinkURL;


/**
 @brief Using this method user can set current location of the user which will be used by SDK.
 
 @discussion If this method is called by developer SDK need not call startupdainglocation
 
 @param location CLLocation object
 */

- (void)setLocation:(CLLocation*)location;

/**
 @brief This method will be used to handle authorisation state changes
 
 @discussion This method will be used to handle authorisation state changes
 
 @param status CLAuthorizationStatus
 */
- (void)handleDidChangeAuthorizationStatus:(CLAuthorizationStatus)status;

/*
 @brief This method is for opening URL from the Smartech SDK.
 
 @discussion You need to call this method inside your app delegates application:openURL method.
 
 You can use the below code.
 
 @code
 [[Smartech sharedInstance] application:app openURL:url options:options];
 @endcode
 
 @param app The instace of Application.
 @param url The URL to open.
 @param options The launch option dictionary.
 @return true if url is created for pairing process, false if the url is not created for pariing process. If false is returned, then the app should handle the url.
 */
- (BOOL)application:(UIApplication *)app openURL:(NSURL *)url options:(NSDictionary<UIApplicationOpenURLOptionsKey,id> *)options;

/*
 @brief This method adds app info and device info to webview.
 
 @param appDictionary Add users parameter.
 
 */
- (WKUserScript *)getSmartechAppWebScript:(NSDictionary * _Nullable)appDictionary;

/**
 @brief This method sets messageHandler name.
 
 @return messageHandler name.
 
 */
- (NSString *)getSmartechAppWebMessageHandler;

/**
 @brief Track a event when script message is received from a webpage.
 
 @param message The script message received from webpage.
 
 */
- (void)appWebDidReceiveScriptMessage:(WKScriptMessage *)message;

@end

NS_ASSUME_NONNULL_END
