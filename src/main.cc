#include "header.h"

int main(){
    std::cout << exec("find . -type f -iname \"*.cc*\" 2>/dev/null");

    const std::vector<int> arr={0,1,2,3,4,5,6,7,8,9,10};
    std::vector<int> slice(arr.begin()+5, arr.begin()+9);
    std::cout <<slice;
    return 0;
}