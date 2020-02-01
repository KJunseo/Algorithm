#include <stdio.h>

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

int main(void) {
    int parent[11]; // 노드가 10개 있다. 

    for(int i=1;i<11;i++) {
        parent[i] = i; // 자기자신을 부모로 가리키게 함 
    }

    unionParent(parent, 1, 2); // 노드 1과 노드 2를 연결
    unionParent(parent, 2, 3); // 노드 2와 노드 3을 연결
    unionParent(parent, 3, 4); // 노드 3과 노드 4를 연결

    unionParent(parent, 5, 6); // 노드 5와 노드 6을 연결
    unionParent(parent, 6, 7); // 노드 6과 노드 7을 연결
    unionParent(parent, 7, 8); // 노드 7과 노드 8을 연결 

    // 0일 경우 다른 그래프. 1일 경우 같은 그래프 
    printf("1과 5는 연결되어 있나요? %d\n", findParent(parent, 1, 5));
    printf("1과 4는 연결되어 있나요? %d\n", findParent(parent, 1, 4));

    return 0;
}