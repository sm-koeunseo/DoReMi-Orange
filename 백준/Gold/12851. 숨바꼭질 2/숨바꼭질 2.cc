#include <iostream>
#include <queue>
#include <algorithm>
#include <climits>
using namespace std;

int N, K, cur;
int dist[100001], ways[100001];
queue<int> q;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> K;
    fill(dist, dist + 100001, -1);
    fill(ways, ways + 100001, 0);

    q.push(N);
    dist[N] = 0;
    ways[N] = 1;

    while(q.size()){
        cur = q.front(); q.pop();
        if (cur == K) continue;

        int nexts[3] = {cur - 1, cur + 1, cur * 2 };
        for (int nx : nexts){
            if (nx < 0 || nx > 100000) continue;

            if (dist[nx] == -1) {
                dist[nx] = dist[cur] + 1;
                ways[nx] = ways[cur];
                q.push(nx);
            }else if (dist[nx] == dist[cur] + 1){
                ways[nx] += ways[cur];
            }
        }
    }

    cout << dist[K] << "\n" << ways[K];
}