#include <bits/stdc++.h>
using namespace std;
// 최단 거리 구하기

// vector<int> adj[100];
// int visited[100];
// int nodeList[] = {10, 12, 14, 16, 18, 20, 22, 24};

// void BFS(int here){
//     queue<int> q;
//     visited[here] = 1;
//     q.push(here);
//     while(q.size()){
//         int here = q.front(); q.pop();
//         for (int there : adj[here]){
//             if (visited[there]) continue;
//             visited[there] = visited[here] + 1;
//             q.push(there);
//         }
//     }
// }

// int main(){
//     adj[10].push_back(12);
//     adj[10].push_back(14);
//     adj[10].push_back(16);
//     adj[12].push_back(18);
//     adj[12].push_back(20);
//     adj[20].push_back(22);
//     adj[20].push_back(24);
//     BFS(10);
//     for(int i : nodeList){
//         cout << i << " : " << visited[i] << '\n';
//     }
//     cout << visited[24] - 1 << '\n';
//     return 0;
// }

int dy[] = {-1, 0, 1, 0};
int dx[] = {0, 1, 0, -1};
int a[100][100];
int visited[100][100];
int n, m, x, y, sx, sy, ex, ey;

int main(){
    cin >> n >> m;
    cin >> sy >> sx;
    cin >> ey >> ex;

    for (int i=0; i<n; i++){
        for (int j=0; j<m; j++){
            cin >> a[i][j];
        }
    }

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