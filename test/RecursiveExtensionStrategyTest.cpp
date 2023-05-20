#include <gtest/gtest.h>
#include "../include/RecursiveExtensionStrategy.hpp"
#include <filesystem>

namespace fs = std::filesystem;

// CountFilesTests:

// Test check correct files number
TEST(RecursiveExtensionStrategyTest, CountCorrectNumberOfFiles)
{
  RecursiveExtensionStrategy strategy;
  fs::path directory = "../test/testdata/RecursiveExtensionStrategyTestData/";
  std::string extension = ".txt";

  int actual_count = strategy.countFiles(directory, extension);

  EXPECT_EQ(2, actual_count);
}

// Test check invalid directory
TEST(RecursiveExtensionStrategyTest, InvalidArgumentInvalidDirectory)
{
  RecursiveExtensionStrategy strategy;
  fs::path directory = "/path/to/nonexistent/directory"; // Non existent path
  std::string extension = ".txt";

  EXPECT_THROW(strategy.countFiles(directory, extension), std::invalid_argument);
}

// Test check empty directory
TEST(RecursiveExtensionStrategyTest, CountFilesEmptyDirectory)
{
  RecursiveExtensionStrategy strategy;
  fs::path directory = "../test/testdata/RecursiveExtensionStrategyTestData/empty_directory/";
  std::string extension = ".txt";

  int actual_count = strategy.countFiles(directory, extension);

  EXPECT_EQ(0, actual_count);
}

// CountLinesTests:

// Test check correct number of lines
TEST(RecursiveExtensionStrategyTest, CountLinesCorrectCount)
{
  RecursiveExtensionStrategy strategy;
  fs::path directory = "../test/testdata/RecursiveExtensionStrategyTestData/";
  std::string extension = ".txt";

  std::tuple<int, int> counts = strategy.countLines(directory, extension);

  EXPECT_EQ(2, std::get<0>(counts)); // empty lines
  EXPECT_EQ(4, std::get<1>(counts)); // non_empty_lines
}

// Test check incorrect path
TEST(RecursiveExtensionStrategyTest, ThrowsInvalidArgumentForInvalidDirectoryPath)
{
  RecursiveExtensionStrategy strategy;
  fs::path directory = "/path/to/nonexistent/directory/";
  std::string extension = ".txt";

  EXPECT_THROW(strategy.countLines(directory, extension), std::invalid_argument);
}

// Test check empty directory
TEST(RecursiveExtensionStrategyTest, CountLinesZeroForEmptyDirectory)
{
  RecursiveExtensionStrategy strategy;
  fs::path directory = "../test/testdata/RecursiveExtensionStrategyTestData/empty_directory/";
  std::string extension = ".txt";

  std::tuple<int, int> counts = strategy.countLines(directory, extension);

  EXPECT_EQ(0, std::get<0>(counts)); // empty lines
  EXPECT_EQ(0, std::get<1>(counts)); // non_empty_lines
}