import java.util.*;

public class Solution {
    public int[] solution(int []arr) {
        Stack<Integer> stk = new Stack<>();
        
        for (int a : arr) {
            if (stk.isEmpty()) {
                stk.push(a);
                continue;
            }
            
            Integer top = stk.peek();
            if (top == a) continue;
            else stk.push(a);
            
        }
        
        List<Integer> list = new ArrayList<>(stk);
        
        return list.stream().mapToInt(i->i).toArray();
    }
}