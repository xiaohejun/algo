/*
Created by BOXXHE on 2022/9/18.
*/

#ifndef ALGO_TRIE_H
#define ALGO_TRIE_H

#include <ostream>
#include <vector>
#include "TrieNode.h"

class Trie {
private:
    TrieNode root;
public:
    explicit Trie(const std::vector<std::string> &vec);

    void addString(const std::string &s);
    void addStringVector(const std::vector<std::string> &vec);
    friend std::ostream &operator<<(std::ostream &os, const Trie &trie);
    void dfsOutput(std::ostream &os, int level) const;

    int calcStrPrefixMatchNum(const std::string &str);
};

#endif //ALGO_TRIE_H
