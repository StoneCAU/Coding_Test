import java.util.*;
import java.io.*;

class Solution {
    public int solution(int[][] routes) {
        int answer = 0;
        
        // 도착점 기준 오름차순 정렬
        Arrays.sort(routes, (a,b) -> Integer.compare(a[1], b[1]));
        
        int idx = 0;
        int len = routes.length;
        
        while (idx < len) {       
            // 카메라 한 대 추가
            answer++;
                        
            // 선택
            int sel = routes[idx++][1];    
            System.out.println(sel);
            
            // 다음 것들 얼마나 커버치는 지 확인
            for (int i=idx;i<len;i++) {
                int s = routes[i][0];
                int e = routes[i][1];
                                                
                if (sel >= s && sel <= e) {
                    if (i == len - 1) return answer;
                    continue;
                }
                else {
                    idx = i;
                    break;
                }
            }
        }
        
        return answer;
    }
}