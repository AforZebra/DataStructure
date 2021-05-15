// https://www.interviewbit.com/problems/insertion-sort-list/

ListNode* Solution::insertionSortList(ListNode* A) {
    ListNode *head = A, *prev = NULL, *curr, *loop = A,*temp;
    if(A == NULL || A->next == NULL)
        return A;
    int length = 0;
    while(loop != NULL){
        length++;
        loop = loop->next;
    }
    while(length--){
        curr = head;
        prev = NULL;
        while(curr->next != NULL){
            temp = curr->next;
            if(curr->val > temp->val){
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
    }
    return head;
}
