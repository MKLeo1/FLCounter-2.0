#ifndef DATAPROCESSOR_HPP
#define DATAPROCESSOR_HPP

#include <memory>
#include <vector>
#include <algorithm>
#include <string>
#include <iostream>
#include <tuple>
#include <filesystem>
#include "PathIterator.hpp"
#include "DataInput.hpp"
#include "DataOutput.hpp"
#include "AbstractStrategy.hpp"
#include "StrategyFactory.hpp"
#include "RecursiveAllStrategy.hpp"

namespace fs = std::filesystem;

//  Class responsible for processing data based on a given strategy.

class DataProcessor
{
public:
    DataProcessor(std::string& extension, std::unique_ptr<AbstractStrategy> strategy,std::vector<fs::path> &paths) : extension_(extension), strategy_(std::move(strategy)), paths_(paths) {}

    void processStrategy(int &, int &, int &);

private:
    std::string extension_;
    std::unique_ptr<AbstractStrategy> strategy_;
    std::vector<fs::path> paths_;
};

#endif
