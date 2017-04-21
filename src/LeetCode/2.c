/**
 * Created by LonelyEnvoy on 2017-4-21.
 * Add Two Numbers
 * Keywords: implementation，水题
 */

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) {
    int carry = 0;
    struct ListNode* l = (struct ListNode*)malloc(sizeof(struct ListNode));
    struct ListNode* root = l;

    while(l1 || l2) {
        l = l->next = (struct ListNode*)malloc(sizeof(struct ListNode));
        l->val = (l1 ? l1->val : 0) + (l2 ? l2->val : 0) + carry;
        l->next = NULL;
        carry = (l->val >= 10);
        l->val %= 10;
        if (l1) l1 = l1->next;
        if (l2) l2 = l2->next;
    }
    if (carry) {
        l = l->next = (struct ListNode*)malloc(sizeof(struct ListNode));
        l->val = 1;
        l->next = NULL;
    }
    return root->next;
}
