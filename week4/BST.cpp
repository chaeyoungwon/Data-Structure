#include<iostream>
using namespace std;

template<class T>
class BST {
private:
    class Node {
    public:
        T data; //���� ������ ����
        Node* left; //���� �ڽĳ�带 ����ų ������
        Node* right; //������ �ڽĳ�带 ����ų ������
        Node(T n, Node* L = NULL, Node* R = NULL) : data(n), left(L), right(R) {}; //������
        int Get_Child(); //�ڽĳ���� ���� ��ȯ�ϴ� �Լ�
    };
    Node* root; //Ʈ���� �� ���� �ִ� ���

    void Inorder(Node* ptr); //�ش� ��带 ������ȸ
    void Preorder(Node* ptr); //�ش� ��带 ������ȸ
    void Postorder(Node* ptr); //�ش� ��带 ������ȸ

public:
    BST() : root(NULL) {}; //����Ʈ ������
    BST(T n); //n�� ���� ���� root�� �����ϴ� ������
    void Insert(T n); //n�� ���� ���� ��带 ������ ��ġ�� �����ϴ� �Լ�
    void Delete(T n); //n�� ���� ���� ��带 �����ϴ� �Լ�
    void Find(T n); //n�� ���� ���� ����� ������ ����ϴ� �Լ�
    void Visit(Node* ptr); //��ȸ���� ���� �ش� ����� ���� ����ϴ� �Լ�
    void Inorder(); //������ȸ�� tree���
    void Preorder(); //������ȸ�� tree ���
    void Postorder(); //������ȸ�� tree ���
    ~BST() { Delete(root); } //�⺻ �Ҹ���
    void Delete(Node* ptr) //�⺻ �Ҹ��ڿ��� ȣ��� ��� ��带 �����ϱ� ���� ����Լ�
    {
        if (ptr != NULL)
        {
            Delete(ptr->left);
            Delete(ptr->right);
            delete ptr;
        }
    }
};

template<class T>
int BST<T>::Node::Get_Child() {
    int n = 0; //�ڽĳ���� ������ ������ ����
    if (left != NULL) //���� �ڽĳ�尡 �ִ� ���
        n++;
    if (right != NULL) //������ �ڽĳ�尡 �ִ� ���
        n++;
    return n; //�ڽĳ���� ���� ��ȯ
}

template<class T>
BST<T>::BST(T n) {
    Node* node = new Node(n); //n�� ���� ���� ��� �����Ҵ�
    root = node; //root�� �Ҵ���� ��带 ����Ŵ
}

template<class T>
void BST<T>::Inorder(Node* ptr) {
    if (ptr) { //ptr�� NULL�� ��� �Լ� ����
        Inorder(ptr->left); //���� �ڽ� ��带 ������ȸ
        Visit(ptr); //�ڽ��� ���� ��带 ��ȸ�� �� �ڽ��� �� ���
        Inorder(ptr->right); //������ �ڽ� ��带 ������ȸ
    }
}

template<class T>
void BST<T>::Preorder(Node* ptr) {
    if (ptr) {
        Visit(ptr); //�ڽ��� �� ���
        Preorder(ptr->left); //���� �ڽ� ��带 ������ȸ
        Preorder(ptr->right); //������ �ڽ� ��带 ������ȸ
    }
}

template<class T>
void BST<T>::Postorder(Node* ptr) {
    if (ptr) {
        Postorder(ptr->left); //���� �ڽ� ��带 ������ȸ
        Postorder(ptr->right); //������ �ڽ� ��带 ������ȸ
        Visit(ptr); //�ڽ��� �� ���
    }
}

