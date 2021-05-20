// https://www.interviewbit.com/problems/reorder-list/

ListNode *createNode(ListNode *node, int data){
    ListNode *newNode = (ListNode*)malloc(sizeof(ListNode));
    newNode->val = data;
    newNode->next = node;
    return newNode;
} 

ListNode *reverse(ListNode *curr, ListNode *prev){
    if(curr == NULL)
        return prev;
    ListNode *head = reverse(curr->next, curr);
    curr->next = prev;
    return head;
}

ListNode* Solution::reorderList(ListNode* A) {
    int len = 0;
    ListNode *B = NULL, *loop = A, *C = NULL;
    while(loop != NULL){
        B = createNode(B, loop->val);
        loop = loop->next;
        len++;
    }
    if(len == 1)
        return A;
    int count = 1;
    while(count <= len){
        C = createNode(C, A->val);
        C = createNode(C, B->val);
        if(len%2 ==0 && count == len/2){
                break;
        }
        else if(len%2 !=0 && count == len/2){
            C = createNode(C, A->next->val);
            break;
        }
        A = A->next;
        B = B->next;
        count++;
    }
    C = reverse(C, NULL);
    return C;
}
