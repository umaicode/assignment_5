#include <stdlib.h>
#include <iostream>
/*
queue�� C++�� class�� ��� > ť ������ ����� person ��ü > person�� name�� char* ���ڿ��� ����
<���� ���� public �ȿ� �ְ� �� �Լ� �����>
*/
using namespace std;

class Person {
    friend class Queue;
    char* pid; // �ǵ� ����
    char* pname; // �ǵ� ����
    int age; // �ǵ� ����
public:
    // ������ ����
    Person(char* p, char* n, int a) {
        pid = 0;
        pname = n;
        age = a;
    }
    // ������ ���� ��

};

class Queue {
private:
    int front, rear; // �ǵ� ����
    Person* queue[100]; // �ǵ� ����
/*
protected: // private�� ������ private�� subclass���� �� �� ����. protected�� subclass������ �۵��Ѵ�.
    int count;
*/

public:
    // ������ ����
    // int front, rear; // main������ �� �� ������ debug ���Ѵ�. -> ��� ������ �� ���̴ϱ�. �׷��� private�� ���� class������ ���� �������.
    void Show();
    void Add(Person&);
    // ��ü�� �����ָ� �����͸� ���� &�� ���� ���������� ��� ������ ������ �����ؾ� �Ѵ�.
    Person& Delete();
    int GetFront() {
        cout << front;
    }
    // ������ ���� ��
};

// ������ ����
void Queue::Show() {
    cout << front << endl;
}

void Queue::Add(Person& p) {

}

void Queue::Delete() {

}
// ������ ���� ��


int main() {
    Person* p[10];
    Queue q1, q2;
    // cout << q1.front; // private���� �ȵȴ�.
    while (1)
    {
        char sno[10];
        char sname[20];
        int year;
        int select;
        cout << "\nSelect command 1: AddBatch(), 2: AddOne(1�� ��ü�� ȭ�� �Է¹޾�), 3. Delete, 4: Show, 5. quit => ";
        cin >> select;
        switch (select) {
        case 1://AddBatch
            cout << endl << "10�� ť�� �Է�" << endl;
            // p0, p1, p2, p3 -> ���� ����
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
            cout << endl << "1�� ��ü�� ȭ�� �Է¹޾�" << endl;
            cin >> sno >> sname >> year;

            // Person px = Person(sno, sname, year); ���⼭ ������ �����ڸ� ȣ���ߴµ� �����ڴ� ���� ���� ����. ��ü�� ������µ� ��ü�� ����ų ���� ����.
            Person *px = new Person(sno, sname, year); // new�� ���� �� ��ü�� ����� ������ �Ҵ��ϰ� �� ��ü�� px���� �ش�. 
            // Person px = Person p4(sno, sname, year); // �̰� �� �ȵǳ�?
            q1.Add(px);
            break;

        case 3://Delete
            cout << endl << "Delete" << endl;
            Person result = q1.Delete();
            cout << "������ ��ü:";
            
            // ������ ����
            cout << result;
            //������ ���� ��

            q2.Add(result);
            cout << result;
            break;
        case 4://Show - ť�� ���¸� ���
            // front, rear ��� �ȵ� -> private��.
            cout << endl << "front = " << endl;
            // cout << q1.front; �̰� �������´�.
            q1.GetFront();
            cout << "rear = " << endl;
            //ť�� �ִ� ��ü���� show()�� ����Ͽ� ���
            q1.Show();
            cout << "������ ��ü���� ������ q2�� ��ü���� ���";
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
