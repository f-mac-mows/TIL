#include <iostream>

using namespace std;

// 1번 문자 출력
int main(void) {
    string message = "";

    cout << "3\n2\n1" << endl;
    cout << message << endl;

    return 0;
}

// 2번 각도 합치기
#include <iostream>

using namespace std;

int main(void) {
    int angle1;
    int angle2;
    cin >> angle1 >> angle2;
    
    int sum_angle = (angle1 + angle2) % 360;
    cout << sum_angle << endl;
    return 0;
}

// 3번 수 나누기
#include <iostream>

using namespace std;

int main(void) {
    int number;
    cin >> number;
    
    int answer = 0;
    
    for(int i=0; i<5; i++){
        answer += number % 100;
        number /= 100;
    }
    cout << answer << endl;
    return 0;
}

// 4번 병과분류
#include <iostream>

using namespace std;

int main(void) {
    string code;
    cin >> code;
    string last_four_words = code.substr(code.size()-4, 4);
    if(last_four_words == "_eye"){
        cout << "Ophthalmologyc";
    }
    else if(last_four_words == "head"){
        cout << "Neurosurgery";
    }
    else if(last_four_words == "infl"){
        cout << "Orthopedics";
    }
    else if (last_four_words == "skin")
    {
        cout << "Dermatology";
    }
    else
    {
        cout << "direct recommendation";
    }
    return 0;
}

// 5번 심폐소생술
#include <string>
#include <vector>

using namespace std;
vector<int> solution(vector<string> cpr) {
    vector<int> answer = {0, 0, 0, 0, 0};
    vector<string> basic_order = {"check", "call", "pressure", "respiration", "repeat"};

    for(int i=0; i<5; i++){
        for(int j=0; j<5; j++){
            if(cpr[i] == basic_order[j]){
                answer[i] = j+1;
                break;
            }
        }
    }

    return answer;
}

// 6번 물 부족
#include <string>
#include <vector>

using namespace std;

int solution(int storage, int usage, vector<int> change) {
    int total_usage = 0;
    for(int i=0; i<change.size(); i++){
        usage += usage * change[i] / 100;
        total_usage += usage;
        if(total_usage > storage){
            return i;
        }
    }
    return -1;
}

// 7번 버스 
#include <string>
#include <vector>

using namespace std;

int func1(int num){
    if(0 > num){
        return 0;
    }
    else{
        return num;
    }
}

int func2(int num){
    if(num > 0){
        return 0;
    }
    else{
        return num;
    }
}

int func3(vector<string> station){
    int num = 0;
    for(int i=0; i<station.size(); i++){
        if(station[i] == "Off"){
            num += 1;
        }
    }
    return num;
}

int func4(vector<string> station){
    int num = 0;
    for(int i=0; i<station.size(); i++){
        if(station[i] == "On"){
            num += 1;
        }
    }
    return num;
}

int solution(int seat, vector<vector<string>> passengers) {
    int num_passenger = 0;
    for(int i=0; i<passengers.size(); i++){
        num_passenger += func4(passengers[i]);
        num_passenger -= func3(passengers[i]);
    }
    int answer = func1(seat-num_passenger);
    return answer;
}