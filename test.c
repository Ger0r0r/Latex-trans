#include <stdio.h>
#include <locale.h>

int main()
{
    setlocale(LC_ALL, "ru_RU.CP1251");
	int p = 0;
	p = getchar ();
	printf ("%c %i", p,p);
	return 0;
}