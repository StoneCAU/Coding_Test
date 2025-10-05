#include <bits/stdc++.h>
using namespace std;

int solution(int cacheSize, vector<string> cities) {
    if (cacheSize == 0) return 5 * cities.size();

    int answer = 0;
    list<string> cache;
    unordered_set<string> cacheSet;

    for (auto city : cities) {
        for (auto &c : city) c = tolower(c);

        // cache hit
        if (cacheSet.count(city)) {
            cache.remove(city);
            cache.push_back(city);
            answer += 1;
        } 
        // cache miss
        else {
            if (cache.size() == cacheSize) {
                cacheSet.erase(cache.front());
                cache.pop_front();
            }
            cache.push_back(city);
            cacheSet.insert(city);
            answer += 5;
        }
    }

    return answer;
}