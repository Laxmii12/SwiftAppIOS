//
//  HanselDeepLinkListener.h
//  Hansel
//
//  Created by Hansel Software Private Limited on 22/11/22.
//  Copyright © 2022 Hansel Software Private Limited. All rights reserved.
//

#import <Foundation/Foundation.h>

/*!
 
 @abstract
 Protocol to be implemented by the listener for receiving deep link url from Hansel SDK.
 
 @discussion
 Implement this protocol and register the reference with Hansel SDK via registerHanselDeeplinkListener method of the Hansel class. Registering this listener will allow to receive  Launch URL of actions configured on Hansel Dashboard.
 
 */

@protocol HanselDeepLinkListener

@required

/*!
 @method
 
 @abstract
 This method will be called everytime an action has been performed.
 
 @param URLString Receive  Launch URL of actions configured on Hansel Dashboard.
 
 */

- (void)onLaunchURL:(NSString *)URLString NS_SWIFT_NAME(onLaunchURL(URLString:));

@end
