//
// Created by akhtyamovpavel on 5/1/20.
//

#include "AddTestCase.h"
#include "Functions.h"


TEST_F(AddTestCase, TwoPlusTwo) {
  ASSERT_EQ(4, Add(2, 2));
}

TEST_F(AddTestCase, Month) {
  ASSERT_EQ(GetMonthDays(400, 2), 29);
  ASSERT_EQ(GetMonthDays(1, 2), 28);
  ASSERT_THROW(GetMonthDays(10, -11), std::invalid_argument);  
  ASSERT_EQ(GetMonthDays(11, 4), 30);  
  ASSERT_EQ(GetMonthDays(11, 3), 31);  
}