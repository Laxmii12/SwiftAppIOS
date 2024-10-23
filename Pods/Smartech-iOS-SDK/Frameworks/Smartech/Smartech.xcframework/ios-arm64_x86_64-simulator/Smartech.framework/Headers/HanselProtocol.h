//
//  HanselProtocol.h
//  Smartech
//
//  Created by Netcore Solutions on 12/10/20.
//  Copyright © 2020 Netcore Solutions. All rights reserved.
//

#ifndef HanselProtocol_h
#define HanselProtocol_h

#import <UIKit/UIKit.h>
#import "SmartechProtocol.h"

@protocol HanselProtocol

/**
 @brief This method is for intialiazing the Hansel SDK.
 
 @param appId The Hansel SDK App ID.
 @param appKey The Hansel SDK App Key.
 @param smartechProtocol The Smartech Protocol..
 @param guid The GUID for app.
 */
- (void)initWithAppId:(NSString * _Nullable)appId appKey:(NSString * _Nullable)appKey smartechProtocol:(id <SmartechProtocol> _Nullable)smartechProtocol andGuid:(NSString * _Nullable)guid;

/**
 @brief This method is for passing tracked events to Hansel SDK.
 
 @param eventName Name of the event.
 @param properties Payload to be passed with the event.
 */
- (NSDictionary * _Nonnull)logSmartechEvent:(NSString * _Nonnull)eventName withProperties:(NSDictionary * _Nullable)properties;

/**
 @brief This method is to set list and segment data  to Hansel SDK.
 
 @param lists List  data.
 @param segments  Segment data.
 */
- (void)setListAndSegmentsForUser:(NSArray * _Nullable)lists andSegments:(NSArray * _Nullable)segments;

/**
 @brief This method is for passing User profile to Hansel SDK.
 
 @param userAttributes Name of the event.
 */
- (void)setUserAttributes:(NSDictionary * _Nullable)userAttributes;

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

/*!
@method

@abstract
Set if the url with Smartech for adding a test device.

@param url  The url received from opening the link in pairing email.
 
@return true if url is created for pairing process, false if the url is not created for pariing process. If false is returned, then the app should handle the url.

*/
- (BOOL)handleTestDeviceUrl:(NSURL * _Nullable)url;

- (void)hanselEndPoints:(NSDictionary * _Nonnull)dict;

@end

#endif /* HanselProtocol_h */
