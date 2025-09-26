#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <sstream>

using namespace std;

map<string, vector<int>> db;

void insertInfo(vector<string> &info) {
    int score = stoi(info[4]); // 점수

    // 0~15 (4가지 조건 -> 16개 조합)
    for (int mask = 0; mask < (1 << 4); mask++) {
        string key = "";
        for (int i = 0; i < 4; i++) {
            if (mask & (1 << i)) key += "-";   // i번째 조건 무시
            else key += info[i];               // 원래 값 사용
            if (i < 3) key += " ";             // 구분자
        }
        db[key].push_back(score);
    }
}

vector<int> solution(vector<string> info, vector<string> query) {
    vector<int> answer;

    // 1. info 파싱 → db에 삽입
    for (auto &s : info) {
        stringstream ss(s);
        string a,b,c,d,score;
        ss >> a >> b >> c >> d >> score;
        vector<string> parsed = {a,b,c,d,score};
        insertInfo(parsed);
    }

    // 2. 각 key의 점수 리스트 정렬
    for (auto &p : db) {
        sort(p.second.begin(), p.second.end());
    }

    // 3. 쿼리 처리
    for (auto &q : query) {

        stringstream ss(q);
        string a,b,c,d; int score;
        string trash; // and 스킵
        ss >> a >> trash >> b >> trash >> c >> trash >> d >> score;

        string key = a + " " + b + " " + c + " " + d;

        // db에서 해당 key 찾기
        if (db.find(key) != db.end()) {
            auto &scores = db[key];
            // lower_bound → score 이상인 개수
            int cnt = scores.end() - lower_bound(scores.begin(), scores.end(), score);
            answer.push_back(cnt);
        } else {
            answer.push_back(0);
        }
    }

    return answer;
}