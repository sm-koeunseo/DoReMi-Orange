#include <bits/stdc++.h>
using namespace std;

int n;
char a[10];
vector<int> v1;
vector<int> v2;
bool flag, check;

int main(){
    cin >> n;
    for (int i=0; i<n; i++){
        cin >> a[i];
        v1.push_back(9-i);
        v2.push_back(i);
    }
    v1.push_back(9-n);
    v2.push_back(n);

    flag = true;
    do{
        check = true;
        for (int i=0; i<n; i++){
            if (!((a[i] == '<' && v1[i] < v1[i+1]) or (a[i] == '>' && v1[i] > v1[i+1]))){
                check = false;
                break;
            }
        }
        if (check)
            flag = false;
    }while(flag && prev_permutation(v1.begin(), v1.end()));

    for (int i=0; i<n+1; i++){
        cout << v1[i];
    }
    cout << "\n";

    flag = true;
    do{
        check = true;
        for (int i=0; i<n; i++){
            if (!((a[i] == '<' && v2[i] < v2[i+1]) or (a[i] == '>' && v2[i] > v2[i+1]))){
                check = false;
                break;
            }
        }
        if (check)
            flag = false;
    }while(flag && next_permutation(v2.begin(), v2.end()));

    for (int i=0; i<n+1; i++){
        cout << v2[i];
    }

    return 0;
}