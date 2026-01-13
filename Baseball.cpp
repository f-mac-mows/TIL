#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <map>

using namespace std;

extern string submit(int);

// 두 숫자 사이의 Strike/Ball 계산 (필터링용)
pair<int, int> get_hint(int target, int guess) {
    string s_target = to_string(target);
    string s_guess = to_string(guess);
    int s = 0, b = 0;
    for (int i = 0; i < 4; ++i) {
        if (s_target[i] == s_guess[i]) s++;
        else {
            for (int j = 0; j < 4; ++j) {
                if (s_target[i] == s_guess[j]) {
                    b++;
                    break;
                }
            }
        }
    }
    return {s, b};
}

// "xS yB" 파싱
pair<int, int> parse_result(string result) {
    return {result[0] - '0', result[3] - '0'};
}

// 에러 메시지에 맞게 파라미터를 n 하나로 수정
int solution(int n) {
    vector<int> candidates;
    // 1~9 서로 다른 4자리 숫자 생성
    for (int i = 1; i <= 9; ++i) {
        for (int j = 1; j <= 9; ++j) {
            if (i == j) continue;
            for (int k = 1; k <= 9; ++k) {
                if (i == k || j == k) continue;
                for (int l = 1; l <= 9; ++l) {
                    if (i == l || j == l || k == l) continue;
                    candidates.push_back(i * 1000 + j * 100 + k * 10 + l);
                }
            }
        }
    }

    vector<int> all_possible = candidates;

    while (!candidates.size() == 0) {
        int best_guess = -1;
        
        // n이 매우 작을 때(6, 9 등)를 대비한 Minimax 최적화
        if (candidates.size() == 3024) {
            best_guess = 1234; 
        } else if (candidates.size() == 1) {
            best_guess = candidates[0];
        } else {
            int min_max_partition = 10000;
            // 연산 속도를 위해 남은 후보군 중에서만 최적의 수를 찾음
            for (int guess : candidates) {
                map<pair<int, int>, int> partition_size;
                for (int cand : candidates) {
                    partition_size[get_hint(cand, guess)]++;
                }

                int max_size = 0;
                for (auto const& [hint, count] : partition_size) {
                    max_size = max(max_size, count);
                }

                if (max_size < min_max_partition) {
                    min_max_partition = max_size;
                    best_guess = guess;
                }
            }
        }

        string res_str = submit(best_guess);
        pair<int, int> res = parse_result(res_str);

        if (res.first == 4) return best_guess;

        vector<int> next_candidates;
        for (int cand : candidates) {
            if (get_hint(cand, best_guess) == res) {
                next_candidates.push_back(cand);
            }
        }
        candidates = next_candidates;
    }

    return -1;
}