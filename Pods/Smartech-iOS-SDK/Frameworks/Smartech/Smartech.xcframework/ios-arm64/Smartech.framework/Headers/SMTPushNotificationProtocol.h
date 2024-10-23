//
//  SMTPushNotificationProtocol.h
//  Smartech
//
//  Created by Netcore Solutions on 10/03/21.
//  Copyright © 2021 Netcore Solutions. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <Smartech/SmartechPushProtocol.h>
#import <UserNotifications/UserNotifications.h>
#import <UserNotificationsUI/UserNotificationsUI.h>

@protocol SMTPushNotificationProtocol 

- (void)initPushNotificationSDKWith:(NSDictionary * _Nullable)launchOptions andDelegate:(id <SmartechPushProtocol> _Nullable)pushNotificationProtocol with:(NSString *_Nullable)appGroup;

- (void)setPushAmpAndScheduleNotifications:(NSArray * _Nullable)notifications with:(NSArray * _Nullable)scheduledNotifications;

@end
