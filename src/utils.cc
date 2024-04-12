#include "header.h"

void merge_sort_call(std::vector<std::string>& arr){
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
    std::vector<std::string> temp_left(arr.begin() + left, arr.begin() + left + left_range); //left subarray
    std::vector<std::string> temp_right(arr.begin() + middle+1, arr.begin() + middle+1+right_range); //right subarray

    // DEBUG
    //std::cout << N << temp_left << '\t' << left_range; //DEBUG
    //std::cout << N << temp_right << '\t' << right_range; //DEBUG

    int i =0; // iterates left array
    int j = 0; // iterates right array
    int k = left; // iterates left array
    while (i < left_range && j <right_range){ //sorts the values
        if(temp_left[i].length() > temp_right[j].length()){
            arr[k] = temp_left[i];
            i++;
        } else {
            arr[k] = temp_right[j];
            j++;
        }
        k++;
    }

    while ( i < left_range){ //clears the left subarray 
        arr[k] = temp_left[i];
        i++;
        k++;
    }
    while( j < right_range){
        arr[k] = temp_right[j];
        j++;
        k++;
    }
    
    
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

void write_tmp(const std::string& out, const std::string& filename){
    std::ofstream file;
    file.open(filename);
    file << out;
    file.close();
    return;
}

void loading_screen(bool& stop){
    static char chars[] = {'-', '\\', '|', '/'};
    unsigned int i = 0;
    while(!stop) {
            std::cout << chars[i % sizeof(chars)] << '\r';
            fflush(stdout);
            usleep(200000);
            i++;
    }
}