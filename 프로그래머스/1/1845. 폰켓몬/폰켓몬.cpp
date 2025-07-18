#include <vector>
using namespace std;

int cnt;
bool v[200001];

int solution(vector<int> nums)
{
    int s = nums.size();
    for (int i=0; i<s; i++){
        if (v[nums[i]] == false){
            v[nums[i]] = true;
            cnt++;
        }
    }
    
    if (s/2 < cnt)
        return s/2;
    else
        return cnt;
}