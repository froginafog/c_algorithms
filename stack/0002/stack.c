#include <stdio.h>

int *  stack_push_back(int * stack, int stack_size, int data)
{
    if(stack_size == 0)
    {
        int * new_stack = malloc(sizeof(int));
        new_stack[0] = data;
        return new_stack;
    }
    else
    {
        int * new_stack = malloc(sizeof(int) * stack_size);
        int i;
        for(i = 0; i < stack_size; i++)
       {
            new_stack[i] = stack[i];
       }
       new_stack[i] = data;
       free(stack);
       return new_stack;
    }
}

int stack_pop_back(int * stack, int stack_size)
{
    if(stack_size == 0)
    {
        return 0;
    }
    else
    {
         int last_element = stack[stack_size - 1];

         int * temp = malloc(sizeof(int) * (stack_size - 1));
         for(int i = 0; i < stack_size - 1; i++)
         {
              temp[i] = stack[i];
         }
         free(stack);

         int * stack = malloc(sizeof(int) * (stack_size - 1));
         for(int i = 0; i < stack_size - 1; i++)
         {
              stack[i] = temp[i];
         }

          return last_element;
    }
}

void print_stack(int * stack, int stack_size)
{
    for(int i = 0; i < stack_size; i++)
    {
         printf("%d ", stack[i]);
    }
}

int main()
{
    int stack_size = 0;
    int stack_size_max = 5;
    int n;  //input number

    int * stack;

    while(stack_size < stack_size_max)
    {
        printf("Enter an integer: ");
        scanf("%d", &n);
        while(getchar() != '\n');
        stack = stack_push_back(stack, stack_size, n);
        stack_size++;
    }

    printf("stack:\n");
    print_stack(stack, stack_size);
    printf("\n");

    int popped_value;

    popped_value = stack_pop_back(stack, stack_size);
    printf("popped_value: %d\n", popped_value);
    stack_size--;
    printf("stack:\n");
    print_stack(stack, stack_size);
    printf("\n");

    popped_value = stack_pop_back(stack, stack_size);
    printf("popped_value: %d\n", popped_value);
    stack_size--;
    printf("stack:\n");
    print_stack(stack, stack_size);
    printf("\n");

    return 0;
}

/*
Enter an integer: 10
Enter an integer: 20
Enter an integer: 30
Enter an integer: 40
Enter an integer: 50
stack:
10 20 30 40 50
popped_value: 50
stack:
10 20 30 40
popped_value: 40
stack:
10 20 30
*/

