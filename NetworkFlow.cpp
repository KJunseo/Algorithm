#include <iostream>
#include <vector>
#include <queue>

#define MAX 100 // 가능한 최대 노드 갯수
#define INF 1000000000 // 무한대

using namespace std;

int n = 6; // 노드의 갯수
int result; // 최대 유량

int c[MAX][MAX]; // 용량을 담아주는 배열
int f[MAX][MAX]; // 현재 흐르고 있는 유량

int d[MAX]; // 방문 여부 검사

vector <int> a[MAX];

// 최대 유량을 구하는 함수 
void maxFlow(int start, int end) {

    // 반복적으로 모든 경로 탐색
    while(1) {
        fill(d, d+MAX, -1); // 모든 노드를 방문하지 않았으므로 -1로 초기화
        queue<int> q;
        q.push(start); // 시작점을 큐에 넣어줌
        
        // BFS
        while(!q.empty()) {
            int x = q.front(); // 큐에서 하나를 꺼내
            q.pop();
            for(int i=0;i<a[x].size();i++) { // 인접 노드 전부 확인
                int y = a[x][i]; // 인접 노드 정보

                // 방문하지 않은 노드 중에서 용량이 남은 경우 검사
                if(c[x][y] - f[x][y] > 0 && d[y] == -1) {
                    q.push(y);
                    d[y] = x; // 현재 방문한 노드를 인접노드로 가는 값으로 넣어줌(경로 기억)

                    if(y == end) break; // 도착지에 도달한 경우 
                }
            }
        }

        if(d[end] == -1) break; // 모든 경로를 찾은 후 탈출(BFS 수행 후, 도착지에 도달하지 못하면 모든 경로를 이미 찾은 것이기 때문임)
        int flow = INF; // 최솟값을 찾아 주기 위함 

        // end부터 start까지 돌아오며 최소 유량 탐색(한 번 반복마다, 자기 이전 경로를 찾아 돌아옴)
        for(int i=end;i!=start;i=d[i]) {
            flow = min(flow, c[d[i]][i] - f[d[i]][i]); // 간선 마다 남은 유량 확인하여 최솟값 찾음
        }

        // 최소 유량만큼 추가
        for(int i=end;i!=start;i=d[i]) {
            f[d[i]][i] += flow;
            f[i][d[i]] -= flow; // 음의 유량 처리 
        }

        result += flow; // 최대 유량
    }
}


int main(void) {

    a[1].push_back(2);
    a[2].push_back(1); // 음의 유량도 확인하기 위함 
    c[1][2] = 12; // 용량 

    a[1].push_back(4);
    a[4].push_back(1); // 음의 유량도 확인하기 위함 
    c[1][4] = 11;

    a[2].push_back(3);
    a[3].push_back(2);
    c[2][3] = 6;

    a[2].push_back(4);
    a[4].push_back(2);
    c[2][4] = 3;

    a[2].push_back(5);
    a[5].push_back(2);
    c[2][5] = 5;

    a[2].push_back(6);
    a[6].push_back(2);
    c[2][6] = 9;

    a[3].push_back(6);
    a[6].push_back(3);
    c[3][6] = 8;

    a[4].push_back(5);
    a[5].push_back(4);
    c[4][5] = 9;

    a[5].push_back(3);
    a[3].push_back(5);
    c[5][3] = 3;

    a[5].push_back(6);
    a[6].push_back(5);
    c[5][6] = 4;

    maxFlow(1,6);

    printf("최대 유량: %d\n", result);
    return 0;
}