//
//  TLAsiNetworkHandler.h
//  TLNetworkDemo
//
//  Created by Ted Liu on 2017/3/3.
//  Copyright © 2017年 Ted Liu. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "TLAsiNetworkDefine.h"
#import "TLUploadParam.h"

@interface TLAsiNetworkManager : NSObject
/**
 初始化单例
 */
+ (instancetype) sharedManager;
/**
 接口请求超时时间
 */
@property (nonatomic,assign) NSTimeInterval requestTimeout;
/**
 是否开启HTTPS
 */
@property (nonatomic,assign) BOOL isVerifyHttps;
/**
 是否允许无效证书（也就是自建的证书），默认为NO
 如果是需要验证自建证书，需要设置为YES
 */
@property (nonatomic,assign) BOOL isAllowInvalid;
/**
 假如证书的域名与你请求的域名不一致，需把该项设置为NO，默认为NO；
 如设成NO的话，即服务器使用其他可信任机构颁发的证书，也可以建立连接，这个非常危险，建议打开。
 置为NO，主要用于这种情况：
 客户端请求的是子域名，而证书上的是另外一个域名。
 因为SSL证书上的域名是独立的，假如证书上注册的域名是www.google.com，那么mail.google.com是无法验证通过的；
 当然，有钱可以注册通配符的域名*.google.com，但这个还是比较贵的。
 如置为NO，建议自己添加对应域名的校验逻辑。
 */
@property (nonatomic,assign) BOOL isDomainName;
/**
 如果开启https后，如果是自建证书，则传入证书在工程中的地址，如果是信任证书，则不需要传入
 */
@property (nonatomic,copy  ) NSString *cerPath;
/**
 默认baseUrl
 */
@property (nonatomic,copy  ) NSString *normalUrl;
/**
 设置token
 */
@property (nonatomic,copy  ) NSString *baseToken;

@end

@interface TLAsiNetworkHandler : NSObject
/**
 *  配置请求头
 *
 *  @param httpHeaders 请求头参数
 */
+ (void)configHttpHeaders:(NSDictionary *)httpHeaders;

/**
 *  取消所有请求
 */
+ (void)cancelAllRequest;

/**
 *  根据url取消请求
 *
 *  @param url 请求url
 */
+ (void)cancelRequestWithURL:(NSString *)url;

/**
 *	获取缓存总大小
 *
 *	@return 缓存大小
 */
+ (unsigned long long)totalCacheSize;

/**
 *	清除缓存
 */
+ (void)clearCaches;

/**
 *  更新请求或者返回数据的解析方式(0为HTTP模式，1为JSON模式)
 *
 *  @param requestType  请求数据解析方式
 *  @param responseType 返回数据解析方式
 */
+ (void)updateRequestSerializerType:(TLSerializerType)requestType
                 responseSerializer:(TLSerializerType)responseType;

#pragma mark --- 统一请求接口
/**
 *  统一请求接口
 *
 *  @param url              请求路径
 *  @param params           拼接参数
 *  @param httpMethod       请求方式（0为POST,1为GET）
 *  @param showHUD          是否显示HUD
 *  @param successBlock     成功回调block
 *  @param failBlock        失败回调block
 *
 *  @return 返回的对象中可取消请求
 */
+ (TLURLSessionTask *)requestWithUrl:(NSString *)url
                              params:(NSDictionary *)params
                             showHUD:(BOOL)showHUD
                         httpMedthod:(TLRequestType)httpMethod
                        successBlock:(TLResponseSuccessBlock)successBlock
                           failBlock:(TLResponseFailBlock)failBlock;
#pragma mark --- 多图片上传接口
/**
 *  多图片上传接口
 *
 *	@param imageArray       图片对象集合
 *  @param url              请求路径
 *	@param params           拼接参数
 *	@param progressBlock    上传进度
 *	@param successBlock     成功回调
 *	@param failBlock		失败回调
 *
 *  @return 返回的对象中可取消请求
 */
+ (TLURLSessionTask *)uploadWithImageArray:(NSMutableArray *)imageArray
                                       url:(NSString *)url
                                    params:(NSDictionary *)params
                                   showHUD:(BOOL)showHUD
                             progressBlock:(TLNetWorkingProgress)progressBlock
                              successBlock:(TLResponseSuccessBlock)successBlock
                                 failBlock:(TLResponseFailBlock)failBlock;

/**
 *  文件上传接口
 *
 *  @param url              上传文件接口地址
 *  @param uploadingFile    上传文件路径
 *  @param progressBlock    上传进度
 *	@param successBlock     成功回调
 *	@param failBlock		失败回调
 *
 *  @return 返回的对象中可取消请求
 */
+ (TLURLSessionTask *)uploadFileWithUrl:(NSString *)url
                          uploadingFile:(NSString *)uploadingFile
                                showHUD:(BOOL)showHUD
                          progressBlock:(TLNetWorkingProgress)progressBlock
                           successBlock:(TLResponseSuccessBlock)successBlock
                              failBlock:(TLResponseFailBlock)failBlock;

@end
