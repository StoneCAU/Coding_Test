#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

bool cmp(pair<int, int> &a, pair<int, int> &b) {
    if (a.second != b.second) {
        return a.second > b.second;
    }
    return a.first < b.first;
}

bool strcmp(pair<string, int> &a, pair<string, int> &b) {
    if (a.second != b.second) {
        return a.second > b.second;
    }
    return a > b;
}

vector<int> solution(vector<string> genres, vector<int> plays) {
    vector<int> answer;
    
    // 장르, 총 횟수
    unordered_map<string, int> total_plays_map;
    
    // 고유번호, 장르
    unordered_map<int, string> order_map;
    
    for (int i=0;i<genres.size();i++) {
        total_plays_map[genres[i]] += plays[i];
        order_map[i] = genres[i];
    }
    
    // 장르, 총 횟수 - 내림차순으로 정렬
    vector<pair<string, int>> total_plays_vector(total_plays_map.begin(), total_plays_map.end());
    sort(total_plays_vector.begin(), total_plays_vector.end(), strcmp);
    
    // 고유번호, 장르
    vector<pair<int, string>> order_vector(order_map.begin(), order_map.end());
    
    for (int i=0;i<total_plays_vector.size();i++) {
        // 고유번호, 횟수
        vector<pair<int, int>> order;
        
        for (int j=0;j<order_vector.size();j++) {
            if (order_vector[j].second == total_plays_vector[i].first) 
                order.push_back({order_vector[j].first, plays[order_vector[j].first]});
        }
        
        // 내림차순 정렬
        sort(order.begin(), order.end(), cmp);
                
        // 추가
        int count = 0;

        for (int i=0;i<order.size();i++) {
            answer.push_back(order[i].first);
            count++;
            
            if (count == 2) break;
        }
    }
    
    return answer;
}