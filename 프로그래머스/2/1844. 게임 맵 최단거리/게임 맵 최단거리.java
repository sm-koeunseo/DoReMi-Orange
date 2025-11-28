import java.util.*;

class Solution {
    
    public int solution(int[][] maps) {
        int[] dx = {1, -1, 0, 0};
        int[] dy = {0, 0, 1, -1};
        
        int n = maps.length;
        int m = maps[0].length;
        
        int[][] visited = new int[n][m];
        for (int i = 0; i < n; i++) Arrays.fill(visited[i], -1);
        Queue<int[]> q = new LinkedList<>();
        
        q.add(new int[]{n-1,m-1});
        visited[n-1][m-1] = 1;
        
        while(!q.isEmpty()){
            int[] cur = q.poll();
            int x = cur[0];
            int y = cur[1];
            if (x == 0 && y == 0){
                break;
            }
            
            for (int i=0; i<4; i++){
                int nx = x + dx[i];
                int ny = y + dy[i];
                
                if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
                if (maps[nx][ny] == 0 || visited[nx][ny] > -1) continue;
                visited[nx][ny] = visited[x][y] + 1;
                q.add(new int[]{nx, ny});
            }
        }
        
        return visited[0][0];
    }
}