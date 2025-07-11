def solution(progresses, speeds):
    days = [ (100 - p + s - 1) // s
             for p, s in zip(progresses, speeds) ]
    #days = []
    #for p, s in zip(progresses, speeds):
    #    days.append((100 - p + s - 1) // s)
    
    answer = []
    cur = days[0]
    cnt = 1
    
    for d in days[1:]:
        if d <= cur:
            cnt +=1
        else:
            answer.append(cnt)
            cur = d
            cnt = 1
    
    answer.append(cnt)
    return answer