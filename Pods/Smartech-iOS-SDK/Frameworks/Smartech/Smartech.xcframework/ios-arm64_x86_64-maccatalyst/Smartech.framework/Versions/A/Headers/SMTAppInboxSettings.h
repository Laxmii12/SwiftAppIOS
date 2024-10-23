//
//  SMTAppInboxSettings.h
//  Smartech
//
//  Created by Netcore Solutions on 20/11/20.
//  Copyright © 2020 Netcore Solutions. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface SMTAppInboxSettings : NSObject <NSCoding>

@property (nonatomic, assign) BOOL isAppInboxEnabled;
@property (nonatomic, assign) NSInteger messageCachePeriod;
@property (nonatomic, assign) NSInteger mediaCachingSize;

/**
 @brief This method gives back the dictionary object of self object.
 
 @return NSMutableDictionary The key value pair for self parameters.
 */
- (NSMutableDictionary *)toNSDictionary;

@end

NS_ASSUME_NONNULL_END
