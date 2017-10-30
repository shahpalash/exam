// 
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

using namespace std;

char expr[20];
int count;

void e();
void ed();
void t();
void td();
void f();
bool match(char a, int c);

int main()
{
	count = 0;
	printf("Enter expression:\n");
	scanf("%s", &expr);
	e();
	if(strlen(expr)==count)
	{
		printf("Accepted\n");
	}
	else
	{
		printf("Invalid\n");
	}
}

void e()
{
	printf("e\n");
	t();
	ed();
}

void t()
{
	printf("t\n");
	f();
	td();
}

void ed()
{
	printf("ed\n");
	if(match('+', count))
	{
		t();
		ed();
	}
	else
	{
		return;
	}
}

void td()
{
	printf("td\n");
	if(match('*', count))
	{
		f();
		td();
	}
	else
	{
		return;
	}
}

void f()
{
	printf("f\n");
	if(match('(', count))
	{
		e();
		if(match(')', count))
		{
			return;
		}
		else
		{
			printf("Invalid input\n");
			exit(0);
		}
	}
	else if(isalnum(expr[count]))
	{
		count++;
		return;
	}
	else
	{
		printf("Invalid input\n");
		exit(0);
	}
}

bool match(char a, int c)
{
	if(a == expr[c])
	{
		count = count + 1;
		return 1;
	}
	else
	{
		return 0;
	}
}

