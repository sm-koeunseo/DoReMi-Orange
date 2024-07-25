#include <iostream>
using namespace std;

void star(int i, int j, int num){
    // 가장 작은 계층으로 왔다면 * 출력
    if ( num == 1 )
        cout << '*';
    // num/3 = 모든 칸을 아홉 덩위로 나누기 위한 피연산자 생성
    // i/~ = num이 3이라면 1이 빈칸, num이 9라면 3~5가 빈칸, num이 27이라면 9~17이 빈칸
    else if ( (i/(num/3))%3 == 1 && (j/(num/3))%3 == 1)
        cout << ' ';
    // 위 분기에 해당하지 않다면 num의 계층을 줄여 재귀호출
    else
        star(i, j, num/3);
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int num;
    cin >> num; // 한 칸마다 star 함수 호출
    for (int i=0; i<num; i++){
        for (int j=0; j<num; j++)
            star(i, j, num);
        cout<<endl;
    }
}