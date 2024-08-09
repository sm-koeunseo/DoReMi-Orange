#include <iostream>
#include <vector>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, m;
    cin >> n >> m;

    int a[10000];
    for (int i=0; i<n; i++){
        cin >> a[i];
    }

    int c=0, s;
    for (int i=0; i<n; i++){        // for문으로 하나씩 시작 위치 선정
        s=0;
        for (int j=i; j<n; j++){
            if (s+a[j] > m)         // 더한 게 m보다 크다면 불가능
                break;
            else if (s+a[j] == m){  // m이랑 같다면 hit
                c++;
                break;
            }else                   // m보다 같다면 더해주고 continue
                s+=a[j];
        }
    }

    cout << c;
}