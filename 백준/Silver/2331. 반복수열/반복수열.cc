#include <iostream>
#include <cmath>
using namespace std;

// 최대 경우의 수 계산
int visit[236196];
int b;
int cnt = 0;

void dfs(int a){
    int orig = a;
    int next = 0;

    // 방문 횟수 증가
    visit[orig-1]++;

    // 다음 수열 계산 (pow 부동소수점 오류로 하드코딩)
    next = pow(a/100000, b) + pow((a%100000)/10000, b) + pow((a%10000)/1000, b) + pow((a%1000)/100, b) + pow((a%100)/10, b) + pow((a%10), b);
    
    // 이미 두번 방문했다면 종료
    if (visit[next-1]==2) return;
    
    // 아니라면 깊이우선탐색 진행
    dfs(next);

    // 종료 후 되돌아오며 한번만 방문했을 경우에 cnt 증가
    if (visit[orig-1]==1) cnt++;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int a;
    cin >> a >> b;

    dfs(a);
    cout << cnt;
}
