/**
 * [UVA 11995] I Can Guess the Data Structure
 * https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=3146
 *
 * A very naive approach can be used with this problem. All we do, is create the
 * three data structures, and simulate the operations. If one's not possible, we
 * mark its flag as false. Then, we check if more than one are true, all are
 * false or only one is true, and print the correct answer.
 *
 * Time complexity will be equal to the time complexity of the most time
 * consuming data structure. In this case, the priority queue. O(n*log(n))
 **/

#include <iostream>
#include <queue>
#include <stack>

using namespace std;

int main(int argc, char const *argv[]) {
    int n;
    while (cin >> n) {
        stack<int> s;
        queue<int> q;
        priority_queue<int> pq;

        bool is_stack = true;
        bool is_queue = true;
        bool is_pqueue = true;

        while (n > 0) {
            int op, val;
            cin >> op >> val;

            if (op == 1) {
                s.push(val);
                q.push(val);
                pq.push(val);
            } else if (op == 2) {
                if (s.size() > 0) {
                    int a = s.top();
                    s.pop();
                    if (a != val) is_stack = false;
                } else {
                    is_stack = false;
                }

                if (q.size() > 0) {
                    int b = q.front();
                    q.pop();
                    if (b != val) is_queue = false;
                } else {
                    is_queue = false;
                }

                if (pq.size() > 0) {
                    int c = pq.top();
                    pq.pop();
                    if (c != val) is_pqueue = false;
                } else {
                    is_pqueue = false;
                }
            }

            n--;
        }

        if (!is_stack && !is_queue && !is_pqueue) {
            cout << "impossible\n";
        } else if (is_stack && is_queue || is_stack && is_pqueue ||
                   is_queue && is_pqueue) {
            cout << "not sure\n";
        } else if (is_stack) {
            cout << "stack\n";
        } else if (is_queue) {
            cout << "queue\n";
        } else if (is_pqueue) {
            cout << "priority queue\n";
        }
    }

    return 0;
}