template<class T>
void BST<T>::Insert(T n) {
    Node* node = new Node(n); //n�� data�� ���� ������ ��� ����

    if (root == NULL) { //tree�� ����ִ� ���
        root = node;
        return; //�Լ� ����
    }
    //Ʈ���� ������� ���� ���
    Node* tmp = root; //������ ������ ��ġ�� ����ų ������
    Node* prev = NULL; //������ ������ ��ġ�� �θ��带 ����ų ������

    while (tmp) //tmp�� NULL�� ����Ű�� (������ ������ ��ġ) �ݺ� ����
    {
        if (n == tmp->data) //������ n�� �̹� tree�� �ִ� ���
        {
            cout << "�ش� ���� ���� node�� �����մϴ�" << endl; //��� ���
            return; //�Լ� ����
        }
        else if (n < tmp->data) //������ n�� tmp�� data���� ���� ���
        {
            prev = tmp; //prev�� tmp�� ����Ű���� �� �� tmp �̵�
            tmp = tmp->left;
        }
        else if (n > tmp->data) //������ n�� tmp�� data���� Ŭ ���
        {
            prev = tmp; //prev�� tmp�� ����Ű���� �� �� tmp �̵�
            tmp = tmp->right;
        }
    }

    if (n < prev->data) //������ n�� prev�� data���� ���� ���
        prev->left = node; //���ο� ��� ����
    else if (n > prev->data) //������ n�� prev�� data���� Ŭ ���
        prev->right = node; //���ο� ��� ����
}

template<class T>
void BST<T>::Delete(T n) {
    if (!root) { //tree�� ����ִ� ���
        cout << "Empty Tree" << endl; //��� ���
        return; //�Լ� ����
    }

    //Ʈ���� ������� ���� ���
    Node* del = root; //������ n�� data�� ���� ��带 ã�� ������
    Node* delParent = NULL; //del�� �ּҸ� �ľ��ϱ� ���� ������

    while (del != NULL) //del�� NULL�� ����Ű�� �ݺ� ����
    {
        if (n == del->data) //del�� ������ n�� data�� ���� ���
        {
            break; //�ݺ� ����
        }
        else if (n < del->data) //������ n�� del�� data���� ���� ���
        {
            delParent = del;
            del = del->left; //���� �ڽĳ�带 ����Ű�� ��
        }
        else if (n > del->data) //������ n�� del�� data���� Ŭ ���
        {
            delParent = del;
            del = del->right; //������ �ڽ� ��带 ����Ű�� ��
        }
    } //������ ��带 ã�� del�� ����Ű�� ����


    //����ó�� 1
    if (del == NULL) //del == NULL�� ��� (������ n�� tree�� ���� ���)
    {
        cout << n << " doesn't exist in this tree" << endl; //��� ���
        return; //�Լ� ����
    }
    //����ó�� 2
    if (del == root) //������ ��尡 root�� ���
        delParent = new Node(0, root, root); //���Ƿ� delParent ��� ����

    //�ڽĳ�� ������ ���� ����
    if (del->Get_Child() == 0) //del�� leaf ����� ���
    {
        if (del == delParent->left) //del�� delParent�� ���� �ڽĳ���� ���
            delParent->left = NULL; //del�� ����Ű�� ������ �ʱ�ȭ
        else if (del == delParent->right) //del�� delParent�� ������ �ڽĳ���� ���
            delParent->right = NULL; //del�� ����Ű�� ������ �ʱ�ȭ

        delete del; //del ����
    }
    else if (del->Get_Child() == 1) //del�� �ڽĳ�带 1�� ���� ���
    {
        if (del == delParent->left) //del�� delParent�� ���� �ڽĳ���� ���
        {
            if (del->left != NULL) //del�� ���� �ڽĳ�带 ���� ���
                delParent->left = del->left; //del�� ���� �ڽ� ��带 ����Ű�� ��
            else if (del->right != NULL) //del�� ������ �ڽĳ�带 ���� ���
                delParent->left = del->right; //del�� ������ �ڽ� ��带 ����Ű�� ��
        }
        else if (del == delParent->right) //del�� delParent�� ������ �ڽĳ���� ���
        {
            if (del->left != NULL) //del�� ���� �ڽĳ�带 ���� ���
                delParent->right = del->left; //del�� ���� �ڽ� ��带 ����Ű�� ��
            else if (del->right != NULL) //del�� ������ �ڽĳ�带 ���� ���
                delParent->right = del->right; //del�� ������ �ڽ� ��带 ����Ű�� ��
        }

        delete del; //del ����
    }
    else if (del->Get_Child() == 2) //del�� �ڽĳ�带 2�� ���� ���
    {
        Node* tmp = del->left; //del�� ���� �ڽĳ�� �� ���� ū ���� ���� ��带 ã�� ������
        Node* tmpParent = del; //tmp�� �ּҸ� �ľ��ϱ� ���� ������

        while (tmp->right != NULL) //�� �̻� ������ �ڽĳ�尡 ���� ��忡 �����ϸ� �ݺ� ����
        {
            tmpParent = tmp; //tmpParent�� tmp�� ����Ű�� �� �� tmp �̵���Ű�� ���
            tmp = tmp->right; //tmp�� ������ �ڽĳ��� �̵�
        } //���� ���� �� ���� ū ���� ã�� ����, �� ���� tmp�� ����Ŵ

        if (del == tmpParent) //����ó�� �ʿ��� ���̽�
        {
            tmp->right = del->right; // ������ ����� �ڽĳ�带 �ӽ� ����� �ڽĳ��� �̵���Ŵ
        }
        else //���� ��� �� ��� ���
        {
            tmpParent->right = tmp->left; //tmp�� �ڽ� ����� ��ġ ����
            tmp->left = del->left;
            tmp->right = del->right; //tmp�� ������ ����� �ڽĳ�带 �ڽĳ��� �ް� ��

        }


        if (del == delParent->left) //del�� delParent�� ���� �ڽĳ���� ���
            delParent->left = tmp; //������� �ϴ� ��� ��ġ�� tmp�� ������ ��
        else if (del == delParent->right) //del�� delParent�� ������ �ڽĳ���� ���
            delParent->right = tmp; //������� �ϴ� ��� ��ġ�� tmp�� ������ ��

            delete del; //del ����
    }

    if (delParent->right == root) //root ��带 ������ ���
    {
        root = delParent->left; //root ����
        delete delParent; //���Ƿ� �����ߴ� delParent ����
    }

}

