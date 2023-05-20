#include "../include/RecursiveExtensionStrategy.hpp"

int RecursiveExtensionStrategy::countFiles(const fs::path &directory, const std::string &extension)
{
  if (!fs::is_directory(directory) || !fs::exists(directory))
  {
    throw std::invalid_argument("Not a valid directory path");
  }
  int files_count{};
  std::for_each(fs::recursive_directory_iterator(directory), {}, [&files_count, &extension](const fs::directory_entry &path)
                {
        if (fs::is_regular_file(path) && path.path().extension() == extension)
        {
            ++files_count;
        } });

  return files_count;
}

std::tuple<int, int> RecursiveExtensionStrategy::countLines(const fs::path &directory, const std::string &extension)
{
  if (!fs::is_directory(directory) || !fs::exists(directory))
  {
    throw std::invalid_argument("Not a valid directory path");
  }
  int num_empty = 0;
  int num_non_empty = 0;

  std::for_each(fs::recursive_directory_iterator(directory), {}, [&](const fs::directory_entry &path)
                {
        if (fs::is_regular_file(path) && path.path().extension() == extension) {
            std::ifstream is{ path.path().string() };
            if (!is) {
                throw std::runtime_error("Failed to open file " + path.path().string());
            }

            std::string line;
            while (std::getline(is, line)) {
                if (line.empty()) {
                    ++num_empty;
                }
                else {
                    ++num_non_empty;
                }
            }
        } });

  return {num_empty, num_non_empty};
}
