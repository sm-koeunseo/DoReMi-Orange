#include <string>
#include <vector>
#include <algorithm>

using namespace std;
int p1=0, p2=0, p3=0;
int a1[] = {1, 2, 3, 4, 5};
int a2[] = {2, 1, 2, 3, 2, 4, 2, 5};
int a3[] = {3, 3, 1, 1, 2, 2, 4, 4, 5, 5};

vector<int> solution(vector<int> answers) {
    
    for (int i=0; i<answers.size(); i++){
        if (answers[i] == a1[i % 5]) p1++;
        if (answers[i] == a2[i % 8]) p2++;
        if (answers[i] == a3[i % 10]) p3++;
    }
    
    vector<int> answer;
    int maxv = max({p1, p2, p3});
    if (p1 == maxv) answer.push_back(1);
    if (p2 == maxv) answer.push_back(2);
    if (p3 == maxv) answer.push_back(3);
    
    return answer;
}