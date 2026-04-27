#include <iostream>
#include <bitset>

int main() {
    unsigned int x = 0b000000101; // 5
    unsigned int y = 0b000000111; // 7
    
    std::cout << std::bitset<8>(x).to_ulong() << '\n';
    std::cout << std::bitset<8>(y).to_ulong() << '\n';
    return 0;
}
