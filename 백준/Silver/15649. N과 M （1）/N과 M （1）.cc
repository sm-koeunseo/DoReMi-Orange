#include <bits/stdc++.h>
using namespace std;

int n, m;
int nature[8];
int visited[8];

void dfs(int num){
    if (num == m){
        for (int i=0; i<m; i++){
            cout << nature[i] << " ";
        }
        cout << "\n";
        return;
    }

    for (int i=0; i<n; i++){
        if (visited[i]) continue;
        nature[num] = i+1;

        visited[i] = 1;
        dfs(num + 1);
        visited[i] = 0;
    }
}

int main(){    
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> m;
    dfs(0);
    
    return 0;
}