#include <bits/stdc++.h>
using namespace std;

int n, m, tmp1, tmp2, mx;
vector<int> adj[10001];
int dp[10001], visited[10001];

int dfs(int here){
	visited[here] = 1;
    int ret = 1;
    for (int there : adj[here]) {
        if (visited[there]) continue;
        visited[there] = 1;
        ret += dfs(there);
    }
    return ret;
}

int main(){    
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> m;
    while(m--){
        cin >> tmp1 >> tmp2;
        adj[tmp2].push_back(tmp1);
    }

    n++;
    for (int i=1; i<n; i++){
        memset(visited, 0, sizeof(visited));
        dp[i] = dfs(i);
        mx = max(dp[i], mx);
    }

    for (int i=1; i<n; i++) if (mx == dp[i]) cout << i << " ";
    return 0;
}