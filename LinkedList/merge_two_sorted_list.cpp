// https://www.interviewbit.com/problems/merge-two-sorted-lists/

ListNode* Solution::mergeTwoLists(ListNode* A, ListNode* B) {
    ListNode *C, *curr;
    
    if(A == NULL)
        return B;
    else if(B == NULL)
        return A;
        
    if(A->val < B->val){
        C = A;
        A = A->next;
    }
    else{
        C = B;
        B = B->next;
    }
    curr = C;
    
    while(A && B){
        if(A->val < B->val){
            curr->next = A;
            curr = A;
            A = A->next;
        }
        else{
            curr->next = B;
            curr = B;
            B = B->next;
        }
    }
    
    if(A == NULL && B)
        curr->next = B;
    else if(B == NULL && A)
        curr->next = A;
    return C;
}
