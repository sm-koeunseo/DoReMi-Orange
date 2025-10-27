#include <string>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;
int maxl = 0, minl = 0;

int solution(vector<vector<int>> sizes) {
    for (int i=0; i<sizes.size(); i++){
        maxl = max(maxl, max(sizes[i][0], sizes[i][1]));
        minl = max(minl, min(sizes[i][0], sizes[i][1]));
    }
    return maxl * minl;
}