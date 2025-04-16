#include <iostream>
#include <algorithm> 
#include <climits>
#include <vector>
using namespace std;

int N;
vector<int> num;
vector<char> op;
string str;
int i, t1, t2;
int ret = INT_MIN;

int cal(int num1, char op, int num2){
    if (op == '+') return num1 + num2;
    if (op == '-') return num1 - num2;
    if (op == '*') return num1 * num2;
}

void solve(int here, int _num){
    if (here == num.size() - 1){
        ret = max(ret, _num);
        return;
    }

    // 현재 연산자를 바로 계산하는 경우 (괄호 함함)
    solve(here + 1, cal(_num, op[here], num[here+1]));
    if(here + 2 < num.size()) { // 괄호를 쳐서 먼저 계산하는 경우
        int tmp = cal(num[here + 1], op[here + 1], num[here + 2]);
        solve(here + 2, cal(_num, op[here], tmp));
    }
    return;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> str;
    for (i=0; i<N/2; i++){
        num.push_back(str[i*2] - '0');
        op.push_back(str[i*2+1]);
    }
    num.push_back(str[i*2] - '0');

    // 현재 숫자의 index와 그 값 num[0] = 첫번째 피연산자
    solve(0, num[0]);
    cout << ret;
    return 0;
}
