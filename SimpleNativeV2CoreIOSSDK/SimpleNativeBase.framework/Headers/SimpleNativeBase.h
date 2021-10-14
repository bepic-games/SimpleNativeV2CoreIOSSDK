//
//  SimpleNativeBase.h
//  SimpleNativeBase
//
//  Created by qus on 2021/5/11.
//
#ifndef SimpleNativeBase_h
#define SimpleNativeBase_h
#import <Foundation/Foundation.h>
#import "SimpleSDKUtils.h"

NS_ASSUME_NONNULL_BEGIN

#pragma mark - Base

@interface StaticInfo : NSObject

@property (nonatomic,strong) NSString * gameName;
@property (nonatomic,strong) NSString * pn;
@property (nonatomic,strong) NSString * appVersion;
@property (nonatomic,strong) NSString * deviceid;
@property (nonatomic,strong) NSString * platform;
@property (nonatomic,strong) NSString * idfa;
@property (nonatomic,strong) NSString * uid;
@property (nonatomic,strong) NSString * sessionId;
@property (nonatomic,strong) NSString * idfv;
@property (nonatomic,strong) NSString * android_id;

@property (nonatomic,strong) NSString * band;
@property (nonatomic,strong) NSString * model;
@property (nonatomic,strong) NSString * deviceName;
@property (nonatomic,strong) NSString * systemVersion;
@property (nonatomic,strong) NSString * network;

- (instancetype)initWithGameName:(NSString*)gameName;

@end

@interface SimpleAttrInfo : NSObject

@property (nonatomic,strong) NSString * network;
@property (nonatomic,strong) NSString * campaign;
@property (nonatomic,strong) NSString * adgroup;
@property (nonatomic,strong) NSString * creative;
@property (nonatomic,strong) NSString * attrid;

@end

@interface SimpleSDKConfig : NSObject

@property (nonatomic,strong) NSString * gameName;
@property (nonatomic) bool chn;
@property (nonatomic) bool debug;
@property (nonatomic,strong) NSString * adjustKey;
@property (nonatomic,strong) NSString * appsflyerKey;

@property (nonatomic,strong) NSString * appleId;
@property (nonatomic,strong) NSString * toponAppid;
@property (nonatomic,strong) NSString * toponKey;
@property (nonatomic,strong) NSString * toponReward;
@property (nonatomic,strong) NSString * toponInterstitial;
@property (nonatomic,strong) NSString * toponBanner;
@property (nonatomic) int bannerHeight;
@property (nonatomic) int bannerWidth;

@property (nonatomic,strong) NSString * ryKey;
@property (nonatomic,strong) NSString * ryChannel;
@property (nonatomic,strong) NSString * adtag;

- (instancetype)initWithDict:(NSDictionary*)dict;

@end


@protocol SimpleAttrCallback
- (void)getAttr:(SimpleAttrInfo*)info;
@end

@protocol SimpleSDKAttributionProtocol <NSObject>
- (NSString *) getAttributionType;
- (NSString *) getAttributionVersion;
- (void) initWithConfig:(SimpleSDKConfig *)simpleConfig;
- (NSString *) getAttributionId;
- (void) setSimpleAttrCallback:(id<SimpleAttrCallback>)cb;
- (SimpleAttrInfo*) getAttrInfo;
@end

#pragma mark - Ad

@interface SimpleAdCallbackInfo:NSObject

@property (nonatomic,strong) NSString * network;
@property (nonatomic,strong) NSString * placementId;
@property (nonatomic,strong) NSString * adsourceId;

@end



@protocol SimpleSDKRewardedVideoListener <NSObject>

- (void) onRewardedVideoAdPlayStart:(NSString *) unitId callback:(SimpleAdCallbackInfo *) callbackInfo;
- (void) onRewardedVideoAdPlayFail:(NSString *) unitId code:(NSString *) code  message:(NSString *) message;
- (void) onRewardedVideoAdPlayClosed:(NSString *) unitId callback:(SimpleAdCallbackInfo *) callbackInfo;
- (void) onRewardedVideoAdPlayClicked:(NSString *) unitId callback:(SimpleAdCallbackInfo *) callbackInfo;
- (void) onReward:(NSString *) unitId callback:(SimpleAdCallbackInfo *) callbackInfo;

