#include <stdlib.h>
#include <iostream>
/*
queue研 C++税 class研 紫遂 > 泥 汽戚斗 呉獄亜 person 梓端 > person税 name戚 char* 庚切伸稽 姥薄
<五昔 左壱 public 照拭 隔壱 益 敗呪 幻級奄>
*/
using namespace std;

class Person {
	friend class Queue;
	char* pid; // 闇級 いい
	char* pname; // 闇級 いい
	int age; // 闇級 いい
public:
	// 嘘呪還 竺誤
	Person(char* p, char* n, int a) {
		pid = new char[strlen(p) + 1];
		strcpy(pid, p);
		pname = new char[strlen(n) + 1];
		strcpy(pname, n);
		age = a;
	}
	// 嘘呪還 竺誤 魁
	~Person() {
		delete[] pid;
		delete[] pname;
	}

	friend ostream& operator<<(ostream& os, Person& p) {
		os << "ID : " << p.pid << ", NAME : " << p.pname << ", AGE : " << p.age;
		return os;
	}
};

class Queue {
private:
	int front, rear; // 闇級 いい
	Person* queue[100]; // 闇級 いい

protected: // private人 旭精汽 private澗 subclass拭辞 承 呪 蒸陥. protected澗 subclass拭辞幻 拙疑廃陥.
	int count;


public:
	// 嘘呪還 竺誤
	// int front, rear; // main拭辞亀 承 呪 赤生檎 debug 公廃陥. -> 乞窮 員拭辞 陥 床戚艦苑. 益掘辞 private拭 兜壱 class拭辞幻 床惟 幻窮暗績.
	Queue() {
		front = 0;
		rear = 0;
	}
	void Show();
	void Add(Person&);
	// 梓端研 揮閃爽檎 匂昔斗研 承走 &研 承走 凧繕痕呪研 嬢胸惟 軒渡拝 依昔走 持唖背醤 廃陥.
	Person& Delete();
	int GetFront() {
		return front;
	}

	int GetRear() {
		return rear;
	}
	// 嘘呪還 竺誤 魁
};

// 嘘呪還 竺誤

void Queue::Show() {
	// 鎧亜 呪舛廃 坪球
	for (int i = front; i<rear; i++){
		cout << "ID : " << queue[i]->pid << ", NAME : " << queue[i]->pname << ", AGE : " << queue[i]->age << endl;
	}
}

void Queue::Add(Person& p) {
	this->queue[rear] = new Person(p.pid, p.pname, p.age);
	rear++;
	count++;
}

Person& Queue::Delete() {
	if (front > rear) {
		cout << "泥亜 搾嬢赤柔艦陥." << endl;
		exit(1);
	}
	Person* p = queue[front];
	front++;
	return *p;
}

// 嘘呪還 竺誤 魁


int main() {
	Person* p[10];
	Queue q1, q2;
	// cout << q1.front; // private食辞 照吉陥.
	while (1)
	{
		char sno[10];
		char sname[20];
		int year;
		int select;
		cout << "\nSelect command 1: AddBatch(), 2: AddOne(1鯵 梓端研 鉢檎 脊径閤焼), 3. Delete, 4: Show, 5. quit => ";
		cin >> select;
		switch (select) 
		{
			case 1://AddBatch
			{
				cout << endl << "10鯵 泥拭 脊径" << endl;
				// p0, p1, p2, p3 -> 稽鎮 痕呪
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
			}

			case 2://AddOne
			{
				cout << endl << "1鯵 梓端研 鉢檎 脊径閤焼" << endl;
				cin >> sno >> sname >> year;

				// Person px = Person(sno, sname, year); 食奄辞 庚薦澗 持失切研 硲窒梅澗汽 持失切澗 軒渡 葵戚 蒸陥. 梓端研 幻級醸澗汽 梓端研 亜軒迭 依戚 蒸陥.
				Person* px = new Person(sno, sname, year); // new研 床檎 益 梓端研 幻級壱 因娃聖 拝雁馬壱 益 梓端研 px拭惟 層陥. 
				// Person px = Person p4(sno, sname, year); // 戚暗 訊 照鞠葛?
				q1.Add(*px);
				break;
			}

			case 3://Delete
			{
				cout << endl << "Delete" << endl;
				Person result = q1.Delete();
				cout << "肢薦吉 梓端:";

				// 嘘呪還 竺誤
				cout << result;
				//嘘呪還 竺誤 魁

				q2.Add(result);
//				cout << result;
				break;
			}
			case 4://Show - 泥税 雌殿研 窒径
			{
				// front, rear 窒径 照喫 -> private績.
				cout << endl << "front = " << q1.GetFront() << endl;
				// cout << q1.front; 戚暗 公亜閃紳陥.
				cout << "rear = " << q1.GetRear() << endl;
				//泥拭 赤澗 梓端級聖 show()研 紫遂馬食 窒径
				q1.Show();
				cout << "肢薦吉 梓端級聖 煽舌廃 q2税 梓端級聖 窒径";
				q2.Show();
				break;
			}

			default:
			{
				exit(0);
				break;
			}
		}
	}
	system("pause");
	return 1;
}