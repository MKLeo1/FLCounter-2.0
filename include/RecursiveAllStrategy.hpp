#ifndef RECURSIVEALLSTRATEGY_HPP
#define RECURSIVEALLSTRATEGY_HPP

#include <filesystem>
#include <tuple>
#include <algorithm>
#include <fstream>
#include "AbstractStrategy.hpp"

namespace fs = std::filesystem;

/*A concrete strategy that operates on all files and subfolders in a directory.
This strategy counts the number of files and the number of lines in all files and subfolders
within a specified directory. It implements the AbstractStrategy interface.*/

class RecursiveAllStrategy : public AbstractStrategy
{
public:
    RecursiveAllStrategy() = default;
    virtual ~RecursiveAllStrategy() = default;

    int countFiles(const fs::path &, const std::string &) override;
    std::tuple<int, int> countLines(const fs::path &, const std::string &) override;
};

#endif