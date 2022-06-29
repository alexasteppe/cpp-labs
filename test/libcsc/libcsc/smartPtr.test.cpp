#include <gtest/gtest.h>
#include <libcsc/smartptr/SharedPtr.hpp>
#include <libcsc/smartptr/UniquePtr.hpp>

using namespace shared;
using namespace unique;

TEST(Shared, Get) {
  SharedPtr getPtr(new int{9});
  EXPECT_EQ(*getPtr.get(), 9);
  EXPECT_EQ(*getPtr, *getPtr.get());
}

TEST(Shared, Count) {
  SharedPtr firstPtr(new int{1});
  SharedPtr secondPtr(firstPtr);
  SharedPtr thirdPtr(firstPtr);
  EXPECT_EQ(3, firstPtr.use_count());

  SharedPtr countPtr(new int{77});
  EXPECT_EQ(countPtr.use_count(), 1);
  {
    SharedPtr ptr(countPtr);
    EXPECT_EQ(countPtr.use_count(), 2);
  }
  EXPECT_EQ(countPtr.use_count(), 1);
}

TEST(Shared, Reset) {
  SharedPtr newPtr(new int{11});
  SharedPtr copyPtr(newPtr);
  EXPECT_EQ(newPtr.use_count(), 2);
  copyPtr.reset(new int{22});
  EXPECT_EQ(*copyPtr.get(), 22);
}

TEST(Unique, Get) {
  UniquePtr getPtr(new int{5});
  EXPECT_EQ(*getPtr.get(), 5);
  EXPECT_EQ(*getPtr, *getPtr.get());
}

TEST(Unique, Reset) {
  UniquePtr newPtr(new int{3});
  EXPECT_EQ(*newPtr.get(), 3);
  newPtr.reset(new int{6});
  EXPECT_EQ(*newPtr.get(), 6);
}
