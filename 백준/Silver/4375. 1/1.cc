#include <iostream>
using namespace std;
typedef long long ll;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    // 11... 만들기 => n = (n-1)*10+1
    ll n;
    while(scanf("%d", &n) != EOF){
        ll cnt = 1, ret = 1;
        while(true){
            if (cnt % n == 0){
                printf("%lld\n", ret);
                break;
            }else{
                cnt = (cnt * 10) + 1;
                cnt %= n;
                ret++;
            }
        }
    }
}