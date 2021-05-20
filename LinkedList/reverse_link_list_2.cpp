// https://www.interviewbit.com/problems/reverse-link-list-ii/

ListNode *reverse(ListNode *node, int k){
    ListNode *curr = node, *prev = NULL, *next;
    int counter = 1;
    while(counter <= k){
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
        counter++;
    }
    node->next = curr;
    return prev;
}
 
ListNode* Solution::reverseBetween(ListNode* A, int B, int C) {
    ListNode *curr = A, *prev = NULL;
    int counter = 1;
    while(curr != NULL){
        if(counter == B){
            ListNode *temp = reverse(curr, C-B+1);
            if(prev){
                prev->next = temp;
                return A;
            }
            else 
                return temp;
        }
        counter++;
        prev = curr;
        curr = curr->next;
    }
}
