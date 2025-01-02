#include <string>
#include <vector>
#include <cmath>

using namespace std;

long long solution(long long n) {
    long long answer = 0;
            
    if ((long long) sqrt(n) * (long long) sqrt(n) == n) {
        return (long long) pow(sqrt(n)+1, 2);
    }
    
    return -1;
}