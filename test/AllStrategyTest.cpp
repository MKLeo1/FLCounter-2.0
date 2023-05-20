#include <gtest/gtest.h>
#include "../include/AllStrategy.hpp"
#include <filesystem>

namespace fs = std::filesystem;

// Important - std::string extension = ".xxx" passed to func isn't used here, but it's necessary to use the mechanism of inheritance from an abstract strategy class. It's used in strategies classes with "extension" in name

// CountFilesTests:

// Test check correct files number
TEST(AllStrategyTest, CountCorrectNumberOfFiles)
{
  AllStrategy strategy;
  fs::path directory = "../test/testdata/AllStrategyTestData/";
  std::string extension = ".xxx";

  int actual_count = strategy.countFiles(directory, extension);

  EXPECT_EQ(2, actual_count);
}

// Test check invalid directory
TEST(AllStrategyTest,InvalidArgumentInvalidDirectory)
{
  AllStrategy strategy;
  fs::path directory = "/path/to/nonexistent/directory"; // Non existent path
  std::string extension = ".xxx";

  EXPECT_THROW(strategy.countFiles(directory, extension), std::invalid_argument);
}

// Test check empty directory
TEST(AllStrategyTest, CountFilesEmptyDirectory)
{
  AllStrategy strategy;
  fs::path directory = "../test/testdata/AllStrategyTestData/empty_directory/"; 
  std::string extension = ".xxx";

  int actual_count = strategy.countFiles(directory, extension);

  EXPECT_EQ(0, actual_count);
}



// CountLinesTests:



// Test check correct number of lines
TEST(AllStrategyTest, CountLinesReturnsCorrectCount)
{
  AllStrategy strategy;
  fs::path directory = "../test/testdata/AllStrategyTestData/";
  std::string extension = ".xxx";

  std::tuple<int, int> counts = strategy.countLines(directory, extension);

  EXPECT_EQ(1, std::get<0>(counts)); // empty lines
  EXPECT_EQ(2, std::get<1>(counts)); // non_empty_lines
}

// Test check incorrect path
TEST(AllStrategyTest, ThrowsInvalidArgumentForInvalidDirectoryPath)
{
  AllStrategy strategy;
  fs::path directory = "/path/to/nonexistent/directory"; 
  std::string extension = ".xxx"; 

  EXPECT_THROW(strategy.countLines(directory, extension), std::invalid_argument);
}

// Test check empty directory
TEST(AllStrategyTest, CountLinesReturnsZeroForEmptyDirectory)
{
  AllStrategy strategy;
  fs::path directory = "../test/testdata/AllStrategyTestData/empty_directory/"; 
  std::string extension = ".xxx"; 

  std::tuple<int, int> counts = strategy.countLines(directory, extension);

  EXPECT_EQ(0, std::get<0>(counts)); // empty lines
  EXPECT_EQ(0, std::get<1>(counts)); // non_empty_lines
}