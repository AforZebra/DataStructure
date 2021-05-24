// https://www.interviewbit.com/problems/palindrome-list/

ListNode *reverse(ListNode *curr){
    ListNode *prev = NULL, *next;
    while(curr != NULL){
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    return prev;
}
int Solution::lPalin(ListNode* A) {
    int middle = 0, len = 0;
    ListNode *loop = A;
    while(loop != NULL){
        len++;
        loop = loop->next;
    }
    middle = (len%2) ? len/2 + 1 : len/2;
    int counter = 1;
    loop = A;
    while(counter <= middle){
        loop = loop->next;
        counter++;
    }
    ListNode *rev = reverse(loop);
    loop = A;
    int flag = 1;
    while(loop != NULL && rev != NULL){
        if(loop->val != rev->val){
            flag = 0;
            break;
        }
        loop = loop->next;
        rev = rev->next;
    }
    return flag;
}
