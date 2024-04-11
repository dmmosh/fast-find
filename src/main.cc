#include "header.h"

/*
FAST FIND
cli tool for quickly searching files

manual compile:
g++ src/main.cc src/utils.cc -o fast-find;
*/


int main(int argc, char* argv[]){
    //std::cout << exec("find . -type f -iname \"*.cc*\" 2>/dev/null");
    char loose = '\0'; // loose search, default is empty
    bool pwd = false; // whether to print the working directory
    bool cd = true; // whether to cd command
    // iterates over passed parameters
    for (size_t i = 1; i < argc; i++)
    {
        

        std::string input = argv[i];
        if(input == "-l" || input == "--loose"){ //specifies looseness of search
            loose = '*'; // assigns loose to asterisk

        } else if (input == "-s" || input == "--strict"){ //specifies strictness of search
            loose= '\0'; //sets loose to nothing

        } else if (input == "-pwd" || input == "--print-work-dir"){ //if user wants to print the working directory
            pwd = true; //assign to true

        } else if (input == "-cd" || input == "--change-dir"){ //if want to change dir
            cd = (cd) ? false : true; //turns cd on/off if it's already on/off

        } else {

        std::string print_input = input;
        std::transform(print_input.begin(), print_input.end(), print_input.begin(), ::toupper); 
        std::cout << "\nVARIABLE  " << print_input << ((loose != '\0') ? "  (LOOSE)" : "  (STRICT)") << ":\n";

        
        if(loose != '\0') { // if loose is NOT null terminator, aka search is LOOSE
            input.push_back(loose); //inserts loose asterisk in end
            input.insert(input.begin(), loose); // inserts loose asterisk in beginning
            input.insert(0, "-iname \""); // inserts -iname, case INSENSITIVE
        } else { // if strict
            input.insert(0, "-name \""); // inserts -name, case SENSITIVE
        }
        input.push_back('\"'); // adds a closing bracket

        // runs the linux command
        std::vector <std::string> arr_file = exec("find . -type f " + input + " 2>/dev/null");
        std::vector <std::string> arr_dir = exec("find . -type d " + input + " 2>/dev/null");

        int total = arr_file.size() + arr_dir.size(); // the total # of elements
        int iterated = 0; //iterated counter
        
        if (arr_file.empty() && arr_dir.empty()){ //if both vectors are empty
            std::cout << "\tNo files/directories found.\n"; // prints message
            continue; // skips to the next element
        }
        
        if (!arr_file.empty()){ // if there's files
            if(arr_file.size() > 1) merge_sort(arr_file); //sorts the output files, if more than 1 element
            std::cout << "FILES:";
            for(const std::string& out: arr_file){
                std::cout << N << total - iterated++ << "\t" << ((pwd) ? exec("pwd \"" + out + "\"")[0] + out.substr(1) : out);
            }
            std::cout << N;
        }
        
        if (!arr_dir.empty()){ // if theres directories
            if(arr_dir.size() > 1) merge_sort(arr_dir); //sorts the output files, if more than 1 element
            std::cout << "DIRECTORIES:";
            for(const std::string& out: arr_dir){
                std::cout << N <<  total - iterated++ << "\t" << ((pwd) ? exec("pwd \"" + out + "\"")[0] + out.substr(1) : out);
            }
            std::cout << N;
        }

        if(cd) {
            std::string input; // the input
            std::cout << "cd? [number 1-" << total << " / No]:  "; //enters a number to change directory to
            std::cin >> input; // takes input
            std::transform(input.begin(), input.end(), input.begin(), ::tolower); //make input lowercase
            if (input == "no" || input == "n") { // if user types no
                continue;
            }
            if (!isdigit(atoi(input.c_str()))) { // if the input is invalid character
                std::cout << "\tInvalid number.\n"; 
                continue;
            }
            int cd_loc = atoi(input.c_str()); //change directory to

        }
        //merge_sort(arr_dir);
        //std::cout << arr_file << N << arr_dir;
        }
    }
    
    return 0;
}