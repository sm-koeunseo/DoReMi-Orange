#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false); //표준 스트림 동기화 해제
    cin.tie(nullptr); //입출력 연결 끊기
    int N, M;
    vector<int> vec;
    cin >> N;
    for (int i = 0; i < N; ++i)
    {
        int input;
        cin >> input;
        vec.push_back(input);
    }
    sort(vec.begin(), vec.end());
    cin >> M;
    for (int i = 0; i < M; ++i)
    {
        int input;
        cin >> input;
        cout << binary_search(vec.begin(), vec.end(), input) << ' ';
    }
}