#ifndef RECURSIVEEXTENSIONSTRATEGY_HPP
#define RECURSIVEEXTENSIONSTRATEGY_HPP

#include <filesystem>
#include <tuple>
#include <algorithm>
#include <fstream>
#include "AbstractStrategy.hpp"

namespace fs = std::filesystem;

/*A concrete strategy that operates on all files with specified extension and subfolders in a directory.
This strategy counts the number of files  with specified extension and the number of lines in all files and subfolders
within a specified directory. It implements the AbstractStrategy interface.*/

class RecursiveExtensionStrategy : public AbstractStrategy
{
public:
    RecursiveExtensionStrategy() = default;
    virtual ~RecursiveExtensionStrategy() = default;

    int countFiles(const fs::path &, const std::string &) override;
    std::tuple<int, int> countLines(const fs::path &, const std::string &) override;
};

#endif