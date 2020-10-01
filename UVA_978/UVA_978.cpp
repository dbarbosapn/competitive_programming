/**
 * [UVA 978] Lemmings Battle!
 * https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=919
 *
 * First, we insert the values in two multisets: The green lemmings and blue
 * ones. Then, while both armies have soldiers alive, we get the highest values
 * from the sets and make them fight eachother. If one of them wins, we add it
 * to a list. Then, we rebuild the multisets with the winning lemmings. This is
 * a very straightforward problem, with no special catches.
 *
 * Time complexity is roughly quadratic.
 **/

#include <iostream>
#include <list>
#include <set>

using namespace std;

int main(int argc, char const *argv[]) {
    int n;
    cin >> n;

    while (n > 0) {
        int b, sg, sb;
        cin >> b >> sg >> sb;

        multiset<int> green;
        multiset<int> blue;

        for (int i = 0; i < sg; i++) {
            int val;
            cin >> val;
            green.insert(val);
        }

        for (int i = 0; i < sb; i++) {
            int val;
            cin >> val;
            blue.insert(val);
        }

        while (green.size() > 0 && blue.size() > 0) {
            int m = min(green.size(), blue.size());

            multiset<int>::iterator it_green = green.begin();
            multiset<int>::iterator it_blue = blue.begin();

            list<int> wg;
            list<int> wb;

            for (int i = 0; i < min(m, b); i++) {
                it_green = green.end();
                it_green--;
                it_blue = blue.end();
                it_blue--;

                int p_green = *it_green;
                int p_blue = *it_blue;

                if (p_green > p_blue) {
                    wg.push_back(p_green - p_blue);
                } else if (p_blue > p_green) {
                    wb.push_back(p_blue - p_green);
                }

                green.erase(it_green);
                blue.erase(it_blue);
            }

            for (list<int>::iterator i = wg.begin(); i != wg.end(); i++) {
                green.insert(*i);
            }

            for (list<int>::iterator i = wb.begin(); i != wb.end(); i++) {
                blue.insert(*i);
            }
        }

        if (green.size() == 0 && blue.size() == 0) {
            cout << "green and blue died\n";
        } else if (blue.size() == 0) {
            cout << "green wins\n";
            for (multiset<int>::reverse_iterator i = green.rbegin();
                 i != green.rend(); i++) {
                cout << *i << '\n';
            }
        } else {
            cout << "blue wins\n";
            for (multiset<int>::reverse_iterator i = blue.rbegin();
                 i != blue.rend(); i++) {
                cout << *i << '\n';
            }
        }

        if (n != 1) cout << '\n';

        n--;
    }

    return 0;
}
