#include <bits/stdc++.h>
using namespace std;

int n;
vector<string> v;
string str1, str2;

void save(){
    string tmp = "";
    bool chk = true;
    int i=0;

    for (; i<str2.size() && chk; i++){
        if (str2[i] != '0')
            chk = false;
    }
    for (i=i-1; i<str2.size(); i++){
        tmp += str2[i];
    }
        
    if (tmp.size() > 0)
        v.push_back(tmp);
    str2 = "";
}

bool cmp(string a, string b){
    if (a.size() == b.size()) return a < b;
    return a.size() < b.size();
}

int main(){    
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;
    for (int i=0; i<n; i++){
        cin >> str1;
        str2 = "";
        for (int j=0; j<str1.length(); j++){
            if (str1[j] < '0' || str1[j] > '9'){
                save();
            } else {
                str2 += str1[j];
            }
        }
        save();
    }

    sort(v.begin(), v.end(), cmp);
    for (int i=0; i<v.size(); i++){
        cout << v[i] << "\n";
    }
    
    return 0;
}