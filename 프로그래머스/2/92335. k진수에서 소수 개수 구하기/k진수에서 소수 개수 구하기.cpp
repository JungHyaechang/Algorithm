#include <string>
#include <vector>
#include <cmath>

using namespace std;


bool isPrime(long long num) {
    if (num < 2) return false;
    for (long long i = 2; i <= sqrt(num); ++i) {
        if (num % i == 0) return false;
    }
    return true;
}


string convertToBase(long long n, int k) {
    string result;
    while (n > 0) {
        result = to_string(n % k) + result;
        n /= k;
    }
    return result;
}

int solution(int n, int k) {
    string baseK = convertToBase(n, k);
    int count = 0;
    string part;

    for (char c : baseK) {
        if (c == '0') {
            if (!part.empty()) {
                if (part.find('0') == string::npos) { 
                    long long number = stoll(part);
                    if (isPrime(number)) {
                        ++count;
                    }
                }
                part.clear();
            }
        } else {
            part += c;
        }
    }

   
    if (!part.empty() && part.find('0') == string::npos) {
        long long number = stoll(part);
        if (isPrime(number)) {
            ++count;
        }
    }

    return count;
}