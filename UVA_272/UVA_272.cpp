/**
 * [UVA 272] TEX Quotes
 * https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=208
 *
 * To solve this, we scan the input char by char and print them out until we
 * find '"'. Then, we put the value of 'flag' to true, so that we know we're
 * inside a quote, and output '``'. The next time we find '"', flag will be true
 * and we can output ''.
 *
 * The time complexity is O(n) where n is the number of characters on the input.
 **/

#include <string>
using namespace std;

int main(int argc, char const *argv[]) {
    bool flag = false;

    char c;
    while ((c = getchar()) != EOF) {
        if (c != '"') {
            putchar(c);
        } else if (flag) {
            fputs("''", stdout);
            flag = false;
        } else {
            fputs("``", stdout);
            flag = true;
        }
    }

    return 0;
}
