/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* removeNthFromEnd(struct ListNode* head, int n) {
    struct ListNode* ptr = head, *par;
    int nodes = 0, skip, x = 0;
    while(ptr != NULL)
    {
        ptr = ptr->next;
        nodes++;
    }
    if(n == nodes)
    {
        head = head->next;
        return head;
    }
    skip = nodes - n;
    ptr = head;
    while(x++ < skip)
    {
        par = ptr;
        ptr = ptr->next;
    }
    if(ptr->next == NULL)
    {
        par->next = NULL;
    }
    else
    {
        par->next = ptr->next;
    }
    return head;
}
