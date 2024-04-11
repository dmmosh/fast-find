#include <cstdio>
#include <iostream>
#include <stdlib.h>
#include <memory>
#include <stdexcept>
#include <string>
#include <array>
#include <vector>


std::vector<std::string> exec(const std::string& cmd);

// PRINT A VECTOR
template<typename T>
std::ostream& operator<<(std::ostream& out, const std::vector<T>& input){
        for (unsigned int i = 0; i < input.size(); i++) //iterates over the elements
        {
            if(i) out << " "; //adds a space to before printing if not first element
            out << input[i];
        }
        
        return out;
};