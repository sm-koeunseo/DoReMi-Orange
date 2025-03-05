#include <bits/stdc++.h>
using namespace std;

int n, m, a[100][100], visited[100][100], cnt = 1, bcnt, wcnt;
vector<pair<int, int>> v;
int dy[] = {-1, 0, 1, 0};
int dx[] = {0, 1, 0, -1};

void DFS(int y, int x){
    visited[y][x] = 1;
    if (a[y][x] == 1){
        v.push_back({y, x});
        return;
    }

    for (int i=0; i<4; i++){
        int ny = y + dy[i];
        int nx = x + dx[i];

        if (ny < 0 || nx < 0 || ny >= n || nx >= m || visited[ny][nx]) continue;
        DFS(ny, nx);
    }
}


int solve(){
    v.clear();
    fill(&visited[0][0], &visited[0][0] + 100 * 100, 0);
    DFS(0, 0);

    for (pair<int, int> t : v)
        a[t.first][t.second] = 0;
    return v.size();
}

int main(){    
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> m;
    for (int i=0; i<n; i++)
        for (int j=0; j<m; j++)
            cin >> a[i][j];

    while(cnt > 0){
        wcnt++;
        bcnt = cnt;
        cnt = solve();
    }

    cout << wcnt - 1 << "\n" << bcnt;
    return 0;
}