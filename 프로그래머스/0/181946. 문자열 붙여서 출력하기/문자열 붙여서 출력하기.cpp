#include <iostream>
#include <string>

using namespace std;

int main(void) {
    string str1, str2;
    cin >> str1 >> str2;
    cout << str1;
    cin >> std::ws;
    cout << str2;

    return 0;
}