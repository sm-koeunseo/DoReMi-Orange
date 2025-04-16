#include <iostream>
#include <queue>
#include <cstring>
#include <vector>
#include <climits>
using namespace std;

int R, C;
bool a[1000][1000];
int vJ[1000][1000];
int vF[1000][1000];
string str;
pair<int, int> J;
vector<pair<int, int>> F;
int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};
int ret;

void getFireRoute(){
    queue<pair<int, int>> q;
    for (int i=0; i<F.size(); i++){
        q.push(F[i]);
        vF[F[i].first][F[i].second] = 0;
    }

    while (!q.empty()){
        int x = q.front().first;
        int y = q.front().second; q.pop();

        for (int i=0; i<4; i++){
            int nx = x + dx[i];
            int ny = y + dy[i];

            if (nx < 0 || ny < 0 || nx >= R || ny >= C) continue;
            if (a[nx][ny] || vF[nx][ny] > -1) continue;
            q.push({nx, ny});
            vF[nx][ny] = vF[x][y] + 1;
        }
    }
}

void getJRoute(){
    queue<pair<int, int>> q;
    q.push(J);
    vJ[J.first][J.second] = 0;

    while (!q.empty()){
        int x = q.front().first;
        int y = q.front().second; q.pop();

        for (int i=0; i<4; i++){
            int nx = x + dx[i];
            int ny = y + dy[i];

            if (nx < 0 || ny < 0 || nx >= R || ny >= C) continue;
            if (a[nx][ny] || vJ[nx][ny] > -1) continue;
            q.push({nx, ny});
            vJ[nx][ny] = vJ[x][y] + 1;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> R >> C;
    for (int i=0; i<R; i++){
        cin >> str;
        for (int j=0; j<str.size(); j++){
            switch (str[j]) {
            case '#': a[i][j] = 1; break;
            case 'J': a[i][j] = 0; J = {i, j}; break;
            case 'F': a[i][j] = 0; F.push_back({i, j}); break;
            default: a[i][j] = 0; break;
            }
        }
    }

    memset(vF, -1, sizeof(vF));
    getFireRoute();

    memset(vJ, -1, sizeof(vJ));
    getJRoute();

    int answer = INT_MAX;
    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            if (i == 0 || i == R - 1 || j == 0 || j == C - 1) {
                if (vJ[i][j] != -1 && (vF[i][j] == -1 || vJ[i][j] < vF[i][j])) {
                    answer = min(answer, vJ[i][j] + 1);
                }
            }
        }
    }

    if (answer == INT_MAX) cout << "IMPOSSIBLE";
    else cout << answer;
    
    return 0;
}
