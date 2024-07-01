#include <iostream>
#include <stack>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    // 스택 선언
    stack<int> s;

    // 막대기 개수, 임시값, 최대값, 개수
    int num, tmp, max=0, cnt=0;
    cin >> num;
    // 순서대로 tmp에 담아 스택에 push
    for(int i=0; i<num; i++){
        cin >> tmp;
        s.push(tmp);
    }
    // 다시 하나씩 빼며 검증, 현재의 값이 지금까지 나온 값들 중 최대값이라면 보일 것
    for(int i=0; i<num; i++){
        tmp = s.top();
        s.pop();
        if (tmp > max){
            max = tmp;  // 최대값 변경
            cnt++;      // 보이는 막대기 개수 증가
        }
    }

    cout << cnt;
}