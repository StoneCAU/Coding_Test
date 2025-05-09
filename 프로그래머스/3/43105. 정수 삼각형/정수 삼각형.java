import java.util.*;

// j=0 -> 0, j=1 ->0,1, j=2 ->1,2...
class Solution {
    public int solution(int[][] triangle) {
        int answer = 0;
        
        for (int i=triangle.length-2;i>=0;i--) {
            for (int j=0;j<triangle[i].length;j++) {
                triangle[i][j] = Math.max(triangle[i][j] + triangle[i+1][j], 
                                          triangle[i][j] + triangle[i+1][j+1]);
            }
        }
        
        answer = triangle[0][0];
        
        return answer;
    }
}