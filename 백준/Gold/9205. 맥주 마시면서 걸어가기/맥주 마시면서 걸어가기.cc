#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<pair<int,int>> v;
queue<int> q;
bool visited[102];
int t, n, x, y;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> t;
    for (int i=0; i<t; i++){
        v.clear();
        fill(visited, visited + 102, false);

        cin >> n;
        cin >> x >> y;
        v.push_back({x, y});
        for (int j=0; j<n; j++){
            cin >> x >> y;
            v.push_back({x, y});
        }
        cin >> x >> y;
        v.push_back({x, y});

        q = queue<int>();
        q.push(0);
        visited[0] = true;
        bool go = false;

        while(q.size()){
            int cur =  q.front(); q.pop();

            if (cur == v.size() - 1){
                go = true;
                break;
            }

            for (int i = 0; i < v.size(); i++) {
                if (visited[i]) continue;

                int dist = abs(v[cur].first - v[i].first) + abs(v[cur].second - v[i].second);
                if (dist <= 1000) {
                    visited[i] = true;
                    q.push(i);
                }
            }
        }

        cout << (go ? "happy\n" : "sad\n");
    }

    return 0;
}