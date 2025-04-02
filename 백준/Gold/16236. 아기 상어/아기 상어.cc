#include <bits/stdc++.h>
using namespace std;

int a[20][20], visited[20][20], dist[20][20];
int s_size = 2, s_eat = 0;  // 상어 크기와 먹은 물고기 수
int n, x, y;  // 상어 현재 위치
int dx[] = {-1, 0, 1, 0};  // 상하좌우
int dy[] = {0, 1, 0, -1};
int t1, t2;

int BFS(int sx, int sy) {
    queue<pair<int, int>> q;
    memset(visited, 0, sizeof(visited));
    memset(dist, 0, sizeof(dist));
    visited[sx][sy] = 1;
    q.push({sx, sy});

    int min_dist = INT_MAX;
    int fx = -1, fy = -1;

    while (!q.empty()) {
        int qx = q.front().first;
        int qy = q.front().second;
        q.pop();

        for (int i = 0; i < 4; i++) {
            int nx = qx + dx[i];
            int ny = qy + dy[i];

            if (nx < 0 || ny < 0 || nx >= n || ny >= n) continue;
            if (visited[nx][ny]) continue;
            if (a[nx][ny] > s_size) continue;

            visited[nx][ny] = 1;
            dist[nx][ny] = dist[qx][qy] + 1;
            q.push({nx, ny});

            if (a[nx][ny] != 0 && a[nx][ny] < s_size) {
                int d = dist[nx][ny];
                if (d < min_dist || 
                    (d == min_dist && (nx < fx || (nx == fx && ny < fy)))) {
                    min_dist = d;
                    fx = nx;
                    fy = ny;
                }
            }
        }
    }

    // 먹을 물고기 없음
    if (min_dist == INT_MAX) return 0;

    s_eat++;
    if (s_eat == s_size) {
        s_size++;
        s_eat = 0;
    }

    // 상어 위치 이동 및 물고기 제거
    a[fx][fy] = 0;
    x = fx;
    y = fy;

    return min_dist;  // 이동 시간
}

int main() {
    cin >> n;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++) {
            cin >> a[i][j];
            if (a[i][j] == 9) {
                x = i;
                y = j;
                a[i][j] = 0;
            }
        }

    while (t2 = BFS(x, y)) {
        t1 += t2;
    }

    cout << t1;
}

/*

vector<tuple<int, int, int>> fish;
fish.push_back({dist[nx][ny], nx, ny});
if (fish.empty()) return 0;
sort(fish.begin(), fish.end());
int d, fx, fy;
tie(d, fx, fy) = fish[0];

*/