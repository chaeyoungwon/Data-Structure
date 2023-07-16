#include<iostream>
using namespace std;

class Dictionary {
private:
    class Node {
    public:
        string data; //�ܾ ������ ����
        Node* link; //���� ����� �ּҸ� ������ ������
    };
    Node* first = NULL; //ù ��° ��带 ����ų ������

public:
    Dictionary(string word); //word�� ù ���� ���� Linked list ������
    void Find(string word); //word�� �� ��° ��ġ�� �ִ� �� ���, ������ ���ٰ� ���
    void Insert(string word); //�ܾ� ������ ��ġ�� ����(���ĺ� ��)
    void Delete(string word); //word�� ����Ʈ���� ����, ���� ��쵵 ����ó�� �ؾ� ��
    void Display();
};

Dictionary::Dictionary(string word) {
    first = new Node; // ���� first ���� ����
    first->data = word; // ���޹��� �ܾ data�� ����
    first->link = NULL; // ù ��° ����̹Ƿ� ������ link�� ���� ��带 ����Ű�� ����
}

void Dictionary::Find(string word) {
    Node* p = first; // ù��° ����� �ּ� �����ϴ� ������
    int index = 0; // ��ġ�� �˾Ƴ��� ���� ����
    while (p != NULL) { // linked list�� ������ ������ �ݺ�
        if (p->data == word) { // ����� data�� ���޹��� word�� ��ġ�ϴٸ�
            cout << "�� �ܾ�� " << index << "��° ��ġ�� �ֽ��ϴ�." << endl;
            return;
        }
        p = p->link; // ���� ���� �Ѿ
        index++; // ���� ���� �Ѿ ������ 1�� ����
    }
    cout << "�ܾ �������� �ʽ��ϴ�." << endl;
}

void Dictionary::Insert(string word) {
    Node* q = new Node; // ��� ������ q ���� �Ҵ� ���� 
    q->data = word; // ���޹��� �ܾ q�� data�� ����
    q->link = NULL; // ���� ���� ��带 ����Ű�� �ʴ� ����

    if (first == NULL || word <= first->data) { // ù��° ��尡 NULL�̰ų� ���޹��� �ܾ ���������� �տ� ��ġ�� ��
        q->link = first; // ��� q�� ���� ��尡 first�� �ǵ��� ��
        first = q; // ù��° ��带 q�� ����
        return;
    }

    Node* p = first; // ù��° ����� �ּ� �����ϴ� ������
    while (p->link != NULL && (p->link)->data < word) { // ������ ��尡 �ƴϰ� ���޹��� �ܾ ���������� �ڿ� ��ġ�� ���� �ݺ�
        p = p->link; // ���� ���� �Ѿ
    }
    q->link = p->link; // ���ο� ����� ���� �ʵ尡 p�� ���� ��带 ����Ű���� ��
    p->link = q; // ���ο� ��带 p�� ���� ���� ����

}

void Dictionary::Delete(string word){
    Node* p = first; // ù��° ����� �ּ� �����ϴ� ������
    if (first == NULL) { // ù��° ��尡 NULL�� ��� ���� ���� ��ȯ
        return;
    }
    else if (first->data == word) { // ù��° ����� data�� ���޹��� �ܾ��� ���
        first = first->link; // ù��° ��尡 �� ����� ���� ��带 ����Ű���� ��
        return;
    }
    else {
        while (p->link != NULL) { // ������ ��� ������ �ݺ�
            if ((p->link)->data == word) { // ����� data�� word�� ��ġ�� ���
                p->link = (p->link)->link; // ���� ��带 ����Ű���� ��
                return;
            }
            p = p->link; // ���� ���� �Ѿ
        }
        cout << "�ܾ �������� �ʽ��ϴ�." << endl;
    }
}

void Dictionary::Display() {
    if (first == NULL)
        cout << "empty" << endl; // ù��° ��尡 NULL�� ��� ��������� �ǹ�
    else {
        Node* n = first; // ù��° ����� �ּ� �����ϴ� ������
        while (n != NULL) { // ������ ��尡 �ƴҋ����� �ݺ�
            cout << n->data <<" "; // ����� data ���
            n = n->link; // ���� ���� �Ѿ
        }
    }cout << endl;
}

int main() {
    Dictionary Dt("ABC");
    int input = 1;
    string word;

    while (input) { // ���� �ݺ�
        cout << "(1)Insert    (2)Delete    (3)Display    (4)Find    (0)END" << endl;
        cin >> input;

        if (input == 1) {
            cout << "Word to insert : "; // �ܾ �߰��� ���
            cin >> word;
            Dt.Insert(word);
        }
        else if (input == 2) {
            cout << "Word to Delete : "; // �ܾ ������ ���
            cin >> word;
            Dt.Delete(word);
        }
        else if (input == 3) { // �ܾ���� ���� ���
            Dt.Display();
        }
        else if (input == 4) {
            cout << "Word to Find : "; // �ܾ ã�� ���
            cin >> word;
            Dt.Find(word);
        }
    }
}