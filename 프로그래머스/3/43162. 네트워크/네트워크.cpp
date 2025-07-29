#include <bits/stdc++.h>
using namespace std;

bool visited[201];
int cnt;

void bfs(int i, vector<vector<int>> &computers){            
    visited[i] = true;
    for (int j=0; j<computers[i].size(); j++){
        if (visited[j] == false && computers[i][j] == 1)
            bfs(j, computers);
    }
}

int solution(int n, vector<vector<int>> computers) {
    for (int i=0; i<computers.size(); i++){
        if (visited[i]) continue;
        bfs(i, computers);
        cnt++;
    }
    
    return cnt;
}