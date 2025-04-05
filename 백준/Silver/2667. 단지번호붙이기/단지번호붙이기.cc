#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

bool a[25][25], visited[25][25];
int dx[] = {-1, 0, 1, 0};
int dy[] = {0, -1, 0, 1};
int n;
string str;
vector<int> g;

int bfs(int x, int y){
    queue<pair<int,int>> q;
    visited[x][y] = true;
    int c = 0;

    q.push(make_pair(x, y));
    while(q.size()){
        int tx = q.front().first;
        int ty = q.front().second;
        q.pop(); c++;

        for (int i=0; i<4; i++){
            int nx = tx + dx[i];
            int ny = ty + dy[i];

            if (nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
            if (!a[nx][ny] || visited[nx][ny]) continue;
            visited[nx][ny] = true;
            q.push(make_pair(nx, ny));
        }

    }

    return c;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;
    for (int i=0; i<n; i++){
        cin >> str;
        for (int j=0; j<n; j++){
            a[i][j] = (str[j] == '1');
        }
    }

    for (int i=0; i<n; i++){
        for (int j=0; j<n; j++){
            if (a[i][j] == 1 && !visited[i][j])
                g.push_back(bfs(i, j));
        }
    }

    cout << g.size() << "\n";
    sort(g.begin(), g.end());
    for (int i=0; i<g.size(); i++){
        cout << g[i] << "\n";
    }
}