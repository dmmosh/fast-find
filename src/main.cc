#include "header.h"

/*
FAST FIND
cli tool for quickly searching files

manual compile:
g++ src/main.cc src/utils.cc -o fast-find;
*/


int main(int argc, char* argv[]){
    //std::cout << exec("find . -type f -iname \"*.cc*\" 2>/dev/null");

    for (size_t i = 1; i < argc; i++)
    {
        std::cout << "\nVARIABLE ";
        int j = 0;
        while(argv[i][j]){
            std::cout <<toupper(argv[i][j]);
            j++;
        };
        std::cout << N;

        std::vector <std::string> arr_file = exec("find . -type f -iname \"*"+ std::string(argv[i]) +"*\" 2>/dev/null");
        std::vector <std::string> arr_dir = exec("find . -type d -iname \"*"+ std::string(argv[i]) +"*\" 2>/dev/null");
        merge_sort(arr_file); //aad
        merge_sort(arr_dir);
        std::cout << arr_file << N << arr_dir;
    }
    
    return 0;
}