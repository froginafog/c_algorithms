//digital numbers
#include <stdio.h>

int main()
{
	int number;
	int n;
	int numberOfDigits;
	int i;
	int j;
	int k;
	int digit;
	
	printf("Enter a number: ");
	scanf("%d", &number);
	n = number;
	numberOfDigits = 0;	
	
	while(n != 0)
	{
		n = n / 10;
		numberOfDigits++;
	}
	
	int digits[numberOfDigits];
	
	n = number;
	
	for(i = numberOfDigits - 1; i >= 0; i--)
	{
		digits[i] = n % 10;
		n = n / 10;
	}
	
	printf("digits: ");
	for(i = 0; i < numberOfDigits; i++)
	{
		printf("%d ", digits[i]);
	}
	printf("\n");
	
	int numberOfRows = 3;
	int numberOfColumns = 3 * numberOfDigits;
	
	//for row 0
	
	k = 0;
	for(j = 0; j < numberOfColumns; j++)
	{
		if(j % 3 == 0)
		{
			digit = digits[k];
			k++;
		}

		if(j % 3 == 1)
		{
			if(digit == 0)
			{
				printf("_");
			}
			else if(digit == 1)
			{
				printf(" ");
			}
			else if(digit == 2)
			{
				printf("_");
			}
			else if(digit == 3)
			{
				printf("_");
			}
			else if(digit == 4)
			{
				printf(" ");
			}
			else if(digit == 5)
			{
				printf("_");
			}
			else if(digit == 6)
			{
				printf("_");
			}
			else if(digit == 7)
			{
				printf("_");
			}
			else if(digit == 8)
			{
				printf("_");
			}
			else if(digit == 9)
			{
				printf("_");
			}
		}
		else
		{
			printf(" ");
		}
	}
	
	printf("\n");
	
	//for row 1

	k = 0;
	digit = digits[k];
	k++;
	for(j = 0; j < numberOfColumns; j++)
	{
		if(j != 0 && j % 3 == 0)
		{
			digit = digits[k];
			k++;
		}
			
		if(j % 3 == 0)
		{
			if(digit == 0)
			{
				printf("|");
			}
			else if(digit == 1)
			{
				printf(" ");
			}
			else if(digit == 2)
			{
				printf(" ");
			}
			else if(digit == 3)
			{
				printf(" ");
			}
			else if(digit == 4)
			{
				printf("|");
			}
			else if(digit == 5)
			{
				printf("|");
			}
			else if(digit == 6)
			{
				printf("|");
			}
			else if(digit == 7)
			{
				printf(" ");
			}
			else if(digit == 8)
			{
				printf("|");
			}
			else if(digit == 9)
			{
				printf("|");
			}
		}
		
		if(j % 3 == 1)
		{
			if(digit == 0)
			{
				printf(" ");
			}
			else if(digit == 1)
			{
				printf(" ");
			}
			else if(digit == 2)
			{
				printf("_");
			}
			else if(digit == 3)
			{
				printf("_");
			}
			else if(digit == 4)
			{
				printf("_");
			}
			else if(digit == 5)
			{
				printf("_");
			}
			else if(digit == 6)
			{
				printf("_");
			}
			else if(digit == 7)
			{
				printf(" ");
			}
			else if(digit == 8)
			{
				printf("_");
			}
			else if(digit == 9)
			{
				printf("_");
			}
		}
		
		if(j % 3 == 2)
		{
			if(digit == 0)
			{
				printf("|");
			}
			else if(digit == 1)
			{
				printf("|");
			}
			else if(digit == 2)
			{
				printf("|");
			}
			else if(digit == 3)
			{
				printf("|");
			}
			else if(digit == 4)
			{
				printf("|");
			}
			else if(digit == 5)
			{
				printf(" ");
			}
			else if(digit == 6)
			{
				printf(" ");
			}
			else if(digit == 7)
			{
				printf("|");
			}
			else if(digit == 8)
			{
				printf("|");
			}
			else if(digit == 9)
			{
				printf("|");
			}
		}
	}
	printf("\n");	
	
	//for row 2
	
	k = 0;
	digit = digits[k];
	k++;
	for(j = 0; j < numberOfColumns; j++)
	{
		if(j != 0 && j % 3 == 0)
		{
			digit = digits[k];
			k++;
		}
			
		if(j % 3 == 0)
		{
			if(digit == 0)
			{
				printf("|");
			}
			else if(digit == 1)
			{
				printf(" ");
			}
			else if(digit == 2)
			{
				printf("|");
			}
			else if(digit == 3)
			{
				printf(" ");
			}
			else if(digit == 4)
			{
				printf(" ");
			}
			else if(digit == 5)
			{
				printf(" ");
			}
			else if(digit == 6)
			{
				printf("|");
			}
			else if(digit == 7)
			{
				printf(" ");
			}
			else if(digit == 8)
			{
				printf("|");
			}
			else if(digit == 9)
			{
				printf(" ");
			}
		}
		
		if(j % 3 == 1)
		{
			if(digit == 0)
			{
				printf("_");
			}
			else if(digit == 1)
			{
				printf(" ");
			}
			else if(digit == 2)
			{
				printf("_");
			}
			else if(digit == 3)
			{
				printf("_");
			}
			else if(digit == 4)
			{
				printf(" ");
			}
			else if(digit == 5)
			{
				printf("_");
			}
			else if(digit == 6)
			{
				printf("_");
			}
			else if(digit == 7)
			{
				printf(" ");
			}
			else if(digit == 8)
			{
				printf("_");
			}
			else if(digit == 9)
			{
				printf("_");
			}
		}
		
		if(j % 3 == 2)
		{
			if(digit == 0)
			{
				printf("|");
			}
			else if(digit == 1)
			{
				printf("|");
			}
			else if(digit == 2)
			{
				printf(" ");
			}
			else if(digit == 3)
			{
				printf("|");
			}
			else if(digit == 4)
			{
				printf("|");
			}
			else if(digit == 5)
			{
				printf("|");
			}
			else if(digit == 6)
			{
				printf("|");
			}
			else if(digit == 7)
			{
				printf("|");
			}
			else if(digit == 8)
			{
				printf("|");
			}
			else if(digit == 9)
			{
				printf("|");
			}
		}
	}
	printf("\n");	
		
	
	return 0;
}
