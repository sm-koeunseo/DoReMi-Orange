#include <bits/stdc++.h>
using namespace std;

int a[51][51];
vector<pair<int, int>> chicken, house;
int n, m, d = INT_MAX, cd, pd, tmp;

int main(){    
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> m;
    n++;
    for (int i=1; i<n; i++)
        for (int j=1; j<n; j++){
            cin >> a[i][j];
            if (a[i][j] == 1) house.push_back(make_pair(i, j));
            else if (a[i][j] == 2) chicken.push_back(make_pair(i, j));
        }

    do{

        cd = 0;
        for (int i=0; i<house.size(); i++){
            pd = INT_MAX;
            for (int j=0; j<m; j++){
                pd = min(pd, abs(house[i].first - chicken[j].first) + abs(house[i].second - chicken[j].second));
            }
            cd += pd;
        }
        d = min(d, cd);

    }while(next_permutation(chicken.begin(), chicken.end()));

    cout << d;
    return 0;
}