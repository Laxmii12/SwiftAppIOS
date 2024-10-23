//
//  HanselTracker.h
//  Pods
//
//  Created by Akash Nagar on 8/7/17.
//
//

#import <Foundation/Foundation.h>

@protocol HanselEventsListener;

typedef void (^completionBlock)(NSString * _Nullable eventName, NSString * _Nullable vendor, NSDictionary * _Nullable properties);

@class HanselProperties;

@interface HanselTracker : NSObject

/*!
 @method
 
 @abstract
 Set the events listener with Hansel SDK.
 
 @discussion
 Hansel SDK needs to send some events to analyze user behavior. These events need to be fired to your analytics vendor. Please fire these events to only one analytics vendor. To allow Hansel SDK to send events, implement HanselEventsListener protocol and register the reference of the object with Hansel SDK. At any point of time there can only be one events listener registered with Hansel SDK.
 
 @param listener  Instance of a class implementing the HanselEventsListener protocol.
 
 */

+ (void)registerListener:(id <HanselEventsListener> _Nonnull)listener NS_SWIFT_NAME(registerListener(_:));

/*!
 @method
 
 @abstract
 Remove the events listener from Hansel SDK.
 
 @discussion
 Remove the events listener from Hansel SDK already registered with Hansel SDK. Please don't do this unless you wish to register another listener with the Hansel SDK.
 
 */

+ (void)deRegisterListener NS_SWIFT_NAME(deRegisterListener());

/*!
 @method
 
 @abstract
 Get the Hansel Data for the given event.
 
 @discussion
 Call this method to get the Hansel Data. Append the data returned by this method to the another properties that you intend to send to your analytics vendor.
 
 @param eventName   Event to be tracked
 @param vendor      Vendor for the given event.
 @param properties  Event properties
 
 @return A dictionary containing the analytics data.
 
 */

+ (NSDictionary * _Nonnull)getHanselData:(NSString * _Nonnull)eventName andVendor:(NSString * _Nonnull)vendor withProperties:(NSDictionary * _Nullable)properties NS_SWIFT_NAME(getHanselData(_:vendor:withProperties:)) __deprecated_msg("Please use logEvent method for logging events with Hansel SDK.");

/*!
 @method
 
 @abstract
 Checks whether the event is tracked by any of the Maps on the Hansel dashboard.
 
 @param event       Event to be tracked
 @param vendor      Vendor for the given event
 @param properties  Event properties
 
 @return True if the event is tracked by any of the Maps on Hansel Dashboard, False otherwise.
 
 */

+ (BOOL)isUsedInMap:(NSString * _Nonnull)event andVendor:(NSString * _Nonnull)vendor withProperties:(NSDictionary * _Nullable)properties NS_SWIFT_NAME(isUsedInMap(_:vendor:withProperties:))  __deprecated_msg("Please use logEvent method for logging events with Hansel SDK.");

/*
 @abstract
 Log the event and get the Hansel Data for the given event.
 
 @discussion
 Call this method to log the event and get the Hansel Data for the given event. Append the data returned by this method to the another properties that you intend to send to your analytics vendor. The appending is optional.
 
 @param eventName   Event to be tracked
 @param vendor      Vendor for the given event.
 @param properties  Event properties
 
 @return A dictionary containing the analytics data.
 
 */

+ (NSDictionary * _Nonnull)logEvent:(NSString * _Nonnull)eventName andVendor:(NSString * _Nonnull)vendor withProperties:(NSDictionary * _Nullable)properties NS_SWIFT_NAME(logEvent(_:vendor:withProperties:));


/*
 @abstract
 Handles the event and gets the Hansel Data for the event.
 
 @discussion
 Call this method to log the event and get the Hansel Data
 for the given event. You may append the data returned by
 this method to the another properties that you intend to
 send to your analytics vendor.
 
 @param eventName   Event to be tracked
 @param vendor      The analytics provider that you use
 @param properties  Event properties
 @param shouldFire  Whether an equivalent Hansel event should be fired
 
 @return A dictionary containing the analytics data.
 
 */

+ (NSDictionary * _Nonnull)handleEventWithName:(NSString * _Nonnull)eventName
                                        vendor:(NSString * _Nonnull)vendor
                                 andProperties:(NSDictionary * _Nullable)properties
                                    shouldFire:(BOOL)shouldFireEvent;

/*
 @abstract
 Handles the event and gets the Hansel Data for the event.
 
 @discussion
 Call this method to log the event and get the Hansel Data
 for the given event. You may append the data returned by
 this method to the another properties that you intend to
 send to your analytics vendor.
 
 @param eventName   Event to be tracked
 @param vendor      The analytics provider that you use
 @param properties  Event properties
 @param shouldFire  Whether an equivalent Hansel event should be fired
 @param completionBlock  Will provide the data back to you.
 
 @return A dictionary containing the analytics data.
 
 */

+ (void)logEventInBackground:(NSString * _Nonnull)eventName
                   andVendor:(NSString * _Nullable)vendor
              withProperties:(NSDictionary * _Nullable)properties
             completionBlock:(completionBlock)block;

@end

