#include "header.h"

int main(int argc, char* argv[]){
    //std::cout << exec("find . -type f -iname \"*.cc*\" 2>/dev/null");

    for (size_t i = 1; i < argc; i++)
    {
        std::vector <std::string> arr = exec("find . -type f -iname \"*"+ std::string(argv[i]) +"*\" 2>/dev/null");
        merge_sort(arr); //aad
        std::cout << arr;
    }
    
    return 0;
}