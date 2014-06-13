template <class T>
cTST<T>::~cTST()
{
    deleteNode(pRoot);
}

template <class T>
std::vector<std::string> cTST<T>::keys() 
{
    mKeys = std::vector<std::string> { 0 };
    collect(pRoot);
    return mKeys;
}

template <class T>
std::vector<std::string> cTST<T>::wildcardSearch(const std::string& format)
{
    mKeys = std::vector<std::string> { 0 };
    collect(pRoot, "", format, 0);
    return mKeys;
}

template <class T>
inline bool cTST<T>::equals(char a, char format) const
{
    return format == '*' ? true : format == a;
}

template <class T>
void cTST<T>::collect(nodePtr p, const std::string& prefix,
                      const std::string& format, size_t d)
{
    if ( p == nullptr ) return;
    
    if ( format != "" && d >= format.size() )
    {
        return;
    }
    
    if ( p->mValue != mNullValue )
    {
        if ( format == "" || ( d == format.size()-1 && equals(p->mChar, format[d])) )
            mKeys.push_back(prefix + p->mChar);
    }
    
    if ( p->pLeft != nullptr ) collect(p->pLeft, prefix, format, d);
    if ( p->pMid != nullptr )
    {
        if ( format == "" || equals(p->mChar, format[d]) )
        {
            collect(p->pMid, prefix + p->mChar, format, d+1);
        }
    }
    if ( p->pRight != nullptr ) collect(p->pRight, prefix, format, d);
}

template <class T>
void cTST<T>::deleteNode(nodePtr p)
{
    if ( p == nullptr ) return;
    deleteNode(p->pLeft);
    deleteNode(p->pMid);
    deleteNode(p->pRight);
    
    delete p;
}

template <class T>
T cTST<T>::get(const std::string& key) const
{
    return get(pRoot, key, 0);
}

template <class T>
T cTST<T>::get(nodePtr p, const std::string& key, size_t d) const
{
    if ( p == nullptr ) return mNullValue;
    if ( p->mChar > key[d] ) return get(p->pLeft, key, d);
    else if (p->mChar < key[d] ) return get(p->pRight, key, d);
    else
    {
        if ( d == key.size()-1 ) return p->mValue;
        else return get(p->pMid, key, d+1);
    }
}

template <class T>
void cTST<T>::put(const std::string& key, T value)
{
    pRoot = put(pRoot, key, value, 0);
}

template <class T>
cTSTNode<T>*    cTST<T>::put(nodePtr p, const std::string& key, T value, size_t d)
{
    if ( p == nullptr )
    {
        p = new cTSTNode<T> { key[d], mNullValue };
    }
    
    if ( p->mChar == key[d] )
    {
        if ( d != key.size()-1 )
        {
            p->pMid = put(p->pMid, key, value, d+1);
        }
        else
        {
            p->mValue = value;
        }
    } else
        if ( p->mChar > key[d] )
        {
            p->pLeft = put(p->pLeft, key, value, d);
        }
        else
        {
            p->pRight = put(p->pRight, key, value, d);
        }
    
    return p;
}
