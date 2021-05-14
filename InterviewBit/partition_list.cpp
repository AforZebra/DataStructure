// https://www.interviewbit.com/problems/partition-list/

ListNode* Solution::partition(ListNode* A, int B) {
    if(A == NULL || A->next == NULL)
        return A;
    ListNode *head = A, *prev = A, *temp, *startofB, *prevB = NULL;
    bool flag = false;
    while(A != NULL){
        if(A->val < B && !flag)
            prevB = A;
        else if(!flag){
            startofB = A;
            flag = true;
        }
        if(A->val < B && flag){
            prev->next = A->next;
            temp = A;
            A = A->next;
            temp->next = startofB;
            if(prevB == NULL){
                head = temp;
                prevB = temp;
            }
            else{
                prevB->next = temp;
                prevB = temp;
            }
        }
        else{
            prev = A;
            A = A->next;
        }
    }
    return head;
}
