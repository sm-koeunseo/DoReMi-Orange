#include <iostream>
#include <queue>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int num;
    cin >> num;         // 카드 개수 입력
    queue<int> q;       // 카드를 오름차순으로 queue에 push
    for (int i=1; i<num+1; i++){
        q.push(i);
    }

    while(q.size()>1){  // queue에 남은 카드가 한장일 때까지
        cout << q.front() << " ";
        q.pop();        // 버리는 카드 출력

        q.push(q.front());
        q.pop();        // 그 다음 카드는 빼서 가장 밑으로 이동 (선입후출로 처리)
    }

    cout << q.front();
}