def dfs(numbers, target, depth, value):
    if depth == len(numbers):
        return 1 if value == target else 0
    
    return (dfs(numbers, target, depth+1, value + numbers[depth])
          + dfs(numbers, target, depth+1, value - numbers[depth]))

def solution(numbers, target):
    return dfs(numbers, target, 0, 0)