#include <iostream>
#include <fstream>
#include <string>
#include <print>
#include <memory>

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

    std::println("Latest stable linux kernel version: {}", finalValue);
}

// better cmd function
std::string cmd(std::string command){
    std::array<char, 256> b; // buffer
    std::string final_output = "";
    std::unique_ptr<FILE, decltype(&pclose)> file(popen(command.c_str(), "r"), pclose); // pipe

    if (!file){
        throw std::runtime_error("Insane error on cmd()! Popen error.\n"); 
    }
    while(fgets(b.data(), b.size(), file.get()) != nullptr){
        final_output += b.data(); // append to the variable
    }
    return final_output;
}

// get data
namespace linuxInfo{
    int returnData(){
        // lazy curl
        #if defined(_WIN32)
        std::string command = cmd("curl.exe -sS https://www.kernel.org/releases.json");
        #elif defined(__linux__)
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
        std::println("Error: {}", e.what());
        return EXIT_FAILURE;
    }
    return 0;
}

// most useless program ever
