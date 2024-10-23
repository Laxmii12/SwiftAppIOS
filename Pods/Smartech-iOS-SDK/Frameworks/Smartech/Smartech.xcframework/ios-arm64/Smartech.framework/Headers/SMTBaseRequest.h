//
//  SMTBaseRequest.h
//  Smartech
//
//  Created by Netcore Solutions on 21/02/19.
//  Copyright © 2019 Netcore Solutions. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
#import <CoreLocation/CoreLocation.h>
#import "SMTBackendAPIRequest.h"

NS_ASSUME_NONNULL_BEGIN

@class SMTInfo;
@class SMTConfig;

@interface SMTBaseRequest : NSObject <SMTBackendAPIRequest>

@property (nonatomic, copy, readonly) NSString *appVersion;
@property (nonatomic, copy, readonly) NSString *appBuild;
@property (nonatomic, copy, readonly) NSString *osName;
@property (nonatomic, copy, readonly) NSString *osVersion;
@property (nonatomic, copy, readonly) NSString *deviceMake;
@property (nonatomic, copy, readonly) NSString *deviceModel;
@property (nonatomic, copy, readonly) NSString *deviceLanguage;
@property (nonatomic, copy, readonly) NSString *deviceAdvertiserId;
@property (nonatomic, copy, readonly) NSString *appId;
@property (nonatomic, copy, readonly) NSString *pushid;
@property (nonatomic, copy, readonly) NSString *pushidOld;
@property (nonatomic, copy, readonly) NSString *appBundleId;
@property (nonatomic, copy, readonly) NSString *carrier;
@property (nonatomic, copy, readonly) NSString *countryCode;
@property (nonatomic, copy, readonly) NSString *radio;
@property (nonatomic, copy, readonly) NSString *vendorId;
@property (nonatomic, assign, readonly) CGFloat deviceWidth;
@property (nonatomic, assign, readonly) CGFloat deviceHeight;
@property (nonatomic, copy, readonly) NSString *deviceGuid;
@property (nonatomic, copy, readonly) NSNumber *bod;
@property (nonatomic, copy, readonly) NSString *eventId;
@property (nonatomic, copy, readonly) NSString *eventName;
@property (nonatomic, copy, readonly) NSString *eventTime;
@property (nonatomic, copy, readonly) NSString *sdkVersion;

/**
 @brief This method is called for initializing the base request. Override the base method for initilazing the specific request object.
 
 @param info - the info object required for initializing.
 
 @return SMTBaseRequest Instance
 */
- (instancetype)initWithInfo:(SMTInfo *)info;

@end

NS_ASSUME_NONNULL_END
