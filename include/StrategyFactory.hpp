#ifndef STRATEGYFACTORY_HPP
#define STRATEGYFACTORY_HPP

#include <memory>
#include <string>
#include <filesystem>
#include "AllStrategy.hpp"
#include "ExtensionStrategy.hpp"
#include "RecursiveAllStrategy.hpp"
#include "RecursiveExtensionStrategy.hpp"
#include "DataInput.hpp"
#include "AbstractStrategy.hpp"

namespace fs = std::filesystem;

/*A factory class creating concrete strategies based on the strategy type.
The StrategyFactory class is responsible for creating concrete strategy objects based on the given strategy type.
It takes a strategy type as input and returns a unique pointer to the corresponding concrete strategy object.*/

class StrategyFactory
{
public:
    StrategyFactory(std::string &strategy_type) : strategy_type_(strategy_type) {}
    virtual ~StrategyFactory() = default;

    std::unique_ptr<AbstractStrategy> createStrategy(std::string &);

private:
    std::string &strategy_type_;
};

#endif