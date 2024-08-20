#include <iostream>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    bool p[1000001];    // 소수 판별 배열
    fill_n(p, 1000001, true);
    p[1] = false;       // 1은 소수가 아님 (미리 입력)

    int m, n;
    cin >> m >> n;

    n++;    // 입력받은 n도 계산에 포함시키기 위해 1 증가
    for (int i=2; i<n; i++){
        if(p[i])    // i가 소수라면 i의 배수는 소수가 아님
            for (int j=i*2; j<n; j+=i)  // n 이상은 계산할 필요가 없음
                p[j] = false;
    }

    for (int i=m; i<n; i++)
        if(p[i])    cout << i << endl;
}