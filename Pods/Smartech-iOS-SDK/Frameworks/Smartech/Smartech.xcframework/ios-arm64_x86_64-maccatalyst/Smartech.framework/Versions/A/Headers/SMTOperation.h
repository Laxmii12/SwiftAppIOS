//
//  SMTOperation.h
//  Smartech
//
//  Created by Netcore Solutions on 28/01/19.
//  Copyright © 2019 Netcore Solutions. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

/**
 @brief This class subclass NSOperation and overrides all its method.
 */
@interface SMTOperation : NSOperation

/**
 @brief Finishes the execution of the operation.
 
 @note - This shouldn’t be called externally as this is used internally by subclasses. To cancel an operation use cancel instead.
 */
- (void)finish;

@end

NS_ASSUME_NONNULL_END
