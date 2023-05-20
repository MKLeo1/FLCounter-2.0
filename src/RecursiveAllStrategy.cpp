#include "../include/RecursiveAllStrategy.hpp"


int RecursiveAllStrategy::countFiles(const fs::path &directory, const std::string &extension)
{

  if (!fs::is_directory(directory) || !fs::exists(directory))
  {
    throw std::invalid_argument("Not a valid directory path");
  }
  return static_cast<int>(std::distance(fs::recursive_directory_iterator{directory}, {}));
}

// IMPORTANT! const std::string &extension passed to func isn't used here, but it's necessary to use the mechanism of inheritance from an abstract strategy class. It's used in strategies classes with "extension" in name
std::tuple<int, int> RecursiveAllStrategy::countLines(const fs::path &directory, const std::string &extension)
{
  if (!fs::is_directory(directory) || !fs::exists(directory))
  {
    throw std::invalid_argument("Not a valid directory path");
  }
  int num_empty{}, num_non_empty{};

  std::for_each(fs::recursive_directory_iterator(directory), {}, [&num_empty, &num_non_empty](const fs::directory_entry &path)
                {
    std::ifstream is{path.path().string()};  
    if (!is){
        throw std::runtime_error("Failed to open file " + path.path().string());
    }
    
    std::string line;
    while (std::getline(is, line))
    {
      if (line.empty()) {
        ++num_empty;
      } else {
        ++num_non_empty;
      }
    } });

  return {num_empty, num_non_empty};
}
