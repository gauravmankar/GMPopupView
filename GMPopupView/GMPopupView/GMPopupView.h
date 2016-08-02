//
//  GMPopupView.h
//  GMPopupView
//
//  Created by EclatSol_Mac1 on 01/08/16.
//  Copyright © 2016 Eclatsol_Mac. All rights reserved.
//

#import <UIKit/UIKit.h>


@class GMPopupView;

@protocol GMPopupViewDataSource <NSObject>

@required

- (NSInteger)numberOfRowsInPopupView : (GMPopupView *)popupView;

@optional

- (NSAttributedString *)gmPopupView :(GMPopupView *)popupView attributedTitleForRow:(NSInteger)row;


- (NSString *)gmPopupView :(GMPopupView *)popupView titleForRow:(NSInteger)row;


@end


@protocol GMPopupViewDelegate <NSObject>

@optional

- (void)gmPopupView : (GMPopupView *)popupView didConfirmWithItemAtRow :(NSInteger)row;

- (void)gmPopupView : (GMPopupView *)popupView didConfirmWithItemAtRows:(NSArray *)rows;

- (void)gmpopupViewDidCancel : (GMPopupView *)popupView;


@end

@interface GMPopupView : UIView<UITableViewDelegate,UITableViewDataSource>


- (id)initWithHeaderTitle: (NSString *)headerTitle cancelButtonTitle:(NSString *)cancelButtonTitle confirmButtonTitle:(NSString *)confirmButtonTitle;

- (void)show;

- (NSArray *)selectedRows;

- (void)setSelectedRows: (NSArray *)rows;


@property id<GMPopupViewDataSource> datasource;

@property id<GMPopupViewDelegate> delegate;

@property BOOL tapBackgroundToDismiss;
@property BOOL needFooterView;
@property BOOL allowMultipleSelection;


/** picker header background color */
@property (nonatomic, strong) UIColor *headerBackgroundColor;

/** picker header title font */
@property (nonatomic, strong) UIFont *headerTitleFont;

/** picker header title color */
@property (nonatomic, strong) UIColor *headerTitleColor;

/** picker cancel button background color */
@property (nonatomic, strong) UIColor *cancelButtonBackgroundColor;

/** picker cancel button normal state color */
@property (nonatomic, strong) UIColor *cancelButtonNormalColor;

/** picker cancel button highlighted state color */
@property (nonatomic, strong) UIColor *cancelButtonHighlightedColor;

/** picker confirm button background color */
@property (nonatomic, strong) UIColor *confirmButtonBackgroundColor;

/** picker confirm button normal state color */
@property (nonatomic, strong) UIColor *confirmButtonNormalColor;

/** picker confirm button highlighted state color */
@property (nonatomic, strong) UIColor *confirmButtonHighlightedColor;

/** tint color for tableview, also checkmark color */
@property (nonatomic, strong) UIColor *checkmarkColor;

/** picker's animation duration for showing and dismissing */
@property CGFloat animationDuration;

/** width of picker */
@property CGFloat pickerWidth;




@end
