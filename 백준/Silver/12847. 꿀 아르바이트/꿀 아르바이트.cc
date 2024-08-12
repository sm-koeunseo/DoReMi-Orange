#include <iostream>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int d1, d2;     // n일(후보 날), m일(일을 할 수 있는 날)
    cin >> d1 >> d2;

    int a[100000];
    for (int i=0; i<d1; i++){
        cin >> a[i];
    }

    long m = 0, t;
    for (int i=0; i<d2; i++)
        m += a[i];

    t = m;
    int r=0, l=d2;
    while(l < d1){  // l이 최대일보다 작을 때까지
        t -= a[r];
        t += a[l];

        if (t > m)
            m = t;
        
        r++;
        l++;
    }

    cout << m;
}