#include <bits/stdc++.h>
using namespace std;

int main(){
    int n, m;
    cin >> n >> m;
    vector<string> poketmon(n + 1);
    unordered_map<string, int> poketmonMap;
    string str;
    int num;

    n++;
    for(int i=1; i<n; i++){
        cin >> poketmon[i];
        poketmonMap[poketmon[i]] = i;
    }
    for (int i=0; i<m; i++){
        cin >> str;
        if (isdigit(str[0])){
            num = stoi(str);
            cout << poketmon[num] << "\n";
        }else{
            cout << poketmonMap[str] << "\n";
        }
    }
}