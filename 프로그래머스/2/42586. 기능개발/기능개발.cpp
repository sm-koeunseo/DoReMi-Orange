#include <string>
#include <vector>
#include <cmath>

using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;
    
    int tday = ceil((float)(100-progresses[0])/speeds[0]), day;
    int cnt = 1;
    
    for (int i=1; i<progresses.size(); i++){
        day = ceil((float)(100-progresses[i])/speeds[i]);
        if (tday >= day)
            cnt++;
        else {
            answer.push_back(cnt);
            tday = day;
            cnt = 1;
        }
    }
    answer.push_back(cnt);
    
    return answer;
}