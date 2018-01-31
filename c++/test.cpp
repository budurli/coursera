#include <iostream>

using namespace std;

void ovfb(char *arg){
    int authenticated = 0;
    char buffer[0];
    strcpy(buffer, arg);
    if (authenticated){
        cout << "authenticated" << endl;
    } else {
        cout << "NOT authenticated" << endl;
    }
}

int main(int argc, char const *argv[])
{
    char *str = "AuthMe!";
    ovfb(str);

    return 0;
}