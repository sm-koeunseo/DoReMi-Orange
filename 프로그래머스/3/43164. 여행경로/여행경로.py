def solution(tickets):
    tickets.sort()
    used = [False] * len(tickets)
    path = ["ICN"]
    
    def dfs(city, depth):
        if depth == len(tickets):
            return True
        
        for i, (s, e) in enumerate(tickets):
            if not used[i] and s == city:
                used[i] = True
                path.append(e)
                if dfs(e, depth+1):
                    return True
                used[i] = False
                path.pop()
        return False
        
    dfs("ICN", 0)
    return path