from collections import defaultdict

def solution(clothes):
    cnt = defaultdict(int)
    
    for name, kind in clothes:
        cnt[kind] += 1
        
    answer = 1
    for c in cnt.values():
        answer *= (c + 1)
        
    return answer - 1