#include<iostream>
using namespace std;

template<typename T>
class Queue {
private:
    class Node {
    public:
        T data; //단어를 저장할 변수
        Node* link; //다음 노드의 주소를 저장할 포인터
    };
    Node* first; //제일 앞의 노드를 가리킬 포인터
    Node* rear; //제일 뒤의 노드를 가리킬 포인터

public:
    Queue(T token); //Token을 첫 노드로 갖는 Linked list 생성자
    void Push(T token); //제일 뒤에 노드 삽입
    void Pop(); //제일 앞의 노드 삭제
    void Print(); //제일 앞의 노드부터 순서대로 마지막 노드의 data까지 출력
};

template<typename T>
Queue<T>::Queue(T token) {
    first = new Node; // first 동적 할당 선언
    first->data = token; // 전달받은 token을 first 노드의 data로 지정 
    first->link = NULL; // first의 link는 노드를 가리키지 않음
    rear = first; // rear을 first로 초기화
}

template<typename T>
void Queue<T>::Push(T token) {
    Node* p = new Node; // 노드 p 동적 생성
    p->data = token; // p의 data에 전달받은 token 저장
    p->link = NULL; // p의 link는 노드를 가리키지 않음

    if (first == NULL){ // first가 NULL일 경우
        first = p; // first와 rear 모두 p 지정
        rear = p;
    }
    else { // 아닐 경우
        rear->link = p; // p를 rear의 다음 노드로 만듦
        rear = p; // rear를 p로 지정
    }
    
}

template<typename T>
void Queue<T>::Pop() {
    
    if (first == NULL) { // 첫번째 노드가 NULL일 경우
        cout << "Queue is empty." << endl; // 큐가 비었음을 의미
        return;
    }
    
    Node* q = new Node; // 새로운 노드 q 동적 생성
    q = first; // 노드가 first를 가리키도록 함
    first = first->link; // first가 다음 노드를 가리키도록 함
    delete q; 
   
}

template<typename T>
void Queue<T>::Print() {
    Node* tmp = first; // 첫번째 노드의 주소를 저장하는 포인터
    if (tmp == NULL) { // 첫번쨰 노드가 NULL일 경우
        cout << "empty" << endl; // linked list가 비었음을 의미
        return;
    }
    else {
        while (tmp != NULL) { // tmp가 NULL일동안 반복
            cout << tmp->data << " ";// tmp의 data 출력
            tmp = tmp->link; // tmp가 tmp의 다음 노드를 가리키도록 함 
        }
    }cout << endl;
}

int main(void)
{
    Queue<int> queue(3); // 정수형 큐 생성
    queue.Print();

    queue.Push(1);
    queue.Print();

    queue.Push(2);
    queue.Print();

    queue.Push(3);
    queue.Print();

    queue.Push(4);
    queue.Print();

    queue.Pop();
    queue.Print();

    queue.Pop();
    queue.Print();

    queue.Push(5);
    queue.Print();

    queue.Pop();
    queue.Print();

    queue.Pop();
    queue.Print();

    queue.Pop();

    return 0;
}