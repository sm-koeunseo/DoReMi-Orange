#include <iostream>
#include <vector>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int num, tmp;
    cin >> num;                     // 개수 입력
    vector<int> v;
    bool flag = false;              // continue를 위한 flag

    for (int i=0; i<num; i++){      // 개수만큼 for문 돌려서 입력 받기
        cin >> tmp;                 // 현재 vector의 개수만큼 for문 돌리기
        for (int j=v.size()-1; j>-1; j--){
            if (tmp < v[j]){        // 현재 입력받은 수가 vector의 수보다 작다면
                cout << (j+1) << " ";
                v.push_back(tmp);   // 해당 vector의 index 출력 후 vector에 현재 입력값 push
                flag = true; 
                break;
            }
        }
        if (flag){                  // 위에서 출력이 있었다면 continue
            flag = false;
            continue;
        }
        else {                      // 출력이 없었다면 0 출력 후 vector에 현재 입력값 push
            cout << "0 ";
            v.push_back(tmp);
        }
    }
}