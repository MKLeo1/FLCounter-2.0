#ifndef EXTENSIONSTRATEGY_HPP
#define EXTENSIONSTRATEGY_HPP

#include <filesystem>
#include <tuple>
#include <algorithm>
#include <fstream>
#include "AbstractStrategy.hpp"

namespace fs = std::filesystem;

/*A concrete strategy that operates on all files with specified extension in a directory.
This strategy counts the number of files and the number of lines in all files with specified extension
within a specified directory. It implements the AbstractStrategy interface.*/

class ExtensionStrategy : public AbstractStrategy
{
public:
    ExtensionStrategy() = default;
    virtual ~ExtensionStrategy() = default;

    int countFiles(const fs::path &, const std::string &) override;
    std::tuple<int, int> countLines(const fs::path &, const std::string &) override;
};

#endif