import java.util.*;

class Solution {
    boolean[] used;
    List<String> path = new ArrayList<>();
    List<String> answer = null;
    
    public String[] solution(String[][] tickets) {
        Arrays.sort(tickets, (a, b) -> {
            if (a[0].equals(b[0])) {
                return a[1].compareTo(b[1]);
            }
            return a[0].compareTo(b[0]);
        });
        
        used = new boolean[tickets.length];
        path.add("ICN");
        
        dfs("ICN", tickets, 0);
        
        return answer.toArray(new String[0]);
    }
    
    private void dfs(String cur, String[][] tickets, int depth) {
        if (depth == tickets.length) {
            answer = new ArrayList<>(path);
            return;
        }
        
        for (int i=0;i<tickets.length;i++) {
            if (!used[i] && tickets[i][0].equals(cur)) {
                used[i] = true;
                path.add(tickets[i][1]);
                
                dfs(tickets[i][1], tickets, depth + 1);
                if (answer != null) return;
                
                used[i] = false;
                path.remove(path.size()-1);
            }
        }
    }
}