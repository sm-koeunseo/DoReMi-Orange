#include <bits/stdc++.h>
using namespace std;

int dy[] = {-1, 0, 1, 0};
int dx[] = {0, 1, 0, -1};
int a[50][50];
int visited[50][50];
int n, m, ny, nx;

void DFS(int y, int x){
    visited[y][x] = 1;
    for (int i=0; i<4; i++){
        ny = y + dy[i];
        nx = x + dx[i];
        if (ny < 0 || ny >= n || nx < 0 || nx >= m) continue;
        if (a[ny][nx] && !visited[ny][nx])
            DFS(ny, nx);
    }
}

int main(){
    int r, c, t1, t2, ret;
    cin >> r;

    for(int i=0; i<r; i++){
        memset(a, 0, sizeof(a));
        memset(visited, 0, sizeof(visited));
        ret = 0;
        cin >> n >> m >> c;

        for(int j=0; j<c; j++){
            cin >> t1 >> t2;
            a[t1][t2] = 1;
        }

        for(int j=0; j<n; j++){
            for (int k=0; k<m; k++){
                if(a[j][k] && !visited[j][k]){
                    DFS(j, k);
                    ret++;
                }
            }
        }

        cout << ret << "\n";
    }
    
}