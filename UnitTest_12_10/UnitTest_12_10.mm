//
//  UnitTest_12_10.m
//  UnitTest_12_10
//
//  Created by USER on 01.06.2023.
//
#include <sstream>
#import "Header.h"
#import <XCTest/XCTest.h>

@interface UnitTest_12_10 : XCTestCase

@end

@implementation UnitTest_12_10

- (void)testExample {
    
    TreeNode* root = nullptr;
    insert(root, "abc");
    insert(root, "def");
    insert(root, "abc");
    insert(root, "ghi");
    insert(root, "ghi");
    insert(root, "jkl");
    
    stringstream output;
    streambuf* coutBuffer = cout.rdbuf();
    cout.rdbuf(output.rdbuf());
    
    print(root);
    
    cout.rdbuf(coutBuffer);
    string expectedOutput = "abc : 2\n"
                            "def : 1\n"
                            "ghi : 2\n"
                            "jkl : 1\n";
    XCTAssert(output.str() == expectedOutput);
    
}



@end
