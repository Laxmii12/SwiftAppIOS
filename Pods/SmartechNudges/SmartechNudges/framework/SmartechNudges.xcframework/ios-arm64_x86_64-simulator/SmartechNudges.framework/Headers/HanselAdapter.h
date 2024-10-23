//
//  HanselSmartechAdapter.h
//  Pods
//
//  Created by Parminder Singh on 12/9/20.
//

#ifndef HanselAdapter_h
#define HanselAdapter_h

#import <Smartech/HanselProtocol.h>

@interface HanselAdapter : NSObject <HanselProtocol>

/**
 @brief This method is for intialiazing the Hansel SDK.
 
 @param appId The Hansel SDK App ID.
 @param appKey The Hansel SDK App Key.
 @param smartechProtocol The instance of Smartech Adapter implementing Smartech Protocol.
 @param guid The GUID for app.
 */

- (void)initWithAppId:(NSString *)appId
               appKey:(NSString *)appKey
     smartechProtocol:(id <SmartechProtocol>)smartechProtocol
              andGuid:(NSString *)guid;

@end

#endif
