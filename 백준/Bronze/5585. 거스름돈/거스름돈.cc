#include <iostream>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int price;
    cin >> price;
    price = 1000 - price;
    int cnt = 0;

    int money[5] = {500, 100, 50, 10, 5};

    for (int i=0; i<5; i++){
        while(price/money[i] > 0){
            price -= money[i];
            cnt++;
        }
    }

    cnt += price;
    cout << cnt;
}