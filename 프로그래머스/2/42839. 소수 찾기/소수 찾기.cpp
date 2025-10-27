#include <string>
#include <vector>
#include <unordered_set>

using namespace std;

unordered_set<int> s;

bool isPrime(int n) {
    if (n < 2) return false;
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) return false;
    }
    return true;
}

void check(string numbers, string cur, vector<bool>& visited) {
    if (!cur.empty()) {
        int num = stoi(cur);
        if (isPrime(num)) s.insert(num);
    }

    for (int i = 0; i < numbers.size(); i++) {
        if (!visited[i]) {
            visited[i] = true;
            check(numbers, cur + numbers[i], visited);
            visited[i] = false;
        }
    }
}

int solution(string numbers) {
    s.clear();
    vector<bool> visited(numbers.size(), false);
    check(numbers, "", visited);
    return s.size();
}