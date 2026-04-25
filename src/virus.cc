#define WIN32_LEAN_AND_MEAN
#include <windows.h>

// main virus
int main(){
    ShowWindow(GetConsoleWindow(), SW_HIDE); // ouch we can't hijack the user, so we fail
    const char* text = "Hi, I am Azerbaijan virus, due to poor "
    "technology in my country I am not able "
    "to damage your computer, please be "
    "kind enough to smash your "
    "computer with a hammer";

    MessageBox(NULL, text, "Virus Alert !", MB_OKCANCEL | MB_ICONERROR);
    return 0;
}
