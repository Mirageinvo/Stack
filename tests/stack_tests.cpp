#include <iostream>

#include "gtest/gtest.h"
#include "Stack.hpp"
#include "Stack_impl.hpp"

const int kNum = 1e5;

TEST(IntStack, PushTest) {
  Stack<int> st;
  for (int i = 0; i < kNum; ++i) {
    st.push(i + 1);
    ASSERT_TRUE(st.top() == i + 1);
  }
  for (int i = kNum - 1; i >= 0; --i) {
    ASSERT_TRUE(st.top() == i + 1);
    st.pop();
  }
}

TEST(IntStack, IsEmptyTest) {
  Stack<int> tmp;
  ASSERT_EQ(tmp.is_empty(), true);
  tmp.push(3);
  EXPECT_EQ(tmp.is_empty(), false);
  tmp.push(48254);
  EXPECT_EQ(tmp.is_empty(), false);
}

TEST(IntStack, PopTest) {
  Stack<int> st;
  for (int i = 0; i < kNum; ++i) {
    st.push(i + 1);
    ASSERT_TRUE(st.top() == i + 1);
  }
  for (int i = kNum - 1; i >= 0; --i) {
    ASSERT_TRUE(st.pop() == i + 1);
  }
}

TEST(IntStack, SizeTest) {
  Stack<int> st;
  ASSERT_TRUE(st.size() == 0);
  for (int i = 0; i < kNum; ++i) {
    st.push(i + 1);
    ASSERT_TRUE(st.size() == static_cast<size_t>(i + 1));
  }
  for (int i = kNum - 1; i >= 0; --i) {
    st.pop();
    ASSERT_TRUE(st.size() == static_cast<size_t>(i));
  }
}

TEST(IntStack, CopyConstrTest) {
  Stack<int> tmp_1;
  for (int i = 0; i < kNum; ++i) {
    tmp_1.push(i + 1);
  }
  Stack<int> tmp_2(tmp_1);
  EXPECT_FALSE(tmp_1.size() != tmp_2.size());
  for (int i = kNum - 1; i >= 0; --i) {
    EXPECT_FALSE(tmp_2.pop() != i + 1);
  }
}

TEST(IntStack, MoveConstrTest) {
  Stack<int> tmp_1;
  for (int i = 0; i < kNum; ++i) {
    tmp_1.push(i + 1);
  }
  Stack<int> tmp_2(std::move(tmp_1));
  ASSERT_TRUE(tmp_2.size() == kNum);
  for (int i = kNum - 1; i >= 0; --i) {
    EXPECT_TRUE(tmp_2.pop() == i + 1);
  }
}

TEST(IntStack, SwapTest) {
  Stack<int> tmp_1;
  Stack<int> tmp_2;
  for (int i = 0; i < kNum; ++i) {
    tmp_1.push(i + 1);
  }
  for (int i = kNum * 2; i <= kNum * 3; ++i) {
    tmp_2.push(i);
  }
  tmp_1.swap(&tmp_2);
  ASSERT_TRUE(tmp_1.size() == kNum + 1 && tmp_2.size() == kNum);
  for (int i = kNum - 1; i >= 0; --i) {
    ASSERT_TRUE(tmp_2.pop() == i + 1);
  }
  for (int i = kNum * 3; i >= kNum * 2; --i) {
    ASSERT_TRUE(tmp_1.pop() == i);
  }
}

TEST(BoolStack, PushTest) {
  Stack<bool> st;
  for (int i = 0; i < kNum; ++i) {
    st.push(static_cast<bool>((i + 1) % 2));
    ASSERT_TRUE(st.top() == static_cast<bool>((i + 1) % 2));
  }
  for (int i = kNum - 1; i >= 0; --i) {
    ASSERT_TRUE(st.top() == static_cast<bool>((i + 1) % 2));
    st.pop();
  }
}

TEST(BoolStack, IsEmptyTest) {
  Stack<bool> st;
  ASSERT_TRUE(st.is_empty());
  st.push(true);
  ASSERT_FALSE(st.is_empty());
  st.push(true);
  ASSERT_FALSE(st.is_empty());
}

TEST(BoolStack, PopTest) {
  Stack<bool> st;
  for (int i = 0; i < kNum; ++i) {
    st.push(static_cast<bool>((i + 1) % 2));
  }
  for (int i = kNum - 1; i >= 0; --i) {
    ASSERT_TRUE(st.pop() == static_cast<bool>((i + 1) % 2));
  }
}

TEST(BoolStack, SizeTest) {
  Stack<bool> st;
  ASSERT_TRUE(st.size() == 0);
  for (int i = 0; i < kNum; ++i) {
    st.push(static_cast<bool>((i + 1) % 2));
    ASSERT_TRUE(st.size() == static_cast<size_t>(i + 1));
  }
  for (int i = kNum - 1; i >= 0; --i) {
    st.pop();
    ASSERT_TRUE(st.size() == static_cast<size_t>(i));
  }
}

TEST(BoolStack, CopyConstrTest) {
  Stack<bool> tmp_1;
  for (int i = 0; i < kNum; ++i) {
    tmp_1.push(static_cast<bool>((i + 1) % 2));
  }
  Stack<bool> tmp_2(tmp_1);
  ASSERT_TRUE(tmp_1.size() == tmp_2.size());
  for (int i = kNum - 1; i >= 0; --i) {
    ASSERT_TRUE(tmp_2.pop() == static_cast<bool>((i + 1) % 2));
  }
}

TEST(BoolStack, MoveConstrTest) {
  Stack<bool> tmp_1;
  for (int i = 0; i < kNum; ++i) {
    tmp_1.push(static_cast<bool>((i + 1) % 2));
  }
  Stack<bool> tmp_2(std::move(tmp_1));
  ASSERT_TRUE(tmp_2.size() == kNum);
  for (int i = kNum - 1; i >= 0; --i) {
    ASSERT_TRUE(tmp_2.pop() == static_cast<bool>((i + 1) % 2));
  }
}

TEST(BoolStack, SwapTest) {
  Stack<bool> tmp_1;
  Stack<bool> tmp_2;
  for (int i = 0; i < kNum; ++i) {
    tmp_1.push(static_cast<bool>((i + 1) % 2));
  }
  for (int i = 200000; i <= 300000; ++i) {
    tmp_2.push(static_cast<bool>(i % 2));
  }
  tmp_1.swap(&tmp_2);
  ASSERT_TRUE(tmp_1.size() == 100001 && tmp_2.size() == kNum);
  for (int i = kNum - 1; i >= 0; --i) {
    ASSERT_TRUE(tmp_2.pop() == static_cast<bool>((i + 1) % 2));
  }
  for (int i = 300000; i >= 200000; --i) {
    ASSERT_TRUE(tmp_1.pop() == static_cast<bool>(i % 2));
  }
}

int main(int argc, char* argv[]) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}