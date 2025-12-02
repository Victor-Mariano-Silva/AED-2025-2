/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

 struct Stack {
    int top;
    int array[1000];
 } Stack;

void initialize(struct Stack *stack);
int getLenght(struct ListNode* head);
int getValue(struct ListNode* head);
void IsEmpty(struct Stack *stack);
void isFull(struct Stack *stack);
void push(struct Stack *stack, int node);

void reorderList(struct ListNode* head) {
// make a stack with the nodes of the linked list but alternating between the first and last remaing nodes
// problem 1, dont remember how to get the lenght of a linked list since its not a array. kinda resolved
// problem 2, dont remeber how to operate a linked list 
struct Stack stack;
initialize(&stack);
int listLen = getLenght(head);
int listVal[] = getValue(head);

for(int i = 0; i < listLen/2;i++) {

    push(&stack, listVal[i]);
    push(&stack, ListVal[listLen - i]);
    
}
   return stack; 
}


 void initialize(struct Stack *stack) {
    if (!isEmpty(stack)) {
        return 0;
    }
    stack->top = -1;
}

int getLenght(struct ListNode* head) {
    int lenght = 0;

    while (head != NULL){
        head = head->next;
        lenght ++;
    }

    return lenght;
}

int getValue(struct ListNode* head) {
    int count = 0;
    int arr[];

    while (head != NULL){
        arr[count] = curr->val;
        count++
        head = head->next;
    }

    return arr[];
}

void IsEmpty(struct Stack *stack) {
}

void isFull(struct Stack *stack) {
    return stack->top == 1000 - 1;
}

void push(struct Stack *stack, int node) {
    if(isFull(stack)) {
        return 0;
    }

    stack->arr[++stack->top] = node;
}