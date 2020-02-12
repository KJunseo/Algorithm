#include <iostream>

using namespace std;

int findString(string parent, string pattern) {
    int parentSize = parent.size(); // 전체 문자열 길이
    int patternSize = pattern.size(); // 찾으려는 문자열 길이

    for(int i=0;i<=parentSize - patternSize;i++) {
        bool finded = true;

        for(int j=0;j<patternSize;j++) {
            if(parent[i+j] != pattern[j]) {
                finded = false;
                break;
            }
        }

        if(finded) {
            return i;
        }
    }
    return -1;
}

int main(void) {
    string parent = "Hello World";
    string pattern = "o Wor";

    int result = findString(parent, pattern);

    if(result == -1) {
        printf("찾을 수 없습니다.\n");
    } else {
        printf("%d번 째에서 찾았습니다\n", result+1);
    }
    return 0;
}