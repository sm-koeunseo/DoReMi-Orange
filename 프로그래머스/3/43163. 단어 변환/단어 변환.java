import java.util.*;

class Solution {
    boolean check(String a, String b){
        int diff = 0;
        for (int i=0; i<a.length(); i++){
            if (a.charAt(i) != b.charAt(i)) diff++;
            if (diff > 1) return false;
        }
        return diff == 1;
    }
    
    public int solution(String begin, String target, String[] words) {
        int[] visited = new int[words.length];
        Arrays.fill(visited, -1);
        
        Queue<Integer> q = new ArrayDeque<>();
        for (int i=0; i<words.length; i++){
            if (check(begin, words[i])){
                q.offer(i);
                visited[i] = 1;
            }
        }
        
        while(!q.isEmpty()){
            int n = q.poll();
            if (words[n].equals(target)){
                return visited[n];
            }
            
            for (int i=0; i<words.length; i++){
                if (visited[i] == -1 && check(words[n], words[i])){
                    q.offer(i);
                    visited[i] = visited[n] + 1;
                }
            }
        }
        
        return 0;
    }
}