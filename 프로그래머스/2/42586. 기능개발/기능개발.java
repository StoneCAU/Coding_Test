import java.util.*;
import java.io.*;
class Solution {
    public int[] solution(int[] progresses, int[] speeds) {
        int[] answer = {};
        List<Integer> temp = new ArrayList<>();
        
        int day = (100 - progresses[0] + speeds[0] - 1) / speeds[0];
        int cnt = 1;
        for (int i=1;i<progresses.length;++i) {
            progresses[i] += speeds[i] * day;
            
            if (progresses[i] >= 100) {
                cnt++;
            }
            else {
                int newDay = (100 - progresses[i] + speeds[i] - 1) / speeds[i];
                day += newDay;
                temp.add(cnt);
                cnt = 1;
            }
            
        }
        
        if (cnt > 0) temp.add(cnt);
        answer = temp.stream().mapToInt(Integer::intValue).toArray();
        
        return answer;
    }
}