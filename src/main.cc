#include "header.h"

/*
FAST FIND
cli tool for quickly searching files

manual compile:
g++ -std=c++20 src/main.cc src/utils.cc -o ./fast-find_/exec;

debug:
./uninstall.sh; ./install.sh

*/


int main(int argc, char* argv[]){
    if (argc <=1){ //if no args 
        std::cout << R""""(FAST FIND
        https://github.com/dmmosh/fast-find
        Quick CLI naviation tool.
        Usage: ff [options...] search terms...
        Options:
          -l, --loose       Loose search. Displays all results with anything remotely like the search term.
          -m, --medium      Medium search. Displays specific results with diregard for file suffix. Default option.
          -s, --strict      Strict search. Displays only results with exact full name.
          -pwd, --print-dir Print full directory of all results. Can be turned on/off.
          -cd, --change-dir Change directory message. By default turned on. Can be turned on/off.

        Refer to the Github repo for any potential bugs and fixes.
        )"""" << N;
        return 0;
    }

    //std::cout << exec("find . -type f -iname \"*.cc*\" 2>/dev/null");
    char loose_left = '\0'; // loose search, default is empty
    char loose_right = '*'; //loose search, default is asterisk
    bool pwd = false; // whether to print the working directory
    bool cd = true; // whether to cd command, default true

    int iterated = 1; //iterated counter
    std::vector<std::string> results; // vector of pointers, 2d vector

    // iterates over passed parameters
    for (size_t i = 1; i < argc; i++)
    {
        
        std::string input = argv[i];
        if(input == "-l" || input == "--loose"){ //specifies looseness of search
            loose_left = '*'; 
            loose_right= '*';

        } else if (input == "-m" || input == "--medium"){  // specified mediumness of search
            loose_left= '\0';
            loose_right= '*';

        } else if (input == "-s" || input == "--strict"){ //specifies strictness of search
            loose_left= '\0'; 
            loose_right = '\0';

        } else if (input == "-pwd" || input == "--print-dir"){ //if user wants to print the working directory
            pwd = (pwd) ? false :true; //turns pwd on/off

        } else if (input == "-cd" || input == "--change-dir"){ //if want to change dir
            cd = (cd) ? false : true; //turns cd on/off if it's already on/off

        } else { // actually looks

        std::string print_input = input;
        std::transform(print_input.begin(), print_input.end(), print_input.begin(), ::toupper); 
        if (!loose_left && !loose_right) // if neither is * (STRICT)
        {
            print_input += " (STRICT):\n"; //adds to print input
            input.insert(0, "-name \""); // inserts -name, case SENSITIVE

        }
        else if(!loose_left){ // if right is * (MEDIUM)
            print_input += "  (MEDIUM):\n"; //adds to print input
            input.insert(0, "-iname \""); // inserts -iname, case INSENSITIVE
            input.push_back(loose_right); //inserts loose asterisk in end

        }else { // if BOTH are * (LOOSE)
            print_input += " (LOOSE):\n"; //adds to print input
            input.insert(input.begin(), loose_left); // inserts loose asterisk in beginning
            input.insert(0, "-iname \""); // inserts -iname, case INSENSITIVE
            input.push_back(loose_right); //inserts loose asterisk in end

        }
        input.push_back('\"'); // adds a closing bracket
        

        std::cout << "VARIABLE  " << print_input;

        
        // runs the linux commands
        // and allocates the output vectors in dynamically allocated memory
        bool stop_file = false;
        std::jthread load_file(loading_screen, std::ref(stop_file));
        std::vector <std::string> arr_file = exec("find . -type f " + input + " 2>/dev/null");

        bool stop_dir = false;
        std::jthread load_dir(loading_screen, std::ref(stop_dir));

        std::vector <std::string> arr_dir = exec("find . -type d " + input + " 2>/dev/null");

        
        if (arr_file.empty() && arr_dir.empty()){ //if both vectors are empty
            stop_file = true; //stops the loading wheel
            load_file.join(); //joins the thread
            stop_dir = true; //stops the dir
            load_dir.join(); // joins the thread
            std::cout << "\tNo files/directories found.\n"; // prints message
            continue; // skips to the next element
        }
        
        if (!arr_file.empty()){ // if there's files
            if((arr_file).size() > 1) {
                std::jthread file_merge(merge_sort_call, std::ref(arr_file));
            } 
            results.insert(results.end(), arr_file.begin(), arr_file.end());

            stop_file = true; //stops the loading wheel
            load_file.join(); //joins the thread

            std::cout << "\r\r\tFILES:";
            for(const std::string& out: (arr_file)){
                std::cout << N << iterated++ << "\r\t" << ((pwd) ? exec("pwd \"" + out + "\"")[0] + out.substr(1) : out);
            }
            std::cout << N;
        } else {
            stop_file = true; //stops the loading wheel
            load_file.join(); //joins the thread
        }
        
        if (!arr_dir.empty()){ // if theres directories
            if((arr_dir).size() > 1) {
                std::jthread file_merge(merge_sort_call, std::ref(arr_dir));
            } 
            results.insert(results.end(), arr_dir.begin(), arr_dir.end());
            stop_dir = true; //stops the dir
            load_dir.join(); // joins the thread

            std::cout << "\r\r\tDIRECTORIES:";
            for(const std::string& out: (arr_dir)){
                std::cout << N << iterated++ << "\t" << ((pwd) ? exec("pwd \"" + out + "\"")[0] + out.substr(1) : out);
            }
            std::cout << N;
        } else {
            stop_dir = true; //stops the dir
            load_dir.join(); // joins the thread
        }

        
        //merge_sort((arr_dir));
        //std::cout << (arr_file) << N << (arr_dir);
        }
    }
    if (cd && !results.empty()) { //loop to exit out of at will (lots of if statements)
            std::string input = ""; // the input
            if (results.size() == 1){
                std::cout << "cd? [Yes / No]:  "; // if onlt 1 total
            } else {
                std::cout << "cd? [number 1-" << results.size() << " / No]:  "; //enters a number to change directory to
            }
            std::getline(std::cin, input);

            std::transform(input.begin(), input.end(), input.begin(), ::tolower); //make input lowercase

            if (input == "no" || input == "n") { // if user types no
                return 0;
            } else if (input == "yes" || input == "y"){ //if user says yes, set input to 1
                input = "1"; //sets input
            } else if (input == ""){ //if blank input, bottom location is cd into
                input = std::to_string(results.size());
            }

            char* invalid; //invalid/valid pointer
            long cd_loc = strtol(input.c_str(), &invalid, 10); // converts string to int
            if(*invalid){ // if input is invalid
                std::cout << "\tInvalid number.\n"; 
                return 0;
            }
            if(cd_loc > results.size() || cd_loc < 1){ //if input is bigger than the # of elements
                std::cout << "\tInput out of bounds.\n";
                return 0;
            }
            //system( ("cd " + (*(results[data_i]))[cd_loc-end_i[data_i]]).c_str() );
            
            system(("echo \"$(realpath "+ std::regex_replace(results[cd_loc-1], std::regex(" "), "\\ ") +")\" > ~/.fftmp").c_str());
            //std::filesystem::current_path("./src");    // change directory

            //std::cout << exec("if [[ -f \"" + location + "\" ]]; then cd $(dirname \"" + location + "\"); else cd \"" + location + "\"; fi;");
    }
}