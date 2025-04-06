#include <iostream>
#include <cstring>
using namespace std;

int a[300][300], c[300][300], v[300][300];
int dx[] = {-1, 0, 1, 0};
int dy[] = {0, -1, 0, 1};
int n, m, d;

void dfs(int x, int y){
    v[x][y] = 1;

    for (int i=0; i<4; i++){
        int nx = x + dx[i];
        int ny = y + dy[i];

        if (nx < 0 || ny < 0 || nx >= n || ny >= m) continue;
        if (a[nx][ny] < 1 || v[nx][ny]) continue;
        dfs(nx, ny);
    }
}

void search(int x, int y){
    for (int i=0; i<4; i++){
        int nx = x + dx[i];
        int ny = y + dy[i];

        if (nx < 0 || ny < 00 || nx >= n || ny >= m) continue;
        if (a[nx][ny] == 0) c[x][y]++;
    }
}

bool solve(){
    int cnt = 0;
    memset(c, 0, sizeof(c));
    memset(v, 0, sizeof(v));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (a[i][j] > 0 && !v[i][j]) {
                cnt++;
                dfs(i, j);
            }
        }
    }

    if (cnt > 1) return false;
    else if (cnt == 0){
        d = 0;
        return false;
    }

    for(int i=0; i<n; i++)
        for (int j=0; j<m; j++)
            if (a[i][j] > 0) search(i, j);
    
    for(int i=0; i<n; i++)
        for (int j=0; j<m; j++)
            if (c[i][j] > 0){
                a[i][j] -= c[i][j];
                if (a[i][j] < 0) a[i][j] = 0;
            }
    
    return true;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> m;
    for(int i=0; i<n; i++)
        for (int j=0; j<m; j++)
            cin >> a[i][j];

    while(solve()){
        d++;
    }
    cout << d;
    
    return 0;
}