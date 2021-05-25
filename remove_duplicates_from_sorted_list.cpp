// https://www.interviewbit.com/problems/remove-duplicates-from-sorted-list/

ListNode* Solution::deleteDuplicates(ListNode* A) {
    ListNode *curr = A, *newNode = A;
    int counter = 0;
    if(A == NULL)
        return A;
    while(curr != NULL){
        while(curr && (curr->val == newNode->val)){
            curr = curr->next;
            counter++;
        }
        if(counter > 1)
            newNode->next = curr;
        newNode = curr;
    }
    return A;
}
