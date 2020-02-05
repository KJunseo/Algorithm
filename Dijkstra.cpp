#include <iostream>
#include <vector>
#include <queue> // 힙 구조를 사용하기 위함(우선순위 큐)

using namespace std;

int number = 6;
int INF = 1000000000;

vector<pair<int, int> > a[7]; // 간선 정보(pair 형태로 자신과 연결된 노드 정보 저장)

int d[7]; // 최소 비용

void dijkstra(int start) {
    d[start] = 0; // 탐색 시작하는 노드의 최소비용은 0

    priority_queue<pair<int, int> > pq; // 힙구조 유지

    pq.push(make_pair(start, 0));

    // 가까운 순서대로 처리 -> 큐 사용
    while(!pq.empty()) { // 우선순위 큐가 비어있지 않다면 
        int current = pq.top().first; // 큐의 가장 위에는 가장 적은 비용을 가진 node의 정보가 들어있다.

        // 짧은 것이 먼저 오도록 음수화
        int distance = -pq.top().second;

        pq.pop();

        // 최단 거리가 아닌 경우 스킵
        if(d[current] < distance) continue;

        for(int i=0;i<a[current].size();i++) {
            // 선택된 노드의 인접노드를 담아줌 
            int next = a[current][i].first;

            // 선택된 노드를 거쳐서 인접노드로 가는 비용 계산
            int nextDistance = distance + a[current][i].second;

            // 기존의 비용과 비교
            if(nextDistance < d[next]) {
                d[next] = nextDistance;
                pq.push(make_pair(next, -nextDistance));
            }
        }

    }

}

int main(void) {
    for(int i=1;i<=number;i++) {
        d[i] = INF;
    }

    a[1].push_back(make_pair(2,2)); // 1번 노드에서 2번 노드로 가는 비용은 2
    a[1].push_back(make_pair(3,5)); // 1번 노드에서 3번 노드로 가는 비용은 5
    a[1].push_back(make_pair(4,1));

    a[2].push_back(make_pair(1,2));
    a[2].push_back(make_pair(3,3));
    a[2].push_back(make_pair(4,2));

    a[3].push_back(make_pair(1,5));
    a[3].push_back(make_pair(2,3));
    a[3].push_back(make_pair(4,3));
    a[3].push_back(make_pair(5,1));
    a[3].push_back(make_pair(6,5));

    a[4].push_back(make_pair(1,1));
    a[4].push_back(make_pair(2,2));
    a[4].push_back(make_pair(3,3));
    a[4].push_back(make_pair(5,1));

    a[5].push_back(make_pair(3,1));
    a[5].push_back(make_pair(4,1)); 
    a[5].push_back(make_pair(6,2));

    a[6].push_back(make_pair(3,5));
    a[6].push_back(make_pair(5,2));

    dijkstra(6);

    for(int i=1;i<=number;i++) {
        printf("%d ", d[i]);
    }
}