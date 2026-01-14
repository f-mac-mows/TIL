#include <string>
#include <vector>

using namespace std;

int solution(int n, int w, int num) {
    // 총 개수 n
    // 줄 당 개수 w
    // 꺼낼 상자 num
    int answer = 0;
    
    // 2차원 배열
    int line = (n % w) > 0 ? (n / w) + 1 : (n / w);
    int a[line][w];
    for (int i = 0; i < line; ++i) {
        for (int j = 0; j < w; ++j) {
            if (line % 2 == 0) {
                a[i][j] = (line * w) + (j + 1);
            }
            else {
                a[i][j] = (line * w) + (w - j);
            }
        }
    }
    
    return answer;
}