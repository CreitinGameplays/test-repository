#include <iostream>
#include <fstream>
#include <string>

// declaration
std::string readFile(std::string file);

void parseInfo(std::string jsonstr){
    size_t findName = jsonstr.find("latest_stable");
    size_t findVersion = jsonstr.find("version", findName);
    size_t findColon = jsonstr.find(':', findVersion);
    size_t findQuot = jsonstr.find('\"', findColon);

    int start = findQuot + 1;
    std::string finalValue;
    while (jsonstr[start] != '\"'){
        finalValue += jsonstr[start];
        start++;
    }

    std::cout << "Latest stable linux kernel version: " << finalValue << "\n";
}

// get data
namespace linuxInfo{
    int returnData(){
        // lazy download
        #ifdef _WIN32
        std::system("curl -O https://www.kernel.org/releases.json >nul 2>&1"); 
        #else defined(__linux__)
        std::system("curl -O https://www.kernel.org/releases.json >/dev/null 2>&1");
        #endif

        std::string file = readFile("releases.json");
        parseInfo(file);
        return 0;
    }
};

// main function
int main(void){
    linuxInfo::returnData();
    return 0;
}

std::string readFile(std::string file){
    // open the goddamn file
    std::ifstream jsonfile(file);
    if(!jsonfile.is_open()){
        std::cerr << "wild file reading error\n";
    }

    std::string cur_line;
    std::string jsonStr;
    // extract each line
    while (std::getline(jsonfile, cur_line)){
        jsonStr += cur_line + '\n';
    }

    // cleanup
    jsonfile.close();
    std::remove("releases.json");
    return jsonStr;
}

// most useless program ever
