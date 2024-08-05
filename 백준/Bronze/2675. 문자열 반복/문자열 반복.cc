#include <iostream>
#include <vector>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    vector<int> vi;     // 숫자, 문자열 저장할 벡터값
    vector<string> vs;
    int ti;             // 임시값
    string ts;

    int n;
    cin >> n;
    for (int i=0; i<n; i++){
        cin >> ti >> ts;    // 입력값 임시 저장 후 벡터로 push
        vi.push_back(ti);
        vs.push_back(ts);
    }

    for (int i=0; i<vi.size(); i++){        // 입력받은 문자열 만큼 반복
        for (int j=0; j<vs[i].size(); j++){ // 입력받은 int 수만큼
            for (int k=0; k<vi[i]; k++){    // 각 문자열 반복
                cout<<vs[i][j];
            }
        }
        cout<<endl;
    }
}