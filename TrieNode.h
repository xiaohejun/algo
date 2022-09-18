/*
Created by BOXXHE on 2022/9/18.
*/

#ifndef ALGO_TRIENODE_H
#define ALGO_TRIENODE_H

#include <unordered_map>
#include <ostream>

class TrieNode {
private:
    int passCnt; // 该节点加入trie树时次数
    std::unordered_map<char, TrieNode *> childNodes;
public:
    TrieNode();
    TrieNode *addChild(const char &ch);
    TrieNode *getChild(const char &ch);
    friend std::ostream &operator<<(std::ostream &os, const TrieNode &node);
    int getPassCnt() const;
    void addPassCnt();
};

#endif //ALGO_TRIENODE_H
