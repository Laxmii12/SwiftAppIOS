//
//  HanselUser.h
//  Hansel
//
//  Created by Akash Nagar on 8/3/18.
//  Copyright © 2018 Hansel Software Private Limited. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface HanselUser : NSObject

/*!
 @method
 
 @abstract
 Adds the given string type user attribute with Hansel SDK.
 
 @param key       Attribute name
 @param attribute String value
 
 */

- (void)putStringAttribute:(NSString * _Nonnull)attribute forKey:(NSString * _Nonnull)key NS_SWIFT_NAME(putAttribute(_:forKey:));

/*!
 @method
 
 @abstract
 Adds the given double type user attribute with Hansel SDK.
 
 @param key       Attribute name
 @param attribute Double value
 
 */

- (void)putDoubleAttribute:(double)attribute forKey:(NSString * _Nonnull)key NS_SWIFT_NAME(putAttribute(_:forKey:));

/*!
 @method
 
 @abstract
 Adds the given boolean type user attribute with Hansel SDK.
 
 @param key       Attribute name
 @param attribute Boolean value
 
 */

- (void)putBoolAttribute:(BOOL)attribute forKey:(NSString * _Nonnull)key NS_SWIFT_NAME(putAttribute(_:forKey:));

/*!
 @method
 
 @abstract
 Sets the user ID with Hansel SDK.
 
 @param userId UserId
 
 */

- (void)setUserId:(NSString * _Nonnull)userId;

/*!
 @method
 
 @abstract
 Removes the user ID and all user attributes set with Hansel SDK. Use this method for clearing the data for the user when a new user logs in.
 
 */

- (void)clear;

@end
