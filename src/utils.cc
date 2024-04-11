#include "header.h"

void merge_sort(std::vector<std::string>& arr){
    merge_sort(arr, 0, arr.size()-1); // calls the recursive merge sort
};

// CALLS THE RECURSIVE MERGE SORT
void merge_sort(std::vector<std::string>& arr, int left, int right){
    if(left< right){ // base case
        int middle = left+ (right-left)/2; // middle index
        merge_sort(arr, left, middle); // divies all left sections
        merge_sort(arr, middle+1, right); // divides all right sections
        merge_sort(arr, left, middle, right); // merges back together
    }
};

// MERGES BACK THE PIECES
void merge_sort(std::vector<std::string>& arr, int left, int middle, int right) {
    int left_range = middle-left+1; // the left value range
    int right_range = right-middle; // the right value range

    // creates temp arrays 
    std::vector<std::string> temp_left(arr.begin() + left, arr.begin() + left + left_range);
    std::vector<std::string> temp_right(arr.begin() + middle+1, arr.begin() + middle+1+right_range);
    std::cout << temp_left << '\t' << left_range << N;
    std::cout << temp_right << '\t' << right_range << N;

    int i =0;
    int j = 0;
    int k = left;
    
    
};


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