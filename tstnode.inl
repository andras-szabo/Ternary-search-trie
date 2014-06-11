template <class T>
cTSTNode<T>::cTSTNode(char c, T value):
mChar { c },
mValue { value }
{
    
}

template <class T>
bool cTSTNode<T>::hasKids() const
{
    return pLeft != nullptr || pMid != nullptr || pRight != nullptr;
}