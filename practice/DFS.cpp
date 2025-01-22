#include <bits/stdc++.h>
using namespace std;

// const int n = 6;
// vector<int> adj[n];
// int visited[n];

// void DFS(int u){
//     visited[u] = 1;
//     cout << u << "\n";
//     for (int v : adj[u]){
//         if (visited[v] == 0)
//             DFS(v);
//     }
//     cout << u << " close\n";
// }

// int main(){
//     adj[1].push_back(2);
//     adj[1].push_back(3);
//     adj[2].push_back(4);
//     adj[4].push_back(2);
//     adj[2].push_back(5);
//     DFS(1);
// }

int visited[100][100];
int a[100][100];

int dy[] = {-1, 0, 1, 0};
int dx[] = {0, 1, 0, -1};

int n, m, ny, nx, ret;

void DFS(int y, int x){
    visited[y][x] = 1;
    for (int i=0; i<4; i++){
        ny = y + dy[i];
        nx = x + dx[i];
        if (ny < 0 || ny >= n || nx < 0 || nx >= m) continue;
        if (a[ny][nx] == 1 && !visited[ny][nx]){
            DFS(ny, nx);
        }
    }
}

int main(){
    cin >> n >> m;
    for (int i=0; i<n; i++){
        for (int j=0; j<m; j++){
            cin >> a[i][j];
        }
    }

    for (int i=0; i<n; i++){
        for (int j=0; j<m; j++){
            if (a[i][j] == 1 && !visited[i][j]){
                DFS(i, j);
                ret++;
            }
        }
    }

    cout << ret;
}