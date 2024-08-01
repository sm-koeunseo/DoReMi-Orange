#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    // 스택 선언
    vector<int> v;

    // 상근이 카드 입력
    int n, tmp;
    cin >> n;
    for (int i=0; i<n; i++){
        cin >> tmp;
        v.push_back(tmp);
    }

    // 상근이가 가지고 있어야 할 카드
    cin >> n;
    for (int i=0; i<n; i++){
        cin >> tmp;
        cout << count(v.begin(), v.end(), tmp) << " ";
    }
}