#include<iostream>
using namespace std;

class Polynomial
{
private:
    class Node
    {
    public:
        float coef; //���
        int exp; //����
        Node* link; //���� ��带 ����ų ������
        Node(float c, int e = 0) { coef = c; exp = e; } //Node ������
    };
    Node* first;
public:
    Polynomial() { first = NULL; } //Polynomial ������
    void Get_Polynomial(); //���׽��� �Է¹��� �Լ�
    void Insert(float c, int e); //���c�� ����e�� ���� ���� ���׽Ŀ� �߰�
    Polynomial operator +(const Polynomial& b); //���׽� ���� ��� ��ȯ
    void Print(); //���׽��� ������������ ���
};

void Polynomial::Get_Polynomial()
{
    float C; //����� �Է¹��� ����
    int E; //������ �Է¹��� ����

    cout << "���׽� ���� ���� (����� 0�� �Է��ϸ� ������ �ߴ��մϴ�)" << endl;

    while (1) //�Ʒ� ���ǹ��� ���� �ߴܵǱ� ������ ���ѹݺ�
    {
        cout << "�߰��� ���� ���(�Ǽ�)�� ����(����)�� �Է��ϼ��� : ";
        cin >> C >> E; //����� ���� �Է¹���

        if (C == 0) //����� 0�� �Է¹�����
            break; //�Լ� ���� (���׽� ���� �ߴ�)

        Insert(C, E); //���C�� ����E�� ���� ���� �߰�
    }
}

void Polynomial::Insert(float c, int e) { // ���� ������ ��带 �����ϱ� ���� �ڵ�
    Node* p = new Node(c,e); // c�� e�� ���� node q ���� ����
    if (first == NULL) { // first�� NULL�� ���
        p->link = NULL; // ���� ���� ��带 ����Ű�� ���� ����
        first = p; // first�� p�� ����
    }
    else if (e > first->exp) { // ���޹��� ������ ù���� ����� �������� Ŭ ���
        p->link = first; // ��� p�� ���� ��尡 first�� �ǵ��� ��
        first = p; // first�� p�� ����
    }
    else if (e == first->exp) { // ���޹��� ������ ù���� ����� ������ ���� ���
        first->coef += c; // ù��° ����� ��� ������ c�� ����
        delete p;
    }
    else {
        Node* before = first; // first �ּҸ� �����ϴ� ��� before
        Node* now = first->link; // first�� ���� ����� �ּҸ� �����ϴ� ��� now
        
        while (now != NULL && now->exp > e) { // now�� NULL�� �ƴϰ� ������ ���޹��� �������� Ŭ ��� �ݺ�
            before = now; // before�� now�� ����Ŵ
            now = now->link; // ���� ���� ����Ŵ
        }

        if (now != NULL && now->exp == e) { // now�� Null�� �ƴϰ� ������ ���޹��� ������ ���ٸ�
            now->coef += c; // now ����� ����� ���޹��� c�� ����
            delete p;
        }
        else {
            p->link = now; // p�� ���� ��尡 now�� �ǵ��� ��
            before->link = p; // before�� ���� ��尡 p�� �ǵ��� ��
            
        }
    }

}

Polynomial Polynomial::operator +(const Polynomial& b)
{
    Polynomial result; //�� ���׽��� ���� ������ ���׽�
    Node* ai = this->first; //ù ��° ���׽��� ��带 ����ų ������
    Node* bi = b.first; //�� ��° ���׽��� ��带 ����ų ������
    
    while(1) //�Ʒ� ���ǹ��� ���� �ߴܵǱ� ������ ���ѹݺ�
    {
        if (!ai) //ai�� NULL�� ��� (���׽� a�� �� �̻� ����� ���� ���� ���)
        {
            while (bi) //bi�� NULL�� �����ϸ� �ݺ� ���� (���׽� b���� �� �̻� ����� ���� ���� ��)
            {
                result.Insert(bi->coef, bi->exp); //bi�� ����� ������ result�� �߰�
                bi = bi->link; //���� ���� ����Ŵ
            }
            break; //�ݺ� ����
        }
        else if (!bi) //bi�� NULL�� ��� (���׽� b�� �� �̻� ����� ���� ���� ���)
        {
            while (ai) { //ai�� NULL�� �����ϸ� �ݺ� ���� (���׽� a���� �� �̻� ����� ���� ���� ��)
                result.Insert(ai->coef, ai->exp); // ai�� ����� ������ result�� �߰�
                ai = ai->link; // ���� ���� ����Ŵ
            }
            break; //�ݺ� ����
        }

        if (ai->exp > bi->exp) //ai�� ����Ű�� ���� ������ �� ū ���
        {
            result.Insert(ai->coef, ai->exp); // ai�� ����� ������ result�� �߰�
            ai = ai->link; // ���� ���� ����Ŵ
        }
        else if (ai->exp < bi->exp) //bi�� ����Ű�� ���� ������ �� ū ���
        {
            result.Insert(bi->coef, bi->exp); // ai�� ����� ������ result�� �߰�
            bi = bi->link; // ���� ���� ����Ŵ
        }
        else //ai�� bi�� ����Ű�� �� ���� ������ ���� ���
        {
            result.Insert(ai->coef + bi->coef, ai->exp); // ai�� bi ����� �հ� ������ result�� �߰�
            ai = ai->link; // ���� ���� ����Ŵ
            bi = bi->link; // ���� ���� ����Ŵ
        }
    }

    return result; //������ �Ϸ�� ���׽��� return
}

void Polynomial::Print()
{
    if (first == NULL)
        cout << "empty" << endl; // first�� NULL�� ��� linked list�� ������� �ǹ�
    else{
        Node* tmp = this->first;// first �ּҸ� ������ ������ ���� tmp ����
        while (tmp != NULL) { // tmp�� ������ ��尡 �ƴ� ���� �ݺ�
            cout << tmp->coef << "x^" << tmp->exp; // ���׽� ���� ���
            if ((tmp->link) != NULL) // tmp�� ���� ��尡 ������ ��尡 �ƴ� ���
                cout << " + "; // + ��ȣ ���̱�
            tmp = tmp->link; // ���� ���� ����Ŵ
        }cout << endl;
    }
}

int main()
{
    Polynomial A, B;

    cout << "[A] ";
    A.Get_Polynomial();
    cout << "[B] ";
    B.Get_Polynomial();

    cout << "[A] = ";
    A.Print();
    cout << "[B] = ";
    B.Print();

    Polynomial C = A + B;

    cout << "[A] + [B] = ";
    C.Print();

    return 0;
}