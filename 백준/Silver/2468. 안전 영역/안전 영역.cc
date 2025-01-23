#include <bits/stdc++.h>
using namespace std;

int dy[] = {-1, 0, 1, 0};
int dx[] = {0, 1, 0, -1};
int a[100][100];
int visited[100][100];
int n, tmp, maxH = 0, minH = 100, c, ret = 1, ny, nx;

void DFS(int y, int x){
    visited[y][x] = 1;
    for (int i=0; i<4; i++){
        ny = dy[i] + y;
        nx = dx[i] + x;
        if (ny < 0 || ny >= n || nx < 0 || nx >= n) continue;
        if (a[ny][nx] > tmp && !visited[ny][nx])
            DFS(ny, nx);
    }
}

int main(){
    cin >> n;
    for (int i=0; i<n; i++){
        for (int j=0; j<n; j++){
            cin >> tmp;
            a[i][j] = tmp;
            maxH = max(maxH, tmp);
            minH = min(minH, tmp);
        }
    }

    for (tmp=minH; tmp<maxH; tmp++){
        memset(visited, 0, sizeof(visited));
        c = 0;
        for (int i=0; i<n; i++){
            for (int j=0; j<n; j++){
                if (a[i][j]>tmp && !visited[i][j]){
                    c++;
                    DFS(i, j);
                }
            }
        }
        ret = max(ret, c);
    }
    
    cout << ret;
}