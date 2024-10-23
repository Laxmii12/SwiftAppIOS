//
//  SmartechPushProtocol.h
//  Smartech
//
//  Created by Netcore Solutions on 11/03/21.
//  Copyright © 2021 Netcore Solutions. All rights reserved.
//

//#ifndef SmartechPushProtocol_h
#define SmartechPushProtocol_h

@protocol SmartechPushProtocol

- (BOOL)checkIfTokenNeedsToBeSend;

- (BOOL)checkIfNotificationPermissionNeedsToBeSend;

- (void)processEventsManually;

- (BOOL)checkIfAttributionNeedsToBeUpdated:(NSString *_Nullable)appIdentity withRecievedIdentity:(NSString *_Nullable)recievedIdentity;

- (void)handleOpenOperation:(NSInvocationOperation *_Nullable)operation;

- (void)handleDeeplinkOnMainQueue:(NSString * _Nullable)deeplinkURLString withCustomPayload:(NSDictionary * _Nullable)customPayload;

- (void)recordEventWithId:(NSInteger)eventId eventType:(NSInteger)eventType andPayload:(NSDictionary * _Nullable)payloadDictionary;

- (void)handleDeeplinkURLString:(NSString *_Nullable)deeplinkString customPayload:(NSDictionary * _Nullable)customPayload;

- (void)loadSmartechStore;

@end
