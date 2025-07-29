#include <bits/stdc++.h>

using namespace std;

int cal(vector<int> &numbers, int target, int depth, int val){
    if (depth == numbers.size())
        if (val == target) return 1;
        else return 0;
    
    return cal(numbers, target, depth+1, val+numbers[depth]) + 
        cal(numbers, target, depth+1, val-numbers[depth]);
}

int solution(vector<int> numbers, int target) {
    return cal(numbers, target, 0, 0);
}