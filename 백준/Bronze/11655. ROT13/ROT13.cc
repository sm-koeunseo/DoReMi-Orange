#include <iostream>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    string s;
    char t;
    getline(cin, s);            // 띄어쓰기 포함 입력
    for(int i=0; i<s.length(); i++){
        t = s[i];
        if(64<t && t<91)        // 대문자 처리
            s[i] = 65 + (t+13-65)%26;
        else if (96<t && t<123) // 소문자 처리
            s[i] = 97 + (t+13-97)%26;
    }

    cout << s;
}