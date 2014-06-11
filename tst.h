//
//  tst.h
//  ternary search trie
//

#ifndef __ternary_search_trie__tst__
#define __ternary_search_trie__tst__

#include "tstnode.h"
#include <string>
#include <vector>

template <class T>
class cTST {
public:
    typedef cTSTNode<T>*                nodePtr;
    typedef std::vector<std::string>    iterable;
    
    cTST(T nullValue): mNullValue { nullValue } { };
    ~cTST();
    
    void            put(const std::string& key, T value);
    T               get(const std::string& key) const;
    iterable        keys();
    iterable        wildcardSearch(const std::string& format);
    
private:
    nodePtr         put(nodePtr, const std::string&, T, size_t d);
    T               get(nodePtr, const std::string&, size_t) const;
    void            deleteNode(nodePtr);        // recursive node deletion
    void            collect(nodePtr, const std::string& prefix = "",
                            const std::string& format = "", size_t d = 0);
    inline bool     equals(char a, char format) const;
    
private:
    nodePtr         pRoot { nullptr };
    T               mNullValue;
    iterable        mKeys;
};

#include "tst.inl"

#endif /* defined(__ternary_search_trie__tst__) */
