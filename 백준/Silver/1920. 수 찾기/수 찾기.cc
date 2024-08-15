#include <iostream>
#include <algorithm>
using namespace std;

int a[100000];
int n;

void binary_search(int key){
    int start = 0;
    int end = n-1;
    int mid;

    while (end >= start){
        mid = (start+end)/2;
        if (a[mid] == key){
            cout << 1 << "\n";
            return;
        } else if (a[mid]>key)
            end = mid - 1;
        else
            start = mid + 1;
    }
    cout << 0 << "\n";
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;   // 배열 입력받기
    for (int i=0; i<n; i++)
        cin >> a[i];

    sort(a, a+n);   // 정렬

    int m, t;
    cin >> m;
    for (int i=0; i<m; i++){
        cin >> t;   // 하나씩 입력받아 저장된 배열 안에 있는지 없는지 체크
        binary_search(t);
    }
}