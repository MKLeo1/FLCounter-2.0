#ifndef PATHITERATOR_HPP
#define PATHITERATOR_HPP

#include <vector>
#include <filesystem>

namespace fs = std::filesystem;

//Iterator class to iterate over a vector of filesystem paths.
class PathIterator
{
public:
    explicit PathIterator(const std::vector<fs::path> &paths) : paths_(paths) {}
    bool hasNext() const;
    fs::path next();

private:
    const std::vector<fs::path> &paths_;
    std::size_t index_ {};
};

#endif