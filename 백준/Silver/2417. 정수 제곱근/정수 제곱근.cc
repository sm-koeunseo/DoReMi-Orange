#include <iostream>
#include <cmath>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    long long n, m; // 2^64를 저장할 수 있는 자료형 사용
    cin >> n;

    m = sqrt(n);    // 제곱근 구하기
    if ((m*m)<n)    // 올림 구현
        m++;

    cout << m;
}