#include <filesystem>
#include <string>
#include <unordered_set>
#include <memory>
#include <vector>
#include <ostream>

#include "../include/StrategyFactory.hpp"
#include "../include/RecursiveAllStrategy.hpp"
#include "../include/AllStrategy.hpp"
#include "../include/ExtensionStrategy.hpp"
#include "../include/RecursiveExtensionStrategy.hpp"
#include "../include/AbstractStrategy.hpp"
#include "../include/DataInput.hpp"
#include "../include/DataOutput.hpp"
#include "../include/PathIterator.hpp"
#include "../include/DataProcessor.hpp"
#include "../include/AbstractStrategy.hpp"

/*****************************************************************************
 *   FLCounter helps to count the number of files and empty and non-empty
 *   lines in implemented locations on hard drive and their subfolders. M.K.
 *
 *
 *   argc - The number of command-line arguments.
 *   argv - Strings array containing the command-line arguments.
 *
 *   argv[0]: program invocation
 *   argv[1]: extension
 *   argv[2]: strategy type
 *   argv[3]: and subsequent arguments: paths to selected locations
 *
 *   The number of command-line arguments.
 *   Strings array containing the command-line arguments.
 *
 *   Available strategies:
 *
 *    "-all": operates on all files in the directory
 *
 *    "-all-r": operates on all files in the directory and all subfolders
 *
 *    "-ext": operates on all files in the directory with the specified extension
 *
 *    "-ext-r": operates on all files with the specified extension in the directory and all subfolders
 *
 *
 *                                      Important!
 *
 *
 * When selecting strategies for all files ("-all" and "-all-r"), you still need to provide a value for argv[1].
 * It will not affect the program's functionality but is necessary for the proper ordering of parameters.
 *
 *
 *   Example 1:   ./FLCounter .txt -ext-r /home/user/Desktop
 *   Example 2: ./FLCounter .doc -ext /home/user/Desktop
 *   Example 3: ./FLCounter .xxx -all /home/user/Desktop
 *   Example 4: ./FLCounter .xxx -all-r /home/user/Desktop /next/path/somewhere ...
 *
 *   Correct way: ./program <extension> <strategy_type> <path1> [<path2> ...]
 *
 *****************************************************************************/

namespace fs = std::filesystem;

int main(int argc, char **argv)
{
    std::unordered_set<std::string> allowed_strategy = {"-all", "-all-r", "-ext", "-ext-r"};

    if (argc < 4)
    {
        std::cerr << "Wrong arguments. Correct way: ./program <extension> <strategy_type> <path1> [<path2> ...]\n";
        return EXIT_FAILURE;
    }

    std::string extension = argv[1];
    std::string strategy_type = argv[2];

    strategy_type.erase(std::remove_if(strategy_type.begin(), strategy_type.end(), ::isspace), strategy_type.end());

    if (std::find(allowed_strategy.begin(), allowed_strategy.end(), argv[2]) == allowed_strategy.end())
    {
        std::cerr << "Invalid strategy. Correct way: ./program <extension> <strategy_type> <path1> [<path2> ...]\n";
        return EXIT_FAILURE;
    }

    std::vector<fs::path> paths;

    for (int i = 3; i < argc; ++i)
    {
        paths.emplace_back(fs::absolute(argv[i]));
    }

    DataInput Input(std::move(extension), std::move(strategy_type), std::move(paths));

    StrategyFactory Strategyfatory(Input.strategy_type);

    auto Strategy = Strategyfatory.createStrategy(Input.strategy_type);
    
    DataProcessor Processor(Input.extension, std::move(Strategy), Input.paths);

    DataOutput Output;
    
    Processor.processStrategy(Output.files_number, Output.num_empty, Output.num_non_empty);

    std::cout << Output << "\n";

    return EXIT_SUCCESS;
}
