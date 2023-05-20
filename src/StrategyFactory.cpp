#include "../include/StrategyFactory.hpp"

std::unique_ptr<AbstractStrategy> StrategyFactory::createStrategy(std::string &strategy_type)
{
    if (strategy_type == "-all")
    {
        return std::make_unique<AllStrategy>();
    }
    if (strategy_type == "-all-r")
    {
        return std::make_unique<RecursiveAllStrategy>();
    }
    if (strategy_type == "-ext")
    {
        return std::make_unique<ExtensionStrategy>();
    }
    if (strategy_type == "-ext-r")
    {
        return std::make_unique<RecursiveExtensionStrategy>();
    }
    else
    {
        return nullptr;
    }
}