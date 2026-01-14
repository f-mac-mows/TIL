#include <string>
#include <vector>

using namespace std;

int solution(vector<int> players, int m, int k) {
    int answer = 0;
    vector<int> count(24, 0);
    
    // 전체 시간대
    for (int i = 0; i < 24; ++i) {
        int current = 0;

        // 현재 시간까지 증설된 서버 개수
        for (int j = max(0, i - k + 1); j <= i; ++j) {
            current += count[j];
        }
    
        // 필요한 서버 개수
        int needed = players[i] / m;
        
        // 추가로 필요한 서버 개수 계산
        if (current < needed) {
            int diff = needed - current;
            count[i] = diff;
            answer += diff;
        }
    }
    return answer;
}