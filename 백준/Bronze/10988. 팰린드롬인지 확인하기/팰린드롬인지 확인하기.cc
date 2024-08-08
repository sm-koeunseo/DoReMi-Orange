#include <iostream>
#include <vector>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    string s;
    cin >> s;

    int l = s.size()-1;
    for (int i=(l+1)/2-1; i>-1; i--){
        if (s[i] != s[l-i]){
            cout << 0;
            return 0;
        }
    }

    cout << 1;
    return 0;
    
}