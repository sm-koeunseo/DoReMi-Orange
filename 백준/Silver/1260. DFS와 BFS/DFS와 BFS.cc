#include <iostream>
#include <algorithm>
#include <queue>
#include <cstring>
using namespace std;

vector<int> v[1001];
int n, m, s, visited[1001];
int t1, t2;

void DFS(int x){
    visited[x] = 1;
    cout << x << " ";

    for (int i=0; i<v[x].size(); i++){
        int t = v[x][i];
        if (!visited[t]) DFS(t);
    }
}

void BFS(int x){
    queue<int> q;
    visited[x] = 1;

    q.push(x);
    while(q.size()){
        int n = q.front(); q.pop();
        cout << n << " ";
        for (int t : v[n]){
            if (!visited[t]) {
                visited[t] = 1;
                q.push(t);
            }
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> m >> s;
    n++;
    for (int i=0; i<m; i++){
        cin >> t1 >> t2;
        v[t1].push_back(t2);
        v[t2].push_back(t1);
    }
    for (int i=1; i<n; i++){
        if(v[i].size() > 1) {
            sort(v[i].begin(), v[i].end());
        }
    }

    DFS(s);
    cout << "\n";
    memset(visited, 0, sizeof(visited));
    BFS(s);
}