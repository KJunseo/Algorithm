#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

// 특정한 노드의 부모를 찾는 함수 
int getParent(int parent[], int x) {
    if(parent[x]==x) return x; // 노드의 값이 자기자신인 경우 부모노드이므로 return
    return parent[x] = getParent(parent, parent[x]);
}

// 두 노드의 부모를 합치는 함수
void unionParent(int parent[], int a, int b) {
    // 두 노드의 부모 찾기 
    a = getParent(parent, a);
    b = getParent(parent, b);

    // 더 작은 값으로 부모를 합쳐줌(연결시켜주는 행위)
    if(a<b) parent[b] = a;
    else parent[a] = b;

}

// 같은 부모를 가지는지 확인(같은 그래프에 속해있는 지 확인)
int findParent(int parent[], int a, int b) {
    // 두 노드의 부모 찾기 
    a = getParent(parent, a);
    b = getParent(parent, b);

    if(a==b)return 1; // 같은 부모를 가지고 있다.
    return 0; // 다른 부모를 가지고 있다.
}

// 간선 클래스
class Edge {
    
public:
    int node[2]; // 이 간선이 연결하고 있는 두 개의 노드
    int distance; // 이 간선의 비용 

    Edge(int a, int b, int distance) {
        this->node[0] = a;
        this->node[1] = b;
        this->distance = distance;
    }
    // 정렬기준(비용이 작은 순 대로 정렬)
    bool operator < (const Edge &edge) const {
        return this->distance < edge.distance;
    }
};

int main(void) {
    int n = 7; // 노드의 수
    int m = 11; // 간선의 수 

    vector<Edge> v;
    v.push_back(Edge(1, 7, 12)); // 노드 1과 노드 7을 비용 12인 간선으로 연결 
    v.push_back(Edge(1, 4, 28));
    v.push_back(Edge(1, 2, 67));
    v.push_back(Edge(1, 5, 17));
    v.push_back(Edge(2, 4, 24));
    v.push_back(Edge(2, 5, 62));
    v.push_back(Edge(3, 5, 20));
    v.push_back(Edge(3, 6, 37));
    v.push_back(Edge(4, 7, 13));
    v.push_back(Edge(5, 6, 45));
    v.push_back(Edge(5, 7, 73));

    // 간선의 비용을 기준으로 오름차순 정렬
    sort(v.begin(), v.end());

    // 사이클 테이블 
    int parent[n];
    for(int i=0;i<n;i++) {
        parent[i]=i; // 모든 노드의 값이 자기자신
    }

    int sum=0; // 거리의 합
 
    // 오름차순 정렬된 모든 간선을 차례대로 확인 
    for(int i=0;i<v.size();i++) {
        // 사이클이 발생하지 않는 경우 sum에 더해주고, 두 노드 연결
        if(!findParent(parent, v[i].node[0] - 1, v[i].node[1] - 1)) {
            sum += v[i].distance;
            unionParent(parent, v[i].node[0] - 1, v[i].node[1] - 1);
        }
    }

    printf("%d\n", sum);
    return 0;
}