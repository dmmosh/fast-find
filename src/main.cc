#include "header.h"

int main(){
    std::cout << "fdkjskl\n";
    std::cout << exec("find . -type d -iname \"*.cc*\" 2>/dev/null");
    return 0;
}