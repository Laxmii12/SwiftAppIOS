//
//  HanselEventsListener.h
//  Hansel
//
//  Created by Rajeev Rajeshuni on 02/01/19.
//  Copyright © 2019 Hansel Software Private Limited. All rights reserved.
//

#import <Foundation/Foundation.h>

/*!
 
 @abstract
 Protocol to be implemented by the listener for firing Hansel events.
 
 @discussion
 Hansel SDK needs to fire some events for purpose of analyzing the user behavior. These events need to be fired to your analytics vendor.  To allow Hansel to fire events, you will have to implement this protocol and register the reference of the object via registerListener method of HanselTracker class.
 */


@protocol HanselEventsListener
@required

/*!
 @method
 
 @abstract
 Fire hansel events to your analytics vendor in this method.
 
 @param eventName  Name of the event
 @param properties A map for event properties.
 
 */

- (void)fireHanselEventwithName:(NSString * _Nonnull)eventName andProperties:(NSDictionary * _Nullable)properties NS_SWIFT_NAME(fireHanselEventwithName(eventName:properties:));

@end
