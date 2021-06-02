// https://www.interviewbit.com/problems/subtract/

ListNode *recursive(ListNode *curr, int count, int middle, bool even){
    if(count == middle){
        if(even)
            return curr;
        return curr->next;
    }
    ListNode *temp = recursive(curr->next, ++count, middle, even);
    curr->val = temp->val - curr->val;
    return temp->next;
}
 
ListNode* Solution::subtract(ListNode* A) {
    int len = 0;
    ListNode *loop = A;
    while(loop){
        loop = loop->next;
        len++;
    }
    if(len < 2)return A;
    bool even = (len%2 == 0) ? true : false;
    recursive(A, 0, len/2, even);
    return A;
}
