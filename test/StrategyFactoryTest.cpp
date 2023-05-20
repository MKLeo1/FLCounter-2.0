#include "gtest/gtest.h"
#include "../include/StrategyFactory.hpp"
#include "../include/AllStrategy.hpp"
#include "../include/RecursiveAllStrategy.hpp"
#include "../include/ExtensionStrategy.hpp"
#include "../include/RecursiveExtensionStrategy.hpp"
#include <memory>
#include <string>

class MockStrategy : public AbstractStrategy{};
class MockAllStrategy : public AllStrategy{};
class MockRecursiveAllStrategy : public RecursiveAllStrategy{};
class MockExtensionStrategy : public ExtensionStrategy{};
class MockRecursiveExtensionStrategy : public RecursiveExtensionStrategy{};

// Fixture class
class StrategyFactoryTest : public ::testing::Test
{
protected:
    void SetUp() override
    {
        strategy_type;
        factory = std::make_unique<StrategyFactory>(strategy_type);
    }

    std::string strategy_type;
    std::unique_ptr<StrategyFactory> factory;
};

TEST_F(StrategyFactoryTest, CreateStrategy_All)
{
    strategy_type = "-all";
    std::unique_ptr<AbstractStrategy> strategy = factory->CreateStrategy(strategy_type);
    EXPECT_NE(strategy, nullptr);
    EXPECT_EQ(typeid(*strategy), typeid(AllStrategy));
}

TEST_F(StrategyFactoryTest, CreateStrategy_RecursiveAll)
{
    strategy_type = "-all-r";
    std::unique_ptr<AbstractStrategy> strategy = factory->CreateStrategy(strategy_type);
    EXPECT_NE(strategy, nullptr);
    EXPECT_EQ(typeid(*strategy), typeid(RecursiveAllStrategy));
}

TEST_F(StrategyFactoryTest, CreateStrategy_Extension)
{
    strategy_type = "-ext";
    std::unique_ptr<AbstractStrategy> strategy = factory->CreateStrategy(strategy_type);
    EXPECT_NE(strategy, nullptr);
    EXPECT_EQ(typeid(*strategy), typeid(ExtensionStrategy));
}

TEST_F(StrategyFactoryTest, CreateStrategy_RecursiveExtension)
{
    strategy_type = "-ext-r";
    std::unique_ptr<AbstractStrategy> strategy = factory->CreateStrategy(strategy_type);
    EXPECT_NE(strategy, nullptr);
    EXPECT_EQ(typeid(*strategy), typeid(RecursiveExtensionStrategy));
}

TEST_F(StrategyFactoryTest, CreateStrategy_InvalidType)
{
    strategy_type = "-invalid";
    std::unique_ptr<AbstractStrategy> strategy = factory->CreateStrategy(strategy_type);
    EXPECT_EQ(strategy, nullptr);
}