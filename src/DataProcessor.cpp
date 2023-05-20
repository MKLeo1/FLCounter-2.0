#include "../include/DataProcessor.hpp"

void DataProcessor::processStrategy(int &files_num, int &empty, int &non_empty)
{

    auto Pathiterator = std::make_unique<PathIterator>(paths_);

    while (Pathiterator->hasNext())
    {
        auto path = Pathiterator->next();
        try
        {
            int empty_lines{}, non_empty_lines{};
  
            files_num += strategy_->countFiles(path, extension_);
    
            std::tie(empty_lines, non_empty_lines) = strategy_->countLines(path, extension_);
            empty += empty_lines;
            non_empty += non_empty_lines;
        }
        catch (std::exception &e)
        {
            std::cerr << "Error processing path: " << path << ": " << e.what() << "\n";
        }
    }
}
