#include <bits/stdc++.h>
using namespace std;

string str;
int aioue;
int j, m;
char alpha;
char c;
bool flag;

int main(){
    cin >> str;
    while (str.compare("end")){
        flag = true;
        aioue = 0;
        j = 0;
        m = 0;
        alpha = '\0';

        if (str.size() > 20){
            flag = false;
        } else{
            for (int i=0; i<str.size(); i++){
                c = str[i];

                switch (c){
                case 'a': case 'i': case 'o': case 'u': case 'e':
                    aioue++;
                    j = 0; m++;
                    if (m > 2){
                        flag = false;
                    }
                break;
                default:
                    m = 0; j++;
                    if (j > 2){
                        flag = false;
                    }
                }

                if (alpha == c && c != 'e' && c != 'o'){
                    flag = false;
                }
                alpha = c;
            }
        }

        if (aioue == 0){
            flag = false;
        }

        if (flag){
            cout << "<" << str << "> is acceptable.\n";
        }else {
            cout << "<" << str << "> is not acceptable.\n";
        }
        cin >> str;
    }
}