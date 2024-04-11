#include "header.h"

/*
FAST FIND
cli tool for quickly searching files

manual compile:
g++ src/main.cc src/utils.cc -o fast-find;
*/


int main(int argc, char* argv[]){
    //std::cout << exec("find . -type f -iname \"*.cc*\" 2>/dev/null");
    char loose = '\0'; // loose search, default is empty
    
    // iterates over passed parameters
    for (size_t i = 1; i < argc; i++)
    {
        std::string input = argv[i];
        if(input == "-l" || input == "--loose"){ //specifies looseness of search
            loose = '*'; // assigns loose to asterisk

            continue; // iterates
        } else if (input == "-s" || input == "--strict"){ //specifies strictness of search
            loose= '\0'; //sets loose to nothing
            continue; //iterates
        } 

        std::string print_input = input;
        std::transform(print_input.begin(), print_input.end(), print_input.begin(), ::toupper); 
        std::cout << "\nVARIABLE " << print_input << ":\n" << ((loose) ? "(strict)" : "(loose)");

        if(loose) { // if loose is NOT the null terminator, append it to the input
            input.push_back(loose);
            input.insert(input.begin(), loose);
        }


        std::vector <std::string> arr_file = exec("find . -type f -iname \""
                                                    + input
                                                    + "\" 2>/dev/null");
        std::vector <std::string> arr_dir = exec("find . -type d -iname \""
                                                    + input
                                                    + "\" 2>/dev/null");

        
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