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
    bool cd = true; // whether to cd command, default true

    int total = 0; // the total # of elements
    int iterated = 1; //iterated counter
    std::vector<std::vector<std::string>*> vector_ptr; // vector of pointers, 2d vector

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

        // runs the linux commands
        // and allocates the output vectors in dynamically allocated memory
        std::vector <std::string>* arr_file = new std::vector <std::string>(exec("find . -type f " + input + " 2>/dev/null"));
        std::vector <std::string>* arr_dir = new std::vector <std::string>(exec("find . -type d " + input + " 2>/dev/null"));

        vector_ptr.push_back(arr_file);
        vector_ptr.push_back(arr_dir);
        
        
        if ((*arr_file).empty() && (*arr_dir).empty()){ //if both vectors are empty
            std::cout << "\tNo files/directories found.\n"; // prints message
            continue; // skips to the next element
        }
        
        if (!(*arr_file).empty()){ // if there's files
            total += (*arr_file).size();
            if((*arr_file).size() > 1) merge_sort((*arr_file)); //sorts the output files, if more than 1 element
            std::cout << "\tFILES:";
            for(const std::string& out: (*arr_file)){
                std::cout << N << iterated++ << "\t" << ((pwd) ? exec("pwd \"" + out + "\"")[0] + out.substr(1) : out);
            }
            std::cout << N;
        }
        
        if (!(*arr_dir).empty()){ // if theres directories
            total += (*arr_dir).size();
            if((*arr_dir).size() > 1) merge_sort((*arr_dir)); //sorts the output files, if more than 1 element
            std::cout << "\tDIRECTORIES:";
            for(const std::string& out: (*arr_dir)){
                std::cout << N << iterated++ << "\t" << ((pwd) ? exec("pwd \"" + out + "\"")[0] + out.substr(1) : out);
            }
            std::cout << N;
        }

        
        //merge_sort((*arr_dir));
        //std::cout << (*arr_file) << N << (*arr_dir);
        }
    }
    if(cd && total) {
            std::string input; // the input
            if (total == 1){
                std::cout << "cd? [Yes / No]:  "; // if onlt 1 total
            } else {
                std::cout << "cd? [number 1-" << total << " / No]:  "; //enters a number to change directory to
            }
            std::cin >> input; // takes input
            std::transform(input.begin(), input.end(), input.begin(), ::tolower); //make input lowercase

            if (input == "no" || input == "n") { // if user types no
                return 0;
            } else if (input == "yes" || input == "y"){ //if user says yes, set input to 1
                input = "1"; //sets input
            }

            char* invalid; //invalid/valid pointer
            int cd_loc = strtol(input.c_str(), &invalid, 10); // converts string to int
            if(*invalid){
                std::cout << "\tInvalid number.\n"; 
                return 0;
            }
            if(cd_loc > total){
                std::cout << "\tInput out of bounds.\n";
                return 0;
            }
            std::cout << cd_loc << N;


        }

        for (size_t i = 0; i < vector_ptr.size(); i++)
        {
            std::cout << *(vector_ptr[i]);
            delete vector_ptr[i]; //frees the memory
        }
        
    
    
    return 0;
}