//
//  ViewController.m
//  GMPopupView
//
//  Created by EclatSol_Mac1 on 01/08/16.
//  Copyright © 2016 Eclatsol_Mac. All rights reserved.
//

#import "ViewController.h"
#import "GMPopupView.h"

@interface ViewController ()<GMPopupViewDataSource,GMPopupViewDelegate>{
    NSMutableArray *cityArray;
}

//@property NSArray *fruits;


@end

@implementation ViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    
    cityArray = [[NSMutableArray alloc]initWithObjects:@"Mumbai",@"pune",@"nashik", nil];
    
   // self.fruits = @[@"Mumbai", @"Nashik", @"Satara", @"Sangli",@"A'Nagar", @"Nagpur"];
    
    
}

- (void)didReceiveMemoryWarning {
    [super didReceiveMemoryWarning];
    // Dispose of any resources that can be recreated.
}

- (IBAction)onBtn:(id)sender {
    
    GMPopupView *popupView = [[GMPopupView alloc]initWithHeaderTitle:@"City" cancelButtonTitle:@"Cancel" confirmButtonTitle:@"Confirm"];
    popupView.allowMultipleSelection = NO;
    popupView.needFooterView = YES;
    popupView.tapBackgroundToDismiss = YES;
    popupView.delegate = self;
    popupView.datasource = self;
    [popupView show];
}

- (NSAttributedString *)gmPopupView:(GMPopupView *)popupView attributedTitleForRow:(NSInteger)row{
    NSAttributedString *att = [[NSAttributedString alloc]
                               initWithString:cityArray[row]
                               attributes:@{
                                            NSFontAttributeName:[UIFont fontWithName:@"Avenir-Light" size:18.0]
                                            }];
    return att;
}

- (NSString *)gmPopupView:(GMPopupView *)popupView titleForRow:(NSInteger)row{
    
    NSLog(@"city name %@",cityArray[row]);
    return cityArray[row];
}

- (NSInteger)numberOfRowsInPopupView:(GMPopupView *)popupView{
    return cityArray.count;
}

- (void)gmPopupView:(GMPopupView *)popupView didConfirmWithItemAtRow:(NSInteger)row{
    NSLog(@"%@ is chosen!", cityArray[row]);
}

- (void)gmPopupView:(GMPopupView *)popupView didConfirmWithItemAtRows:(NSArray *)rows{
    for(NSNumber *n in rows){
        NSInteger row = [n integerValue];
        NSLog(@"%@ is chosen!", cityArray[row]);
    }
}

- (void)gmpopupViewDidCancel:(GMPopupView *)popupView{
    NSLog(@"canceled...");
}

@end
