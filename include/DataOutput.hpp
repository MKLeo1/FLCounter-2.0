#ifndef DATAOUTPUT_HPP
#define DATAOUTPUT_HPP

#include <ostream>

/*Struct representing output data for the program.*/

struct DataOutput
{
    DataOutput() : files_number(0), num_empty(0), num_non_empty(0) {}
    virtual ~DataOutput() = default;

    int files_number;
    int num_non_empty;
    int num_empty;

   friend std::ostream &operator<<(std::ostream &os, const DataOutput &dataOutput)
{
    os << "Number of files: " << dataOutput.files_number << std::endl;
    os << "Number of empty lines: " << dataOutput.num_empty << std::endl;
    os << "Number of non-empty lines: " << dataOutput.num_non_empty << std::endl;

    return os;
}
};


#endif