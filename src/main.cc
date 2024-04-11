#include "header.h"

int main(){
    std::cout << exec("find . -type f -iname \"*.cc*\" 2>/dev/null");

    std::vector <std::string> arr = {"hello", "apple", "test", "banana", "tom", "jerry"};
    std::vector<std::string> temp_left(arr.begin() + 1, arr.begin() + 4);
    std::cout << temp_left;
    return 0;
}