#include <cstdio>
#include <iostream>
#include <stdlib.h>
#include <memory>
#include <stdexcept>
#include <string>
#include <array>
#include <vector>


std::vector<std::string> exec(const std::string& cmd);

template<typename T>
std::ostream& operator<<(std::ostream& out, const std::vector<T>& input){
        for(const T data: input){
            out << data << "fdjkl";
        }
        return out;
};