@end

@protocol SimpleSDKInterstitialAdListener <NSObject>

- (void) onInterstitialAdShow:(NSString *) unitId callback:(SimpleAdCallbackInfo *) callbackInfo;
- (void) onInterstitialAdClose:(NSString *) unitId callback:(SimpleAdCallbackInfo *) callbackInfo;
- (void) onInterstitialAdClick:(NSString *) unitId callback:(SimpleAdCallbackInfo *) callbackInfo;

@end

@protocol SimpleSDKBannerAdListener <NSObject>

- (void) onAdImpress:(NSString *) unitId callback:(SimpleAdCallbackInfo *) callbackInfo;
- (void) onAdClick:(NSString *) unitId callback:(SimpleAdCallbackInfo *) callbackInfo;

@end

typedef void(^SimpleAdInitCallback)(void);

@protocol SimpleSDKAdProtocol <NSObject>

@property (weak, nonatomic) id<SimpleSDKRewardedVideoListener> simpleSDKRewardedVideoListener;
@property (weak, nonatomic) id<SimpleSDKInterstitialAdListener> simpleSDKInterstitialAdListener;
@property (weak, nonatomic) id<SimpleSDKBannerAdListener> simpleSDKBannerAdListener;

- (NSString *) getMediationType;
- (NSString *) getMediationVersion;
- (void) initWithConfig:(SimpleSDKConfig *)simpleConfig callback:SimpleAdInitCallback;
- (bool) hasReward;
- (void) showReward:(NSString *) adEntry;
- (bool) hasInterstitial;
- (void) showInterstitial:(NSString *) adEntry;
- (void) showOrReShowBanner:(int) pos;
- (void) setBannerRect:(float) width height:(float)height x:(float)x y:(float)y;
- (void) setBannerBackGround:(int) color;
- (void) hideBanner;
- (void) removeBanner;
- (NSDictionary *) getLoadingStatusSummary;
@end

#pragma mark - UserPayment

typedef NS_ENUM(NSUInteger, LOGIN_TYPE) {
    DEVICE,
    FACEBOOK,
    GAME_CENTER
};

@interface State : NSObject
@property (nonatomic) int code;
@property (nonatomic,strong) NSString * msg;
+(State *) initWith:(int ) code msg:(NSString * )msg;
-(State *) withMsg:(NSString *) msg;
-(NSString *) toString;
@end

@interface AutoLoginResult:NSObject
@property (nonatomic,strong) NSString * gameId;
@property (nonatomic) long long gameAccountId;
@property (nonatomic,strong) NSString * loginType;
@property (nonatomic) bool isNew;
@end

@interface CheckLoginResult : NSObject
@property (nonatomic,strong) NSString * gameId;
@property (nonatomic) long long gameAccountId;
@end

@interface LoginResult : NSObject
@property (nonatomic) long long gameAccountId;
@property (nonatomic,strong) NSString * loginType;
@property (nonatomic,strong) NSString * sessionToken;
@property (nonatomic) bool isNew;
@end

@interface LoginInfo :NSObject
@property (nonatomic,strong) NSString *  platform;
@property (nonatomic) bool hasLinked;
@property (nonatomic,strong) NSString *  uniqeId;
@property (nonatomic,strong) NSString *  iconUrl;
@property (nonatomic,strong) NSString *  nickName;
@end

@interface UserInfoResult : NSObject
@property (nonatomic,strong) NSString * gameId;
@property (nonatomic) long long gameAccountId;
@property (nonatomic,strong) NSMutableArray<LoginInfo *> * loginInfo;

- (NSString *) simpleList;
@end

@interface Item : NSObject
@property (nonatomic,strong) NSString * itemId;
@property (nonatomic,strong) NSString * itemType;
@property (nonatomic) long long price;
@property (nonatomic,strong) NSString * currency;
@property (nonatomic,strong) NSString * formattedPrice;
@property (nonatomic,strong) NSDictionary * methodItemMap;
@end

@interface ShopItemResult : NSObject
@property (nonatomic,strong) NSMutableArray<Item *> * items;
@end

