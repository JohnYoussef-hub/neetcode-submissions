class Solution {
    int _size = 0;

   public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* temp = head;
        while (temp){
            _size++;
            temp = temp->next;
        }

        return helper(head, k);
    }

    ListNode* helper(ListNode* head, int k) {
        if (_size / k < 1) return head;

        ListNode* prev = nullptr;
        ListNode* curr = head;
        ListNode* next = nullptr;

        ListNode* newHead;

        for (int i = 0; i < k; i++) {
            if (i == k - 1) newHead = curr;

            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }

        _size -= k;

        head->next = helper(curr, k);

        return newHead;
    }
};