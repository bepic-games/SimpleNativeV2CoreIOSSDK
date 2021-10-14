//
//  SimpleNativeIOSSDK.h
//  SimpleNativeIOSSDK
//
//  Created by qus on 2021/4/25.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
#import <SimpleNativeBase/SimpleNativeBase.h>
NS_ASSUME_NONNULL_BEGIN


typedef void(^SimpleCallback)(bool isSuccess, NSString* msg);

@interface SimpleNativeIOSSDK<AppsFlyerLibDelegate> : NSObject

+ (instancetype)sharedInstance;

- (void)sdkInit:(SimpleCallback) cb;

- (void)sdkInitWithString:(NSString *) jsonStr callback:(SimpleCallback)cb;

- (StaticInfo *) getStaticInfo;

- (id<SimpleSDKAttributionProtocol>) getAttrInstance;

- (id<SimpleSDKAdProtocol>) getAdInstance;

- (id<SimpleSDKUPProtocol>) geUPInstance;

- (void)log:(NSString*)eventName withParams:(NSDictionary *)params;

- (void)logPaySuccess:(NSString *) store withTransactionID:(NSString *)transactionID
    withProductID:(NSString *)productID
    withPurchaseDate:(NSDate *) purchaseDate
    withPrice:(double)price
    withPriceString:(NSString *) priceString
    withCurrency:(NSString *) currency;

- (BOOL)application:(UIApplication *)app openURL:(NSURL *)url options:(NSDictionary<UIApplicationOpenURLOptionsKey, id> *)options;

- (void)scene:(UIScene *)scene openURLContexts:(NSSet<UIOpenURLContext *> *)URLContexts;

@end

NS_ASSUME_NONNULL_END

//! Project version number for SimpleSDKCore.
FOUNDATION_EXPORT double SimpleNativeIOSSDKVersionNumber;

//! Project version string for SimpleSDKCore.
FOUNDATION_EXPORT const unsigned char SimpleNativeIOSSDKVersionString[];

// In this header, you should import all the public headers of your framework using statements like #import <SimpleSDKCore/PublicHeader.h>


