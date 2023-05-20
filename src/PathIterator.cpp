#include "../include/PathIterator.hpp"

bool PathIterator::hasNext() const
{
    return index_ < paths_.size();
}

fs::path PathIterator::next()
{
    return paths_[index_++];
}