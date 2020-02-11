#include <iostream>
#include <vector>

#define MAX 101 // 최대 정점 갯수

using namespace std;

vector <int> a[MAX]; // 각 정점과 연결된 간선 정보
int d[MAX]; // 특정B 집단을 점유하고 있는 A 집단 노드 정보
bool c[MAX]; // 특정 노드를 이미 처리했는 지 여부
int n = 3; // 노드 수
int m; // 간선 수

// 매칭에 성공한 경우 true, 실패한 경우 false를 리턴하는 DFS
bool dfs(int x) {
    // 연결된 모든 노드에 대해서 들어갈 수 있는 지 시도 
    for(int i=0;i<a[x].size();i++) {
        int t = a[x][i]; // 연결된 노드

        // 이미 처리한 노드는 더 이상 확인 x
        if(c[t]) continue;
        c[t] = true; 

        // 비어 있거나, 점유 노드에 더 들어갈 공간이 있는 경우
        // 해당 노드와 매칭
        if(d[t]==0||dfs(d[t])) {
            d[t] = x;
            return true;
        }
    }
    return false;
}

int main(void) {
    a[1].push_back(1);
    a[1].push_back(2);
    a[1].push_back(3);
    a[2].push_back(1);
    a[3].push_back(2);

    int count = 0; // 최대 매칭 수

    // 매번 매칭 할 때 마다, 기본적으로 처리되지 않았다고 생각
    for(int i=1;i<=n;i++) {
        fill(c, c+MAX, false); 
        if(dfs(i)) count++;
    }
    printf("총 %d개의 매칭이 이루어졌습니다\n", count);

    // 구체적인 매칭 정보
    for(int i=1;i<MAX;i++) {
        if(d[i]!=0) {
            printf("%d -> %d\n", d[i], i);
        }
    }
    return 0;
}
