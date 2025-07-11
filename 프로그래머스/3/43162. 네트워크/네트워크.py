def bfs(node, computers, visited):
    visited[node] = True
    for tmp in range(len(computers)):
        if not visited[tmp] and computers[node][tmp] == 1:
            bfs(tmp, computers, visited)

def solution(n, computers):
    visited = [False] * n
    answer = 0
    
    for i in range(n):
        if not visited[i]:
            bfs(i, computers, visited)
            answer += 1
    
    return answer