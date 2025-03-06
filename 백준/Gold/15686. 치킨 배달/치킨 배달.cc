#include <bits/stdc++.h>
using namespace std;

int n, m, a[51][51], result = INT_MAX;
vector<vector<int>> chickenList;
vector<pair<int, int>> chicken, house;

void combi (int start, vector<int> v){
    if (v.size() == m){
        chickenList.push_back(v);
        return;
    }
    for (int i=start + 1; i < chicken.size(); i++){
        v.push_back(i);
        combi(i, v);
        v.pop_back();
    }
    return;
}

int main(){    
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> m;
    n++;
    for (int i=1; i<n; i++)
        for (int j=1; j<n; j++){
            cin >> a[i][j];
            if (a[i][j] == 1) house.push_back(make_pair(i, j));
            else if (a[i][j] == 2) chicken.push_back(make_pair(i, j));
        }

    vector<int> v;
    combi(-1, v);
    for (vector<int> cList : chickenList){
        int ret = 0;
        for (pair<int, int> home : house){
            int _min = INT_MAX;
            for (int ch : cList){
                int _dis = abs(home.first - chicken[ch].first) + abs(home.second - chicken[ch].second);
                _min = min(_min, _dis);
            }
            ret += _min;
        }
        result = min(result, ret);
    }

    cout << result;
    return 0;
}