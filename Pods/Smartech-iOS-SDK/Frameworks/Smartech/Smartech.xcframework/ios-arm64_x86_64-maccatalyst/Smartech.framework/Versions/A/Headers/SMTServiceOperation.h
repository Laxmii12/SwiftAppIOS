//
//  SMTServiceOperation.h
//  Smartech
//
//  Created by Netcore Solutions on 29/01/19.
//  Copyright © 2019 Netcore Solutions. All rights reserved.
//

#import "SMTOperation.h"
#import "SMTBackendService.h"

NS_ASSUME_NONNULL_BEGIN

/**
 @brief This class should be subclassed and object of the same should be added into the Operation queue.
 
 @discussion Because we want to use the BackendService for executing network calls, we subclassed NetworkOperation and created ServiceOperation.
 */
@interface SMTServiceOperation : SMTOperation

/**
 @brief It internally uses SMTBackendService to execute the request.
 
 */
@property (nonatomic, readonly, strong) SMTBackendService *service;

@end

NS_ASSUME_NONNULL_END
