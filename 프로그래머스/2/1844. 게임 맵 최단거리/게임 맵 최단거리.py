from collections import deque
    

def solution(maps):
    n = len(maps)
    m = len(maps[0])
    
    visited = [[-1] * m for _ in range(n)]
    dirs = [(1,0), (-1,0), (0,1), (0, -1)]
    
    def bfs(i, j):
        q = deque()
        q.append((i, j))
        visited[i][j] = 1
        
        while q:
            x, y = q.popleft()
            for dx, dy in dirs:
                nx, ny = x + dx, y + dy
                if 0 <= nx < n and 0 <= ny < m \
                and maps[nx][ny] == 1 \
                and visited[nx][ny] == -1:
                    visited[nx][ny] = visited[x][y] + 1
                    q.append((nx, ny))
        
    bfs(n-1, m-1)
    
    return visited[0][0]