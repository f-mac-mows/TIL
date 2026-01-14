#include <iostream>

int main(int argc, char** argv){
    
    int n = 13;
    int w = 3;
    int num = 6;
    int idx = 0xFFFFFFFF;
    int line = (n % w) > 0 ? (n / w) + 1 : (n / w);
    int answer = 0;
    int a[line][w];
    for (int i = 0; i < line; ++i) {
        for (int j = 0; j < w; ++j) {
            // 2차원 배열 생성
            if (i % 2 == 0) {
                a[i][j] = (i * w) + (j + 1);
                if (a[i][j] > n) {
                    a[i][j] = 0;
                }

                if (a[i][j] == (i * w) + (idx + 1)) {
                    std::cout << "홀수 라인" << a[i][j] << std::endl;
                    answer++;
                }
                std::cout << a[i][j] << std::endl;
            }
            else {
                a[i][j] = (i * w) + (w - j);
                if (a[i][j] > n) {
                    a[i][j] = 0;
                }

                if (a[i][j] == (i * w) + (w - idx)) {
                    std::cout << "짝수 라인" << a[i][j] << std::endl;
                    answer++;
                }
                std::cout << a[i][j] << std::endl;
            }

            // 첫 번째 찾기
            if (a[i][j] == num) {
                std::cout << "찾음" << a[i][j] << std::endl;
                answer++;
                idx = j;
            }
        }
        std::cout << std::endl;
    }
    std::cout << answer << std::endl;
}
