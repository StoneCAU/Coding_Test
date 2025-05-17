import java.util.*;

class Solution {
    public String solution(String[] participant, String[] completion) {        
        HashMap<String, Integer> par = new HashMap<>();
        
        for (String p : participant) {
            par.put(p, par.getOrDefault(p, 0) + 1);
        }
        
        for (String c : completion) {
            par.put(c, par.get(c) - 1);
        }
        
        for (String key : par.keySet()) {
            if (par.get(key) > 0) return key;
        }

        return "";
    }
}