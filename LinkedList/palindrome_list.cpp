// https://www.interviewbit.com/problems/palindrome-list/

ListNode *reverse(ListNode *curr){
    ListNode *prev = NULL, *next;
    while(curr != NULL){
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    cout<<prev->val;
    return prev;
}
int Solution::lPalin(ListNode* A) {
    int middle = 0, len = 0;
    ListNode *loop = A;
    while(loop != NULL){
        len++;
        loop = loop->next;
    }
    cout<<"len"<<len<<endl;
    middle = (len%2) ? len/2 + 1 : len/2;
    cout<<"middle"<<middle<<endl;
    int counter = 1;
    loop = A;
    while(counter <= middle){
        loop = loop->next;
        counter++;
    }
    cout<<"loop"<<loop->val<<endl;
    ListNode *rev = reverse(loop);
    loop = A;
    int flag = 0;
    while(loop != NULL && rev != NULL){
        if(loop->val != rev->val){
            flag = 1;
            break;
        }
    }
    return flag;
}
