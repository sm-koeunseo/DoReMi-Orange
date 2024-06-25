#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n1, n2;
    vector <int> v1;
    int i, tmp;

    cin >> n1;
    for (i=0; i<n1; i++){
        cin >> tmp;
        v1.push_back(tmp);
    }
    sort(v1.begin(), v1.end());

    cin >> n2;
    for (i=0; i<n2; i++){
        cin >> tmp;
        cout << binary_search(v1.begin(), v1.end(), tmp) << " ";
    }
}
