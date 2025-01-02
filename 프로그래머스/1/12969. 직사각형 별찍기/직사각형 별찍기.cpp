#include <iostream>

using namespace std;

int main(void) {
    int a;
    int b;
    cin >> a >> b;

    int count = 0;
    for (int i = 0; i < b; i++) {
        for (int j = 0; j < a; j++) {
            cout << '*';
            count++;
        }
        if (count % a == 0) {
            cout << endl;
        }
    }
    
    return 0;
}