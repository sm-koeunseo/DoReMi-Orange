#include <iostream>
#include <algorithm>
using namespace std;

vector<int> a[101];
int visited[100];
int n, x, y, m;

int dfs(int x, int y){
    visited[x] = 1;

    if (x == y) return 0;

    for (int p : a[x]){
        if (visited[p]) continue;
        int r = dfs(p, y);
        if (r > -1) return r + 1;
    }

    return -1;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> x >> y >> m;
    for (int i=0; i<m; i++){
        int t1, t2;
        cin >> t1 >> t2;
        a[t1].push_back(t2);
        a[t2].push_back(t1);
    }

    cout << dfs(x, y);
}