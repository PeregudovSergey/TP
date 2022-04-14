//
// Created by akhtyamovpavel on 5/1/20.
//

#include "LeapTestCase.h"

#include <Functions.h>



TEST_F(LeapTestCase, checkThrow) {
  ASSERT_THROW(IsLeap(-100), std::invalid_argument);  
}

TEST_F(LeapTestCase, checkYear) {
  EXPECT_TRUE(IsLeap(400));  
  EXPECT_FALSE(IsLeap(100));  
  EXPECT_TRUE(IsLeap(4));  
  EXPECT_FALSE(IsLeap(1));  
}

/*
int main(int argc, char** argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}	
*/