#include <iostream>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, m;
    cin >> n >> m;

    if (n == 1)         // 엄지라면 갔다 오고 끝
        cout << m * 8;
    else if (n == 5)    // 새끼라면 갔다 오고 다시 갈 수 있음
        cout << m * 8 + 4;
    else {              // 가운데라면 왕복 말고 편도로 계산
        if (m % 2 == 0)
            cout << m * 4 + n - 1;
        else
            cout << m * 4 + 5 - n;
    }
}