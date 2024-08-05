#include <iostream>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, cnt=0;
    string t[50], t1, t2;
    char c;

    cin >> n;
    for (int i=0; i<n; i++){
        cin >> t[i];
    }

    for (int i=0; i<n-1; i++){
        t1 = t[i];
        for (int j=i+1; j<n; j++){
            t2 = t[j];

            bool b[26] = {0, };
            for (int k=0; k<t1.length(); k++){
                if(!(b[t1[k]-97] || b[t2[k]-97])){
                    for(int l=k+1; l<t1.length(); l++){
                        if (t2[k] == t2[l])
                            t2[l] = t1[k];
                    }
                    t2[k] = t1[k];
                    b[t1[k]-97] = true;
                    b[t2[k]-97] = true;
                }
            }
            if (t1.compare(t2) == 0){
                cnt++;
                cout << t1 << ", " << t2 << endl;
            }
        }
    }

    cout << cnt;
}