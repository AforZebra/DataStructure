https://www.interviewbit.com/problems/add-two-numbers-as-lists/

ListNode* Solution::addTwoNumbers(ListNode* A, ListNode* B) {
    int carry = 0, rem, sum;
    if(A == NULL)
        return B;
    else if(B == NULL)
        return A;
    ListNode *C = A, *curr = A;
    while(A && B){
        curr = A;
        sum = A->val + B->val + carry;
        carry = sum/10;
        curr->val = sum%10;
        A = A->next;
        B = B->next;
    }
    if(A == NULL && B){
        curr->next = B;
        while(B){
            curr = B;
            sum = B->val + carry;
            carry = sum/10;
            curr->val = sum%10;
            B = B->next;
        }
    }
    else if(B == NULL && A){
        while(A){
            curr = A;
            sum = A->val + carry;
            carry = sum/10;
            curr->val = sum%10;
            A = A->next;
        }
    }
    if(carry){
        ListNode *newNode = (ListNode*)malloc(sizeof(ListNode));
        newNode->next = NULL;
        newNode->val = 1;
        curr->next = newNode;
    }
    return C;
}
