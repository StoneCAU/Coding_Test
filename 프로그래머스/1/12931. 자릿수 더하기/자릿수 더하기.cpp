#include <iostream>

using namespace std;
int solution(int n)
{
    int answer = 0;
    int temp = 10;
    
    while (n != 0) {
        answer += n % temp;
        n /= temp;
    }

    return answer;
}