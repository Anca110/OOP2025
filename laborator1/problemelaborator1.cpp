#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<string.h>
using namespace std;

/////problema1/////

int atoi_convert(char s[100])
{
	int nr = 0;
	int c = 0;
	for (int i = 0; i < 100; i++)
		if (s[i] >= '0' && s[i] <= '9')
			c = s[i] - '0';
	nr = nr * 10 + c;
	return nr;
}
void main1()
{
	FILE* file;
	int s = 0;
	char n[100];

	fopen_s(&file, "in.txt", "r");
	while (fgets(n, 100, file))
		s = s + atoi_convert(n);

	printf("%d", s);
	fclose(file);
}

//////problema3///////
bool isPrime(int n)
{
	for (int tr = 2; tr < n / 1; tr++)
		if ((n % tr) == 0)
			return false;
	return true;
}
int main3()
{
	int n;
	std::cout << "Enter a number:";//using namespace
	std::cin >> n;
	if (isPrime(n))
		std::cout << n << " is prime !";
	else
		std::cout << n << " is NOT prime !";
	return 0;
}

//////problema2//////

bool comparare_alfabetica( char* s1, char* s2) 
{
	for (int i = 0; s1[i]; i++)
		if (s1[i] < s2[i])
			return true;
		else if (s1[i] > s2[i])
			return false;

	return true;
}
int main2()
{
	char s[100];
	char cuv[100][30];
	char aux[30];
	char* p;
	int i = 0;
	scanf_s("%[^\n]", s, 100);
	p = strtok(s, " ");
	while (p)
	{
		strcpy(cuv[i++], p);
		p=strtok(NULL, " ");
		int j = i - 1;
		while (j > 0 && strlen(cuv[j]) < strlen(cuv[j - 1]))
		{
			strcpy(aux, cuv[j]);
			strcpy(cuv[j], cuv[j - 1]);
			strcpy(cuv[j - 1], aux);
		}
		while (j > 0 && strlen(cuv[j]) == strlen(cuv[j - 1]) && comparare_alfabetica(cuv[j], cuv[j - 1]))
		{
			strcpy(aux, cuv[j]);
			strcpy(cuv[j], cuv[j - 1]);
			strcpy(cuv[j - 1], aux);
		}


	}
	for (int j = 0; j < i; j++)
		printf("%s\n", cuv[j]);
	return 0;
}
int main()
{
	main2();
	return 0;
}




