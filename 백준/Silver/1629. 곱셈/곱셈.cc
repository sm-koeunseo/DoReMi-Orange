#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll a, b, c;

ll get_result(ll a, ll b){
    if (b == 1) return a % c;

    ll ret = get_result(a, b/2);    // 반씩 나누면서 계산
    ret = (ret * ret) % c;
    if(b % 2) ret = (ret * a) % c;  // 홀수는 한 번 더
    return ret;
}

int main(){    
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    // 최대값: 20억을 20억번 곱하기 -> long long을 써도 부족함
    // -> 매 연산마다 % 처리

    cin >> a >> b >> c;
    cout << get_result(a, b);
}