#include <iostream>
#include <algorithm>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    int cost[3];            // 현재 입력받는 색깔별 비용
    int minCost[1001][3];   // 각 단계별 색에 대한 최소 비용을 저장하는 배열
    minCost[0][0] = 0;      // 첫 번째 계산에서 오류를 제거하기 위한 값
    minCost[1][0] = 0;
    minCost[2][0] = 0;

    cin >> n;
    int m = n+1;
    for (int i=1; i<m; i++){
        cin >> cost[0] >> cost[1] >> cost[2];   // 지금의 rgb별 비용과 그에 따라 전까지 계산한 비용 더하여 저장
        minCost[i][0] = min(minCost[i-1][1], minCost[i-1][2]) + cost[0];
        minCost[i][1] = min(minCost[i-1][0], minCost[i-1][2]) + cost[1];
        minCost[i][2] = min(minCost[i-1][0], minCost[i-1][1]) + cost[2];
    }

    cout << min(minCost[n][0],min(minCost[n][1],minCost[n][2]));
}