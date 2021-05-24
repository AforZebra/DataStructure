// https://www.interviewbit.com/problems/k-reverse-linked-list/

ListNode *reverse(ListNode *node, int len){
    int count = 1;
    ListNode *next, *curr = node, *prev = NULL;
    if(curr == NULL)
        return NULL;
    while((count <= len) && (curr != NULL)){
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
        count++;
    }
    node->next = reverse(curr, len);
    return prev;
} 

ListNode* Solution::reverseList(ListNode* A, int B) {
    if(A == NULL || A->next == NULL)
        return A;
    return reverse(A, B);
}
