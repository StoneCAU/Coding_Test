#include <vector>
#include <unordered_map>
#include <algorithm>
#include <iostream>
using namespace std;

bool cmp(pair<int,int> &a, pair<int,int> &b) {
    if (a.second == b.second) return a.first > b.first;
    return a.second > b.second;
} 

int solution(vector<int> nums)
{
    int answer = 0;
    int sum = 0;
    
    unordered_map<int,int> map;
    
    for(int i=0;i<nums.size();i++) {
        if (!map[nums[i]]) {
            map[nums[i]] = 1;
        }
        else map[nums[i]]++;
    }
    
    vector<pair<int,int>> v(map.begin(), map.end());
    sort(v.begin(), v.end(), cmp);
    
    for(int i=0;i<v.size();i++) {
        while (v[i].second != 1) {
            sum++;
            v[i].second--;
            if (sum == nums.size() / 2) break;
        }
        
        if (sum == nums.size() / 2) return v.size();
    }
    
    if (sum != nums.size()) return v.size() - (nums.size() / 2 - sum);

}