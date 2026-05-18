#include <iostream>
#include <fstream>
#include <string>

// declaration
void parseInfo(std::string jsonstr){
    size_t findName = jsonstr.find("latest_stable");
    if (findName == std::string::npos) throw std::runtime_error("Could not find latest_stable.\n");
    size_t findVersion = jsonstr.find("version", findName);
    if (findVersion == std::string::npos) throw std::runtime_error("Could not find version.\n");
    size_t findColon = jsonstr.find(':', findVersion);
    if (findColon == std::string::npos) throw std::runtime_error("Failure on findColon.\n");
    size_t findQuot = jsonstr.find('\"', findColon);
    if (findQuot == std::string::npos) throw std::runtime_error("Failure on findQuot.\n");

    int start = findQuot + 1;
    std::string finalValue;
    while (jsonstr[start] != '\"'){
        finalValue += jsonstr[start];
        start++;
    }

    std::cout << "Latest stable linux kernel version: " << finalValue << "\n";
}

std::string cmd(std::string command){
    char b[256]; // the buffer
    std::string final_output = "";
    FILE* file = popen(command.c_str(), "r"); // "r" = read
    if (!file){
        throw std::runtime_error("Insane error on cmd()! Popen error.\n"); 
    }
    while(fgets(b, sizeof(b), file) != NULL){
        final_output += b; // append to the variable
    }
    pclose(file);
    return final_output;
}

// get data
namespace linuxInfo{
    int returnData(){
        // lazy curl
        #ifdef _WIN32
        std::string command = cmd("curl.exe -sS https://www.kernel.org/releases.json");
        #else defined(__linux__)
        std::string command = cmd("curl -sS https://www.kernel.org/releases.json");
        #endif
        parseInfo(command);
        return 0;
    }
};

// main function
int main(void){
    try{
        linuxInfo::returnData();
    } catch (const std::exception &e){
        std::cerr << "Error: " << e.what() << "\n";
        return EXIT_FAILURE;
    }
    return 0;
}

// most useless program ever
