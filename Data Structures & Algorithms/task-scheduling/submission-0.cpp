class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {

        vector<int> count(26, 0);
        for (char c : tasks) 
            count[c - 'A']++;
        
        ::sort(count.begin(), count.end());

        int max_freq = count[25];
        int idle_slots = (max_freq - 1) * n;

        for (int i = 24; i >= 0 && count[i] > 0; i--)
        {
            idle_slots -= ::min(max_freq - 1, count[i]);
        }

        if (idle_slots < 0) idle_slots = 0;

        return tasks.size() + idle_slots;

    }
};