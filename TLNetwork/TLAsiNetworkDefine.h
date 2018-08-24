//
//  TLAsiNetworkDefine.h
//  TLNetworkDemo
//
//  Created by Ted Liu on 2017/3/2.
//  Copyright © 2017年 Ted Liu. All rights reserved.
//  网络请求配置项

#ifndef TLAsiNetworkDefine_h
#define TLAsiNetworkDefine_h
// 默认网络错误信息文本
#define TL_ERROR_IMFORMATION @"网络出现错误，请检查网络连接"
// 网络错误Log打印
#define TL_ERROR [NSError errorWithDomain:@"com.chenchaobang.TLNetworking.ErrorDomain" code:-999 userInfo:@{ NSLocalizedDescriptionKey:TL_ERROR_IMFORMATION}]
// 缓存路径
#define DIRECTORYPATH [[NSHomeDirectory() stringByAppendingPathComponent:@"Documents/"] stringByAppendingString:@"/TLNetWorking/"];
// 最大缓存大小（目前接口暂未做缓存）
#define MAX_CACHE_SIZE (10 * 1024 * 1024)
/**
 *  网络状态
 */
typedef NS_ENUM(NSInteger, TLNetworkStatus) {
    /**
     *  未知网络
     */
    TLNetworkStatusUnknown             = 1 << 0,
    /**
     *  无法连接
     */
    TLNetworkStatusNotReachable        = 1 << 2,
    /**
     *  网络正常
     */
    TLNetworkStatusNormal              = 1 << 3
};
/**
 *  请求方式
 */
typedef NS_ENUM(NSInteger, TLRequestType) {
    /**
     *  GET方式来进行请求
     */
    TLAsiNetWorkGET     = 1 << 0,
    /**
     *  POST方式来进行请求
     */
    TLAsiNetWorkPOST    = 1 << 1,
    /**
     *  PATCH方式来进行请求
     */
    TLAsiNetWorkPATCH   = 1 << 2,
    /**
     *  DELETE方式来进行请求
     */
    TLAsiNetWorkDELETE  = 1 << 3,
    /**
     *  PUT方式来进行请求
     */
    TLAsiNetWorkPUT     = 1 << 4
};

/**
 *  数据串行方式
 */
typedef NS_ENUM(NSInteger, TLSerializerType) {
    /**
     *  HTTP方式来进行请求或响应
     */
    TLHTTPSerializer = 1 << 0,
    /**
     *  JSON方式来进行请求或响应
     */
    TLJSONSerializer = 1 << 1
};

/**
 *  请求任务
 */
typedef NSURLSessionTask TLURLSessionTask;
/**
 *  接口请求成功，且状态为0
 *
 *  @param responseObj 成功后返回的数据
 */
typedef void(^TLResponseSuccessBlock)(id responseObj);
/**
 *  接口请求成功，但状态不为0
 *
 *  @param responseObj 成功后返回的数据
 */
typedef void(^TLResponseOtherBlock)(id responseObj);
/**
 *  接口请求失败，如404，500错误
 *
 *  @param error 失败后返回的错误信息
 */
typedef void(^TLResponseFailBlock)(NSError *error);
/**
 *  进度
 *
 *  @param bytesRead   已下载或者上传进度的大小
 *  @param totalBytes  总下载或者上传进度的大小
 */
typedef void(^TLNetWorkingProgress)(int64_t bytesRead,
int64_t totalBytes);

#endif /* TLAsiNetworkDefine_h */
