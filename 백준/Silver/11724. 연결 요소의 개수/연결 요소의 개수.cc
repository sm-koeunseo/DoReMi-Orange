#include <iostream>
#include <algorithm>
using namespace std;

int N, M;
vector<int> v[1001];
int tmp1, tmp2;
int cnt, visited[1001];


void dfs(int x){
    for (int i=0; i<v[x].size(); i++){
        tmp1 = v[x][i];
        if (!visited[tmp1]){
            visited[tmp1] = 1;
            dfs(tmp1);
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> M;
    for (int i=0; i<M; i++){
        cin >> tmp1 >> tmp2;
        v[tmp1].push_back(tmp2);
        v[tmp2].push_back(tmp1);
    }

    for (int i=1; i<=N; i++){
        if (!visited[i]){   // 연결 요소가 있다면
            cnt++;
            visited[i] = 1;
            dfs(i);
        }
    }

    cout << cnt;
}