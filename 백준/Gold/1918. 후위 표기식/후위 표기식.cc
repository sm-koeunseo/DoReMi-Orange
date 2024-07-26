#include <iostream>
#include <stack>
#include <string>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    string str;     // 문자열 입력
    cin >> str;
    char tmp;
    stack<char> s;
    for (int i=0; i<str.length(); i++){
        tmp = str[i];
        if (tmp >= 'A' && tmp <= 'Z')           // 피연산자는 바로 출력
            cout << tmp;
        else{
            if (tmp == '(')                     // '(' 연산자는 push
                s.push(tmp);
            else if (tmp == '*' || tmp == '/'){ // *,/ 연산자는 이전의 *,/ 연산자가 있다면 출력 후 현재 연산자 push
                if (!s.empty() && (s.top() == '*' || s.top() == '/')){
                    cout << s.top();
                    s.pop();
                }
                s.push(tmp);
            }
            else if (tmp == '+' || tmp == '-'){ // '(' 전까지 출력 후 현재 연산자 push
                while (!s.empty() && s.top() != '('){
                    cout << s.top();
                    s.pop();
                }
                s.push(tmp);
            }
            else if (tmp == ')'){               // '(' 전까지 출력 후 '(' 버리기
                while (!s.empty() && s.top() != '('){
                    cout << s.top();
                    s.pop();
                }
                s.pop();
            }
        }
    }

    while (!s.empty()){
        cout << s.top();
        s.pop();
    }
}