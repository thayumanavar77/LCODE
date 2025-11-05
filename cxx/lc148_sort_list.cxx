/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* sortList(ListNode* head) {
        if (head == nullptr || head->next == nullptr)
            return head;

        ListNode *p = nullptr, *f = head, *s = head;
        while(f != nullptr && f->next != nullptr) {
            p = s;
            f = f->next->next;
            s = s->next;
        }
        p->next = nullptr;

        ListNode *l1 = sortList(head);
        ListNode *l2 = sortList(s);
        return merge(l1, l2);
    }

    ListNode *merge(ListNode *l1, ListNode *l2) {
        ListNode *dummy = new ListNode(), *p = dummy;
        while (l1 != nullptr && l2 != nullptr) {
            if (l1->val < l2->val) {
                p->next = l1;
                l1 = l1->next;
            }
            else {
                p->next = l2;
                l2 = l2->next;
            }
            p = p->next;
        }

        if (l1 != nullptr) p->next = l1;

        if (l2 != nullptr) p->next = l2;

        return dummy->next;
    }
};
