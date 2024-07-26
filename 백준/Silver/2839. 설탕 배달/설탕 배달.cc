#include <iostream>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int s, c=0;
    cin >> s;

    while (s > -1){
        if (s%5 == 0){
            c += s/5;
            cout << c;
            return 0;
        }
        s -= 3;
        c++;
    }
    cout << -1;
}