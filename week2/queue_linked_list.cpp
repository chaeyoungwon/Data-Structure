#include<iostream>
using namespace std;

template<typename T>
class Queue {
private:
    class Node {
    public:
        T data; //�ܾ ������ ����
        Node* link; //���� ����� �ּҸ� ������ ������
    };
    Node* first; //���� ���� ��带 ����ų ������
    Node* rear; //���� ���� ��带 ����ų ������

public:
    Queue(T token); //Token�� ù ���� ���� Linked list ������
    void Push(T token); //���� �ڿ� ��� ����
    void Pop(); //���� ���� ��� ����
    void Print(); //���� ���� ������ ������� ������ ����� data���� ���
};

template<typename T>
Queue<T>::Queue(T token) {
    first = new Node; // first ���� �Ҵ� ����
    first->data = token; // ���޹��� token�� first ����� data�� ���� 
    first->link = NULL; // first�� link�� ��带 ����Ű�� ����
    rear = first; // rear�� first�� �ʱ�ȭ
}

template<typename T>
void Queue<T>::Push(T token) {
    Node* p = new Node; // ��� p ���� ����
    p->data = token; // p�� data�� ���޹��� token ����
    p->link = NULL; // p�� link�� ��带 ����Ű�� ����

    if (first == NULL){ // first�� NULL�� ���
        first = p; // first�� rear ��� p ����
        rear = p;
    }
    else { // �ƴ� ���
        rear->link = p; // p�� rear�� ���� ���� ����
        rear = p; // rear�� p�� ����
    }
    
}

template<typename T>
void Queue<T>::Pop() {
    
    if (first == NULL) { // ù��° ��尡 NULL�� ���
        cout << "Queue is empty." << endl; // ť�� ������� �ǹ�
        return;
    }
    
    Node* q = new Node; // ���ο� ��� q ���� ����
    q = first; // ��尡 first�� ����Ű���� ��
    first = first->link; // first�� ���� ��带 ����Ű���� ��
    delete q; 
   
}

template<typename T>
void Queue<T>::Print() {
    Node* tmp = first; // ù��° ����� �ּҸ� �����ϴ� ������
    if (tmp == NULL) { // ù���� ��尡 NULL�� ���
        cout << "empty" << endl; // linked list�� ������� �ǹ�
        return;
    }
    else {
        while (tmp != NULL) { // tmp�� NULL�ϵ��� �ݺ�
            cout << tmp->data << " ";// tmp�� data ���
            tmp = tmp->link; // tmp�� tmp�� ���� ��带 ����Ű���� �� 
        }
    }cout << endl;
}

int main(void)
{
    Queue<int> queue(3); // ������ ť ����
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