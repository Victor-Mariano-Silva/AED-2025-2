#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct ListNode {
      int val;
      struct ListNode *next;
  };

void reorderList(struct ListNode* head) {
    if (!head || !head->next) return;
    
    struct ListNode* current = head;
    int length = 0;
    while (current) {
        length++;
        current = current->next;
    }
    
    struct ListNode** nodes = (struct ListNode**)malloc(length * sizeof(struct ListNode*));
    if (!nodes) return; 
    
    current = head;
    for (int i = 0; i < length; i++) {
        nodes[i] = current;
        current = current->next;
    }
    

    int i = 0, j = length - 1;
    struct ListNode* newHead = nodes[i];
    current = newHead;
    
    while (i < j) {
        current->next = nodes[j];
        current = current->next;
        i++;
        
        if (i >= j) break;
        
        current->next = nodes[i];
        current = current->next;
        j--;
    }
    
    current->next = NULL;
    
    free(nodes);
}