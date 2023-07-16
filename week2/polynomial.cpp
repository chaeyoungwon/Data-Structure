#include<iostream>
using namespace std;

class Polynomial
{
private:
    class Node
    {
    public:
        float coef; //계수
        int exp; //지수
        Node* link; //다음 노드를 가리킬 포인터
        Node(float c, int e = 0) { coef = c; exp = e; } //Node 생성자
    };
    Node* first;
public:
    Polynomial() { first = NULL; } //Polynomial 생성자
    void Get_Polynomial(); //다항식을 입력받을 함수
    void Insert(float c, int e); //계수c와 지수e를 갖는 항을 다항식에 추가
    Polynomial operator +(const Polynomial& b); //다항식 덧셈 결과 반환
    void Print(); //다항식을 내림차순으로 출력
};

void Polynomial::Get_Polynomial()
{
    float C; //계수를 입력받을 변수
    int E; //지수를 입력받을 변수

    cout << "다항식 생성 시작 (계수에 0을 입력하면 생성을 중단합니다)" << endl;

    while (1) //아래 조건문에 의해 중단되기 전까지 무한반복
    {
        cout << "추가할 항의 계수(실수)와 지수(정수)를 입력하세요 : ";
        cin >> C >> E; //계수와 지수 입력받음

        if (C == 0) //계수로 0을 입력받으면
            break; //함수 종료 (다항식 생성 중단)

        Insert(C, E); //계수C와 지수E를 갖는 항을 추가
    }
}

void Polynomial::Insert(float c, int e) { // 지수 순으로 노드를 삽입하기 위한 코드
    Node* p = new Node(c,e); // c와 e를 받은 node q 동적 생성
    if (first == NULL) { // first가 NULL일 경우
        p->link = NULL; // 아직 다음 노드를 가리키지 않은 상태
        first = p; // first를 p로 지정
    }
    else if (e > first->exp) { // 전달받은 지수가 첫번쨰 노드의 지수보다 클 경우
        p->link = first; // 노드 p의 다음 노드가 first가 되도록 함
        first = p; // first를 p로 지정
    }
    else if (e == first->exp) { // 전달받은 지수가 첫번쨰 노드의 지수와 같을 경우
        first->coef += c; // 첫번째 노드의 계수 변수에 c를 더함
        delete p;
    }
    else {
        Node* before = first; // first 주소를 저장하는 노드 before
        Node* now = first->link; // first의 다음 노드의 주소를 저장하는 노드 now
        
        while (now != NULL && now->exp > e) { // now가 NULL이 아니고 지수가 전달받은 지수보다 클 경우 반복
            before = now; // before가 now를 가리킴
            now = now->link; // 다음 항을 가리킴
        }

        if (now != NULL && now->exp == e) { // now가 Null이 아니고 지수가 전달받은 지수와 같다면
            now->coef += c; // now 노드의 계수에 전달받은 c를 더함
            delete p;
        }
        else {
            p->link = now; // p의 다음 노드가 now가 되도록 함
            before->link = p; // before의 다음 노드가 p가 되도록 함
            
        }
    }

}

Polynomial Polynomial::operator +(const Polynomial& b)
{
    Polynomial result; //두 다항식의 합을 저장할 다항식
    Node* ai = this->first; //첫 번째 다항식의 노드를 가리킬 포인터
    Node* bi = b.first; //두 번째 다항식의 노드를 가리킬 포인터
    
    while(1) //아래 조건문에 의해 중단되기 전까지 무한반복
    {
        if (!ai) //ai가 NULL인 경우 (다항식 a에 더 이상 계산할 항이 없는 경우)
        {
            while (bi) //bi가 NULL에 도달하면 반복 종료 (다항식 b에도 더 이상 계산할 항이 없을 때)
            {
                result.Insert(bi->coef, bi->exp); //bi의 계수와 지수를 result에 추가
                bi = bi->link; //다음 항을 가리킴
            }
            break; //반복 종료
        }
        else if (!bi) //bi가 NULL인 경우 (다항식 b에 더 이상 계산할 항이 없는 경우)
        {
            while (ai) { //ai가 NULL에 도달하면 반복 종료 (다항식 a에도 더 이상 계산할 항이 없을 때)
                result.Insert(ai->coef, ai->exp); // ai의 계수와 지수를 result에 추가
                ai = ai->link; // 다음 항을 가리킴
            }
            break; //반복 종료
        }

        if (ai->exp > bi->exp) //ai가 가리키는 항의 지수가 더 큰 경우
        {
            result.Insert(ai->coef, ai->exp); // ai의 계수와 지수를 result에 추가
            ai = ai->link; // 다음 항을 가리킴
        }
        else if (ai->exp < bi->exp) //bi가 가리키는 항의 지수가 더 큰 경우
        {
            result.Insert(bi->coef, bi->exp); // ai의 계수와 지수를 result에 추가
            bi = bi->link; // 다음 항을 가리킴
        }
        else //ai와 bi가 가리키는 두 항의 지수가 같은 경우
        {
            result.Insert(ai->coef + bi->coef, ai->exp); // ai와 bi 계수의 합과 지수를 result에 추가
            ai = ai->link; // 다음 항을 가리킴
            bi = bi->link; // 다음 항을 가리킴
        }
    }

    return result; //덧셈이 완료된 다항식을 return
}

void Polynomial::Print()
{
    if (first == NULL)
        cout << "empty" << endl; // first가 NULL일 경우 linked list가 비었음을 의미
    else{
        Node* tmp = this->first;// first 주소를 저장할 포인터 변수 tmp 생성
        while (tmp != NULL) { // tmp가 마지막 노드가 아닐 동안 반복
            cout << tmp->coef << "x^" << tmp->exp; // 다항식 형태 출력
            if ((tmp->link) != NULL) // tmp의 다음 노드가 마지막 노드가 아닐 경우
                cout << " + "; // + 기호 붙이기
            tmp = tmp->link; // 다음 항을 가리킴
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