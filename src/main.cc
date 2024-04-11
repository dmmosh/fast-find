#include "header.h"

/*
FAST FIND
cli tool for quickly searching files

manual compile:
g++ src/main.cc src/utils.cc -o fast-find;
*/


int main(int argc, char* argv[]){
    //std::cout << exec("find . -type f -iname \"*.cc*\" 2>/dev/null");
    std::string loose = ""; // loose search, default is empty

    // iterates over passed parameters
    for (size_t i = 1; i < argc; i++)
    {
        if(EQUALS(argv[i], "-l") || EQUALS(argv[i], "--loose")){ //specifies looseness of search
            loose = "*"; // assigns loose to asterisk
            continue; // iterates
        } else if (EQUALS(argv[i], "-s") || EQUALS(argv[i], "--strict")){ //specifies exactness of search
            loose= ""; //sets loose to nothing
            continue;
        }

        // prints the variable name
        std::cout << "\nVARIABLE ";
        int j = 0;
        while(argv[i][j]){
            std::cout << (char)toupper(argv[i][j]);
            j++;
        };
        std::cout << N;

        std::vector <std::string> arr_file = exec("find . -type f -iname \""+ loose + std::string(argv[i]) + loose+ "\" 2>/dev/null");
        std::vector <std::string> arr_dir = exec("find . -type d -iname \""+ loose + std::string(argv[i]) + loose+ "\" 2>/dev/null");

        
        if (arr_file.empty() && arr_dir.empty()){ //if both vectors are empty
            std::cout << "  No files/directories found.\n"; // prints message
            continue; // skips to the next element
        }
        
        if (!arr_file.empty()){ // if there's files
            if(arr_file.size() > 1) merge_sort(arr_file); //sorts the output files, if more than 1 element
            std::cout << "FILES:";
            for(const std::string& out: arr_file){
                std::cout << N << "  "<< out;
            }
            std::cout << N;
        }
        
        if (!arr_dir.empty()){
            if(arr_dir.size() > 1) merge_sort(arr_dir); //sorts the output files, if more than 1 element
            std::cout << "DIRECTORIES:";
            for(const std::string& out: arr_dir){
                std::cout << N << "  "<< out;
            }
            std::cout << N;
        }


        //merge_sort(arr_dir);
        //std::cout << arr_file << N << arr_dir;
    }
    
    return 0;
}