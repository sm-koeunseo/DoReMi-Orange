#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    // 강의 개수, 블루레이 개수
    int countC, countB;
    cin >> countC >> countB;

    // 한 블루레이의 최소/최대 길이
    int s=0, l=0, result=0;

    // 각 강의 길이
    vector<int> v;
    int tmp;
    for (int i=0; i<countC; i++){
        cin >> tmp;
        v.push_back(tmp);
        l += tmp;
    }

    while (s <= l){
        int mid = (s+l)/2;  // 현재 블루레이 한 개의 크기 (이진탐색으로 중앙값 적용)

        int cnt = 1;        // 현재 필요한 블루레이 개수
        int sum = 0;        // 현재 블루레이에 녹화된 길이

        // 모든 강의를 녹화하기 위한 블루레이 개수 구하기
        for (int i=0; i<countC; i++){
            if (mid < v[i]){        // i번째 강의의 크기가 블루레이 한개 크기보다 크다면 녹화 불가
                cnt = countB+1;     // 필요 블루레이 수 증가 -> 추후 블루레이 크기를 증가시키기 위해
                break; 
            }
            if (sum + v[i] <= mid)  // 현재 블루레이에 i번째 강의 녹화 가능하다면 녹화
                sum += v[i];
            else{                   // 녹화 불가능하다면 새로운 블루레이에 녹화
                sum = v[i];
                cnt++;
            }
        }

        if (cnt <= countB){     // 필요 블루레이 수가 주어진 개수보다 적다면 블루레이 크기 감소
            result = mid;
            l = mid - 1;
        } else                  // 필요 블루레이 수가 주어진 개수보다 많다면 블루레이 크기 증가
            s = mid + 1;
    }

    cout << result;
}