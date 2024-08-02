#include <iostream>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int a[26] = {0};
    string s;
    cin >> s;
    for (int i=0; i<s.length(); i++){
        if (s[i]>'Z')       // 소문자 처리
            a[s[i]-97]++;   // 각 알파벳 자리수의 호출 횟수 증가
        else                // 대문자 처리
            a[s[i]-65]++;
    }

    int m = 0;
    char t = '?';  // m = 최대 호출 횟수, t = Index 저장
    for (int i=0; i<26; i++){
        if (a[i]>m){
            m = a[i];
            t = i + 65;
        } else if (a[i] == m)
            t = '?';
    }

    cout << t;
}