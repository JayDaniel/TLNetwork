//
//  ViewController.m
//  TLNetworkDemo
//
//  Created by Ted Liu on 2017/2/21.
//  Copyright © 2017年 Ted Liu. All rights reserved.
//

#import "ViewController.h"
#import "TLAsiNetworkHandler.h"

@interface ViewController ()

@end

@implementation ViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    // Do any additional setup after loading the view, typically from a nib.
}

- (IBAction)actionTouchTest:(id)sender {
    
    [[TLAsiNetworkManager sharedManager] setIsVerifyHttps:YES];
    
    [TLAsiNetworkHandler requestWithUrl:@"https://192.168.1.49:8443/T/Holen?key=hello"
                                 params:nil
                                showHUD:YES httpMedthod:TLAsiNetWorkGET
                           successBlock:^(id response) {
                               
        
                               
    } failBlock:^(NSError *error) {
        
        
    }];
}


- (void)didReceiveMemoryWarning {
    [super didReceiveMemoryWarning];
    // Dispose of any resources that can be recreated.
}


@end
