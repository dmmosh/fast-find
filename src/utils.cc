#include "header.h"

std::vector<std::string> exec(const std::string& cmd) {
    std::array<char, 200> buffer;
    std::vector<std::string> result;
    std::unique_ptr<FILE, decltype(&pclose)> pipe(popen(cmd.c_str(), "r"), pclose);
    if (!pipe) {
        throw std::runtime_error("popen() failed!");
    }

    while (fgets(buffer.data(), static_cast<int>(buffer.size()), pipe.get()) != nullptr) {
        result.push_back(buffer.data());
        int pos = result.back().find("\n");
        result.back().erase(pos, 2);
    }
    return result;
}