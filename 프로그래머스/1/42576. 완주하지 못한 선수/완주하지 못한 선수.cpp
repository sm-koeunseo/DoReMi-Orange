#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

string solution(vector<string> participant, vector<string> completion) {
    unordered_map<string, int> hash;
    
    for (auto& p : participant)
        hash[p]++;
    
    for (auto& c : completion)
        hash[c]--;
    
    for (auto& entry : hash)
        if (entry.second > 0)
            return entry.first;
}