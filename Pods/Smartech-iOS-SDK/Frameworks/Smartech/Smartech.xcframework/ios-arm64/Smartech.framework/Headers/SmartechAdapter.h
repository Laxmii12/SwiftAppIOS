//
//  SmartechAdapter.h
//  Smartech
//
//  Created by Netcore Solutions on 14/12/20.
//  Copyright © 2020 Netcore Solutions. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
#import "SmartechProtocol.h"

NS_ASSUME_NONNULL_BEGIN

@interface SmartechAdapter : NSObject

/**
 @brief This method returns the SmartechAdapter instance.
 
 @return The SmartechAdapter instance object.
 */
+ (instancetype)sharedInstance;

/**
 @brief This method is for intialiazing the Hansel SDK.
 
 @param deviceGUID The GUID for app.
 */
- (void)initSDKWithHanselWithGUID:(NSString * _Nullable)deviceGUID;

/**
 @brief This method is for passing tracked events to Hansel SDK.
 
 @param eventName Name of the event.
 @param payloadDictionary Payload to be passed with the event.
 */
- (void)updateTrackEvent:(NSString * _Nonnull)eventName andPayload:(NSDictionary * _Nullable)payloadDictionary;

/**
 @brief This method is to set list and segment data  to Hansel SDK.
 
 @param listSegmentDictionary List and Segment data.
 */
- (void)setListAndSegmentData:(NSDictionary *)listSegmentDictionary;

- (void)removeListAndSegmentData;

/**
 @brief This method would set the user identity locally and with all subsequent events this identity will be send.
 
 @discussion This method should be called only when the user gets the identity.
 
 @param userIdentity The user identity.
 */
- (void)setUserIdentity:(NSString * _Nullable)userIdentity;

/**
 @brief This method would clear the identity that is stored in the SDK.
 
 @discussion This method will clear the user's identity by removing it from.
 */
- (void)clearUserIdentity;

/**
 @brief This method is for opening URL from the Smartech SDK.

 @param app The instace of Application.
 @param url The URL to open.
 @param options The launch option dictionary.
 @return true if url is created for pairing process, false if the url is not created for pariing process. If false is returned, then the app should handle the url.
 */
- (BOOL)application:(UIApplication * _Nullable)app openURL:(NSURL * _Nullable)url options:(NSDictionary<UIApplicationOpenURLOptionsKey,id> * _Nullable)options;

- (void)hanselURLEndPoints:(NSDictionary * _Nullable)endPointDict;

#pragma mark - Share system events with Hansel SDK

/**
 @brief This method is used to record life cycle events.
 */
- (void)trackAppLaunchEvents;

- (void)updateUserProfile:(NSDictionary *)payloadDictionary;

@end

NS_ASSUME_NONNULL_END
