#include <stdlib.h>
#include <iostream>
/*
queue�� C++�� class�� ��� > ť ������ ����� person ��ü > person�� name�� char* ���ڿ��� ����
*/
using namespace std;

class Person {
    friend class Queue;
    char* pid;
    char* pname;
    int age;
public:

};

class Queue {
    int front, rear;
    Person* queue[100];
public:

};


int main() {
    Person* p[10];
    Queue q1, q2;
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
            Person p0("s1", "hong", 12);
            Person p1("s2", "kim", 22);
            Person p2("s3", "lee", 23);
            Person p3("s4", "park", 24);
            p[0] = &p0; p[1] = &p1; p[2] = &p2; p[3] = &p3;
            for (int i = 0; i < 4; i++) {
                q1.Add(*p[i]);
            }
            break;
        case 2://AddOne
            cout << endl << "1�� ��ü�� ȭ�� �Է¹޾�" << endl;
            cin >> sno >> sname >> year;
            Person px = Person(sno, sname, year);
            q1.Add(px);
            break;

        case 3://Delete
            cout << endl << "Delete" << endl;
            Person result = q1.Delete();
            cout << "������ ��ü:";
            q2.Add(result);
            cout << result;
            break;
        case 4://Show - ť�� ���¸� ���
            cout << endl << "front = " << endl;
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
