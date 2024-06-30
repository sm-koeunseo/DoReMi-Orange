#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int a, b, num, value;
    cin >> a >> b;
    int cnt = 1;

    vector <int> v;
    v.push_back(a);

    while(true){
        value = 0;

        value = pow(a/1000, b) + pow((a%1000)/100, b) + pow((a%100)/10, b) + pow((a%10), b);

        if (!count(v.begin(), v.end(), value))
            cnt++;
        else if (count(v.begin(), v.end(), value) == 1)
            cnt--;
        else if (count(v.begin(), v.end(), value) > 1){
            break;
        }

        v.push_back(value);
        a = value;
    }

    cout << cnt;
}