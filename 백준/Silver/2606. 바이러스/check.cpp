#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>
using namespace std;

int num;
int set;
int cnt = 0;

vector <int> v;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int a, b;

    cin >> num >> set;

    v.push_back(1);
    for (int i=0; i<set; i++){
        cin >> a >> b;
        if(count(v.begin(), v.end(), a))
            if (!count(v.begin(), v.end(), b))
                v.push_back(b);
        else if (count(v.begin(), v.end(), b))
            if (!count(v.begin(), v.end(), a))
                v.push_back(b);
    }

    cout << v.size()-1 ;
}