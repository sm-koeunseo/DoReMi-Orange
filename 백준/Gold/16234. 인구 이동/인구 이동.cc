#include <bits/stdc++.h>
using namespace std;

int a[50][50], visited[50][50];
int n, l, r, cnt, sum, c;
vector<pair<int,int>> v;
int dy[] = {-1, 0, 1, 0};
int dx[] = {0, 1, 0, -1};

void DFS(int y, int x){
    visited[y][x] = 1;
    sum += a[y][x];
    v.push_back(make_pair(y, x));

    for (int i=0; i<4; i++){
        int ny = y + dy[i];
        int nx = x + dx[i];

        if (ny < 0 || nx < 0 || ny >= n || nx >= n) continue;
        if (visited[ny][nx] || abs(a[y][x] - a[ny][nx]) < l || abs(a[y][x] - a[ny][nx]) > r ) continue;
        DFS(ny, nx);
        c++;
    }
}

bool move(){
    c = 0;
    for (int i=0; i<n; i++)
        for (int j=0; j<n; j++){
            if (visited[i][j] == 0){
                v.clear();
                sum = 0;
                DFS(i, j);
                for (pair<int, int> p : v){
                    a[p.first][p.second] = (int)(sum/v.size());
                }
            }
        }

    if (c > 0) return true;
    else return false;
}

int main(){    
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> l >> r;
    for (int i=0; i<n; i++)
        for (int j=0; j<n; j++)
            cin >> a[i][j];

    while(move()){
        memset(visited, false, sizeof(visited));
        cnt++;
    }
    cout << cnt;

    return 0;
}