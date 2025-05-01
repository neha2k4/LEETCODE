#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

class Solution {
public:
    int maxTaskAssign(vector<int>& tasks, vector<int>& workers, int pills, int strength) {
        sort(tasks.begin(), tasks.end());
        sort(workers.begin(), workers.end());

        int left = 0, right = min((int)tasks.size(), (int)workers.size()), answer = 0;

        while (left <= right) {
            int mid = (left + right + 1) / 2;
            if (canAssign(tasks, workers, pills, strength, mid)) {
                answer = mid;
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }

        return answer;
    }

private:
    bool canAssign(vector<int>& tasks, vector<int>& workers, int pills, int strength, int k) {
        if (k == 0) return true;
        if (k > workers.size()) return false;

        multimap<int, int> availableWorkers;
        for (int i = workers.size() - k; i < workers.size(); i++) {
            availableWorkers.insert({workers[i], i});
        }

        int usedPills = 0;

        for (int i = k - 1; i >= 0; i--) {
            int task = tasks[i];

            auto it = prev(availableWorkers.end());
            if (it->first >= task) {
                availableWorkers.erase(it);
            } else {
                auto boostedIt = availableWorkers.lower_bound(task - strength);
                if (boostedIt == availableWorkers.end() || usedPills >= pills) {
                    return false;
                }
                availableWorkers.erase(boostedIt);
                usedPills++;
            }
        }

        return true;
    }
};