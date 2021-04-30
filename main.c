#include "head.h"
#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

void main()
{
	setlocale(0, "Ru");
	int count;
	printf("¬ведите номер задачи:");
	scanf_s("%d", &count);
	switch (count)
	{
	case 1:
		compl();
		break;
	case 2:
		parole();
		break;
	default:
		break;
	}

}