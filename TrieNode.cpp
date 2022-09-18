/*
Created by BOXXHE on 2022/9/18.
*/
#include <assert.h>
#include "TrieNode.h"

TrieNode::TrieNode() {
    this->passCnt = 0;
}

std::ostream &operator<<(std::ostream &os, const TrieNode &node) {
    for (const auto &iter : node.childNodes) {
        os << iter.first << " " << *iter.second;
    }
    os << "\n";
    return os;
}

TrieNode* TrieNode::addChild(const char &ch) {
    TrieNode *node = getChild(ch);
    if (node == nullptr) {
        TrieNode *newChildNode = new TrieNode;
        assert(newChildNode != nullptr);
        auto ret = this->childNodes.emplace(std::make_pair(ch, newChildNode));
        assert(ret.second == true);
    }
    return getChild(ch);
}

TrieNode *TrieNode::getChild(const char &ch) {
    auto iter = this->childNodes.find(ch);
    return (iter == this->childNodes.end()) ? nullptr : iter->second;
}

int TrieNode::getPassCnt() const {
    return passCnt;
}

void TrieNode::addPassCnt() {
    this->passCnt++;
}

