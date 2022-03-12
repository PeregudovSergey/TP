#include "main.h"
#include <gtest/gtest.h>

TEST(TestIndex, nothing) {
	EXPECT_TRUE(true); 
}

TEST(FirstTest, init_add) {
	Modular x = 7; 
	EXPECT_EQ(7, x.get());
	x.add(3); 
	EXPECT_EQ(10, x.get());
}