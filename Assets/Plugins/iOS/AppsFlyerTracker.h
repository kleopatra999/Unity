//
//  AppsFlyerTracker.h
//  AppsFlyerLib
//
//  AppsFlyer iOS SDK v2.5.3.7
//  22-Feb-2013
//  Copyright (c) 2013 AppsFlyer Ltd. All rights reserved.
//
//  Please read AppsFlyer's iOS SDK documentation before integrating this library in your app:
//  http://support.appsflyer.com/entries/25458906-iOS-SDK-Integration-Guide-v2-5-3-x-New-API-
//

#import <Foundation/Foundation.h>

/*
 * This delegate should be use if you want to use AppsFlyer conversion data. See AppsFlyer iOS
 * Tracking SDK documentation for more details http://support.appsflyer.com/entries/25458906-iOS-SDK-Integration-Guide-v2-5-3-x-New-API-
 */
@protocol AppsFlyerTrackerDelegate <NSObject>

@optional
- (void) onConversionDataReceived:(NSDictionary*) installData;
- (void) onConversionDataRequestFailure:(NSError *)error;

@end

@interface AppsFlyerTracker : NSObject<AppsFlyerTrackerDelegate> {
    NSString* customerUserID;
    NSString* appsFlyerDevKey;
    NSString* appleAppID;
    NSString* currencyCode;
    BOOL deviceTrackingDisabled;
        
    BOOL isDebug;
    
    BOOL isHTTPS;
    
    BOOL disableAppleAdSupportTracking;
}

/* In case you use your own user ID in your app, you can set this property to that ID. */
@property (nonatomic,retain) NSString *customerUserID;

/* Use this property to set your AppsFlyer's dev key. */
@property (nonatomic,retain) NSString *appsFlyerDevKey;

/* Use this property to set your app's Apple ID (taken from the app's page on iTunes Connect) */
@property (nonatomic,retain) NSString *appleAppID;

/* 
 * In case of in app purchase events, you can set the currency code your user has purchased with.
 * The currency code is a 3 letter code according to ISO standards. Example: "USD"
 */
@property (nonatomic,retain) NSString *currencyCode;

/* AppsFlyer's SDK send the data to AppsFlyer's servers over HTTPS. You can set the isHTTPS property to NO in order to use regular HTTP. */
@property BOOL isHTTPS;

/* 
 * AppsFLyer SDK collect Apple's advertisingIdentifier if the AdSupport framework included in the SDK.
 * You can disable this behavior by setting the following property to YES.
 */
@property BOOL disableAppleAdSupportTracking;

/* 
 * Prints our messages to the log. This property should only be used in DEBUG mode. The default value 
 * is NO.
 */
@property BOOL isDebug;

/*
 * Opt-out tracking for specific user
 */
@property BOOL deviceTrackingDisabled;

+(AppsFlyerTracker*) sharedTracker;

/* Track application launch*/
- (void) trackAppLaunch;

/*
 * Use this method to track events in your app like purchases or user actions.
 * Example :
 *      [[AppsFlyer sharedTracker] trackEvent:@"hotel-booked" withValue:"200"];
 */
- (void) trackEvent:(NSString*)eventName withValue:(NSString*)value;

/* 
 * This method returns AppsFLyer's internal user ID (unique for your app) 
 */
- (NSString *) getAppsFlyerUID;

/* 
 * In case you want to use AppsFlyer tracking data in your app you can use the following method set a
 * delegate with callbakc buttons for the tracking data. See AppsFlyerTrackerDelegate above.
 */
- (void) loadConversionDataWithDelegate:(id<AppsFlyerTrackerDelegate>) delegate;

@end
