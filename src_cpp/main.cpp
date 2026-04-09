#include <iostream>
using string = std::string;
int main() {
  string name {};
  std::cout << "Simple test code\n";
  std::getline(cin, string);
  std::cout << "You said: " << name << '\n';
  return 0;
}
