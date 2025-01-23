#include <bits/stdc++.h>
using namespace std;

int n, m, k, ny, nx;
int a[100][100];
int visited[100][100];
int dy[] = {-1, 0, 1, 0};
int dx[] = {0, 1, 0, -1};
vector<int> ret;

int DFS(int y, int x){
    visited[y][x] = 1;
    int ret = 1;
    for (int i=0; i<4; i++){
        ny = dy[i] + y;
        nx = dx[i] + x;
        if (ny < 0 || ny >= m || nx < 0 || nx >= n) continue;
        if (visited[ny][nx] || a[ny][nx]) continue;
        ret += DFS(ny, nx);
    }
    return ret;
}

int main(){
    int x1, x2, y1, y2;

    cin >> m >> n >> k;
    for (int i=0; i<k; i++){
        cin >> x1 >> y1 >> x2 >> y2;
        for (int x=x1; x<x2; x++){
            for (int y=y1; y<y2; y++){
                a[y][x] = 1;
            }
        }
    }

    for(int i=0; i<m; i++){
        for (int j=0; j<n; j++){
            if(!a[i][j] && !visited[i][j])
                ret.push_back(DFS(i,j));
        }
    }

    sort(ret.begin(), ret.end());
    cout << ret.size() << "\n";
    for(int a : ret) cout << a << " ";
}