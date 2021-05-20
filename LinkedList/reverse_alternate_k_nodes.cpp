// https://www.interviewbit.com/problems/reverse-alternate-k-nodes/

ListNode *reverseLL(ListNode *node, int k, bool b){
    if(node == NULL)
        return node;
    ListNode *curr = node, *next, *prev = NULL;
    int counter = 1;
    while(counter <= k){
        next = curr->next;
        if(b)
            curr->next = prev;
        prev = curr;
        curr = next;
        counter++;
    }
    if(b){
        node->next = reverseLL(curr, k, !b);
        return prev;
    }
    else{
        prev->next = reverseLL(curr, k, !b);
        return node;
    }
}
 
ListNode* Solution::solve(ListNode* A, int B) {
    return reverseLL(A, B, true);
}
