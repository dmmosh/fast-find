#include "header.h"

int main(){
    //std::cout << exec("find . -type f -iname \"*.cc*\" 2>/dev/null");

    std::vector <std::string> arr = {"hello", "apple", "test", "banana", "tom", "jerry"};
    merge_sort(arr);
    std::cout << arr;
    return 0;
}