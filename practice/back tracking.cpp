// #include <bits/stdc++.h>
// using namespace std;
// int n, temp, ret, cnt;
// vector<int> v;
// const int mod = 11;
// void go(int idx, int sum)
// {
//     if(ret == 10) return;
//     if (idx == n)
//     {

//         ret = max(ret, sum % mod);
//         cnt++;
//         return;
//     }
//     go(idx + 1, sum + v[idx]);
//     go(idx + 1, sum);
// }
// int main()
// {
//     cin >> n;
//     for (int i = 0; i < n; i++)
//     {
//         cin >> temp;
//         v.push_back(temp);
//     }
//     go(0, 0);
//     cout << ret << "\n";
//     cout << cnt << "\n";
//     return 0;
// }

// #include <bits/stdc++.h>
// using namespace std;
// int visited[4];
// vector<int> adj[4];
// vector<int> v;
// void print()
// {
//     for (int i : v)
//         cout << char(i + 'A') << " ";
//     cout << '\n';
// }
// void go(int idx)
// {
//     if (v.size() == 3)
//     {
//         print();
//         return;
//     }
//     for (int there : adj[idx])
//     {
//         if (visited[there])
//             continue;
//         visited[there] = 1;
//         v.push_back(there);
//         go(there);
//         visited[there] = 0;
//         v.pop_back();
//     }
// }
// int main()
// {
//     adj[0].push_back(1);
//     adj[1].push_back(2);
//     adj[1].push_back(3);
//     adj[1].push_back(0);
//     adj[2].push_back(1);
//     adj[3].push_back(1);

//     visited[0] = 1;
//     v.push_back(0);
//     go(0);
//     return 0;
// }

#include <bits/stdc++.h>
using namespace std;
const int n = 3;
int a[3][3] = {
    {10, 20, 21},
    {70, 90, 12},
    {80, 110, 120}};
int visited[3][3];
const int dy[] = {-1, 0, 1, 0};
const int dx[] = {0, 1, 0, -1};
vector<int> v;
void print()
{
    for (int i : v)
        cout << i << " ";
    cout << '\n';
}
void go(int y, int x)
{
    if (y == n - 1 && x == n - 1)
    {
        print();
        return;
    }
    for (int i = 0; i < 4; i++)
    {
        int ny = y + dy[i];
        int nx = x + dx[i];
        if (ny < 0 || nx < 0 || ny >= n || nx >= n)
            continue;
        if (visited[ny][nx])
            continue;
        visited[ny][nx] = 1;
        v.push_back(a[ny][nx]);
        go(ny, nx);
        visited[ny][nx] = 0;
        v.pop_back();
    }
}
int main()
{
    visited[0][0] = 1;
    v.push_back(a[0][0]);
    go(0, 0);
    return 0;
}