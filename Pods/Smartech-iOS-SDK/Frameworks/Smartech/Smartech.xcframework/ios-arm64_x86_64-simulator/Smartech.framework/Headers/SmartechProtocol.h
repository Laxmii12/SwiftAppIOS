//
//  SmartechProtocol.h
//  Smartech
//
//  Created by Netcore Solutions on 12/10/20.
//  Copyright © 2020 Netcore Solutions. All rights reserved.
//

#ifndef SmartechProtocol_h
#define SmartechProtocol_h

@protocol SmartechProtocol

/**
 @brief This method is for passing tracked events from Hansel SDK to Smartech SDK.
 
 @param eventName Name of the event.
 @param payloadDictionary Payload to be passed with the event.
 */
- (void)trackEventFromHanselWithName:(NSString * _Nonnull)eventName andPayload:(NSDictionary * _Nullable)payloadDictionary;

/**
 @brief This method is for passing tracked events from Hansel SDK to Smartech SDK.
 
 @param eventId Name of the event.
 @param payloadDictionary Payload to be passed with the event.
 */
- (void)trackSystemEventFromHanselWithID:(NSInteger)eventId andPayload:(NSDictionary * _Nullable)payloadDictionary;

/**
 @brief This method is to fetch list and segment data  from Smartech SDK.
 
 */
- (void)fetchListAndSegment;

- (void)removeListAndSegmentData;


@end

#endif /* SmartechProtocol_h */
