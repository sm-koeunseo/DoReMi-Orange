#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;

    vector<pair<int,int>> v;
    int s, e;
    for (int i=0; i<n; i++){
        cin >> s >> e;
        v.push_back(make_pair(e, s));
    }

    sort(v.begin(), v.end());
    int t = v[0].first;
    int m=1;
    for (int i=1; i<n; i++)
        if (v[i].second >= t) {
            m++;
            t = v[i].first;
        }
    
    cout << m;
}