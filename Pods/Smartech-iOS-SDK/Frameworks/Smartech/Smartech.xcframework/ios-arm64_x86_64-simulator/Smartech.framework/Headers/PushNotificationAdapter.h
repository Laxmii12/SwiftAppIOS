//
//  PushNotificationAdapter.h
//  Smartech
//
//  Created by Netcore Solutions on 10/03/21.
//  Copyright © 2021 Netcore Solutions. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UserNotifications/UserNotifications.h>
#import <UserNotificationsUI/UserNotificationsUI.h>

NS_ASSUME_NONNULL_BEGIN

@interface PushNotificationAdapter : NSObject

/**
 @brief This method returns the SmartechAdapter instance.
 
 @return The SmartechAdapter instance object.
 */
+ (instancetype)sharedInstance;

- (void)initPushNotificationSDKWith:(NSDictionary * _Nullable)launchOptions;

- (void)setPushAmpAndScheduleNotifications:(NSArray *)notifications with:(NSArray *)scheduledNotifications;

- (void)recordEventWithId:(NSInteger)eventId eventType:(NSInteger)eventType andPayload:(NSDictionary * _Nullable)payloadDictionary;

@end

NS_ASSUME_NONNULL_END
