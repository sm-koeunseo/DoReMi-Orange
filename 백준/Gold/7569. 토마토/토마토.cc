#include <iostream>
#include <queue>
#include <tuple>
using namespace std;

int m, n, h;
int a[100][100][100], visited[100][100][100];
int dx[] = {-1, 0, 0, 1, 0, 0};
int dy[] = {0, -1, 0, 0, 1, 0};
int dz[] = {0, 0, -1, 0, 0, 1};
queue<tuple<int, int, int>> q;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> m >> n >> h;

    for (int z = 0; z < h; z++) {
        for (int y = 0; y < n; y++) {
            for (int x = 0; x < m; x++) {
                cin >> a[x][y][z];
                if (a[x][y][z] == 1) {
                    q.push({x, y, z});
                }
            }
        }
    }

    while (!q.empty()) {
        auto [x, y, z] = q.front(); q.pop();

        for (int i = 0; i < 6; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            int nz = z + dz[i];

            if (nx < 0 || nx >= m || ny < 0 || ny >= n || nz < 0 || nz >= h)
                continue;
            if (a[nx][ny][nz] != 0)
                continue;

            a[nx][ny][nz] = a[x][y][z] + 1;
            q.push({nx, ny, nz});
        }
    }

    int result = 0;
    for (int z = 0; z < h; z++) {
        for (int y = 0; y < n; y++) {
            for (int x = 0; x < m; x++) {
                if (a[x][y][z] == 0) {
                    cout << -1 << '\n';
                    return 0;
                }
                result = max(result, a[x][y][z]);
            }
        }
    }

    cout << result - 1 << '\n';
    return 0;
}