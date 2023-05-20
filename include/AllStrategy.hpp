#ifndef ALLSTRATEGY_HPP
#define ALLSTRATEGY_HPP

#include <filesystem>
#include <tuple>
#include <algorithm>
#include <fstream>
#include "AbstractStrategy.hpp"

namespace fs = std::filesystem;

/*A concrete strategy that operates on all files in a directory.
This strategy counts the number of files and the number of lines in all files
within a specified directory. It implements the AbstractStrategy interface.*/

class AllStrategy : public AbstractStrategy
{
public:
    AllStrategy() = default;
    virtual ~AllStrategy() = default;

    int countFiles(const fs::path &, const std::string &) override;
    std::tuple<int, int> countLines(const fs::path &, const std::string &) override;
};

#endif