#include <gtest/gtest.h>
#include "../include/ExtensionStrategy.hpp"
#include <filesystem>
#include <fstream>

namespace fs = std::filesystem;

// CountFilesTests:

// Test check correct files number
TEST(ExtensionStrategyTest, CountCorrectNumberOfFiles)
{
  ExtensionStrategy strategy;
  fs::path directory = "../test/testdata/ExtensionStrategyTestData/";
  std::string extension = ".txt";

  int actual_count = strategy.countFiles(directory, extension);

  EXPECT_EQ(1, actual_count);
}

// Test check invalid directory
TEST(ExtensionStrategyTest, InvalidArgumentInvalidDirectory)
{
  ExtensionStrategy strategy;
  fs::path directory = "/path/to/nonexistent/directory"; // Non existent path
  std::string extension = ".txt";

  EXPECT_THROW(strategy.countFiles(directory, extension), std::invalid_argument);
}

// Test check empty directory
TEST(ExtensionStrategyTest, CountFilesEmptyDirectory)
{
  ExtensionStrategy strategy;
  fs::path directory = "../test/testdata/ExtensionStrategyTestData/empty_directory/";
  std::string extension = ".txt";

  int actual_count = strategy.countFiles(directory, extension);

  EXPECT_EQ(0, actual_count);
}

// CountLinesTests:

// Test check correct number of lines
TEST(ExtensionStrategyTest, CountLinesReturnsCorrectCount)
{
  ExtensionStrategy strategy;
  fs::path directory = "../test/testdata/ExtensionStrategyTestData/";
  std::string extension = ".txt";

  std::tuple<int, int> counts = strategy.countLines(directory, extension);

  EXPECT_EQ(1, std::get<0>(counts)); // empty lines
  EXPECT_EQ(2, std::get<1>(counts)); // non_empty_lines
}

// Test check incorrect path
TEST(ExtensionStrategyTest, ThrowsInvalidArgumentForInvalidDirectoryPath)
{
  ExtensionStrategy strategy;
  fs::path directory = "/path/to/nonexistent/directory";
  std::string extension = ".txt";

  EXPECT_THROW(strategy.countLines(directory, extension), std::invalid_argument);
}

// Test check empty directory
TEST(ExtensionStrategyTest, CountLinesReturnsZeroForEmptyDirectory)
{
  ExtensionStrategy strategy;
  fs::path directory = "../test/testdata/ExtensionStrategyTestData/empty_directory/";
  std::string extension = ".txt";

  std::tuple<int, int> counts = strategy.countLines(directory, extension);

  EXPECT_EQ(0, std::get<0>(counts)); // empty lines
  EXPECT_EQ(0, std::get<1>(counts)); // non_empty_lines
}