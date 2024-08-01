#include <iostream>
#include <algorithm>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    string s, r, t;     // 입력, 출력, 임시
    getline(cin, s);    // 줄 전체 입력 (띄어쓰기 포함)

    char c;
    for (int i=0; i<s.length(); i++){
        c = s[i];       // char 한개씩 받기
        if (c == '<'){  // <라면 >가 올때까지 그대로 출력에 추가
            while (c != '>'){
                r += c;
                i++;
                c = s[i];
            }
            r += c;  // >도 추가
        } else if (c == ' ')
            r += c; // 공백은 그대로 추가
        else {
            t = "";
            while (i < s.length() && !(c == ' ' || c == '<')){
                t += c;
                i++;
                c = s[i];
            }
            reverse(t.begin(), t.end());
            r += t; // 임시 단어 역순으로 뒤집어 저장
            i--;    // <의 경우 다음 체크에 걸려야 하니 다시 i를 감소
        }
    }

    cout << r;
}