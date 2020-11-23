#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include "TXLib.h"

char getWord (char *word, FILE *txt);

void putWord (char *word, FILE *lst);

void chopWord (char *word, char *patt);

char detectWord (char *word, char *patt);

void clearWord (char *word);

int detectLetter (int Letter);

int main (int argc, char ** argv) 
{
	FILE *lst, *txt;

	printf("arg: %u\n", argc);

	if( argc < 2)
	{
		printf("ARGs!!\n");
		exit(1);
	}

	txt = fopen(argv[1], "r");
	
	if(errno)
	{
		char ans[1000];
		sprintf(ans, "Problem file: %s\n", argv[1]);
		perror(ans);
		exit(1);
	}

	char flag = 1;
	char word[1000] = {0};
	char patt[1000] = {0};

	lst = fopen("list.dat ", "w");

	while (flag)
	{
		flag = getWord(word, txt);
		printf("%s\n", word);
		chopWord(word, patt);
		putWord(word, lst);
		clearWord(word);
	}	

	fclose(lst);
	fclose(txt);
	return 0; 
}

char getWord (char *word, FILE *txt)
{
	char ch;
	int i = 0;
	do 
	{
		ch = getc(txt);

		if (ch == EOF)
			return 0;
		
		word[i] = ch;
		i++;
	} while (ch != ' ');
	return 1;
}

void putWord (char *word, FILE *lst)
{
	for (int i = 0; word[i] != 0 ; ++i)
	{
		putc(word[i], lst);
	}
}

char detectWord (char *word, char *patt)
{
	for (int i = 0; i < 1000; ++i)
	{
		patt[i] = detectLetter(word[i]);
	}
	printf("%s\n", patt);
	char pos = 0;


}

void chopWord (char *word, char *patt)
{
	char type = detectWord(word, patt);
}

void clearWord (char *word)
{
	for (int i = 0; i < 1000; ++i)
	{
		word[i] = 0;
	}
}

int detectLetter (int Letter)
{
	switch (Letter)
	{
	case 0: return 0;
	case "Б":;case 'В':;case 'Г':;case 'Д':;case 'Ж':;case 'З':;case 'Й':;case 'К':;case 'Л':;case 'М':
	case 'Н':;case 'П':;case 'Р':;case 'С':;case 'Т':;case 'Ф':;case 'Х':;case 'Ц':;case 'Ч':;case 'Ш':
	case 'Щ':;case 'Ъ':;case 'Ь':
	return 'B';

	case 'б':;case 'в':;case 'г':;case 'д':;case 'ж':;case 'з':;case 'й':;case 'к':;case 'л':;case 'м':
	case 'н':;case 'п':;case 'р':;case 'с':;case 'т':;case 'ф':;case 'х':;case 'ц':;case 'ч':;case 'ш':
	case 'щ':;case 'ъ':;case 'ь': 
	return 'b';

	case 192:;case 'Е':;case 'Ё':;case 'И':;case 'О':;case 'У':;case 'Ы':;case 'Э':;case 'Ю':;case 'Я':
	return 'A';

	case 'а':;case 'е':;case 'ё':;case 'и':;case 'о':;case 'у':;case 'ы':;case 'э':;case 'ю':;case 'я':
	return 'a';

	case '-':
	return '-';

	case '\n':;case '\t':;case '!':;case '\"':;case '\'':;case '(':;case ')':;case '.':;case ',':
	case ':':;case ';':;case '?':;case '[':;case ']':;case '{':;case '}':;case '`':;case '~':
	return '!';

	case '0':;case '1':;case '2':;case '3':;case '4':;case '5':;case '6':;case '7':;case '8':;case '9':
	return 'n';

	default: return '?';
	}
}