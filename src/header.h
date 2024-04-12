#include <cstdio>
#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <thread>
#include <memory>
#include <stdexcept>
#include <string>
#include <array>
#include <string.h>
#include <filesystem>
#include <vector>
#include<bits/stdc++.h> 

#define N '\n'
#define HELP std::cout << R""""(FAST FIND
https://github.com/dmmosh/fast-find
Quick CLI naviation tool.
Usage: ff [options...] search terms...
Options:
  -l, --loose\tLoose search. Displays all results with anything remotely like the search term.
  -m, --medium\tMedium search. Displays specific results with diregard for file suffix. Default option.
  -s, --strict\tStrict search. Displays only results with exact full name.
  -pwd, --print-dir\tPrint full directory of all results. Can be turned on/off.
  -cd, --change-dir\tChange directory message. By default turned on. Can be turned on/off.

Refer to the Github repo for any potential bugs and fixes.
)"""";

// EXECUTES A COMMAND AND RETURNS ITS VECTOR
std::vector<std::string> exec(const std::string& cmd);

// CALLS THE RECURSIVE MERGE SORT
void merge_sort_call(std::vector<std::string>& arr);

// RECURSIVE MERGE SORT FUNCTION
void merge_sort(std::vector<std::string>& arr, int left, int right);

// MERGES BACK THE PIECES
void merge_sort(std::vector<std::string>& arr, int left, int middle, int right);


// PRINT A VECTOR
// mostly for debug
template<typename T>
std::ostream& operator<<(std::ostream& out, const std::vector<T>& input){
        for (unsigned int i = 0; i < input.size(); i++) //iterates over the elements
        {
            if(i) out << " "; //adds a space to before printing if not first element
            out << input[i];
        }
        
        return out;
};
void loading_screen(bool& stop);
