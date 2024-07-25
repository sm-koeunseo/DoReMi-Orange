#include <iostream>
#include <unordered_map>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    // hash map
    unordered_map <int, int> m;

    // 상근이 카드 입력
    int n, tmp;
    cin >> n;
    for (int i=0; i<n; i++){
        cin >> tmp;
        m[tmp]++;
    }

    // 상근이가 가지고 있어야 할 카드
    cin >> n;
    for (int i=0; i<n; i++){
        cin >> tmp;
        cout << m[tmp] << " ";
    }
}