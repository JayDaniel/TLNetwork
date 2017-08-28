//
//  TLAsiUrlCache.m
//  TLNetworkDemo
//
//  Created by Ted Liu on 2017/3/2.
//  Copyright © 2017年 Ted Liu. All rights reserved.
//

#import "TLAsiUrlCache.h"

@interface TLURLCache : NSURLCache

@end

//static NSString       *TLURLCacheExpirationKey = @"TLURLCacheExpiration";
//
//static NSTimeInterval TLURLCacheExpirationInterval = 7 * 24 * 60 * 60;

@interface TLURLCache()

@end

@implementation TLURLCache
//
//+ (instancetype)standardURLCache {
//    static TLURLCache *_standardURLCache = nil;
//    
//    static dispatch_once_t onceToken;
//    
//    dispatch_once(&onceToken, ^{
//        _standardURLCache = [[TLURLCache alloc]
//                             initWithMemoryCapacity:MAX_CACHE_SIZE
//                             diskCapacity:5 * MAX_CACHE_SIZE
//                             diskPath:nil];
//    });
//    return _standardURLCache;
//}
//
//- (id)cachedResponseForRequest:(NSURLRequest *)request {
//    NSCachedURLResponse *cachedResponse = [super cachedResponseForRequest:request];
//    
//    if (cachedResponse) {
//        NSDate *cacheDate = cachedResponse.userInfo[TLURLCacheExpirationKey];
//        
//        NSDate *cacheExpirationDate = [cacheDate dateByAddingTimeInterval:TLURLCacheExpirationInterval];
//        
//        if ([cacheExpirationDate compare:[NSDate date]] == NSOrderedAscending) {
//            [self removeCachedResponseForRequest:request];
//            return nil;
//        }
//    }
//    
//    id responseObj = [NSJSONSerialization JSONObjectWithData:cachedResponse.data options:NSJSONReadingAllowFragments error:nil];
//    
//    return responseObj;
//}
//
//- (void)storeCachedResponse:(id)response
//               responseObjc:(id)responseObjc
//                 forRequest:(NSURLRequest *)request {
//    NSData *data = [NSJSONSerialization dataWithJSONObject:responseObjc options:NSJSONWritingPrettyPrinted error:nil];
//    
//    NSMutableDictionary *userInfo = [[NSMutableDictionary alloc] init];
//    
//    userInfo[TLURLCacheExpirationKey] = [NSDate date];
//    
//    NSCachedURLResponse *modifiedCachedResponse = [[NSCachedURLResponse alloc] initWithResponse:response data:data userInfo:userInfo storagePolicy:0];
//    
//    [super storeCachedResponse:modifiedCachedResponse forRequest:request];
//}

@end
