import collections

def solution(participant, completion):
    # collections.Counter() -> 리스트 안의 각 요소가 몇 번 등장했는지 -> {이름: 개수}
    
    part_counter = collections.Counter(participant)
    comp_counter = collections.Counter(completion)
    
    answer = part_counter - comp_counter
        
    return list(answer.keys())[0]