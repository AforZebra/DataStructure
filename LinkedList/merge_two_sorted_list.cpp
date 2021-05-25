// https://www.interviewbit.com/problems/merge-two-sorted-lists/

ListNode* Solution::mergeTwoLists(ListNode* A, ListNode* B) {
    ListNode *C = NULL, *temp, *curr = NULL;
    
    while(A != NULL && B != NULL){
        if(A->val < B->val){
            temp = A;
            A = A->next;
            temp->next = NULL;
            if(curr)
                curr->next = temp;
            else
                C = temp;
            curr = temp;
        }
        else{
            temp = B;
            B = B->next;
            temp->next = NULL;
            if(curr)
                curr->next = temp;
            else
                C = temp;
            curr = temp;
        }
    }
    
    if(A == NULL && B != NULL)
        curr->next = B;
    else if(B == NULL && A != NULL)
        curr->next = A;
    return C;
}
