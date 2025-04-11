#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <cstring>
using namespace std;

int n, m, x, y;
int a[15][15], dist[15][15];
int dx[] = {-1, 0, 0, 1}; // ↑ ← → ↓
int dy[] = {0, -1, 1, 0};

vector<pair<int,int>> every;     // 모든 베이스캠프
vector<pair<int,int>> store;    // 가려는 편의점
vector<pair<int,int>> base;     // 출발 베이스캠프
vector<pair<int,int>> person;   // 현재 사람의 위치
bool arrived[30];               // 편의점 도착 여부

void getBase(int rx, int ry){
    memset(dist, -1, sizeof(dist));
    queue<pair<int,int>> q;
    q.push({rx, ry});
    dist[rx][ry] = 0;

    while(q.size()){
        int qs = q.size();
        vector<pair<int, int>> found;

        while(qs--){
            int x = q.front().first;
            int y = q.front().second;
            q.pop();
            
            for (auto& t : every)
                if (x == t.first && y == t.second) found.push_back({x, y});

            for (int i=0; i<4; i++){
                int nx = x + dx[i];
                int ny = y + dy[i];

                if (nx < 0 || ny < 0 || nx >= n || ny >= n) continue;
                if (a[nx][ny] || dist[nx][ny] != -1) continue;

                dist[nx][ny] = dist[x][y] + 1;
                q.push({nx, ny});
            }
        }

        if (found.size()){
            sort(found.begin(), found.end());
            base.push_back(found[0]);
            a[found[0].first][found[0].second] = 1; // 조직
            break;
        }
    }
}

pair<int,int> moveOne(int i) {
    memset(dist, -1, sizeof(dist));
    queue<pair<int,int>> q;
    pair<int,int> start = person[i];
    pair<int,int> goal = store[i];
    q.push(goal);
    dist[goal.first][goal.second] = 0;

    while (!q.empty()) {
        //auto [x, y] = q.front(); q.pop();
        int x = q.front().first;
        int y = q.front().second;
        q.pop();

        for (int d=0; d<4; d++) {
            int nx = x + dx[d];
            int ny = y + dy[d];

            if (nx < 0 || ny < 0 || nx >= n || ny >= n) continue;
            if (a[nx][ny] || dist[nx][ny] != -1) continue;

            dist[nx][ny] = dist[x][y] + 1;
            q.push({nx, ny});
        }
    }

    int cx = start.first, cy = start.second;
    int best_dist = 1e9;
    pair<int,int> res = {cx, cy};

    for (int d=0; d<4; d++) {
        int nx = cx + dx[d];
        int ny = cy + dy[d];

        if (nx < 0 || ny < 0 || nx >= n || ny >= n) continue;
        if (a[nx][ny]) continue;

        if (dist[nx][ny] != -1 && dist[nx][ny] < best_dist) {
            best_dist = dist[nx][ny];
            res = {nx, ny};
        }
    }
    return res;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> m;
    for (int i=0; i<n; i++) for (int j=0; j<n; j++){
        cin >> a[i][j];
        if (a[i][j] == 1){
            a[i][j] = 0;
            every.push_back({i, j});
        }
    }
    for (int i=0; i<m; i++){
        cin >> x >> y;
        store.push_back({x - 1, y - 1});
    }

    person.assign(m, {-1, -1});
    memset(arrived, 0, sizeof(arrived));

    int time = 0;
    while (true){
        time++;

        // 1. 이동
        for (int i=0; i<m; i++) {
            if (arrived[i] || person[i].first == -1) continue;
            person[i] = moveOne(i);
        }

        // 2. 편의점 도착했다면 건물화
        for (int i=0; i<m; i++) {
            if (arrived[i]) continue;
            if (person[i] == store[i]) {
                arrived[i] = true;
                a[person[i].first][person[i].second] = 1;
            }
        }

        // 3. 현재 시간에 사람 입장
        if (time <= m) {
            int idx = time - 1;
            getBase(store[idx].first, store[idx].second);
            person[idx] = base[idx];
        }

        // 완료 검사
        bool done = true;
        for (int i=0; i<m; i++) {
            if (!arrived[i]) done = false;
        }
        if (done) break;
    }

    cout << time << '\n';
    return 0;
}
