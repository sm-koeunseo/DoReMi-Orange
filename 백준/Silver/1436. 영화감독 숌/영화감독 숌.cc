#include <iostream>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    // i : 666부터 시작
    // c = 현재까지 count한 '666'이 포함된 수의 개수
    // tc = 현재 숫자에서 연속으로 6이 나온 횟수를 기록
    // ti = 현재 수 저장 (/연산을 위해)
    int i=665, c=0, n, tc, ti;
    bool f;
    cin >> n;
    while (n!=c){   // n=c일때까지 반복
        tc=0;       // count 초기화
        i++;        // i값 증가 및 ti에 대입
        ti=i;
        f = false;
        while(ti>0){
            if(ti%10 == 6){ // 10으로 나눈 나머지가 6 -> 6이 포함
                tc++;
                if (tc == 3) { 
                    f = true;
                    break;
                }
            }else           // 6이 아니라면 tc=0 초기화 -> 연속된 값만 찾음
                tc = 0;
            ti /= 10;
        }

        if(f)
            c++;
    }
    cout << i;
}