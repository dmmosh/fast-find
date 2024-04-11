#include "header.h"

int main(){
    std::cout << exec("find . -type f -iname \"*.cc*\" 2>/dev/null");
    return 0;
}