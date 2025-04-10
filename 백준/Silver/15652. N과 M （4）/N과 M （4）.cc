#include <bits/stdc++.h>
using namespace std;

int n, m;
int nature[8];

void dfs(int num, int start){
    if (num == m){
        for (int i=0; i<m; i++){
            cout << nature[i] << " ";
        }
        cout << "\n";
        return;
    }

    for (int i = start; i<=n; i++){
        nature[num] = i;
        dfs(num + 1, i);
    }
}

int main(){    
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> m;
    dfs(0, 1);
    
    return 0;
}