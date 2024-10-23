//
//  SMTPushSmartechHandler.h
//  SmartPush
//
//  Created by Netcore Solutions on 14/03/21.
//

#import <Foundation/Foundation.h>
#import "SMTNotificationPayloadModel.h"
#import "SMTPushEvent.h"
#import "SMTPushDeeplinkHelper.h"

#import <Smartech/SMTPushNotificationProtocol.h>

NS_ASSUME_NONNULL_BEGIN

@interface SMTPushSmartechHandler : NSObject<SMTPushNotificationProtocol>

/**
 @brief This method returns the SMTPushSmartechHandler instance.
 
 @return The SMTPushSmartechHandler instance object.
 */
+ (instancetype)sharedInstance;

- (BOOL)checkIfTokenNeedsToBeSend;

- (BOOL)checkIfNotificationPermissionNeedsToBeSend;

- (BOOL)checkIfAttributionNeedsToBeUpdated:(NSString *)appIdentity withRecievedIdentity:(NSString *)recievedIdentity;

- (void)handleOpenOperation:(NSInvocationOperation *)operation;

- (void)handleDeeplinkOnMainQueue:(NSString * _Nullable)deeplinkURLString withCustomPayload:(NSDictionary * _Nullable)customPayload;

- (void)processEventsManually;

- (void)recordEventWithId:(SMTPushEvent)eventId eventType:(SMTPushEventType)eventType andPayload:(NSDictionary *)payloadDictionary;

- (void)handleDeeplinkURLString:(NSString *)deeplinkString customPayload:(NSDictionary * _Nullable)customPayload withCompletion:(DeeplinkCompletion)completionBlock;

- (void)loadSmartechStore;

@end

NS_ASSUME_NONNULL_END
