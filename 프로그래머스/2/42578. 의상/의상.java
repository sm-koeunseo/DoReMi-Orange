import java.util.*;

class Solution {
    public int solution(String[][] clothes) {
        Map<String, Integer> map = new HashMap<String, Integer>();
        
        for (int i=0; i<clothes.length; i++){
            map.put(clothes[i][1], map.getOrDefault(clothes[i][1], 0) + 1);
        }
        
        int mul = 1;
        for (int num : map.values()){
            mul *= num + 1;
        }
        
        return mul - 1;
    }
}