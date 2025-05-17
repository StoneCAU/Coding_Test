import java.util.*;

class Solution {
    public int[] solution(int[] progresses, int[] speeds) {
        List<Integer> res = new ArrayList<>();
        Queue<Integer> q = new LinkedList<>();
        
        for (int i=0;i<progresses.length;i++) {
            int remain = 100 - progresses[i];
            int day = (int) Math.ceil(remain / (double) speeds[i]);
            q.offer(day);
        }
        
        while(!q.isEmpty()) {
            int cur = q.poll();
            int cnt = 1;
            
            while (!q.isEmpty() && q.peek() <= cur) {
                q.poll();
                cnt++;
            }
            
            res.add(cnt);
        }
        
        return res.stream().mapToInt(i->i).toArray();
    }
}