#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

int solution(vector<string> want, vector<int> number, vector<string> discount) {
    int answer = 0;
    
    for (int i=0;i<discount.size();i++) {
        unordered_map<string,int> m;
        int count = 0;
        
        for (int j=i;j<discount.size();j++) {
            count++;
            
            string product = discount[j % discount.size()];
            
            if (!m[product]) m[product] = 1;
            else m[product]++;
            
            if (count == 10) break;
        }
        
        bool satify = true;
        
        for (int j=0;j<want.size();j++) {
            string product = want[j];
            int quantity = number[j];
            
            if (m[product] < quantity) {
                satify = false;
                break;
            }
        }
        
        if (satify) answer++;
    }
    
    
    return answer;
}