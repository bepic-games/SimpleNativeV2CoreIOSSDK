//
//  SimpleSDKUtils.m
//  SimpleSDKCore
//
//  Created by qus on 2021/2/4.
//
#ifndef SimpleSDKUtils_h
#define SimpleSDKUtils_h
#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface SimpleSDKUtils : NSObject

#pragma - mark info

+ (nullable NSString *)getMainInfoStringForKey:(NSString *)key;

+ (id)getMainInfoValueForKey:(NSString *)key;

+ (nullable NSString *)getBundleInfoStringForKey:(NSString *)key bundleCalss:(Class)clazz;

+ (nullable NSDictionary *)getMainInfo;

+ (nullable NSString *)getBundleVersion:(Class)clazz;

+ (nullable NSString *)appBundleID;

+ (nullable NSString *)appBundleShortVersion;

+ (int)appBundleVersionCode;

+ (nullable NSString *)appBuildVersion;

+ (nullable NSString *)keyChainId;

+ (void) saveInKeyChain:(NSString *) service key:(NSString *) key value:(NSString *)value;

+ (NSString *) getFromKeyChain:(NSString *) service key:(NSString *) key;

+ (nullable NSArray *) listFromKeyChain:(NSString *)service;

+ (void) removeFromKeyChain:(NSString *)service key:(NSString *) key;

+ (nullable NSString *)idfv;

+ (NSString *)idfa;

+ (NSString *)getSystemVersion;

+ (NSString *)getDeviceName;

+ (NSString *)getDeviceVersionWithRaw;

+ (NSString *)getNetworkStatus;

+ (int)isVpn;

+ (int)isProxy;


#pragma - mark json

+ (nullable NSData *)readJSONFileName:(NSString *)fileName subPath:(nullable NSString *)subPath;

+ (nullable NSDictionary *)dictFromJsonStr:(nonnull NSString *)JSON;

+ (nullable NSDictionary *)dictFromJsonData:(nonnull NSData *)JSON;

+ (nullable NSString *)dictToJson:(nonnull NSDictionary *)dictionary;

#pragma - mark dict
+ (NSString *) getStringFromDictionaryOrDefault:(NSDictionary *)dict field:(NSString *)fieldName default:(NSString *) defaultValue;

+ (bool) getBoolFromDictionaryOrDefault:(NSDictionary *)dict field:(NSString *)fieldName default:(bool) defaultValue;

+ (int) getIntFromDictionaryOrDefault:(NSDictionary *)dict field:(NSString *)fieldName default:(int) defaultValue;

#pragma - mark convert

+ (NSString *) boolToNS:(bool) b;

+ (NSString *) intToNS:(int) i;

+ (NSString *) integerToNS:(NSInteger) i;

+ (NSString *) doubleToNS:(double) d;

#pragma - mark base

+ (int) getTimestamp;

+ (bool) notNull:(NSString *)v;

+ (NSString *) nsDateToGmtString:(NSDate *) d;

@end

NS_ASSUME_NONNULL_END

#endif
