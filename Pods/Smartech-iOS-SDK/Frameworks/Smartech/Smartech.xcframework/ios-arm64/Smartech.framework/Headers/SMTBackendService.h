//
//  SMTBackendService.h
//  Smartech
//
//  Created by Netcore Solutions on 29/01/19.
//  Copyright © 2019 Netcore Solutions. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "SMTBackendAPIRequest.h"
#import "SMTBackendConfiguration.h"

NS_ASSUME_NONNULL_BEGIN

/**
 @brief This class helps in executing any request.
 
 @discussion It uses NetworkService internally to make request based on NSURLSession.
 */
@interface SMTBackendService : NSObject

/**
 @param config the SMTBackendConfiguration instance.
 
 @return SMTBackendService instance.
 */
- (id)initWithConfig:(SMTBackendConfiguration *)config;

/**
 @brief This method is used to execute any backend request.
 */
- (void)makeDataRequest:(id <SMTBackendAPIRequest>)request
        success:(void (^)(id _Nullable serializedJSONObject)) success
        failure:(void (^)(NSError * _Nullable error)) failure;

- (void)makeDownloadRequestFor:(NSURL *)downloadURL
                       success:(void (^)(NSURL * _Nullable location)) success
                       failure:(void (^)(NSError * _Nullable error)) failure;
/**
 @brief This cancels the request.
 */
- (void)cancel;

@end

NS_ASSUME_NONNULL_END
