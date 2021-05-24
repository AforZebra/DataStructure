// https://www.interviewbit.com/courses/programming/topics/linked-lists/

ListNode *reverse(ListNode *node, int len){
    ListNode *curr = node, *prev = NULL, *next;
    int counter =  1;
    if(curr == NULL)
        return NULL;
    while(counter <= len && curr != NULL){
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
        counter++;
    }
    node->next = reverse(curr, len);
    return prev;
}
ListNode* Solution::swapPairs(ListNode* A) {
    if(A == NULL || A->next == NULL)
        return A;
    return reverse(A, 2);
}
