#include <iostream>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int p, tmp;
    cin >> p;
    for (int i=0; i<9; i++){
        cin >> tmp;
        p -= tmp;
    }

    cout << p;
}