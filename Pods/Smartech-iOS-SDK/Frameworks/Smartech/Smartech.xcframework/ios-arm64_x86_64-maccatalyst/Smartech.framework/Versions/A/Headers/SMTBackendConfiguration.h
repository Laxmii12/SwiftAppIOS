//
//  SMTBackendConfiguration.h
//  Smartech
//
//  Created by Netcore Solutions on 29/01/19.
//  Copyright © 2019 Netcore Solutions. All rights reserved.
//

#import <Foundation/Foundation.h>

@class SMTBaseURL;

NS_ASSUME_NONNULL_BEGIN

typedef NS_ENUM(NSUInteger, SMTBackendEnvironment) {
    BackendEnvironmentProduction = 0,
    BackendEnvironmentPod = 1,
    BackendEnvironmentStaging = 2,
    BackendEnvironmentIndependent = 3,
};

typedef NS_ENUM(NSUInteger, BackendBaseURLType) {
    BackendBaseURLTypeAppInit = 0,
    BackendBaseURLTypeEvents = 1,
    BackendBaseURLTypePushAmp = 2,
    BackendBaseURLTypeInAppMessage = 3,
    BackendBaseURLTypeAppInbox = 4,
    BackendBaseURLTypeCategory = 5,
    BackendBaseURLTypeListSegment = 6,
    BackendBaseURLTypeGeofences = 7,
    BackendBaseURLTypeAddTestDevice = 8
};


/**
 @brief  This class configures the backend.
 */
@interface SMTBackendConfiguration : NSObject

@property (nonatomic, readonly, copy) NSURL *baseAppInitURL;
@property (nonatomic, readonly, copy) NSURL *baseTrackAppActURL;
@property (nonatomic, readonly, copy) NSURL *basePushAmpURL;
@property (nonatomic, readonly, copy) NSURL *baseInAppURL;
@property (nonatomic, readonly, copy) NSURL *baseInboxURL;
@property (nonatomic, readonly, copy) NSURL *listSegmentURL;
@property (nonatomic, readonly, copy) NSURL *geofencesURL;
@property (nonatomic, readonly, copy) NSURL *addTestDeviceURL;

/**
 @brief Returns the global SMTBackendConfiguration instance.
 
 @return SMTBackendConfiguration instance.
 */
+ (instancetype)sharedInstance;

/**
 @brief Sets the Smartech environment.
 
 @param environment BackendEnvironment instance.
 */
- (void)setEnvironment:(SMTBackendEnvironment)environment;

/**
 @brief Sets the Smartech base URL for backend communication.
 
 @param URLString Backend base URL String.
 */
- (void)setBaseAppInitURLString:(NSString *)URLString;

/**
 @brief Sets the Smartech base URL for backend communication.
 
 @param baseURL Backend base URL object that contains all the base urls.
 */
- (void)setAllBaseURL:(SMTBaseURL *)baseURL;

@end

NS_ASSUME_NONNULL_END
