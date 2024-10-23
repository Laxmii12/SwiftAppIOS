//
//  SMTAppInboxCategoryModel.h
//  SmartechAppInbox
//
//  Created by Netcore Solutions on 23/11/20.
//  Copyright © 2020 Netcore Solutions. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface SMTAppInboxCategoryModel : NSObject

@property (nonatomic, copy) NSString *categoryName;
@property(nonatomic,assign)BOOL isSelected;

@end

NS_ASSUME_NONNULL_END
