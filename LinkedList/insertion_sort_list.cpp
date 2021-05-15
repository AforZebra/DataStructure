// https://www.interviewbit.com/problems/insertion-sort-list/

ListNode* Solution::insertionSortList(ListNode* A) {
    
    ListNode *head = A, *prev = NULL, *curr, *loop = A,*temp, *insertionBreak = NULL;
    int length = 0;
    bool swapFlag = false;
    
    if(A == NULL || A->next == NULL)
        return A;
        
    while(loop != NULL){
        length++;
        loop = loop->next;
    }
    
    while(length--){
        curr = head;
        prev = NULL;
        swapFlag = false;
        while(curr->next != insertionBreak){
            temp = curr->next;
            if(curr->val > temp->val){
                swapFlag = true;
                if(prev == NULL){
                    head = temp;
                }
                else
                    prev->next = temp;
                curr->next = temp->next;
                temp->next = curr;
                prev = temp;
            }
            else{
                prev = curr;
                curr = curr->next;
            }
        }
        insertionBreak = curr;
        if(!swapFlag)
            break;
    }
    return head;
}
