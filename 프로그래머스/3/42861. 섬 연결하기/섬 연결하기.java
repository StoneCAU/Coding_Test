import java.util.*;

class Solution {
    int[] parent = new int[101];
    int cnt = 0;
    int tot = 0;
    
    public int solution(int n, int[][] costs) {  
        // 코스트 작은 순으로 정렬하기
        Arrays.sort(costs, (a, b) -> Integer.compare(a[2], b[2]));
        
        // 부모 집합 set
        for (int i=0;i<n;i++) {
            parent[i] = i;
        }
        
        // 유니온 파인드 진행 
        int idx = 0;
        int len = costs.length;
        
        while (true) {
            if (cnt == n - 1) break;
            
            int[] cost = costs[idx];
            int from = cost[0];
            int to = cost[1];
            int val = cost[2];
            
            union(from, to, val);
            
            idx = (idx + 1) % len;
        }
        
        
        return tot;
    }
    
    
    int find(int x) {
        if (parent[x] != x) {
            parent[x] = find(parent[x]);
        }
        return parent[x];
    }
    
    void union(int a, int b, int val) {
        int root1 = find(a);
        int root2 = find(b);
        
        if (root1 != root2) {
            parent[root2] = root1;
            cnt++;
            tot += val;
        }
    }
}