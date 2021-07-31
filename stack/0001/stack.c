//A stack is first in last out.
#include <stdio.h>
#include <stdbool.h>

#define STACK_SIZE 5

int stack[STACK_SIZE];
int top = 0;  //top position of the stack, which is stack[0] at first

bool isEmpty();
bool isFull(void);
void push(int item);
int pop(void);

int main()
{
	int i;
	int number;
	
	for(i = 0; i < STACK_SIZE; i++)
	{
		printf("Enter a number: ");
		scanf("%d", &number);
		push(number);
	}
	
	printf("items: ");
	for(i = 0; i < STACK_SIZE; i++)
	{
		printf("%d ", pop());
	}
	printf("\n");
	
	return 0;
}


bool isEmpty()
{
	if(top == 0)
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool isFull(void)
{
	if(top == STACK_SIZE)
	{
		return true;
	}
	else
	{
		return false;
	}
}

void push(int item)
{
	if(isFull() == false)
	{
		stack[top] = item;
		top++;
	}
	else
	{
		printf("Failed to push the item into the stack because the stack is full.\n");
	}
}

int pop(void)
{
	if(isEmpty() == false)
	{
		top--;
		return stack[top];
	}
	else
	{
		printf("Failed to pop the item out of the stack because the stack is empty.\n");
	}
}

/*
Enter a number: 1
Enter a number: 2
Enter a number: 3
Enter a number: 4
Enter a number: 5
items: 5 4 3 2 1
*/
