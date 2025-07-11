from collections import deque

def solution(progresses, speeds):
    prog = deque(progresses)
    spd = deque(speeds)
    answer = []
    
    #for progress, speed in zip(progresses, speeds):
    while prog:
        for i in range(len(prog)):
            prog[i] += spd[i]
        
        cnt = 0
        while prog and prog[0] >= 100:
            prog.popleft()
            spd.popleft()
            cnt += 1
        
        if cnt:
            answer.append(cnt)
        
    return answer