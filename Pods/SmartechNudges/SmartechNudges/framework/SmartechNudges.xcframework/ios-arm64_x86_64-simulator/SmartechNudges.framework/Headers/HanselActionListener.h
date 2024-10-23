//
//  HanselActionListener.h
//  Hansel
//
//  Created by Rajeev Rajeshuni on 23/07/19.
//  Copyright © 2019 Hansel Software Private Limited. All rights reserved.
//

#import <Foundation/Foundation.h>

/*!
 
 @abstract
 Protocol to be implemented by the listener for receiving actions from Hansel SDK.
 
 @discussion
 Implement this protocol and register the reference with Hansel SDK via registerHanselActionListener method of the Hansel class. Registering this listener will allow to receive actions configured on Hansel Dashboard.
 
 */

@protocol HanselActionListener

@required

/*!
 @method
 
 @abstract
 This method will be called everytime an action has been performed.
 
 @param action  Name of the action performed
 
 */

- (void)onActionPerformed:(NSString *)action NS_SWIFT_NAME(onActionPerformed(action:));

@end
