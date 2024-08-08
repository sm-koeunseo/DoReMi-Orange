#include <iostream>
#include <vector>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    vector<string> v;
    string s;
    cin >> s;

    while (s != "0"){
        v.push_back(s);
        cin >> s;
    }

    bool f;
    for (int i=0; i<v.size(); i++){
        s = v[i];
        f = true;
        int l = s.size()-1;
        for (int i=(l+1)/2-1; i>-1; i--){
            if (s[i] != s[l-i]){
                cout << "no" << endl;
                f = false;
                break;
            }
        }
        if (f)
            cout << "yes" << endl;
    }
    
}