def solution(arr):
    answer = []
    stack = []
    
    for num in arr:
        if not answer or answer[-1] != num:
            answer.append(num)
    
    return answer