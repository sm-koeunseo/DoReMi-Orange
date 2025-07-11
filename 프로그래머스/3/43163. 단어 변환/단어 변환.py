from collections import deque

def solution(begin, target, words):
    if target not in words:
        return 0
    
    visited = set([begin])
    
    def bfs():
        q = deque()
        q.append((begin, 0))
        
        while q:
            w, step = q.popleft()
            if (w == target):
                return step
            
            for nw in words:
                if nw not in visited and sum(1 for x, y in zip(w, nw) if x != y) == 1:
                    visited.add(nw)
                    q.append((nw, step + 1))
        
        return step
    
    return bfs()