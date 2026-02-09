/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
typedef struct ListNode ListNode;
typedef struct TreeNode TreeNode;

struct ListNode* createListNode (int val);
struct TreeNode* createTreeNode (int val);

struct TreeNode* sortedListToBST(struct ListNode* head) {
    if (head == NULL) return NULL;

    //como a lista está ordenado, a raiz da arvore se encontra no meio da lista
    struct ListNode* prev = NULL;
    struct ListNode* slow = head;
    struct ListNode* fast = head;

    while (fast !=NULL && fast->next !=NULL) {
        prev = slow;
        slow = slow->next;
        fast = fast->next->next;
    }

    struct TreeNode* root = createTreeNode(slow->val);

    //caso a lista tenha apenas um elemento
    if (slow == head) return root;

    if(prev != NULL) {
        prev->next = NULL;
    }

    //recursão
    root->left = sortedListToBST(head);
    root->right = sortedListToBST(slow->next);

    return root;
}

struct TreeNode* createTreeNode (int val) {
    struct TreeNode* node = (TreeNode*)malloc(sizeof(TreeNode));
    node->val = val;
    node->left = NULL;
    node->right = NULL;

    return node;
}