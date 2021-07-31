#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node * next;
};

//add a node after the last node
struct Node * node_push_back(struct Node * input_first, int input_data)
{
    struct Node * current = input_first;
    //go to the last node
    while(current->next != NULL)
    {
        current = current->next;
    }

    //create new node
    struct Node * new_node = malloc(sizeof(struct Node));

    new_node->data = input_data;
    new_node->next = NULL;

    current->next = new_node;
    return input_first;
}

//add a node in front of the first node
struct Node * node_push_front(struct Node * input_first, int input_data)
{
    struct Node * new_node = malloc(sizeof(struct Node));

    new_node->data = input_data;
    new_node->next = input_first;

    return new_node;
}

//delete the first element of the list
struct Node * node_pop_front(struct Node * input_first)
{
    struct Node * current = input_first;

    current = current->next;
    free(input_first);

    return current;
}

//delete the last element of the list
struct Node * node_pop_back(struct Node * input_first)
{
    struct Node * current = input_first;
    struct Node * previous;

    while(current->next != NULL)
    {
        previous = current;
        current = current->next;
    }

    previous->next = NULL;
    free(current);
    return input_first;
};

struct Node * search_node(struct Node * input_first, int sought_data)
{
    struct Node * current = input_first;

    while(current != NULL)
    {
        if(current->data == sought_data)
        {
            return current;
        }
        current = current -> next;
    }

    return NULL;  //node not found
};

struct Node * delete_node(struct Node * input_first, int sought_data)
{
    struct Node * current = input_first;
    struct Node * previous = input_first;

    while(current != NULL)
    {
        if(current->data == sought_data)
        {
            previous->next = current->next;
            free(current);
            return input_first;  //if the sought node is found
        }
        previous = current;
        current = current->next;
    }

    return input_first;  //if the sought node is not found
};

struct Node * reverse_linked_list(struct Node * input_first)
{
    struct Node * current = input_first;
    struct Node * previous = input_first;
    struct Node * previous_previous = input_first;

    current = current->next;
    current = current->next;
    previous = previous->next;
    previous_previous->next = NULL;

    while(current != NULL)
    {
        previous->next = previous_previous;
        previous_previous = previous;
        previous = current;
        current = current->next;
    }

    previous->next = previous_previous;

    return previous;
};

void print_linked_list(struct Node * current)
{
    //traverse the nodes
    while(current != NULL)
    {
        printf("%d ", current->data);
        current = current->next;
    }
}

int main()
{
    int a[] = {0, 10, 20, 30, 40, 50, 60, 70, 80, 90, 100};
    int a_size = sizeof(a)/sizeof(a[0]);

    struct Node * first = NULL;

    //create the first node
    first = malloc(sizeof(struct Node));
    first->data = a[0];
    first->next = NULL;

    for(int i = 1; i < a_size; i++)
    {
        first = node_push_back(first, a[i]);
    }
    
    printf("node_push_back() is iterated over.\n");

    printf("list: ");
    print_linked_list(first);
    printf("\n");


    first = reverse_linked_list(first);
    printf("reverse_linked_list() is executed\n");

    printf("list: ");
    print_linked_list(first);
    printf("\n");
    
    for(int i = 2; i < a_size + 1; i++)
    {
        first = node_push_front(first, a[a_size - i]);
    }
    
    printf("node_push_front() is iterated over.\n");
  
    printf("list: ");
    print_linked_list(first);
    printf("\n");

    return 0;
}

/*
node_push_back() is executed.
list: 0 10 20 30 40 50 60 70 80 90 100 
reverse_linked_list() is executed
list: 100 90 80 70 60 50 40 30 20 10 0 
node_push_print() is executed.
list: 0 10 20 30 40 50 60 70 80 90 100 90 80 70 60 50 40 30 20 10 0
*/
