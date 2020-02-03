#include <iostream>

using namespace std;

int number = 15; // 노드의 개수

//하나의 노드 정보를 담고 있는 구조체
typedef struct node *treePointer;
typedef struct node {
    int data;
    treePointer leftChild, rightChild; // 왼쪽, 오른쪽 자식 노드를 가리키는 포인터변수 
} node;

// 전위 순회(자기자신 -> 왼쪽 -> 오른쪽)
void preorder(treePointer ptr) {
    if(ptr) { // 해당 포인터가 null값이 아니라면
        cout << ptr->data << ' ';
        preorder(ptr->leftChild);
        preorder(ptr->rightChild);
    }
}

// 중위 순회(왼쪽 -> 자기자신 -> 오른쪽)
void inorder(treePointer ptr) {
    if(ptr) { // 해당 포인터가 null값이 아니라면
        inorder(ptr->leftChild);
        cout << ptr->data << ' ';
        inorder(ptr->rightChild);
    }
}

// 후위 순회(왼쪽 -> 오른쪽 -> 자기자신)
void postorder(treePointer ptr) {
    if(ptr) { // 해당 포인터가 null값이 아니라면
        postorder(ptr->leftChild);
        postorder(ptr->rightChild);
        cout << ptr->data << ' ';
    }
}

int main(void) {
    node nodes[number+1]; // 15개의 데이터가 담길 수 있는 배열 

    for(int i=1;i<=number;i++) {
        nodes[i].data = i; // 각 원소 초기화 
        nodes[i].leftChild = NULL;
        nodes[i].rightChild = NULL;
    }

    // 짝수는 왼쪽, 홀수는 오른쪽으로 
    for(int i=1;i<=number;i++) {
        if(i%2==0) { // i가 2의 배수이면, 
            nodes[i/2].leftChild = &nodes[i];
        } else {
            nodes[i/2].rightChild = &nodes[i];
        }
    }

    preorder(&nodes[1]);
    cout << endl;
    inorder(&nodes[1]);
    cout << endl;
    postorder(&nodes[1]);

    return 0;
}