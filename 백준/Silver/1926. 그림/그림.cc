#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

int picture[500][500];
bool chk[500][500];
int dx[4] = { 1, 0, -1, 0};
int dy[4] = { 0, 1, 0, -1};

struct point {
    int x;
    int y;

    point(int x, int y) : x(x), y(y) {}
};

int bfs(int x, int y, int n, int m){
    int size = 1;
    std::queue<point> q;
    int i, nx, ny;

    q.push(point(x,y));
    while (!q.empty()){
        point p = q.front();
        q.pop();

        for(i=0; i<4; i++){
            nx = p.x + dx[i];
            ny = p.y + dy[i];
            if (-1<nx && nx<n && -1<ny && ny<m){
                if (picture[nx][ny] == 1 && chk[nx][ny] == false){
                    size++;
                    chk[nx][ny] = true;
                    q.push(point(nx,ny));
                }
            }
        }
    }
    return size;
};

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, m, i, j;
    int cnt = 0, maxsize = 0;

    cin >> n >> m;
    for (i=0; i<n; i++)
        for (j=0; j<m; j++){
            cin >> picture[i][j];
        }

    for (i=0; i<n; i++)
        for (j=0; j<m; j++){
            if (picture[i][j] && (!chk[i][j])){
                chk[i][j] = 1;
                cnt++;
                maxsize = max(maxsize, bfs(i,j,n,m));
            }
        }
    
    cout << cnt << " " << maxsize;
}