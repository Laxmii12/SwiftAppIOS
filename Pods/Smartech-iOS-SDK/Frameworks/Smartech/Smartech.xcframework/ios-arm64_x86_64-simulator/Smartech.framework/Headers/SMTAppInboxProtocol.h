//
//  SMTAppInboxProtocol.h
//  Smartech
//
//  Created by Netcore Solutions on 25/01/21.
//  Copyright © 2021 Netcore Solutions. All rights reserved.
//

#ifndef SMTAppInboxProtocol_h
#define SMTAppInboxProtocol_h

#import "SMTAppInboxSettings.h"
#import "SMTSmartechProtocol.h"

@protocol SMTAppInboxProtocol

/**
 @brief This method is for passing tracked events from AppInbox SDK to Smartech SDK.
 
 @param appInboxSettings Name of the event.
 */
- (void)initAppInboxSDKWithSettings:(SMTAppInboxSettings *)appInboxSettings withDelegate:(id <SMTSmartechProtocol>)delegate;

/**
 @brief This method is for informing App inbox SDK when it has been disabled from Smartech Panel.
 
 */
- (void)appInboxHasBeenDisabled;

@end

#endif /* SMTAppInboxProtocol_h */
