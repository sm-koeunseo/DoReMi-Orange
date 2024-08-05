#include <iostream>
#include <vector>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int l, p, v;
    vector<int> c;

    int case_num = 1;

    while (true){
        cin >> l >> p >> v;

        if (l == 0 && p == 0 && v == 0) {
            break;
        }

        int full_periods = v / p;
        int remaining_days = v % p;

        int max_days = full_periods * l;
        if (remaining_days > l) {
            max_days += l;
        } else {
            max_days += remaining_days;
        }

        c.push_back(max_days);
    }

    for (int i = 0; i < c.size(); i++) {
        cout << "Case " << (i + 1) << ": " << c[i] << endl;
    }

    return 0;
}
