#include <gtest/gtest.h>
#include "AllStrategyTest.cpp"
#include "RecursiveAllStrategyTest.cpp"
#include "ExtensionStrategyTest.cpp"
#include "RecursiveExtensionStrategyTest.cpp"
#include "StrategyFactoryTest.cpp"

int main(int argc, char **argv)
{
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}