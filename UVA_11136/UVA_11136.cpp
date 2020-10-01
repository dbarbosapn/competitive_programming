/**
 * [UVA 11136] Hoax or what
 * https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=2077
 *
 * Very straight forward solution. Build a set with all the bills and then, at
 * the end of each iteration, take the first and last bill, add the difference
 * to the sum, and keep going until the days end. At the end, print the sum.
 *
 * Time complexity is O(b*log(b)) where b is the total number of bills.
 **/

#include <iostream>
#include <set>

using namespace std;

int main(int argc, char const *argv[]) {
    while (true) {
        int n;
        cin >> n;
        if (n == 0) break;

        multiset<int> set;

        long sum = 0;

        while (n > 0) {
            int b;
            cin >> b;

            while (b > 0) {
                int val;
                cin >> val;
                set.insert(val);
                b--;
            }

            multiset<int>::iterator i;

            i = set.end();
            i--;
            int top = *i;
            set.erase(i);

            i = set.begin();
            int bot = *i;
            set.erase(i);

            sum += top - bot;

            n--;
        }

        cout << sum << endl;
    }
    return 0;
}
