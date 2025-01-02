#include <string>
#include <vector>
#include <iostream>

using namespace std;

int getOneNumber(int n) {
    int count = 1;
    
    while(n != 1) {
        if (n % 2 == 1) count++;
        n /= 2;
    }
    
    return count;
}

int solution(int n) {
    int count = getOneNumber(n);
    
    n++;
    
    while(getOneNumber(n) != count) {
        n++;
    }
    
    
    return n;
}