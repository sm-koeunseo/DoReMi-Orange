#include <iostream>
#include <algorithm>
using namespace std;


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, m;
    int mx = 0;
    int a[1000][1000];
    int dp[1000][1000];

    cin >> n >> m;

    for (int i=0; i<n; i++)
        for (int j=0; j<m; j++)
            cin >> a[i][j];

    for (int i=0; i<n; i++)
        for (int j=0; j<m; j++){
            if (a[i][j] == 1){
                if (i==0 || j==0)
                    dp[i][j] = 1;   // 첫 번째 행/열이면 기본적으로 1 입력해주기 (1*1 정사각형)
                else {    // dp[i][j] = 좌표에서 끝나는 가장 큰 정사각형의 한 변의 길이
                    dp[i][j] = min(min(dp[i-1][j], dp[i][j-1]), dp[i-1][j-1]) + 1;
                    // 가장 작은 걸 골라야 왼쪽, 위쪽, 왼대각선쪽 모두를 포함한 사각형을 하나 더 이룰 수 있음
                }

                mx = max(mx, dp[i][j]);
            }
        }

    // mx = 가장 큰 한 변의 길이 -> 제곱해야 정사각형의 크기
    cout << mx*mx;
}