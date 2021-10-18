//
//  SimpleJsonMapper.h
//  SimpleNativeBase
//
//  Created by qus on 2021/10/18.
//

#ifndef SimpleJsonMapper_h
#define SimpleJsonMapper_h
#import <Foundation/Foundation.h>

@interface SimpleJsonMapper : NSObject

@property NSMutableSet * ignoreField;
@property NSMutableDictionary * mapCache;

+ (instancetype)sharedInstance;

+ (NSDictionary *)objectToDict:(NSObject *)object;

+ (id) dictToObject:(NSDictionary *)dictionary forClass:(Class)classType;

@end


#endif /* SimpleJsonMapper_h */
