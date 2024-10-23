//
//  SyncStateListener.h
//  Hansel
//
//  Created by Rajeev Rajeshuni on 12/03/19.
//  Copyright © 2019 Hansel Software Private Limited. All rights reserved.
//

#import <Foundation/Foundation.h>


/*!
 
 @abstract
 Protocol to be implemented by the listener for getting callbacks of sync state of Hansel SDK.
 
 @discussion
 You can get the sync state from the hansel sdk by registering a listener with us. Every time the updated values are synced to the SDK, this listener is triggered. You can use this to confirm that a sync has taken place, and run additional tasks you may have after every sync. Implement this protocol and register the listener using setHanselSyncStateListener method of Hansel class.
 */


@protocol HanselSyncStateListener
@required

/*!
 @method
 
 @abstract
 Receive sync state from Hansel SDK.
 
 @param state  True if the sync is successful and false if the sync failed.
 Hansel-umbrella.h>
 */

- (void)onHanselSynced:(BOOL)state NS_SWIFT_NAME(onHanselSynced(state:));

@end
