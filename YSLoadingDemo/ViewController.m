//
//  ViewController.m
//  YSLoadingDemo
//
//  Created by william on 16/4/8.
//  Copyright © 2016年 陈大威. All rights reserved.
//

#import "ViewController.h"
#import "UIView+Extension.h"

@interface ViewController ()

@end

@implementation ViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    // Do any additional setup after loading the view, typically from a nib.
    
    
}
- (IBAction)stratLoadingAction:(id)sender {
    [self.view beginLoading];
    [self performSelector:@selector(hideloading) withObject:nil afterDelay:5];
}
- (void)hideloading{
    [self.view endLoading];
}
- (void)didReceiveMemoryWarning {
    [super didReceiveMemoryWarning];
    // Dispose of any resources that can be recreated.
}

@end
