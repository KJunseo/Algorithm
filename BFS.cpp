#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int number = 7; // 탐색할 node의 수 
int checked[7]; // 방문 처리를 위한 배열 
vector<int> a[8]; // node의 index를 0이 아닌 1부터 처리하기 위해 number보다 1크게

void bfs(int start) {
    queue<int> q;
    q.push(start); // 탐색을 시작 할 node를 큐에 넣어준다. 
    checked[start] = true; // 방문처리 

    while(!q.empty()) { // 큐가 빌때까지 반복 
        // 큐에서 하나를 꺼내 출력 
        int x = q.front(); 
        q.pop();
        printf("%d ", x);

        // 큐에서 꺼낸 인접한 node들 차례대로 방문 
        for(int i=0; i<a[x].size();i++){
            int y = a[x][i]; // 인접한 노드

            if(!checked[y]){ // 방문한 상태라면 무시, 방문하지 않았다면 큐에 넣어줌
                q.push(y);
                checked[y] = true; // 방문처리 
            }
        }
    }
}

int main(void) {
    //push_back: vector의 끝에 요소를 추가할 때 사용 
    a[1].push_back(2);
    a[2].push_back(1);
    
    a[1].push_back(3);
    a[3].push_back(1);

    a[2].push_back(3);
    a[3].push_back(2);
    
    a[2].push_back(4);
    a[4].push_back(2);

    a[2].push_back(5);
    a[5].push_back(2);

    a[3].push_back(6);
    a[6].push_back(3);
    
    a[3].push_back(7);
    a[7].push_back(3);

    a[4].push_back(5);
    a[5].push_back(4);

    a[6].push_back(7);
    a[7].push_back(6);

    bfs(1);
    return 0;
}