template<class T>
void BST<T>::Find(T n) {
    int level = 0;

    if (!root) { //tree�� ����ִ� ���
        cout << "Empty Tree" << endl; //��� ���
        return; //�Լ� ����
    }
    //Ʈ���� ������� ���� ���
    Node* tmp = root; //ã�� n�� data�� ���� ��带 ã�� ������

    while (tmp) //tmp�� NULL�� ����Ű�� (������ ������ ��ġ) �ݺ� ����
    {
        if (n == tmp->data) //tmp�� ã�� n�� data�� ���� ���
        {
            break; //�ݺ� ����
        }
        else if (n < tmp->data) //ã�� n�� tmp�� data���� ���� ���
        {
            tmp = tmp->left; //tmp�� ���� �ڽĳ��� �̵�
            level++;
        }
        else if (n > tmp->data) //ã�� n�� tmp�� data���� Ŭ ���
        {
            tmp = tmp->right; //tmp�� ������ �ڽĳ��� �̵�
            level++;
        }
    }
    if (!tmp) //tmp == NULL�� ��� (ã�� n�� tree�� ���� ���)
        cout << n << " doesn't exist this tree" << endl; //��� ���
    else if (tmp) //tmp�� ã�� n�� data�� ���� ���
        cout << "Level of " << n << " is " << level << endl; //�ش� ����� level ���
}

template<class T>
void BST<T>::Visit(Node* ptr) {
    cout << ptr->data << '\t'; //��尡 ���� data ���
}

template<class T>
void BST<T>::Inorder() {
    Inorder(root); //��ͷ� root���� ������ȸ
}

template<class T>
void BST<T>::Preorder() {
    Preorder(root); //��ͷ� root���� ������ȸ
}

template<class T>
void BST<T>::Postorder() {
    Postorder(root); //��ͷ� root���� ������ȸ
}

int main() {
    BST<int> tree;
    int input = 1;
    int n;

    while (input) {
        cout << "(1)Insert    (2)Delete    (3)Find    (4)Print    (0)End" << endl;
        cin >> input;

        if (input == 1) {
            cout << "Word to insert : ";
            cin >> n;
            tree.Insert(n);
        }
        else if (input == 2) {
            cout << "Word to Delete : ";
            cin >> n;
            tree.Delete(n);
        }
        else if (input == 3) {
            cout << "Word to Find : ";
            cin >> n;
            tree.Find(n);
        }
        else if (input == 4) {
            cout << "<1>Inorder    <2>Preorder    <3>Postorder" << endl;
            cin >> input;

            if (input == 1)
                tree.Inorder();
            else if (input == 2)
                tree.Preorder();
            else if (input == 3)
                tree.Postorder();

            cout << endl;
        }
        else
            continue;

    }

    return 0;
}