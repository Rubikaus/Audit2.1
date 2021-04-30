#include "head.h"
#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <math.h>

void parole()
{
	int numb = 0;
	char password[101] = { 0 };
	printf("Введите пароль: ");
	char sym = 0;
	for (int i = 0; i < 100; i++)
	{
		sym = getch();
		if (sym == 8)
		{
			if (i > 0)
			{
				i--;
				printf("\b \b");
				password[i] = 0;
				i--;
			}
			else
				i--;
		}
		else if (sym == 13)
			break;
		else
		{
			putch('*');
			password[i] = sym;
		}

	}
	printf("\nВаш пароль: %s", password);
}

void compl()
{
	int a = 0, b = 0, n = 0, maxa = 0, maxb = 0, howmuch = 0;
	double c = 0.0, max = 0.0;
	setlocale(0, "ru");
	FILE* input;
	errno_t error = fopen_s(&input, "input.txt", "r");
	if (input != 0)
	{
		rewind(input);
		fscanf_s(input, "%d", &n);
	}
	for (int i = 0; i < n; i++)
	{
		if (input != 0)
			fscanf_s(input, "%d %d", &a, &b);
		c = sqrt(pow(a, 2) + pow(b, 2));
		if (b < 0)
			printf("%d%di\n", a, b);
		else
			printf("%d+%di\n", a, b);
		if (max <= c)
		{
			max = c;
			if (abs(maxa) != abs(a) || abs(maxb) != abs(b))
			{
				howmuch = 0;
			}
			maxa = a;
			maxb = b;
			howmuch++;
		}
	}
	if (howmuch > 1)
	{
		printf("Последнее максимальное число по модулю: ");
		if (maxb < 0)
			printf("%d%di\n", maxa, maxb);
		else
			printf("%d+%di\n", maxa, maxb);
	}
	else {
		if (maxb < 0)
			printf("max = %d%di\n", maxa, maxb);
		else
			printf("max = %d+%di\n", maxa, maxb);
	}
}