#include "Stack.h"

#include "gtest/gtest.h"

TEST(TStack, can_create_birch_with_positive_height)
{
  ASSERT_NO_THROW(TStack<int> bf(3));
}

TEST(TStack, can_get_height)
{
  TStack<int> bf(3);

  EXPECT_NEAR(3, bf.GetLen(), 0.000001);
}

//TEST(TStack, new_vector_is_set_to_zero)
//{
//  TStack<int> bf(10);
//
//  int sum = 0;
//  for (int i = 0; i < bf.GetLen(); i++)
//  {
//    sum += bf[i];
//  }
//
//  EXPECT_EQ(0, sum);
//}
//
//TEST(TStack, can_set_number_of_vector)
//{
//  TStack<int> bf(10);
//
//  bf.SetLen(3);
//  EXPECT_EQ(0, bf[0]);
//}
//

TEST(TStack, throws_when_create_vector_with_negative_height)
{
  ASSERT_ANY_THROW(TStack<int> bf(-3));
}
