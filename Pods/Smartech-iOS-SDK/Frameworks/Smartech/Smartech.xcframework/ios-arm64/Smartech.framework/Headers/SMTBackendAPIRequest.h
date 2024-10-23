//
//  SMTBackendAPIRequest.h
//  Smartech
//
//  Created by Netcore Solutions on 30/01/19.
//  Copyright © 2019 Netcore Solutions. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "SMTHTTPMethod.h"
#import "SMTBackendConfiguration.h"

NS_ASSUME_NONNULL_BEGIN

/**
  @brief This defines rule for any Smartech backend request. This is the Request protocol you may implement other classes can conform.
 
  @discussion This protocol is responsible for defining a request along with the common parameters like HTTP Method, Headers, Body and obviously the Path of the request itself
 */
@protocol SMTBackendAPIRequest <NSObject>

/**
 @brief The baseURLType of the request.
 
 @return baseURLType The request baseURLType.
 */
- (BackendBaseURLType)baseURLType;

/**
 @brief The path of the request.
 
 @return NSString The request endpoint.
 */
- (NSString *)endpoint;

/**
 @brief The parameters to be associated with the request.
 
 @return Parameters The request parameters.
 */
- (URLParameters *)URLParameters;

/**
 @brief The parameters to be associated with the request.
 
 @return Parameters The request parameters.
 */
- (BodyParameters *)bodyParameters;

/**
 @brief The headers to append (ie. Cookies, Authorization or whatever).
 
 @return HTTPHeaders The request headers.
 */
- (HTTPHeaders *)headers;

/**
 @brief The HTTP Method used (ie. POST, PUT or whatever).
 
 @return Parameters The request HTTPMethod.
 */
- (SMTHTTPMethod)method;

@end

NS_ASSUME_NONNULL_END
