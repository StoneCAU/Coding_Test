#include <string>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <iostream>

using namespace std;

bool cmp(pair<int,int> &a, pair<int,int> &b) {
    if (a.second == b.second) return a.first < b.first;
    return a.second < b.second;
}

int solution(int k, vector<int> tangerine) {
    int answer = 0;
    int substract = tangerine.size() - k;
    int count = 0;
    int index;
    
    unordered_map<int, int> map;
    
    for(int i=0;i<tangerine.size();i++) {
        if (!map[tangerine[i]]) {
            map[tangerine[i]] = 1;
        }
        else {
            map[tangerine[i]]++;
        }
    }
    
    vector<pair<int,int>> pair(map.begin(), map.end());
    sort(pair.begin(), pair.end(), cmp);

    for (int i=0;i<pair.size();i++) {
        index = i;
        count += pair[i].second;

        if (count >= substract) {
            break;
        }
    }
    
    if (count == substract) return pair.size() - (index + 1);
    
    return pair.size() - index;
}