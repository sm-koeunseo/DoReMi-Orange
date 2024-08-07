#include <iostream>
#include <vector>
#include <algorithm>
#include <cctype>
using namespace std;

// 모든 문자를 소문자화하여 비교하는 함수
bool lowerCompare(string A, string B) { // call by value -> 저장은 대소문자 구분 있이 해야 함
    // 문자열 시작, 문자열 끝, 변환 결과 저장 위치, 전역 namespace의 tolower 함수 사용
    transform(A.begin(), A.end(), A.begin(), ::tolower);
    transform(B.begin(), B.end(), B.begin(), ::tolower);
    return A < B;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    vector<string> v, r;    // 각 라운드 별 모든 문자열 저장, 가장 앞선 한 문자열 저장
    string s;

    cin >> n;
    while (n > 0){
        v.clear();      // 벡터 초기화
        while(n--){     // 입력 받은 숫자만큼 문자열 입력 후 벡터에 저장
            cin >> s;
            v.push_back(s);
        }

        sort(v.begin(), v.end(), lowerCompare); // 대소문자 구분 없이 정렬   
        r.push_back(v[0]);                      // 가장 앞선 문자열을 출력 벡터에 저장
        cin >> n;
    }

    // 각 라운드별 출력
    while(!r.empty()){
        cout << r.front() << endl;
        r.erase(r.begin());
    }
}