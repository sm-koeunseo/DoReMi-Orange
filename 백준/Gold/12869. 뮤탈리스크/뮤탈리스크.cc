#include <iostream>
#include <algorithm>
#include <cstring>
#include <climits>
using namespace std;

int N, hp[3];
int dp[61][61][61]; // 공격 횟수

int attack[6][3] = {
    {9, 3, 1},
    {9, 1, 3},
    {3, 9, 1},
    {3, 1, 9},
    {1, 9, 3},
    {1, 3, 9}
};

int solve(int a, int b, int c) {
    a = max(0, a);
    b = max(0, b);
    c = max(0, c);

    int &ret = dp[a][b][c];
    if (ret != -1) return ret;
    if (a == 0 && b == 0 && c == 0) return 0;

    ret = INT_MAX;
    for (int i = 0; i < 6; i++) {   // 현재 공격 + 최소 공격
        ret = min(ret, 1 + solve(a - attack[i][0], b - attack[i][1], c - attack[i][2]));
    }

    return ret;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    memset(dp, -1, sizeof(dp));
    cin >> N;
    for (int i = 0; i < N; i++) cin >> hp[i];

    cout << solve(hp[0], hp[1], hp[2]) << "\n";
    return 0;
}
