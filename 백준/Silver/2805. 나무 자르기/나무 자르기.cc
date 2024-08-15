#include <iostream>
#include <algorithm>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    long long n, m;
    cin >> n >> m;

    int t[1000000];
    for(int i=0; i<n; i++)  cin >> t[i];

    sort(t, t+n);

    long long l=0, h=t[n-1];
    long long s, c, x;
    while(l <= h){
        s = 0;
        c = (l+h)/2;    // 이진탐색 중앙값 지정

        for (int i=0; i<n; i++) // 기준값보다 큰 나무들의 잉여 길이 합산
            if (t[i] - c > 0) s += t[i] - c;

        if (s >= m){    // 가져간 나무가 기준값보다 같거나 많다면
            x = c;      // 현재 cut 지점을 최대 지점으로 저장
            l = c + 1;  // cut 가능 구간을 더 올림 (낭비를 줄이기 위해)
        } else
            h = c - 1;  // m이 안된다면 cut 가능 구간을 내림
    }

    cout << x;
}