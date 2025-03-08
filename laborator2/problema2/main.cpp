#include "student.h"
#include "global.h"
using namespace std;
int main()
{
	Student s1, s2;

	s1.setname("Ana");
	s1.setmathgrade(9);
	s1.setenglishgrade(9);
	s1.sethistorygrade(7);

	s2.setname("Daniel");
	s2.setmathgrade(8);
	s2.setenglishgrade(9);
	s2.sethistorygrade(8);

	cout << "comparare nume:" << comparnume(s1, s2) << endl;
	cout << "comparare nota mate:" << comparmate(s1, s2) << endl;
	cout << "comparare nota engleza:" << comparengleza(s1, s2) << endl;
	cout << "comparare nota istorie:" << comparistorie(s1, s2) << endl;

}

