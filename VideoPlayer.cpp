#include <string>
#include <vector>
#include <iomanip>
#include <sstream>
#include <iostream>

using namespace std;

int stringToInt(string format) {
    return static_cast<int>((format[0] - '0') * 600 + (format[1] - '0') * 60 + (format[3] - '0') * 10 + format[4] - '0');
}

string intToString(int seconds) {
    int min = seconds / 60;
    int sec = seconds % 60;
    
    stringstream ss;
    
    ss << setfill('0') << setw(2) << min << ":" << setfill('0') << setw(2) << sec;
    
    return ss.str();
}

string solution(string video_len, string pos, string op_start, string op_end, vector<string> commands) {
    // "mm:ss"
    string answer = "";
    // 초로 변환
    int v_len = stringToInt(video_len);
    int p = stringToInt(pos);
    int start = stringToInt(op_start);
    int end = stringToInt(op_end);

    // 커맨드 로직
    for (auto c : commands) {
        if (p >= start && p <= end) {
            p = end;
        }
        
        if (c == "prev") {
            p -= 10;
            if (p < 0) p = 0;
        }
        else if ("next") {
            p += 10;
            if (p > v_len) p = v_len;
        }
        
        if (p >= start && p <= end) {
            p = end;
        }
    }
    answer = intToString(p);
    
    return answer;
}