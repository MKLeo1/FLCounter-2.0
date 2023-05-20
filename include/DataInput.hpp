#ifndef DATAINPUT_HPP
#define DATAINPUT_HPP

#include <vector>
#include <string>
#include <filesystem>

namespace fs = std::filesystem;

/*Struct representing input data for the program.*/

struct DataInput
{
    DataInput() = default;
    DataInput(std::string extension, std::string strategy_type, std::vector<fs::path> &&paths)
        : extension(std::move(extension)), strategy_type(std::move(strategy_type)), paths(std::move(paths)) {}
    virtual ~DataInput() = default;

    std::string extension;
    std::string strategy_type;
    std::vector<fs::path> paths;
};

#endif