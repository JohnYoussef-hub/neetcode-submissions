class Solution {
   public:
    ListNode* mergeKLists(vector<ListNode*>& ls) {
        if (ls.size() == 0) return nullptr;

        priority_queue<ListNode*, vector<ListNode*>,
                       function<bool(ListNode*, ListNode*)>>
            pq([](ListNode* a, ListNode* b) { return a->val > b->val; });

        ListNode* dummy = new ListNode();
        ListNode* curr = dummy;

        for (int i = 0; i < ls.size(); i++) {
            if (ls[i]) pq.push(ls[i]);
        }

        while (!pq.empty()) {
            curr->next = pq.top();

            ListNode* curr2 = pq.top();
            pq.pop();

            if (curr2->next) pq.push(curr2->next);

            curr = curr->next;
        }

        ListNode* result = dummy->next;
        delete dummy;

        return result;
    }
};