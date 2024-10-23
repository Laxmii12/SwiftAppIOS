//
//  Hansel.h
//  pebbletraceiossdk
//
//  Created by Prabodh Prakash on 25/05/16.
//  Copyright © 2016 Hansel. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIView.h>
#import "HanselUser.h"
#import "HanselSyncStateListener.h"
#import "HanselRequestTypeEnum.h"
#import "HanselActionListener.h"
#import "HanselDeepLinkListener.h"

@protocol HanselFlutterPluginProtocol <NSObject>

@required

- (void)initiateScreenCapturing:(NSString *_Nonnull)appVersion screenName:(NSString *_Nonnull)screenName withClassName:(NSString *_Nonnull)className completionHandler:(void (^_Nonnull)(NSDictionary * _Nonnull result))completionHandler;

- (void)findAnchorWidget:(NSDictionary *_Nonnull)data completionHandler:(void (^_Nonnull)(NSDictionary * _Nullable result))completionHandler;
- (void)onAnchorWidgetPositionChange:(NSDictionary *_Nonnull)data;
- (void)startWidgetTracking:(NSDictionary *_Nonnull)data completionHandler:(void (^_Nonnull)(NSDictionary * _Nonnull result))completionHandler;
- (void)stopWidgetTracking:(NSDictionary *_Nonnull)data completionHandler:(void (^_Nonnull)(NSDictionary * _Nonnull result))completionHandler;

@end

@interface Hansel : NSObject 

typedef NS_ENUM(NSUInteger, HanselLogLevel) {
    HanselLogLevelVerbose = 1,
    HanselLogLevelInfo = 2,
    HanselLogLevelWarn = 3,
    HanselLogLevelError = 4,
    HanselLogLevelProd = 5,
    HanselLogLevelNone = 6
};

/*!
 @method
 
 @abstract
 Initializes the hansel sdk.
 
 @discussion
 This method will initialize the hansel SDK. This method should be called in the didFinishLaunchingWithOptions method in the AppDelegate class.
 
 @param appId   The App ID of this app given on the hansel dashboard.
 @param appKey  The App Key of this app given on the hansel dashboard.
 
 */

+ (void)initializeSDKWithAppID:(NSString * _Nonnull)appId andAppKey:(NSString * _Nonnull)appKey NS_SWIFT_NAME(initializeSDK(_:_:));

/*!
 @method
 
 @abstract
 Checks whether the pushPayload was sent by Hansel.
 
 @discussion
 This method will verify whether the pushPayload received by the app was sent from Hansel. This method should be called before passing the payload to Hansel SDK.
 
 @param pushPayload  The payload received from APNS.
 
 @return true if the given push payload is from Hansel
 false otherwise
 
 */

+ (BOOL)isPushFromHansel:(NSDictionary * _Nullable)pushPayload NS_SWIFT_NAME(isHanselPush(userInfo:));

/*!
 @method
 
 @abstract
 Handles the push payload
 
 @param pushPayload  The payload received from APNS.
 
 @return true if Hansel handled the push payload (if it was a hansel push)
 false otherwise
 
 */

+ (BOOL)handlePushPayload:(NSDictionary * _Nullable)pushPayload NS_SWIFT_NAME(handlePushPayload(userInfo:));

/*!
 @method
 
 @abstract
 Sets the APNS token in Hansel SDK.
 
 @param token  The token received from APNS.
 
 */

+ (void)setNewToken:(NSData * _Nullable)token NS_SWIFT_NAME(setNewToken(_:));

/*!
 @method
 
 @abstract
 This method will give the leaf node ID of all interaction map for the current user.
 
 @return  A Dictionary of all Interaction maps. The dictionary will have Interaction Map ID as key and corresponding LeafNodeId for the current user as value.
 
 */

+ (NSDictionary * _Nonnull)getMaps NS_SWIFT_NAME(getMaps());

/*!
 @method
 
 @abstract
 This method will return an user object. Use this object to set the user attributes.
 
 @return The User object.
 
 */

+ (HanselUser * _Nullable)getUser NS_SWIFT_NAME(getUser());

/*!
 @method
 
 @abstract
 Set the sync listener for receiving call backs from Hansel SDK.
 
 @discussion
 Whenever required Hansel SDK syncs values from Hansel backend. If you wish to receive a call back when the syncing is completed. Then implement the protocol HanselSyncStateListener and register an instance of that class with Hansel SDK. Only one listener can be registered for a requestType.
 
 
 @param listener    Instance of a class implementing the HanselSyncStateListener protocol.
 @param requestType An enum for the request type that you are interested in. Currently the values supported are Configs.
 
 */

+ (void)setHanselSyncStateListener:(id <HanselSyncStateListener> _Nonnull)listener forRequest:(HanselRequestType)requestType NS_SWIFT_NAME(setHanselSyncStateListener(_:forRequest:));

/*!
 @method
 
 @abstract
 Remove the sync listener from receiving call backs from Hansel SDK.
 
 @discussion
 For the given request type remove the listener from Hansel SDK.
 
 @param requestType An enum for the request type that you are interested in. Currently the values supported are Configs.
 
 */

+ (void)removeHanselSyncStateListenerForRequest:(HanselRequestType)requestType NS_SWIFT_NAME(removeHanselSyncStateListenerForRequest(_:));

