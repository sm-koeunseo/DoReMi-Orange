import collections

def solution(nums):
    coll = collections.Counter(nums)
    num = len(nums)
    
    if num/2 < len(coll):
        return num/2
    else:
        return len(coll)