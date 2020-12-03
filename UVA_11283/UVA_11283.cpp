/**
 * [UVA 11283] - Playing Boggle
 * https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=2258
 *
 * Trie implementation with simple DFS search
 *
 * https://www.geeksforgeeks.org/trie-insert-and-search/
 *
 * Time complexity is linear
 **/

#include <bits/stdc++.h>

using namespace std;

char grid[6][6];
bool visited[6][6];

typedef struct TrieNode {
    struct TrieNode *children[26];
    bool is_word;
} t_node;

t_node *create_node() {
    t_node *node = new TrieNode;
    node->is_word = false;

    for (int i = 0; i < 26; i++) {
        node->children[i] = NULL;
    }

    return node;
}

void insert(t_node *root, string word) {
    t_node *curr = root;
    for (int i = 0; i < word.length(); i++) {
        int index = word[i] - 'A';
        if (!curr->children[index]) curr->children[index] = create_node();

        curr = curr->children[index];
    }

    curr->is_word = true;
}

bool isEmpty(t_node *root) {
    for (int i = 0; i < 26; i++)
        if (root->children[i]) return false;
    return true;
}

t_node *remove(t_node *root, string word, int depth = 0) {
    if (!root) return NULL;

    if (depth == word.size()) {
        if (root->is_word) root->is_word = false;

        if (isEmpty(root)) {
            delete (root);
            root = NULL;
        }

        return root;
    }

    int index = word[depth] - 'A';
    root->children[index] = remove(root->children[index], word, depth + 1);

    if (isEmpty(root) && root->is_word == false) {
        delete (root);
        root = NULL;
    }

    return root;
}

enum SearchResult { NONE, PREFIX, WORD };

SearchResult search(t_node *root, string word) {
    t_node *curr = root;

    for (int i = 0; i < word.length(); i++) {
        int index = word[i] - 'A';
        if (!curr->children[index]) return NONE;

        curr = curr->children[index];
    }

    if (curr != NULL && curr->is_word)
        return WORD;
    else if (curr != NULL)
        return PREFIX;

    return NONE;
}

int get_score(int word_length) {
    // cout << "Getting score for word of size " << word_length << '\n';
    if (word_length < 5) return 1;
    if (word_length < 7) return word_length - 3;
    if (word_length == 7) return 5;
    return 11;
}

int dfs(int row, int col, string prev_word, t_node *root) {
    if (visited[row][col]) return 0;
    visited[row][col] = true;

    int score = 0;

    string cur_word = prev_word + grid[row][col];

    // cout << "Testing " << cur_word << " at " << row << ", " << col << '\n';

    SearchResult result = search(root, cur_word);

    // cout << "Result: " << result << '\n';

    switch (result) {
        case WORD:
            score += get_score(cur_word.length());
            remove(root, cur_word);
            break;
        case NONE:
            visited[row][col] = false;
            return 0;
    }

    score += dfs(row - 1, col - 1, cur_word, root);
    score += dfs(row - 1, col, cur_word, root);
    score += dfs(row - 1, col + 1, cur_word, root);
    score += dfs(row, col - 1, cur_word, root);
    score += dfs(row, col + 1, cur_word, root);
    score += dfs(row + 1, col - 1, cur_word, root);
    score += dfs(row + 1, col, cur_word, root);
    score += dfs(row + 1, col + 1, cur_word, root);

    visited[row][col] = false;

    return score;
}

int main(int argc, char const *argv[]) {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    for (int i = 0; i < 6; i++) {
        grid[0][i] = '.';
        grid[i][0] = '.';
        grid[5][i] = '.';
        grid[i][5] = '.';
    }

    int t;
    cin >> t;

    for (int ct = 1; ct <= t; ct++) {
        for (int i = 1; i <= 4; i++) {
            string s;
            cin >> s;

            for (int j = 1; j <= 4; j++) {
                grid[i][j] = s[j - 1];
            }
        }

        int m;
        cin >> m;

        t_node *root = create_node();

        for (int i = 0; i < m; i++) {
            string w;
            cin >> w;
            insert(root, w);
        }

        int score = 0;

        for (int i = 1; i <= 4; i++) {
            for (int j = 1; j <= 4; j++) {
                memset(visited, false, sizeof(visited));
                score += dfs(i, j, "", root);
            }
        }

        cout << "Score for Boogle game #" << ct << ": " << score << '\n';
    }

    return 0;
}