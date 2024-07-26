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

    while(price/500 > 0){
        price -= 500;
        cnt++;
    }

    while(price/100 > 0){
        price -= 100;
        cnt++;
    }

    while(price/50 > 0){
        price -= 50;
        cnt++;
    }

    while(price/10 > 0){
        price -= 10;
        cnt++;
    }

    while(price/5 > 0){
        price -= 5;
        cnt++;
    }

    cnt += price;
    cout << cnt;
}