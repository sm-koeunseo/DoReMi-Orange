#include <iostream>
#include <vector>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int l = 1, p = 1, v = 1;
    vector<int> c;
    int t;

    while (true){   // 순차 입력
        cin >> l >> p >> v;

        // 모두 0이면 종료
        if (l==0 && p==0 && v==0)
            break;

        // 특정 일수 중 연속으로 다닐 수 있는 수 계산
        t = (v/p)*l;
        if (v%p > l)    // 나머지가 l보다 크면 l을 더함
            t += l;
        else
            t += v%p;   // 나머지가 l보다 작으면 나머지 더함
        c.push_back(t);
    }

    for (int i=0; i<c.size(); i++)
        cout << "Case " << (i+1) << ": " << c[i] << endl;

}