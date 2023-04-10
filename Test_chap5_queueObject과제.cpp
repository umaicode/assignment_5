#include <stdlib.h>
#include <iostream>
/*
queue를 C++의 class를 사용 > 큐 데이터 멤버가 person 객체 > person의 name이 char* 문자열로 구현
<메인 보고 public 안에 넣고 그 함수 만들기>
*/
using namespace std;

class Person {
    friend class Queue;
    char* pid; // 건들 ㄴㄴ
    char* pname; // 건들 ㄴㄴ
    int age; // 건들 ㄴㄴ
public:
    // 교수님 설명
    Person(char* p, char* n, int a) {
        pid = 0;
        pname = n;
        age = a;
    }
    // 교수님 설명 끝

};

class Queue {
private:
    int front, rear; // 건들 ㄴㄴ
    Person* queue[100]; // 건들 ㄴㄴ
/*
protected: // private와 같은데 private는 subclass에서 쓸 수 없다. protected는 subclass에서만 작동한다.
    int count;
*/

public:
    // 교수님 설명
    // int front, rear; // main에서도 쓸 수 있으면 debug 못한다. -> 모든 곳에서 다 쓰이니깐. 그래서 private에 놓고 class에서만 쓰게 만든거임.
    void Show();
    void Add(Person&);
    // 객체를 던져주면 포인터를 쓸지 &를 쓸지 참조변수를 어떻게 리턴할 것인지 생각해야 한다.
    Person& Delete();
    int GetFront() {
        cout << front;
    }
    // 교수님 설명 끝
};

// 교수님 설명
void Queue::Show() {
    cout << front << endl;
}

void Queue::Add(Person& p) {

}

void Queue::Delete() {

}
// 교수님 설명 끝


int main() {
    Person* p[10];
    Queue q1, q2;
    // cout << q1.front; // private여서 안된다.
    while (1)
    {
        char sno[10];
        char sname[20];
        int year;
        int select;
        cout << "\nSelect command 1: AddBatch(), 2: AddOne(1개 객체를 화면 입력받아), 3. Delete, 4: Show, 5. quit => ";
        cin >> select;
        switch (select) {
        case 1://AddBatch
            cout << endl << "10개 큐에 입력" << endl;
            // p0, p1, p2, p3 -> 로컬 변수
            Person p0("s1", "hong", 12);
            Person p1("s2", "kim", 22);
            Person p2("s3", "lee", 23);
            Person p3("s4", "park", 24);
            p[0] = &p0; p[1] = &p1; p[2] = &p2; p[3] = &p3;
            for (int i = 0; i < 4; i++) {
                q1.Add(*p[i]);
                // q1.Add(p[i]);
                // q1.Add(&p[i]);
            }
            break;
        case 2://AddOne
            cout << endl << "1개 객체를 화면 입력받아" << endl;
            cin >> sno >> sname >> year;

            // Person px = Person(sno, sname, year); 여기서 문제는 생성자를 호출했는데 생성자는 리턴 값이 없다. 객체를 만들었는데 객체를 가리킬 것이 없다.
            Person *px = new Person(sno, sname, year); // new를 쓰면 그 객체를 만들고 공간을 할당하고 그 객체를 px에게 준다. 
            // Person px = Person p4(sno, sname, year); // 이거 왜 안되노?
            q1.Add(px);
            break;

        case 3://Delete
            cout << endl << "Delete" << endl;
            Person result = q1.Delete();
            cout << "삭제된 객체:";
            
            // 교수님 설명
            cout << result;
            //교수님 설명 끝

            q2.Add(result);
            cout << result;
            break;
        case 4://Show - 큐의 상태를 출력
            // front, rear 출력 안됨 -> private임.
            cout << endl << "front = " << endl;
            // cout << q1.front; 이거 못가져온다.
            q1.GetFront();
            cout << "rear = " << endl;
            //큐에 있는 객체들을 show()를 사용하여 출력
            q1.Show();
            cout << "삭제된 객체들을 저장한 q2의 객체들을 출력";
            q2.Show();
            break;
        default:
            exit(0);
            break;
        }
    }
}
system("pause");
return 1;
}
