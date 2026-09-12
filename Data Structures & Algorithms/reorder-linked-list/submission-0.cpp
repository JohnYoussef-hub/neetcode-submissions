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
    ListNode* left;
    bool stop;

public:
    void reorderList(ListNode* head) {
        if (!head || !head->next) return;
        left = head;
        stop = false;
        recursion(head);
    }

    void recursion(ListNode* right) {
        if (!right) return;
        recursion(right->next);

        if (stop) return;

        if (left == right) {
            left->next = nullptr;
            stop = true;
            return;
        }

        if (left->next == right) {
            right->next = nullptr;
            stop = true;
            return;
        }

        ListNode* nextLeft = left->next;
        left->next = right;
        right->next = nextLeft;

        left = nextLeft;
    }
};
