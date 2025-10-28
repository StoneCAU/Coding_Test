import java.util.*;

class Solution {
    
    int num;
    int[] temp;
    int answer = 0;
    
    public void dfs(int idx, int sum) {
        if (idx == temp.length) {
            if (sum == num) answer++;
            return;
        }
        
        dfs(idx+1, sum + temp[idx]);
        dfs(idx+1, sum - temp[idx]);
    }
     
    public int solution(int[] numbers, int target) {
        temp = numbers;
        num = target;
        
        dfs(0, 0);
        
        return answer;
    }
}