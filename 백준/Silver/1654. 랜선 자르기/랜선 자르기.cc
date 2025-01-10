#include <bits/stdc++.h>
using namespace std;

int k, n, tmp;
long long l = 0, mid = 0, num;
vector<int> line;

long long line_search(long long start, long long end){
    long long result = 0;
    while (start <= end){
        mid = (start + end) / 2;
        num = 0;
        for (int a : line) num += a/mid;

        if (num >= n){
            result = mid;
            start = mid + 1;
        } else if (num < n) end = mid - 1;
    }

    return result;
}

int main(){    
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> k >> n;

    for (int i=0; i<k; i++){
        cin >> tmp;
        line.push_back(tmp);
        l += tmp;
    }

    cout << line_search(1, l/n);
}