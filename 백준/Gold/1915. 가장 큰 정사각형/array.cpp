#include <iostream>
#include <algorithm>
using namespace std;

int n, m;
int mx = 0;
int a[1000][1000];
int dp[1000][1000];

void findRec(int i, int j){
    int cnt = 1;

    for (int k=i+1; i<n; i++){
        // (0,1) 기준
        // k = 1 -> (0,2) and (1,1),(1,2)
        // k = 2 -> (0,3),(1,3) and (2,1),(2,2),(2,3)
        
    }

    while (true) {
        // 정사각형의 범위를 넘어서는 경우 종료
        if (i + cnt >= n || j + cnt >= n)
            break;

        // 정사각형이 모두 1로 채워져 있는지 확인
        bool valid = true;
        for (int k = i; k <= i + cnt; k++) {
            if (a[k][j + cnt] == 0) {
                valid = false;
                break;
            }
        }
        for (int k = j; k <= j + cnt; k++) {
            if (a[i + cnt][k] == 0) {
                valid = false;
                break;
            }
        }

        // 정사각형이 유효하지 않다면 종료
        if (!valid)
            break;

        cnt++;  // 크기를 늘려가며 탐색
    }

    // 가장 큰 정사각형 크기를 갱신
    mx = max(mx, cnt * cnt);
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> m;
    for (int i=0; i<n; i++)
        for (int j=0; j<m; j++)
            cin >> a[i][j];

    for (int i=0; i<n; i++)
        for (int j=0; j<m; j++)
            if (a[i][j])
                findRec(i, j);

    cout << m;
}