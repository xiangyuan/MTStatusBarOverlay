//
//  MTStatusBar.h
//  MTHelper
//
//  Created by Matthias Tretter on 27.09.10.
//  Copyright 2010 @myell0w. All rights reserved.
//

// Credits go to: 
// -------------------------------
// http://stackoverflow.com/questions/2833724/adding-view-on-statusbar-in-iphone
// http://cocoabyss.com/2010/ios-custom-status-bar/
// @reederapp
// -------------------------------

#import <Foundation/Foundation.h>

// what happens when the user touches the status bar?
typedef enum MTStatusBarOverlayAnimation {
	// nothing happens
	MTStatusBarOverlayAnimationNone,
	// the status bar shrinks to the right side and only shows the activity indicator
	MTStatusBarOverlayAnimationShrink,
	// the status bar falls down and displays more information
	MTStatusBarOverlayAnimationFallDown
} MTStatusBarOverlayAnimation;


@interface MTStatusBarOverlay : UIWindow {
	// holds all subviews, is touchable to change size of Status Bar
	UIControl *backgroundView_;
	
	// background of Status Bar Black or gray
	UIImageView *statusBarBackgroundImageView_;
	// for displaying Text information
	UILabel *statusLabel1_;
	UILabel *statusLabel2_;
	UILabel *hiddenStatusLabel_;
	// for displaying activity indication
	UIActivityIndicatorView *activityIndicator_;
	UILabel *finishedLabel_;
	
	// Image of gray Status Bar
	UIImage *grayStatusBarImage_;
	UIImage *grayStatusBarImageSmall_;
	
	// Animation-Type
	MTStatusBarOverlayAnimation animation_;
	// Small size of Status Bar
	CGRect smallRect_;
}

//=========================================================== 
#pragma mark -
#pragma mark Properties
//=========================================================== 
@property (nonatomic, retain) UIControl *backgroundView;
@property (nonatomic, assign) CGRect smallRect;
@property (nonatomic, assign) MTStatusBarOverlayAnimation animation;

//=========================================================== 
#pragma mark -
#pragma mark Class Methods
//=========================================================== 

// convenience-constructor
+ (MTStatusBarOverlay *)statusBarOverlay;

//=========================================================== 
#pragma mark -
#pragma mark Instance Methods
//=========================================================== 

// for customizing appearance, automatically disabled userInteractionEnabled on view
- (void)addSubviewToBackgroundView:(UIView *)view;

- (void)show;
- (void)hide;
// convenience-method, set Message and show
- (void)showWithMessage:(NSString *)message;
- (void)finishWithMessage:(NSString *)message duration:(NSTimeInterval)duration;

- (void)setMessage:(NSString *)message animated:(BOOL)animated;

@end
