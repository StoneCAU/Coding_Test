#include <string>
#include <vector>

using namespace std;

vector<vector<int>> solution(vector<vector<int>> arr1, vector<vector<int>> arr2) {
    vector<vector<int>> answer;
    
    int n = arr1.size();
    int m = arr2[0].size();
    int t = arr1[0].size();
    
    for (int i=0;i<n;i++) {
        vector<int> v;
        for (int j=0;j<m;j++) {
            int sum = 0;
            for (int k=0;k<t;k++) {
                sum += arr1[i][k] * arr2[k][j];
            }                
            v.push_back(sum);

        }
        answer.push_back(v);
    }
    
    return answer;
}