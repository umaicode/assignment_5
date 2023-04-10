#include <iostream>
using namespace std;

class Student {
	char* name;
	// char name[10];
	int year;
	char *dept;
	// char dept[20];

public:
	/*
	Student(char* name, int year, char* dept) :year(year) {

	}
	*/

	Student(char name[], int year, char dept[]) :year(year) {
		// name�� dept�� main�� string�� ������ �ִ�.
		// ���� �ڵ� �̴�. -> ��?
		// this->name = name; // char *name�� �̿����� ��
		// this->dept = dept; // char *dept�� �̿����� ��, ������ �� �ִ� lvalue ���� �Ѵ�? this->dept�� �迭 �̸��ε� ���⿡ ���� �����ϴ� ���� �ȵȴ�?
		this->name = new char[sizeof(name)]; // char* name�� �̿��ϸ鼭 strcpy�� �� ��, Heap����, char name[10]�� ���� ���� �����Ҵ��� �Ǿ��־ �ʿ� ����.
		this->dept = new char[sizeof(dept)]; // char* dept�� �̿��ϸ鼭 strcpy�� �� ��, Heap����, char dept[10]�� ���� ���� �����Ҵ��� �Ǿ��־ �ʿ� ����.
		strcpy(this->name, name); // char name[10] �� �̿����� �� strcpy
		strcpy(this->dept, dept); // char dept[20] �� �̿����� �� strcpy
	}

	// this pointer ����
	Student& Print(Student& s){
		this->year += s.year;
		return *this;
	}
	// this pointer ���� ��

	~Student() {
		delete[]name; // Heap ������ �ִ� ������ ���ش�. -> Student�����ڿ��� Heap������ �������ϱ�.
		delete[]dept; // Heap ������ �ִ� ������ ���ش�. -> Student�����ڿ��� Heap������ �������ϱ�.
	}
};

int main() {
	// ���� ������ stack������ �ִ�.
	char sname[10];
	// char* sname; �̰� �� �ȵǴ��� �˾ƾ���.
	int syear;
	char sdept[20];
	cin >> sname >> syear >> sdept;
	Student p1(sname, syear, sdept);
	Student p2(sname, syear, sdept);
	Student s2 = p1.Print(p2);
	cout << "sname = " << sname << ", syear = " << syear << ", sdept = " << sdept << endl;
	system("pause");
	return 1;
}