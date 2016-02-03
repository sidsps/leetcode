struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) {
    struct ListNode* sum = NULL;
    struct ListNode *ptr, *ptr1 = l1, *ptr2 = l2;
    struct ListNode *temp;
    int carry = 0;
    while(ptr1 != NULL && ptr2 != NULL)
    {
        temp = (struct ListNode*)malloc(sizeof(struct ListNode));
        temp->val = (ptr1->val + ptr2->val + carry)%10;
        temp->next = NULL;
        carry = (ptr1->val + ptr2->val + carry)/10;
        if (sum == NULL) {
            sum = temp;
            ptr = temp;
        }
        else
        {
            ptr->next = temp;
            ptr = ptr->next;
        }
        ptr1 = ptr1->next;
        ptr2 = ptr2->next;
    }
    struct ListNode* new = NULL;
    if(ptr1 == NULL && ptr2 == NULL){
        if (carry != 0) {
            temp = (struct ListNode*)malloc(sizeof(struct ListNode));
            temp->val = carry;
            temp->next = NULL;
            ptr->next = temp;
            ptr = ptr->next;
        }
        return sum;
    }
    if(ptr1 == NULL && ptr2 != NULL)
        new = ptr2;
    if(ptr1 != NULL && ptr2 == NULL)
        new = ptr1;
    while(new != NULL)
    {
        temp = (struct ListNode*)malloc(sizeof(struct ListNode));
        temp->val = (new->val + carry)%10;
        temp->next = NULL;
        carry = (new->val + carry)/10;
        ptr->next = temp;
        ptr = ptr->next;
        new = new->next;
    }
    if (carry != 0) {
        temp = (struct ListNode*)malloc(sizeof(struct ListNode));
        temp->val = carry;
        temp->next = NULL;
        ptr->next = temp;
        ptr = ptr->next;
    }
    return sum;
}
