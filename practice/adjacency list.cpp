#include <bits/stdc++.h>
using namespace std;

const int V = 5;
vector<int> adj[V];
bool v[V];

void go(int idx){
    v[idx] = 1;
    cout << idx << '\n';
    for(int there : adj[idx]){
        if (v[there]) continue;
        go(there);
    }
    return;
}

int main(){    
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    adj[1].push_back(2);
    adj[2].push_back(1);

    adj[1].push_back(3);
    adj[3].push_back(1);

    adj[3].push_back(4);
    adj[4].push_back(3);

    for (int i=0; i<V; i++)
        if (adj[i].size() && v[i] == 0) go(i);

    // adj[0].push_back(1);
    // adj[0].push_back(2);
    // adj[0].push_back(3);

    // adj[1].push_back(0);
    // adj[1].push_back(2);

    // adj[2].push_back(0);
    // adj[2].push_back(1);

    // adj[3].push_back(0);

    // for (int i=0 ; i<V; i++){
    //     cout << i << " :: ";
    //     for (int there : adj[i]){
    //         cout << there << " ";
    //     }
    //     cout << '\n';
    // }

    // for (int i=0; i<V; i++){
    //     cout << i << " :: ";
    //     for (int j=0; j<adj[i].size(); j++){
    //         cout << adj[i][j] << " ";
    //     }
    //     cout << '\n';
    // }
}