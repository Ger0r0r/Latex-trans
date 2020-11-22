#include <stdio.h>
#include <stdlib.h>
#include <errno.h>

char getWord (char *word, FILE *txt);

void putWord (char *word, FILE *lst);

void chopWord (char *word, char *patt);

char detectWord (char *word, char *patt);

void clearWord (char *word);

unsigned char detectLetter (unsigned char Letter);

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
	char pattern[1000] = {0};
	for (int i = 0; i < 1000; ++i)
	{
		patt[i] = detectLetter(word[i]);
		printf("word [%d] = %c patt[%d] = %c\n", i, word[i], i, patt[i]);
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

unsigned char detectLetter (unsigned char Letter)
{
	switch (Letter)
	{
	case 0: return 0;
	case 193:case 194:case 195:case 196:case 198:case 199:case 201:case 202:case 203:case 204:
	case 205:case 207:case 208:case 209:case 210:case 212:case 213:case 214:case 215:case 216:
	case 217:case 218:case 220:
	return 'B';

	case 225:case 226:case 227:case 228:case 230:case 231:case 233:case 234:case 235:case 236:
	case 237:case 239:case 240:case 241:case 242:case 244:case 245:case 246:case 247:case 248:
	case 249:case 250:case 252: 
	return 'b';

	case 192:case 197:case 168:case 200:case 206:case 211:case 219:case 221:case 222:case 223:
	return 'A';

	case 224:case 229:case 184:case 232:case 238:case 243:case 251:case 253:case 254:case 255:
	return 'a';

	case '-':
	return '-';

	case '\n':case '\t':case '!':case '\"':case '\'':case '(':case ')':case '.':case ',':
	case ':':case ';':case '?':case '[':case ']':case '{':case '}':case '`':case '~':
	return '!';

	case '0':case '1':case '2':case '3':case '4':case '5':case '6':case '7':case '8':case '9':
	return 'n';

	default: return '?';
	}
}