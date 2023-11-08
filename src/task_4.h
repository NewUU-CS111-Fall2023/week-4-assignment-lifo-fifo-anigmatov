/*
 * Author: Abdusamad 
 * Date: 08.11.2023
 * Name: Task 4
 */

#include <iostream>
#include <vector>
#include <stack>

using namespace std;

int main() {
    int N;
    cin >> N;

    vector<stack<int>> stacks(N);
    vector<int> targetStack(N, -1);  // Target stack for each container type

    // Read the initial container stacks and populate targetStack
    for (int i = 0; i < N; i++) {
        int k;
        cin >> k;
        for (int j = 0; j < k; j++) {
            int type;
            cin >> type;
            stacks[i].push(type);
            if (targetStack[type - 1] == -1) {
                targetStack[type - 1] = i;
            }
        }
    }

    // Simulate moving containers to their target stacks
    vector<pair<int, int>> actions;  // To store actions (from stack to stack)

    for (int i = 0; i < N; i++) {
        while (!stacks[i].empty()) {
            int containerType = stacks[i].top();
            int target = targetStack[containerType - 1];

            if (target == i) {
                // Container is already in the correct stack
                stacks[i].pop();
            } else {
                // Move the container to the target stack
                stacks[i].pop();
                stacks[target].push(containerType);
                actions.push_back({i, target});
            }
        }
    }

    // Check if the containers are now properly stacked
    bool isProperlyStacked = true;
    for (int i = 0; i < N; i++) {
        if (!stacks[i].empty()) {
            isProperlyStacked = false;
            break;
        }
    }

    if (isProperlyStacked) {
        for (const auto& action : actions) {
            cout << action.first + 1 << " " << action.second + 1 << endl;
        }
    } else {
        cout << "0" << endl;  // No solution
    }

    return 0;
}
