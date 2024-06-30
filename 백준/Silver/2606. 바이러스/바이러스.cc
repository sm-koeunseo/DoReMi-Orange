#include <iostream>
#include <vector>
using namespace std;

// 컴퓨터의 최대 수 +1 배열 생성 (index 1부터 사용)
bool check[101];        // 방문 여부
vector<int> com[101];   // 연결 컴퓨터 벡터
int cnt = 0;

// 깊이우선탐색 함수
void dfs(int x){
    cnt++;
    check[x] = true;    // 방문 여부 변경
    for(int i : com[x]) // iterator
        if(!check[i])   // 방문한 적 없다면 깊이우선탐색 (재귀호출)
            dfs(i);
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int num, set;
    cin >> num >> set;
    int a, b;

    // 연결되어있는 쌍의 개수만큼 반복
    for(int i=0; i<set; i++){
        cin >> a >> b;
        com[a].push_back(b);    // 서로를 연결 컴퓨터 벡터에 추가
        com[b].push_back(a);
    }

    dfs(1);
    cout << cnt-1;              // 1번 컴퓨터 개수 제외
}