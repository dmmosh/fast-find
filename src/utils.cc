#include "header.h"

std::vector<std::string> exec(const std::string& cmd) {
    std::array<char, 200> buffer;
    std::vector<std::string> result;
    std::unique_ptr<FILE, decltype(&pclose)> pipe(popen(cmd.c_str(), "r"), pclose);
    if (!pipe) { //exception handle
        throw std::runtime_error("popen() failed!");
    } 

    while (fgets(buffer.data(), static_cast<int>(buffer.size()), pipe.get()) != nullptr) {
        result.push_back(buffer.data()); // pushes the output to the back of the array
        result.back().resize(result.back().size() - 1); //removes the newline character
    }
    return result;
}