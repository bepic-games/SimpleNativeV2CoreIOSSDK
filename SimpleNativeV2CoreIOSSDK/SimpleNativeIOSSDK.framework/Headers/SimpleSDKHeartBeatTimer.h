//
//  SimpleSDKHeartBeatTimer.h
//  SimpleSDKDemo
//
//  Created by qus on 2021/2/7.
//

#ifndef SimpleSDKHeartBeatTimer_h
#define SimpleSDKHeartBeatTimer_h


NS_ASSUME_NONNULL_BEGIN

typedef void(^NotifyBlock)(int passTime);

@interface SimpleSDKLogHeartBeatTimer : NSObject

- (instancetype)initWithTimerIntervals:(NSArray<NSNumber *> *)Intervals notifyBlock:(nullable NotifyBlock)notifyBlock;

- (void)stopTimer;
@end

NS_ASSUME_NONNULL_END

#endif /* SimpleSDKHeartBeatTimer_h */
