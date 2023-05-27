<h1>FLCounter</h1>

<h2>Author's Note:</h2>

FilesLinesCounter 2.0 is a form of exercise to gain practical coding skills and knowledge in the field of C++.

My assumption was to write code that uses good programming practices such as using design patterns, smart pointers, clean code rules etc.

Tested on GNU/Linux.

M.K.

<h2>Overview</h2>

FLCounter is a program written in C++ that helps count the number of files, empty and non-empty lines in provided paths on your hard drive and their subfolders.
  
<h2>Namespace</h2>
The code defines the fs namespace, which is an alias for the filesystem namespace. The filesystem library provides facilities for working with files and directories.
  
<h2>Structs</h2>
DataInput holds the entered paths, which are provided as command-line arguments. The constructor of DataInput takes string extension, string strategy_type, and a vector of fs::path objects as input.

DataOutput holds the results of the program execution. It has three members:

1. files_number: the total number of files found in the specified paths
2. num_non_empty: the total number of non-empty lines found in the specified paths
3. num_empty: the total number of empty lines found in the specified paths
  
<h2>Functions</h2>
  
The code defines three functions: 

countFiles

countLines

countFiles function returns the number of files found in the specified directory and its subdirectories. If the specified path is not a valid directory, the function throws an invalid_argument exception.

countLines function returns a tuple containing the number of empty and non-empty lines found in the specified directory and its subdirectories. If the specified path is not a valid directory, the function throws an invalid_argument exception. If the file cannot be opened, the function throws a runtime_error exception.

<h2>Avalible count strategies: </h2>
    "-all": operates on all files in the directory
 
    "-all-r": operates on all files in the directory and all subfolders
 
    "-ext": operates on all files in the directory with the specified extension
 
    "-ext-r": operates on all files with the specified extension in the directory and all subfolders

<h2>How to build? </h2>
Before using remember to set up your environment. Install CMake & Gtest. Remember to update GTest lib directory in CMakeLists.txt. 

1. Clone this repository
2. Create and go to the build file
3. Open terminal and build with CMake using: 
    "..cmake"
then:
    "make"
then: 
    if you want to test it type: "ctest" or "ctest -V" - for more testing info

<h2>How to use? </h2>
    if you want to use program type in correct order:

    ./program <extension> <strategy_type> <path1> [<path2> ...]

    Example 1: ./FLCounter .txt -ext-r /home/user/Desktop
    Example 2: ./FLCounter .doc -ext /home/user/Desktop
    Example 3: ./FLCounter .xxx -all /home/user/Desktop
    Example 4: ./FLCounter .xxx -all-r /home/user/Desktop/next/path/somewhere ...  

                     <h2>Important!</h2> 
 
  When selecting strategies for all files ("-all" and "-all-r"), you still need to provide a value for argv[1] (extension).
  It will not affect the program's functionality but is necessary for the proper ordering of parameters so you can type for example: "xxx".

   

