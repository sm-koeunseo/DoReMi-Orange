#include <iostream>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    string s, r, t;     // 입력, 출력, 임시
    getline(cin, s);    // 줄 전체 입력 (띄어쓰기 포함)

    char c;
    for (int i=0; i<s.length(); i++){
        c = s[i];   // char 한개씩 받기
        switch (c) {
        case '<':   // <라면 >가 올때까지 그대로 출력에 추가
            while (c != '>'){
                r += c;
                i++;
                c = s[i];
            }
            r += s[i];  // >도 추가
            break;
        
        default:    // 단어가 끝날때까지 임시 변수에 저장
            while(!(c == ' ' || c == '\0' || c == '<')){
                t += c;
                i++;
                c = s[i];
            }       // 역순으로 담아주기
            for (int j=t.length()-1; j>-1; j--){
                r += t[j];
            }
            t = '\0';
            switch (c) {    // <의 경우 다음 체크에 걸려야 하니 다시 i를 감소
                case '<'    : i--;    break;
                default     : r += c;  // 나머지는 그대로 출력에 추가
            }
        }
    }

    cout << r;
}