#include "student.h"
#include "global.h"

using namespace std;

int comparnume(Student s1, Student s2)
{
	if (strcmp(s1.getnume(), s2.getnume()) == 0)
		return 0;
	else
		if (strcmp(s1.getnume(), s2.getnume()) > 0)
			return -1;
		else
			return 1;
}

int comparmate(Student n1, Student n2)
{
	if (n1.getmathgrade() == n2.getmathgrade())
		return 0;
	else
		if (n1.getmathgrade() > n2.getmathgrade())
			return -1;
		else
			return 1;

}
int comparengleza(Student n1, Student n2)
{
	if (n1.getenglishgrade() == n2.getenglishgrade())
		return 0;
	else
		if (n1.getenglishgrade() > n2.getenglishgrade())
			return -1;
		else
			return 1;

}
int comparistorie(Student n1, Student n2)
{
	if (n1.gethistorygrade() == n2.gethistorygrade())
		return 0;
	else
		if (n1.gethistorygrade() > n2.gethistorygrade())
			return -1;
		else
			return 1;

}
int comparmedie(Student n1, Student n2)
{
	if (n1.medianote() == n2.medianote())
		return 0;
	else
		if (n1.medianote() > n2.medianote())
			return -1;
		else
			return 1;

}