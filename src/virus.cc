#include <windows.h>

// virus
int main(){
    ShowWindow(GetConsoleWindow(), SW_HIDE);
    const char* text = "Hi, I am Azerbaijan virus, due to poor "
    "technology in my country I not able "
    "to damage your computer, please be "
    "kind enough to smash your "
    "computer with a hammer";
    // window
    MessageBox(NULL, text, "Azerbaijan virus", MB_OK);
    return 0;
}
