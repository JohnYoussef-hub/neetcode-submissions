#include <math.h>

#include <iostream>
#include <queue>
#include <stack>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

struct DLL {
    int key;
    int val;
    DLL* next;
    DLL* prev;
    DLL(int k, int v) : key(k), val(v), next(nullptr), prev(nullptr) {}
    DLL() : key(0), val(0), next(nullptr), prev(nullptr) {}
};

class LRUCache {
    unordered_map<int, DLL*> hm;
    DLL* head;
    DLL* tail;
    int capacity;

   public:
    LRUCache(int capacity) {
        this->capacity = capacity;
        head = new DLL();
        tail = new DLL();
        head->next = tail;
        tail->prev = head;
    }

    int get(int key) {
        if (hm.find(key) != hm.end()) {
            DLL* node = hm[key];

            node->next->prev = node->prev;
            node->prev->next = node->next;

            DLL* lastNode = tail->prev;
            node->prev = lastNode;
            node->next = tail;
            lastNode->next = node;
            tail->prev = node;

            return node->val;
        }
        return -1;
    }

    void put(int key, int value) {
        if (hm.find(key) != hm.end()) {
            DLL* node = hm[key];
            node->val = value;

            node->prev->next = node->next;
            node->next->prev = node->prev;

            DLL* lastNode = tail->prev;
            node->prev = lastNode;
            node->next = tail;
            lastNode->next = node;
            tail->prev = node;
            return;
        }

        if (hm.size() >= capacity) {
            DLL* lru = head->next;
            head->next = lru->next;
            lru->next->prev = head;

            hm.erase(lru->key);
            delete lru;
        }

        DLL* newNode = new DLL(key, value);
        DLL* lastNode = tail->prev;

        newNode->next = tail;
        newNode->prev = lastNode;

        lastNode->next = newNode;
        tail->prev = newNode;

        hm[key] = newNode;
    }
};