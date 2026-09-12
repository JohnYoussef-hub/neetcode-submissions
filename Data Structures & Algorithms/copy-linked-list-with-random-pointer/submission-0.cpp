class Solution {
public:
    Node* copyRandomList(Node* head) {
        Node* tHead = head;

        unordered_map<Node*, Node*> oldToNew;

        while (tHead) {
            oldToNew[tHead] = new Node(tHead->val);
            tHead = tHead->next;
        }

        tHead = head;

        while (tHead) {
            Node* newNode = oldToNew[tHead];
            newNode->next = oldToNew[tHead->next];
            newNode->random = oldToNew[tHead->random];
            tHead = tHead->next;
        }

        return oldToNew[head];
    }
};