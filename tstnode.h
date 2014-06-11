#ifndef __ternary_search_trie__tstnode__
#define __ternary_search_trie__tstnode__

template <class T>
class cTSTNode {
public:
    typedef cTSTNode* nodePtr;
    
    cTSTNode(char, T);
    bool        hasKids() const;
    
    nodePtr     pLeft { nullptr }, pMid { nullptr }, pRight { nullptr };
    T           mValue;
    char        mChar;
};

#include "tstnode.inl"

#endif /* defined(__ternary_search_trie__tstnode__) */
