#include <iostream>
#include <queue>
using namespace std;

bool a[50][50], v[50][50];
int dy[] = {-1, 0, 1, 0}; // 북, 동, 남, 서
int dx[] = {0, 1, 0, -1};
int n, m, r, c, d, cnt;
queue<pair<int, int>> q;

int bfs(int ty, int tx){

    q.push({ty, tx});
    while(q.size()){
        auto [y, x] = q.front();
        q.pop();

        if (!v[y][x]) {
            v[y][x] = true;
            cnt++;
        }

        bool moved = false;
        for (int i = 0; i < 4; i++) {
            d = (d + 3) % 4;
            int ny = y + dy[d];
            int nx = x + dx[d];

            if (ny < 0 || nx < 0 || ny >= n || nx >= m) continue;
            if (!a[ny][nx] && !v[ny][nx]) {
                q.push({ny, nx});
                moved = true;
                break;
            }
        }

        if (!moved) {
            int back = (d + 2) % 4;
            int ny = y + dy[back];
            int nx = x + dx[back];

            if (ny < 0 || nx < 0 || ny >= n || nx >= m || a[ny][nx]) {
                return cnt;
            } else {
                q.push({ny, nx});
            }
        }
    }

    return 0;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> m >> r >> c >> d;
    for (int i=0; i<n; i++)
        for (int j=0; j<m; j++)
            cin >> a[i][j];

    cout << bfs(r, c);

    return 0;
}