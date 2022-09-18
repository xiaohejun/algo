#include <iostream>
#include <vector>
#include "Trie.h"

int main() {
    std::vector<std::string> vec = {"abcd"};
    Trie trie(vec);
    std::vector<int> ans;
    for (const std::string &str : vec) {
        ans.push_back(trie.calcStrPrefixMatchNum(str));
    }
    for (int x : ans) {
        std::cout << x << " ";
    }
    return 0;
}