@interface StartPaymentResult : NSObject
@property (nonatomic) long long gameOrderId;
@end

@interface UnconsumeItem : NSObject
@property (nonatomic) long long gameOrderId;
@property (nonatomic,strong) NSString * item;
@property (nonatomic) long long createTime;
@property (nonatomic) long long purchaseTime;
@property (nonatomic) int status;
@end

@interface PurchaseItems : NSObject
@property (nonatomic,strong) NSMutableArray<UnconsumeItem *> * unconsumeItems;
@end

@protocol IPurchaseItemsListener <NSObject>

- (void) getPurchaseItems:(PurchaseItems *) purchaseItems;

@end


//callback
typedef void(^CallbackFail)(State * state);
typedef void(^AutoLoginSuccess)(AutoLoginResult * result);
typedef void(^CheckLoginSuccess)(CheckLoginResult * result);
typedef void(^LoginSuccess)(LoginResult * result);
typedef void(^UserInfoSuccess)(UserInfoResult * result);
typedef void(^ShopItemsSuccess)(ShopItemResult * result);
typedef void(^StartPaymentSuccess)(StartPaymentResult * result);

@protocol SimpleSDKUPProtocol <NSObject>

- (void) init:(StaticInfo *)staticInfo  withConfig:(SimpleSDKConfig *) config;
- (long long) getGameAccountId;
- (void) logout;
- (void) autoLoginAsync:(bool) needGameCenter success:(AutoLoginSuccess) success fail:(CallbackFail) fail;
- (void) checkLoginAsync:(CheckLoginSuccess) success fail:(CallbackFail) fail;
- (void) loginWithTypeAsync:(LOGIN_TYPE)loginType success:(LoginSuccess) success fail:(CallbackFail) fail;
- (void) getUserInfoAsync:(UserInfoSuccess)success fail:(CallbackFail) fail;
- (void) bindWithTypeAsync:(LOGIN_TYPE)loginType success:(UserInfoSuccess)success fail:(CallbackFail) fail;
- (void) unbindWithTypeAsync:(LOGIN_TYPE)loginType success:(UserInfoSuccess)success fail:(CallbackFail) fail;
- (ShopItemResult *) getShopItems;
- (void) getShopItemsAsync:(ShopItemsSuccess) success fail:(CallbackFail) fail;
- (void) startPayment:(NSString *) itemId  cpOrderId:(NSString *) cpOrderId success:(StartPaymentSuccess)success fail:(CallbackFail) fail;
- (void) setPurchaseItemsListener:(id<IPurchaseItemsListener>) listener;
- (void) consumeItem:(long long) gameOrderId;
- (void) printDatabase;
@end



@interface SimpleNativeSDKEvent : NSObject

+ (void) logAdLoad:(NSString *) mediationType adtype:(NSString *) adtype unitId:(NSString *)unitId;

+ (void) logAdLoadFail:(NSString *) mediationType adtype:(NSString *) adtype unitId:(NSString *)unitId code:(NSString *)code  message:(NSString *) message;
+ (void) logAdShow:(NSString *) mediationType adtype:(NSString *) adtype unitId:(NSString *)unitId callback:(SimpleAdCallbackInfo *) info;
+ (void) logAdClick:(NSString *) mediationType adtype:(NSString *) adtype unitId:(NSString *)unitId callback:(SimpleAdCallbackInfo *) info;

@end


@protocol SimpleSDKUploader <NSObject>

- (void)log:(NSString*)eventName withParams:(NSDictionary *)params;

@end

@interface SimpleSDKUploadService : NSObject

+ (void) setUploader:(id<SimpleSDKUploader>) uploader;
+ (void) log:(NSString*)eventName withParams:(NSDictionary *)params;

@end

NS_ASSUME_NONNULL_END

//! Project version number for SimpleNativeBase.
FOUNDATION_EXPORT double SimpleNativeBaseVersionNumber;

//! Project version string for SimpleNativeBase.
FOUNDATION_EXPORT const unsigned char SimpleNativeBaseVersionString[];

// In this header, you should import all the public headers of your framework using statements like #import <SimpleNativeBase/PublicHeader.h>

#endif