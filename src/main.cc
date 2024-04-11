#include "header.h"

int main(){
    //std::cout << exec("find . -type f -iname \"*.cc*\" 2>/dev/null");

    std::vector <std::string> arr = {"hello", "applfdfdgrve", "tesfvdt", "bancana", "to", "jerrfdsy"};
    merge_sort(arr); //aad
    std::cout << arr;
    return 0;
}