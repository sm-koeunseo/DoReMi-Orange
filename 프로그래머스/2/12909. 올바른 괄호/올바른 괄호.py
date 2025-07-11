def solution(s):
    stack = []
    
    for ch in s:
        if ch == '(':
            stack.append(ch)
        else:
            if stack and stack[-1] == '(':
                stack.pop()
            else:
                return False

    return not stack