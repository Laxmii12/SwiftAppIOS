//
//  SMTAppInboxFilter.h
//  SmartechAppInbox
//
//  Created by Netcore Solutions on 25/11/20.
//  Copyright © 2020 Netcore Solutions. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface SMTAppInboxFilter : NSObject

@property(nonatomic,assign) NSInteger limit;
@property(nonatomic,copy) NSString *direction;
@property(nonatomic,copy) NSString *timestamp;

- (NSDictionary *)getFilterDictionary;

@end

NS_ASSUME_NONNULL_END
