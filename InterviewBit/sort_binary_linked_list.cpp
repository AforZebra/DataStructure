  
ListNode* Solution::solve(ListNode* A) {
    ListNode *head = A, *prev = A;
    ListNode *temp;
    if(A == NULL || A->next == NULL)
        return A;
    int count1 = 0, count0 = 0;
    while(A != NULL){
        if(A->val == 0)
            count0++;
        else
            count1++;
        A = A->next;
    }
    A = head;
    while(A != NULL){
        if(count0 != 0 && count0--)
            A->val = 0; 
        else
            A->val = 1;
        A = A->next;
    }
    return head;
}
