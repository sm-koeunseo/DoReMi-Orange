#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <unordered_map>

using namespace std;

// 원문, 현재 문자열, 현재 인덱스, 목표 문자열 길이, 조합 카운트
void combi (string &order, string str, int idx, int target, unordered_map<string, int> &counter){
    if (str.size() == target){
        counter[str]++;
        return;
    }
    
    for (int i=idx; i<order.size(); i++){
        combi(order, str+order[i], i+1, target, counter);
    }
}

vector<string> solution(vector<string> orders, vector<int> course) {
    
    vector<string> answer;
    
    for (auto &c : course){
        unordered_map<string,int> counters;
        int maxCnt = 0;
        
        for (auto &order : orders){
            if (order.size() < c) continue;
            sort(order.begin(), order.end());
            combi(order, "", 0, c, counters);
        }
        
        for (auto &counter : counters){
            if (counter.second > 1 && counter.second > maxCnt)
                maxCnt = counter.second;
        }
        
        for (auto &counter : counters){
            if (counter.second == maxCnt && maxCnt > 1){
                answer.push_back(counter.first);
            }
        }
    }
    sort(answer.begin(), answer.end());
    return answer;
}