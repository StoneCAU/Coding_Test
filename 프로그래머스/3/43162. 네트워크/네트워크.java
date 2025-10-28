import java.util.*;

class Solution {
    
    int N;
    int[] visited;
    int[][] temp;
    int answer = 0;
    
    public void bfs(int s) {
        Queue<Integer> q = new LinkedList<>();
        q.add(s);
        
        while(!q.isEmpty()) {
            int t = q.poll();
            
            for (int i=0;i<N;++i) {
                if (i == t) continue;
                if (visited[i] == 1) continue;
                if (temp[t][i] == 0) continue;
                visited[i] = 1;
                q.add(i);
            }
            
        }
    }
    
    public int solution(int n, int[][] computers) {
        N = n;
        visited = new int[N+1];
        temp = computers;
        
        for (int i=0;i<n;++i) {
            if (visited[i] == 1) continue;
            else {
                bfs(i);
                answer++;
            }
        }
        
        return answer;
    }
}