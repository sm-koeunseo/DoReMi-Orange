#include <iostream>
#include <algorithm>
using namespace std;

int c, n, m = 0;
char b[50][50];
char t;

void checkR(){  // 세로 체크
    for (int i=0; i<n; i++){
        t = b[i][0];
        c = 1;
        for (int j=1; j<n; j++){
            if (t == b[j][i]){
                c++;
                m = max(m, c);  // 최대값 업데이트
            }
            else{
                t = b[j][i];
                m = max(m, c);  // 최대값 업데이트
                c = 1;
            }
        }
    }
}

void checkC(){  // 가로 체크
    for (int i=0; i<n; i++){
        t = b[i][0];
        c = 1;
        for (int j=1; j<n; j++){
            if (t == b[i][j]){
                c++;
                m = max(m, c);  // 최대값 업데이트
            }
            else{
                t = b[i][j];
                m = max(m, c);  // 최대값 업데이트
                c = 1;
            }
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;
    for (int i=0; i<n; i++)
        for (int j=0; j<n; j++)
            cin >> b[i][j];
    
    checkC();   // 가로 체크
    checkR();   // 세로 체크

    if (m == n) // 최대값이 입력값과 같다면 출력
        cout << m;
    else {
        for (int i=0; i<n; i++)
            for (int j=1; j<n; j++){
                // 가로 교환 검사
                swap(b[i][j-1], b[i][j]);
                checkC();
                swap(b[i][j-1], b[i][j]);

                // 세로 교환 검사
                swap(b[j-1][i], b[j][i]);
                checkR();
                swap(b[j-1][i], b[j][i]);
            }
        cout << m;
    }
}