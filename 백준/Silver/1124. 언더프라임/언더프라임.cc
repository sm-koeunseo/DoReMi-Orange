#include <iostream>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, m;
    cin >> n >> m;
    m++;

    bool chk[100001];       // 소수 판별
    fill_n(chk, 100001, true);
    chk[0] = false;
    chk[1] = false;

    int arr[100001]={0};    // 소인수 카운트
    int res=0, tmp;

    for (int i=2; i<m; i++){
        if (chk[i]){                    // 만약 소수라면
            for(int j=i*2; j<m; j+=i){  // i의 배수들을
                chk[j] = false;         // 소수가 아님으로 변경
                tmp = j;
                while (tmp%i==0){       // 그리고 그 배수가 i로 나눠지는 만큼 소인수의 수 증가
                    tmp /= i;
                    arr[j]++;
                }   // i는 소인수 (1개)가 저장되지 않지만 0과 1은 모두 소수가 아니므로 차이 없음
            }
        }
    }

    for (int i=n; i<m; i++)
        if (chk[arr[i]]) res++;
    cout << res << endl;
}