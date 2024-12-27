#include <iostream>
#include <string>
#include <cctype>
    
using std::cout;
using std::endl;
using std::string;
using std::cin;

void ChangeString(string &str) {
    for(int i = 0; i < str.size(); i++){
        if(isupper(str[i])){
           
            str[i] = tolower(str[i]);
                
        } else if(islower(str[i])) {
     
            str[i] = toupper(str[i]);
                
        }
    }
    cout << str << endl;
}

int main(void) {
    string str;
    cin >> str;
    
    ChangeString(str);
    
    return 0;
}