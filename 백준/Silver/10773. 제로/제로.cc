#include <iostream>
#include <stack>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int num, tmp;
    cin >> num;                     // 줄 수 입력
    stack<int> s;
    for (int i=0; i<num; i++){
        cin >> tmp;                 // 숫자 입력
        if (tmp)    s.push(tmp);    // 0이 아닐 경우 push
        else        s.pop();        // 0일 경우 pop
    }

    num = 0;            // 더하기 위한 수 (num 재활용)
    tmp = s.size();     // 현재 stack의 크기 (tmp 재활용)
    for (int i=0; i<tmp; i++){
        num += s.top(); // 덧셈 후 pop
        s.pop();
    }
    cout << num;
}