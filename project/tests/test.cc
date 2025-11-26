#include <gtest/gtest.h>
#include "my_string.h"

TEST(testConstructor, ConstructorEmptyString) {
  my_std::String s;

  EXPECT_EQ(s.GetSize(), 0);
  EXPECT_STREQ(s.c_str(), "");
  EXPECT_TRUE(s.IsEmpty());
}

TEST(testConstructor, ConstructorCstr) {
  const char* str = "Friend";
  const char* str2 = str;

  my_std::String s1(str);
  my_std::String s2(str2);
  EXPECT_EQ(s1.GetSize(), 6);
  EXPECT_TRUE(s1 == s2);
  EXPECT_FALSE(s1 == my_std::String("lol"));
}

TEST(testConstructor, ConstructorCopy) {
  my_std::String s1("Hello");
  my_std::String s_copy(s1);
  EXPECT_TRUE(s1 == s_copy);
}

int main(int argc, char** argv) {
  ::testing::InitGoogleTest(&argc, argv);

  return RUN_ALL_TESTS();
}