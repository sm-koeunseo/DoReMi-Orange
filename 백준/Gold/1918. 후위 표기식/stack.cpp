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
    stack<int> s;
    char tmp;
    bool flag = 0;  // 문자열 길이만큼 for문 반복
    for (int i=0; i<str.size(); i++){
        tmp = str.at(i);
        if (tmp < 42)   flag = 0;                           // 괄호일 경우 +/-에 높은 우선순위임으로 flag 다시 0으로 변경
        else if (str.at(i) == 42 || str.at(i) == 47){       // 연산자일 경우 스택에 push
            s.push(str.at(i));
            flag = 1;                                       // 곱셈/나눗셈일 경우 다음 피연산자 출력 후 연산자 출력
        } else if (str.at(i) < 65)  s.push(str.at(i));
        else{
            cout<<tmp;                                      // 피연산자일 경우 출력
            if(flag){
                for (int i=0, num=s.size(); i<num; i++){    // 연산자는 역순으로 출력
                    cout << (char)s.top();
                    s.pop();
                }
            }
            flag = 0;
        }
    }
    
    for (int i=0, num=s.size(); i<num; i++){    // 마지막 연산자가 +/-일 경우를 대비해 한 번 더 출력
        cout << (char)s.top();
        s.pop();
    }
}