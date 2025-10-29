#include <string>
#include <vector>

using namespace std;

vector<int> solution(int brown, int yellow) {
    vector<int> answer;
    int h, w;
    
    for (h=2; h<=(brown + yellow) / h; h++){
        if ((brown + yellow) % h != 0) continue;
        w = (brown+yellow) / h;
        if (yellow == (w - 2) * (h - 2)) break;
    }
    
    return {w, h};
}