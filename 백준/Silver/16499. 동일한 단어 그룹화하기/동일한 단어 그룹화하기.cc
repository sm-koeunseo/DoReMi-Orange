#include <iostream>
#include <map>
#include <algorithm>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;           // 개수 입력
    map<string, int> m; // 맵 선언
    string s;

    while (n--){
        cin >> s;       // 문자열 입력
        sort(s.begin(), s.end());
        m[s] = 1;       // 정렬 후 해당 string을 맵에 추가
    }
    cout << m.size();   // 중복 추가x -> 맵의 사이즈 자체를 출력
}