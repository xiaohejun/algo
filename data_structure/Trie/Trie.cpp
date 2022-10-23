/*
Created by BOXXHE on 2022/9/18.
*/

#include "Trie.h"

void Trie::dfsOutput(std::ostream &os, int level) const {
    // add ' '
    for (int i = 0; i < level - 1; ++i) {
        os << ' ';
    }
    // add '----'
    os << '----';
}

std::ostream &operator<<(std::ostream &os, const Trie &trie) {
    trie.dfsOutput(os, 1);
    return os;
}

void Trie::addString(const std::string &s) {
    TrieNode *curNode = &this->root;
    for (char c : s) {
        assert(curNode != nullptr);
        TrieNode *chNode = curNode->getChild(c);
        if (chNode == nullptr) {
            chNode = curNode->addChild(c);
        }
        chNode->addPassCnt();
        curNode = chNode;
    }
}

void Trie::addStringVector(const std::vector<std::string> &vec) {
    for (const auto &str : vec) {
        this->addString(str);
    }
}

Trie::Trie(const std::vector<std::string> &vec) {
    this->addStringVector(vec);
}

/*
 * 参数：str
 * trie是由 {s1, s2, s3, ... sn}组成的
 * 计算str的所有前缀字符串在trie的si匹配上的次数
 */
int Trie::calcStrPrefixMatchNum(const std::string &str) {
    int ans = 0;
    TrieNode *curNode = &this->root;
    for (char c : str) {
        TrieNode *chNode = curNode->getChild(c);
        if (chNode == nullptr) {
            break;
        }
        ans += chNode->getPassCnt();
        curNode = chNode;
    }
    return ans;
}