/*!
 @method
 
 @abstract
 Set the action listener for receiving call backs from Hansel SDK whenever an action is performed.
 
 @discussion
 Whenever an action which is configured Hansel Dashboard is performed this listener will get a callback. Implement the protocol HanselActionListener and register an instance of that class with Hansel SDK. You have to register a listener for every action that you would like to track. You can only register one listener for each action. We maintain a weak reference to the listener to avoid memory leaks.
 
 @param action      Name of the action performed
 @param listener    Instance of a class implementing the HanselActionListener protocol.
 
 */

+ (void)registerHanselActionListener:(NSString * _Nonnull)action andListener:(id <HanselActionListener> _Nonnull) listener NS_SWIFT_NAME(registerHanselActionListener(action:listener:));

/*!
 @method
 
 @abstract
 Set the Deeplink listener for receiving call backs with Launch URL from Hansel SDK whenever an action is performed.
 
 @discussion
 Whenever an action which is configured with launch url on Hansel Dashboard is performed this listener will get a callback. Implement the protocol HanselDeepLinkListener and register an instance of that class with Hansel SDK. You can register one listener for all custom action. We maintain a weak reference to the listener to avoid memory leaks.
 
 @param listener Instance of a class implementing the HanselDeepLinkListener protocol.
 
 */

+ (void)registerHanselDeeplinkListener:(id <HanselDeepLinkListener> _Nonnull)listener NS_SWIFT_NAME(registerHanselDeeplinkListener(listener:));

/*!
 @method
 
 @abstract
 Remove the listener for an action.
 
 @param action      Name of the action performed
 
 */

+ (void)removeHanselActionListener:(NSString * _Nonnull)action NS_SWIFT_NAME(removeHanselActionListener(action:));

/*!
 @method
 
 @abstract
 Set the appFont so that it can used in prompts. If no appFont is set then System Font will be used whenever App Font is selected. Set the font wherever Hansel SDK is initialized.
 
 @param fontFamily  The font family of the font.
 
 */

+ (void)setAppFont:(NSString * _Nonnull)fontFamily NS_SWIFT_NAME(setAppFont(_:));

/*!
 @method
 
 @abstract
 Set the name of the the current screen. This name will be used to place the nudges in the appropriate screen and also for tracking the screen changes in the app.
 
 @param screenName  The name of the current screen.
 
 */

+ (void)setScreen:(NSString * _Nonnull)screenName NS_SWIFT_NAME(setScreen(_:));

/*!
 @method
 
 @abstract
 UnSets the screen name previsouly set by the set screen method.
 
 */

+ (void)unSetScreen  NS_SWIFT_NAME(unSetScreen());

/*!
 @method
 
 @abstract
 Checks if any other nudges are waiting in queue or not.
 
 @return true if there are any nudges waiting in the queue
 
 */

+ (BOOL)onBackButtonPressed  NS_SWIFT_NAME(onBackButtonPressed());

/*!
 @method
 
 @abstract
 This method will enable the debug logs for the Hansel SDK.
 
 */

/**
 @brief Set the debug logging level
 
 @discussion Set using HanselLogLevel enum values or the corresponding int values.
 
 HanselLogLevelVerbose     - enables all logging.
 HanselLogLevelInfo        - enables minimal information related to SDK integration.
 HanselLogLevelWarn        - enables warning information related to SDK integration.
 HanselLogLevelError       - enables errors information related to SDK integration.
 HanselLogLevelNone        - turns off all SDK logging.
 
 You can use the below code.
 
 @code
 [[Smartech sharedInstance] setDebugLevel:HanselLogLevelNone];
 @endcode
 
 @param level The debug level to set.
 */
+ (void)setDebugLevel:(HanselLogLevel)level;

+ (void)enableDebugLogs NS_SWIFT_NAME(enableDebugLogs());

/*!
 @method
 
 @abstract
 Set the url for adding a test group device. Hansel SDK authenticates the url and adds the device to test device if the url is valid.
 
 @param url  The url received from opening the link in pairing email.
 
 */

+ (void)setTgUrl:(NSURL * _Nullable)url NS_SWIFT_NAME(setTgUrl(_:));

/*!
 @method
 
 @abstract
 Tests if the url is opened for adding a tg device.
 
 @param url  The url received from opening the link in pairing email.
 
 @return true if url is created for pairing process.
 
 */

+ (BOOL)isHanselUrl:(NSURL * _Nullable)url NS_SWIFT_NAME(isHanselUrl(_:));

/*!
 @method
 
 @abstract
 Returns the boolean value whether index value is set or not for the given view.
 
 @param index unique value which is set for given view.
 @param view view  for which the Hansel Index is required.
 
 @return Returns the true if index value is set for the given view else will return false.
 
 */
+ (BOOL)setHanselIndexForView:(UIView * _Nonnull)view withIndex:(NSString * _Nonnull)index;


+ (void)startScreenCapturing:(NSString *_Nonnull)appVersion screenName:(NSString *_Nonnull)screenName withClassName:(NSString *_Nonnull)className success:(void (^_Nonnull)(NSDictionary * _Nonnull result)) success;

+ (void)findAnchorWidget:(NSDictionary *_Nonnull)data completionHandler:(void (^_Nonnull)(NSDictionary * _Nonnull result))completionHandler;

+ (void)onAnchorWidgetPositionChange:(NSDictionary *_Nonnull)data;

+ (void)startWidgetTracking:(NSDictionary *_Nonnull)data;

+ (void)stopWidgetTracking:(NSDictionary *_Nonnull)data;

+ (void)setFlutterDelegate:(id _Nullable )flutterDelegate;

+ (id _Nullable )getFlutterDelegate;

@end
