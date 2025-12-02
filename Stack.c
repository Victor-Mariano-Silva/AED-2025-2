#include <stdio.h>
#include <stdlib.h> // alocação dinamica de memoria (malloc, free)
#include <stdbool.h> // utilizar o tipo booleano

typedef struct
{
    int *collection;
    int capacity; //capacidade de itens da pilha
    int size;
} Stack;

Stack *create_stack( int capacity); //função que retorna um ponteiro apontando para uma pilha
void destroy_stack(Stack *stack); //recebe um ponteiro de uma pilha e "apagar" a pilha
bool is_full(Stack *stack);
bool is_empty(Stack *stack);
bool pop(Stack *stack, int *item);//remove um item da pilha
bool push(Stack *stack, int item);//adiciona um item a pilha
bool peek(Stack *stack, int *item); //retorna o item no topo da pilha pass by pointer

int main ()
{
    Stack *stack = create_stack(5);

    if (stack == NULL)
    {
        printf("Error creating stack.\n");
        return 1;
    }

    if (is_empty(stack)) printf("Stack is empty.\n");

    push(stack, 2);
    printf("Stack size: %d\n", stack->size);

    push(stack, 9);
    push(stack, 4);
    push(stack, 7);
    push(stack, 8);
    if (is_full(stack)) printf("Stack is full.\n");
    printf("Stack size: %d\n", stack->size);

    int peek_val = 0;
    peek(stack, &peek_val);

    printf("Peek val: %d\n",peek_val);

    
    int pop_val = 0;
    for(int i = 0; i < 5; i++)
    {
        pop(stack, &pop_val);
        printf("Popped value: %d\n",pop_val);
    }

    destroy_stack(stack);

    return 0;
}

Stack *create_stack( int capacity)
{
    if (capacity <= 0) return NULL;

    Stack *stack = malloc(sizeof(Stack)); //o malloc vai alocar espaço suficiente para guardar uma pilha
    if (stack == NULL) return NULL;

    stack->collection = malloc(sizeof(int) * capacity); // o malloc vai alocar espaços de int igual a capacidade 
    if (stack->collection == NULL)
    {
        free(stack);
        return NULL;
    } 

    stack->capacity = capacity;
    stack->size = 0;

    return stack;
}

void destroy_stack(Stack *stack)
{
    free(stack->collection);
    free(stack);
}

bool is_full(Stack *stack)
{
    return stack->capacity == stack->size;
}

bool is_empty(Stack *stack)
{
    return stack->size == 0; 
}

bool push(Stack *stack, int item)
{
    if (is_full(stack)) return false;

    stack->collection[stack->size] = item;
    stack->size++;

    return true;
}

bool peek(Stack *stack, int *item)
{
    if(is_empty(stack)) return false;

    *item = stack->collection[stack->size - 1];

    return true;
}

bool pop(Stack *stack, int *item)
{
    if (is_empty(stack)) return false;

    stack->size--;
    *item = stack->collection[stack->size];

    return true;
}

