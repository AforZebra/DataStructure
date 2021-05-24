// https://www.interviewbit.com/problems/rotate-list/

ListNode* Solution::rotateRight(ListNode* A, int B) {
    ListNode *loop1 = A, *loop2, *prev, *prev2, *head;
    int len = 0;
    while(loop1 != NULL){
        len++;
        loop1 = loop1->next;
    }
    int breakPoint = B%len;
    if(breakPoint == 0)
        return A;
    breakPoint = len - breakPoint;
    int counter = 1;
    loop1 = A;
    while(counter <= breakPoint){
        prev = loop1;
        loop1 = loop1->next;
        counter++;
    }
    loop2 = loop1;
    head = loop1;
    prev->next = NULL;
    while(loop2 != NULL){
        prev2 = loop2;
        loop2 = loop2->next;
    }
    prev2->next = A;
    return head;
}
