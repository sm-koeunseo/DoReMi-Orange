class Solution {
    boolean[] visited = new boolean[201];
    
    void bfs(int i, int[][] computers){
        visited[i] = true;
        for (int j=0; j<computers[i].length; j++){
            if (visited[j] == false && computers[i][j] == 1)
                bfs(j, computers);
        }
    }
    
    public int solution(int n, int[][] computers) {
        int answer = 0;
        
        for (int i=0; i<computers.length; i++){
            if (visited[i]) continue;
            bfs(i, computers);
            answer++;
        }
        
        return answer;
        
    }
}