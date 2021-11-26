//
// Created by lossv on 2021/11/8.
//

#ifndef LEETCODEWITHCPP_MANAGEARRAY_H
#define LEETCODEWITHCPP_MANAGEARRAY_H

#include <functional>
#include <utility>
#include <cstdio>

#include <cstdint>
#include <cstdlib>
#include <cstring>

#define bzero(s, n) memset(s, 0, n)
#define BZERO(data) bzero(&data, sizeof(data));


struct S
{
    int key;
    int value;
};

template <class ArrayTypeT, class KeyT>
class ManageArray
{
private:
    ArrayTypeT* m_pArray;
    int& m_iCount;

    std::function<KeyT(ArrayTypeT)> GetKey;
public:
    ManageArray(int& iCount, ArrayTypeT *pTmpArray, std::function<KeyT(ArrayTypeT)> funGetKey): m_iCount(iCount), m_pArray(pTmpArray), GetKey(funGetKey){};

    int DeleteKey(KeyT tKey);

    int DeleteKey(KeyT tKey, std::function<KeyT(ArrayTypeT)> funGetKey);

    void DeleteAllKey(KeyT tKey);

    ArrayTypeT operator[](int iIndex);

    ArrayTypeT Find(KeyT tKey) const;

};

template<class ArrayType, class TKey>
int ManageArray<ArrayType, TKey>::DeleteKey(TKey tKey)
{
    for(int i = 0; i < m_iCount; ++i)
    {
        auto tmpKey = GetKey(m_pArray[i]);
        if(tKey == tmpKey)
        {
            m_pArray[i] = m_pArray[m_iCount - 1];
            BZERO(m_pArray[--m_iCount]);
            return i;
        }
    }
    return -1;
}

template<class ArrayTypeT, class KeyT>
int ManageArray<ArrayTypeT, KeyT>::DeleteKey(KeyT tKey, std::function<KeyT(ArrayTypeT)> funGetKey)
{
    for(int i = 0; i < m_iCount; ++i)
    {
        auto tmpKey = funGetKey(m_pArray[i]);
        if(tKey == tmpKey)
        {
            m_pArray[i] = m_pArray[m_iCount - 1];
            BZERO(m_pArray[--m_iCount]);
            return i;
        }
    }
    return -1;
}

template<class ArrayType, class TKey>
void ManageArray<ArrayType, TKey>::DeleteAllKey(TKey tKey)
{
    int iIndex = 0;
    while (iIndex < m_iCount)
    {
        auto key = GetKey(m_pArray[iIndex]);
        if(key == tKey)
        {
            m_pArray[iIndex] = m_pArray[m_iCount - 1];
            BZERO(m_pArray[--m_iCount]);
        }
        else
        {
            iIndex++;
        }
    }
}

template<class ArrayTypeT, class KeyT>
ArrayTypeT ManageArray<ArrayTypeT, KeyT>::operator[](int iIndex)
{
    if(iIndex < m_iCount)
    {
        return m_pArray[iIndex];
    }
    return NULL;
}

template<class ArrayTypeT, class KeyT>
ArrayTypeT ManageArray<ArrayTypeT, KeyT>::Find(KeyT tKey) const
{
    for(int i = 0; i < m_iCount; ++i)
    {
        if(tKey == GetKey(m_pArray[i]))
        {
            return i;
        }
    }
    return -1;
}




#endif //LEETCODEWITHCPP_MANAGEARRAY_H
