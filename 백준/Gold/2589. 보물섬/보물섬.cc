#include <bits/stdc++.h>
using namespace std;

int n, m, visited[50][50], ret = 0;
char a[50][50];
int dy[] = {-1, 0, 1, 0};
int dx[] = {0, 1, 0, -1};
string str;

void BFS(int y, int x){
    memset(visited, 0, sizeof(visited)); 
    visited[y][x] = 1;
    queue<pair<int, int>> q;
    q.push({y, x});
    while(q.size()){
        tie(y, x) = q.front(); q.pop();
        for (int i=0; i<4; i++){
            int ny = y + dy[i];
            int nx = x + dx[i];
    
            if (ny < 0 || nx < 0 || ny >= n || nx >= m || a[ny][nx] == 'W' || visited[ny][nx]) continue;
            visited[ny][nx] = visited[y][x] + 1;
            q.push({ny, nx});
            ret = max (ret, visited[ny][nx]);
        }
    }
}

int main(){    
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> m;
    for (int i=0; i<n; i++){
        cin >> str;
        for (int j=0; j<m; j++){
            a[i][j] = str[j];
        }
    }

    for (int i=0; i<n; i++)
        for (int j=0; j<m; j++)
            if (a[i][j] == 'L') BFS(i, j);

    cout << ret - 1;
    return 0;
}