#include <iostream>
#include <vector>
#include <queue>

#define MAX 10 // 10개 만큼의 노드

using namespace std;

int n; 
int inDegree[MAX]; // 진입 차수 의미

vector<int> a[MAX]; // 각 정점에 연결되어 있는 모든 노드 정보

void topologySort() {
    int result[MAX]; // 위상정렬을 수행한 결과값 담는 배열
    queue<int> q;

    // 진입 차수가 0인 node 큐에 삽입
    for(int i=1;i<=n;i++) {
        if(inDegree[i] == 0) {
               q.push(i); 
        }
    }

    // 위상 정렬이 완전히 수행되려면 정확히 N개의 노드 방문해야함 
    for(int i=1;i<=n;i++) {
        // n개의 노드를 방문하기 전에 큐가 비면 사이클 발생 
        if(q.empty()) {
            printf("사이클이 발생했습니다.\n");
            return ;
        }
        // 큐의 가장 앞의 원소를 빼서 result 배열에 넣어줌 
        int x = q.front();
        q.pop();
        result[i] = x;

        // 꺼낸 원소에 연결이 되어있는 모든 정점들을 확인하면서 간선제거 
        for(int i=0;i<a[x].size();i++) {
            int y = a[x][i];

            // 진입차수가 0인 노드 큐에 삽입
            if(--inDegree[y]==0) {
                q.push(y);
            }
        }
    }

    // 결과 출력
    for(int i=1;i<=n;i++) {
        printf("%d ", result[i]);
    }
 
}

int main(void) {
    n = 7; // 노드 개수

    a[1].push_back(2); // 1번 노드 -> 2번 노드
    inDegree[2]++; // 2번 노드의 진입차수 1 증가

    a[1].push_back(5); 
    inDegree[5]++; 

    a[2].push_back(3); 
    inDegree[3]++; 

    a[3].push_back(4); 
    inDegree[4]++; 

    a[4].push_back(6); 
    inDegree[6]++; 

    a[5].push_back(6); 
    inDegree[6]++; 

    a[6].push_back(7); 
    inDegree[7]++; 

    topologySort();
    return 0;
}