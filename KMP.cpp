#include <iostream>
#include <vector>

using namespace std;

// 실패함수 구현(접두사와 접미사 최대 일치 길이 비교)
vector<int> makeTable(string pattern) {
    int patternSize = pattern.size();

    vector<int> table(patternSize, 0);

    int j=0;
    for(int i=1;i<patternSize;i++) {

        // j 인덱스가 0이상인데, i번째와 j번째 문자가 일치하지 않는다면, 
        while(j>0&&pattern[i]!=pattern[j]) {
            j = table[j-1]; // 한 칸 뒤로 백 
        }

        if(pattern[i]==pattern[j]) {
            table[i] = ++j;
        }
    }

    return table;
}

void KMP(string parent, string pattern) {
    vector<int> table = makeTable(pattern); 

    int parentSize = parent.size();
    int patternSize = pattern.size();

    int j=0;
    for(int i=0;i<parentSize;i++) {
        while(j>0&&parent[i]!=pattern[j]) {
            j = table[j-1]; // 일치 하지 않았을 때, 이전 단계에 있던 값으로 이동 
        }

        if(parent[i]==pattern[j]) {
            if(j==patternSize-1) {
                printf("%d번 째에서 찾았습니다\n", i - patternSize +2);
                j = table[j]; // 찾았어도 다음에 또 일치할 수 있기 때문에 점프
            } else {
                j++; // 단순히 매칭만 이루어졌기 때문에 j만 증가시켜 매칭 확인 
            }
        }
    }
}

int main(void) {
    string parent="abacaabaqweabacaabaqww";
    string pattern = "abacaaba";
    KMP(parent, pattern);
    return 0;
}