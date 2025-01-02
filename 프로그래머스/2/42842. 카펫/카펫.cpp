#include <string>
#include <vector>

using namespace std;

vector<int> solution(int brown, int yellow) {
    vector<int> answer;
    
    int area = brown + yellow;

    for(int width=area;width>=3;width--) {
        if (area % width != 0) continue;
        
        int height = area / width;
        
        if (height > width) continue;
        if ((width-2) * (height-2) != yellow) continue;
        
        answer.push_back(width);
        answer.push_back(height);
        
        break;
    }
    
    return answer;
}