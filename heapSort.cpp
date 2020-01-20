#include <stdio.h>
#include <iostream>

using namespace std;

int number = 9; // 전체 데이터의 수 
int heap[9] = {7, 6, 5, 8, 3, 5, 9, 1, 6}; // 정렬할 데이터 
int main(void){
    // 최대 힙 트리 구조로 만들어 준다. 
    for(int i=1;i<number;i++){
        int child = i;
        do{
            int root = (child-1)/2; // 특정한 노드의 부모 노드

            // 부모의 값 보다 자식의 값이 더 크면 위치 변경
            if(heap[root]<heap[child]){
                int temp = heap[root];
                heap[root] = heap[child];
                heap[child] = temp;
            } 
            child = root; // 자식이 부모로 이동(상향식)
        } while (child != 0);
    }

    // 크기를 줄여가며 힙 구성
    for(int i=number-1;i>=0;i--){
        // root와 가장 마지막 원소 교환 
        int temp = heap[0];
        heap[0] = heap[i];
        heap[i] = temp;

        int root = 0;
        int child = 1;

        // 힙 구조 만드는 부분 
        do{
            child = 2 * root + 1; // 첫 번째 자식 

            // 두 자식 중에 더 큰 값을 찾기
            // 오른쪽 자식 값이 더 크다면, child값 ++
            if(child < i-1 && heap[child] < heap[child+1]){
                child++; 
            }
            // root보다 자식이 더 크면 교환
            if(child < i && heap[root] < heap[child]){
                temp = heap[root];
                heap[root] = heap[child];
                heap[child] = temp;
            }
            root = child; // child를 root로 이동시킴(다음 노드 검사)
        }while(child < i);
    }

    for(int i=0;i<number;i++)
        cout << heap[i] << ' ';
    
    return 0;
}