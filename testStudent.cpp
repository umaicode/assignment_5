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
		// name과 dept는 main의 string을 가지고 있다.
		// 구린 코드 이다. -> 왜?
		// this->name = name; // char *name을 이용했을 때
		// this->dept = dept; // char *dept를 이용했을 때, 수정할 수 있는 lvalue 여야 한다? this->dept는 배열 이름인데 여기에 값을 변경하는 것은 안된다?
		this->name = new char[sizeof(name)]; // char* name을 이용하면서 strcpy를 쓸 때, Heap영역, char name[10]을 썼을 때는 공간할당이 되어있어서 필요 없다.
		this->dept = new char[sizeof(dept)]; // char* dept을 이용하면서 strcpy를 쓸 때, Heap영역, char dept[10]을 썼을 때는 공간할당이 되어있어서 필요 없다.
		strcpy(this->name, name); // char name[10] 을 이용했을 때 strcpy
		strcpy(this->dept, dept); // char dept[20] 을 이용했을 때 strcpy
	}

	// this pointer 설명
	Student& Print(Student& s){
		this->year += s.year;
		return *this;
	}
	// this pointer 설명 끝

	~Student() {
		delete[]name; // Heap 영역에 있는 공간을 없앤다. -> Student생성자에서 Heap영역이 생겼으니깐.
		delete[]dept; // Heap 영역에 있는 공간을 없앤다. -> Student생성자에서 Heap영역이 생겼으니깐.
	}
};

int main() {
	// 로컬 변수는 stack영역에 있다.
	char sname[10];
	// char* sname; 이게 왜 안되는지 알아야함.
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