#include<iostream>
using namespace std;

class Dictionary {
private:
    class Node {
    public:
        string data; //단어를 저장할 변수
        Node* link; //다음 노드의 주소를 저장할 포인터
    };
    Node* first = NULL; //첫 번째 노드를 가리킬 포인터

public:
    Dictionary(string word); //word를 첫 노드로 갖는 Linked list 생성자
    void Find(string word); //word가 몇 번째 위치에 있는 지 출력, 없으면 없다고 출력
    void Insert(string word); //단어 적절한 위치에 삽입(알파벳 순)
    void Delete(string word); //word를 리스트에서 삭제, 없는 경우도 예외처리 해야 함
    void Display();
};

Dictionary::Dictionary(string word) {
    first = new Node; // 변수 first 동적 생성
    first->data = word; // 전달받은 단어를 data에 저장
    first->link = NULL; // 첫 번째 노드이므로 포인터 link는 다음 노드를 가리키지 않음
}

void Dictionary::Find(string word) {
    Node* p = first; // 첫번째 노드의 주소 저장하는 포인터
    int index = 0; // 위치를 알아내기 위한 변수
    while (p != NULL) { // linked list의 마지막 노드까지 반복
        if (p->data == word) { // 노드의 data가 전달받은 word와 일치하다면
            cout << "이 단어는 " << index << "번째 위치에 있습니다." << endl;
            return;
        }
        p = p->link; // 다음 노드로 넘어감
        index++; // 다음 노드로 넘어갈 때마다 1씩 증가
    }
    cout << "단어가 존재하지 않습니다." << endl;
}

void Dictionary::Insert(string word) {
    Node* q = new Node; // 노드 형태의 q 동적 할당 선언 
    q->data = word; // 전달받은 단어를 q의 data에 저장
    q->link = NULL; // 아직 다음 노드를 가리키지 않는 상태

    if (first == NULL || word <= first->data) { // 첫번째 노드가 NULL이거나 전달받은 단어가 사전순으로 앞에 위치할 때
        q->link = first; // 노드 q의 다음 노드가 first가 되도록 함
        first = q; // 첫번째 노드를 q로 지정
        return;
    }

    Node* p = first; // 첫번째 노드의 주소 저장하는 포인터
    while (p->link != NULL && (p->link)->data < word) { // 마지막 노드가 아니고 전달받은 단어가 사전순으로 뒤에 위치할 동안 반복
        p = p->link; // 다음 노드로 넘어감
    }
    q->link = p->link; // 새로운 노드의 다음 필드가 p의 다음 노드를 가리키도록 함
    p->link = q; // 새로운 노드를 p의 다음 노드로 만듦

}

void Dictionary::Delete(string word){
    Node* p = first; // 첫번째 노드의 주소 저장하는 포인터
    if (first == NULL) { // 첫번째 노드가 NULL일 경우 삭제 없이 반환
        return;
    }
    else if (first->data == word) { // 첫번째 노드의 data가 전달받은 단어일 경우
        first = first->link; // 첫번째 노드가 그 노드의 다음 노드를 가리키도록 함
        return;
    }
    else {
        while (p->link != NULL) { // 마지막 노드 전까지 반복
            if ((p->link)->data == word) { // 노드의 data가 word와 일치할 경우
                p->link = (p->link)->link; // 다음 노드를 가리키도록 함
                return;
            }
            p = p->link; // 다음 노드로 넘어감
        }
        cout << "단어가 존재하지 않습니다." << endl;
    }
}

void Dictionary::Display() {
    if (first == NULL)
        cout << "empty" << endl; // 첫번째 노드가 NULL일 경우 비어있음을 의미
    else {
        Node* n = first; // 첫번째 노드의 주소 저장하는 포인터
        while (n != NULL) { // 마지막 노드가 아닐떄까지 반복
            cout << n->data <<" "; // 노드의 data 출력
            n = n->link; // 다음 노드로 넘어감
        }
    }cout << endl;
}

int main() {
    Dictionary Dt("ABC");
    int input = 1;
    string word;

    while (input) { // 무한 반복
        cout << "(1)Insert    (2)Delete    (3)Display    (4)Find    (0)END" << endl;
        cin >> input;

        if (input == 1) {
            cout << "Word to insert : "; // 단어를 추가할 경우
            cin >> word;
            Dt.Insert(word);
        }
        else if (input == 2) {
            cout << "Word to Delete : "; // 단어를 삭제할 경우
            cin >> word;
            Dt.Delete(word);
        }
        else if (input == 3) { // 단어사전 상태 출력
            Dt.Display();
        }
        else if (input == 4) {
            cout << "Word to Find : "; // 단어를 찾는 경우
            cin >> word;
            Dt.Find(word);
        }
    }
}