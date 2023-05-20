#ifndef ABSTRACTSTRATEGY_HPP
#define ABSTRACTSTRATEGY_HPP

#include <tuple>
#include <filesystem>

namespace fs = std::filesystem;

/*
 *  The AbstractStrategy class represents an abstract base class for file analysis strategies.
 *  It defines pure virtual methods for counting files and counting lines in files.
 */

class AbstractStrategy
{
public:
    AbstractStrategy() = default;
    virtual ~AbstractStrategy() = default;

    virtual int countFiles(const fs::path &, const std::string &) = 0; // path directory, string extension
    virtual std::tuple<int, int> countLines(const fs::path &, const std::string &) = 0;
         // std::tuple<int, int> A tuple containing the total number empty and non empty lines.
};

#endif
