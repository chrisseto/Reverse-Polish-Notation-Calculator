#include <stdio.h>
#include <stdlib.h>
#define SIZE 5
#define UINT unsigned int
#define STRING char *
/*
Written By Chris Seto
25 September 2013
Compile with ' gcc -Wall -ansi -std=c99 main.c'
Please Note: Created in Gedit
*/
struct intStack;
void push(int val, struct intStack *stk);
int pop(struct intStack *stk);
struct intStack
{
	int stack[SIZE];
	int top;
};
int main(int argc, char *argv[])
{
	struct intStack stk;
	stk.top = -1;
	
	if(argc < 2)
	{
		printf(">" );
		char c;
		do{
			c = getchar();
			switch(c)
			{
				case '+':
					push(pop(&stk)+pop(&stk),&stk);
					break;
				case '-':
					push(pop(&stk)-pop(&stk),&stk);
					break;
				case '/':
					push(pop(&stk)/pop(&stk),&stk);
					break;
				case '*':
					push(pop(&stk)*pop(&stk),&stk);
					break;
				case '$':
					push(stk.stack[stk.top],&stk);
					break;
				case '\n':
				case ' ':
					break;
				default:
					push(c - '0', &stk);
			}
		}while(c!='\n');
		printf("%d\n",stk.stack[0]);
	}

	return 0;
}
/*add in error handling for pushing and popping*/
void push(int val, struct intStack *stk)
{
	(stk->top)++;
	stk->stack[(stk->top)] = val;
	printf("Pushed %d to the stack.\n",val);

}
int pop(struct intStack *stk)
{
	(stk->top)--;
	printf("Popped %d from the stack.\n",(stk->stack[(stk->top)+1]));
	return (stk->stack[(stk->top)+1]);
}
void getFiles(char *files)
{
	int size;
	FILE *current;
	STRING toReturn[sizeof(files)/sizeof(char)];
	for(int i =0; i < sizeof(files)/sizeof(char); i++)
	{
		current = fopen(files[i],"r");
		fseek(current, 0, SEEK_END);
		size = ftell(current);
		toReturn[i] = (STRING) malloc(sizeof(char)*size);
		fread(toReturn[i],1,size,current);
		rewind(current);
		fclose(current);
	}
	free(current);
	/*2d array of char (array of strings) concat? pipe to parse*/
}
void parse(char *toParse, struct intStack *stk)
{	
	char * phrase;
	phrase = strtok(toParse," ,.-");
	while(phrase != NULL)
	{
		printf("Caught %s\n",phrase); 
		if(sizeof(phrase)/sizeof(char) == 1)
		{
		printf("Switching %s\n",phrase); 
			/*switch statement here*/
			/*return when @ found*/
		}
		else
		{
		}
		phrase = strtok(NULL," ,.-");
	}
}
