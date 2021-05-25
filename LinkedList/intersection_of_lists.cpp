// https://www.interviewbit.com/problems/intersection-of-linked-lists/

ListNode* Solution::getIntersectionNode(ListNode* A, ListNode* B) {
    
    int lena = 0, lenb = 0, bigLen;
    ListNode *headA = A, *headB = B;
    while(A || B){
        if(A){
            lena++;
            A = A->next;
        }
        if(B){
            lenb++;
            B = B->next;
        }
    }
    bool big = lena > lenb ? true : false;
    bigLen = abs(lena - lenb);
    while(bigLen--){
        if(big)
            headA = headA->next;
        else
            headB = headB->next;
    }
    while(headA && headB){
        if(headA == headB){
            return headA;
        }
        headA = headA->next;
        headB = headB->next;
    }
    return NULL;
}
