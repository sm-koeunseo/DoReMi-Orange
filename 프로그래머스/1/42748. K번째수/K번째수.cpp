#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> vecSlice(vector<int> array, int begin, int end){
    return vector<int>(array.begin() + (begin-1), array.begin() + end);
}

vector<int> solution(vector<int> array, vector<vector<int>> commands) {
    vector<int> answer;
    
    for(int i=0; i<commands.size(); i++){
        vector<int> tmp = vecSlice(array, commands[i][0], commands[i][1]);
        sort(tmp.begin(), tmp.end());
        answer.push_back(tmp[commands[i][2]-1]);
    }
    
    return answer;
}