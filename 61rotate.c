/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* rotateRight(struct ListNode* head, int k) {
    if(head == NULL || head->next == NULL)
        return head;
    struct ListNode *ptr = head, *firstNode = NULL, *lastNode = NULL;
    int numberNodes = 0;
    while(ptr != NULL)
    {
        ptr = ptr->next;
        numberNodes += 1;
    }
    k = k % numberNodes;
    if(k == numberNodes || k == 0)
        return head;
    numberNodes -= k;
    ptr = head;
    for(int i = 0;i < numberNodes - 1;i++)
    {
        ptr = ptr->next;
    }
    lastNode = ptr;
    ptr = ptr->next;
    firstNode = ptr;
    while(ptr->next != NULL)
        ptr = ptr->next;
    ptr->next = head;
    lastNode->next = NULL;
    head = firstNode;
    return head;
}
