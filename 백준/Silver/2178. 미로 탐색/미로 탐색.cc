#include <bits/stdc++.h>
using namespace std;

int dy[] = {-1, 0, 1, 0};
int dx[] = {0, 1, 0, -1};
int a[100][100];
int visited[100][100];
int n, m, x, y, sx, sy, ex, ey;

int main(){
    cin >> n >> m;
    string str;
    for (int i=0; i<n; i++){
        cin >> str;
        for (int j=0; j<m; j++){
            a[i][j] = str[j] - '0';
        }
    }

    sy = 0; sx = 0;
    ey = n-1; ex = m-1;

    queue<pair<int, int>> q;
    visited[sy][sx] = 1;
    q.push({sy, sx});
    while(q.size()){
        tie(y, x) = q.front(); q.pop();
        for (int i=0; i<4; i++){
            int ny = y + dy[i];
            int nx = x + dx[i];
            if (ny < 0 || ny >= n || nx < 0 || nx >= m || a[ny][nx] == 0) continue;
            if(visited[ny][nx]) continue;
            visited[ny][nx] = visited[y][x] + 1;
            q.push({ny, nx});
        }
    }

    cout << visited[ey][ex];
}