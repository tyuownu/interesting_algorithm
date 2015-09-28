/*************************************************************************
    > File Name: avltree.h
    > Author: 
    > Mail: 
    > Created Time: 2015年09月22日 星期二 20时37分11秒
 ************************************************************************/

#ifndef _AVLTREE_H
#define _AVLTREE_H

template<typename T>
class node
{
    public:
        /*
         *T data;
         *node<T>* parent;
         *node<T>* left;
         *node<T>* right;
         */
        node(T d = T(), 
                node<T> *parent = NULL,
                node<T> *left = NULL,
                node<T> *right = NULL): data(d), parent(parent),left(left),right(right){}

    private:
        T data;
    public:
        node<T>* parent;
        node<T>* left;
        node<T>* right;

    public:
        T&         getData();
        void       setData(const T& data);
        /*
         *node<T>*   getParent();
         *bool       setParent(node<T>* p);
         *node<T>*   getLeft();
         *bool       setLeft(node<T>* p);
         *node<T>*   getRight();
         *bool       setRight(node<T>* p);
         */
};

template<typename T>
inline T& node<T>::getData()
{
    return data;
}

template<typename T>
inline void node<T>::setData(const T& tmp)
{
    data = tmp;
}

template<typename T>
class avltree 
{
    public:
        node<T> *m_pRootNode;

    public:
        avltree(node<T> *initroot = NULL);
//        ~avltree();

    public:
        node<T>* LeftLeft  (node<T>* p);
        node<T>* RightRight(node<T>* p);
        node<T>* LeftRight (node<T>* p);
        node<T>* RightLeft (node<T>* p);

        node<T>* Insert(node<T> *p, T data);
        node<T>* Insert(T data);
        int Delete(node<T>* p, T data);
        node<T>* Find(node<T>* p, T data);
        node<T>* FindMax(node<T>* t);
        node<T>* FindMin(node<T>* t);

        int Height(node<T>* p);

    public:
        void PreOrder  (node<T>* p, void (*Visit)(const T &data));
        void InOrder   (node<T>* p, void (*Visit)(const T &data));
        void PostOrder (node<T>* p, void (*Visit)(const T &data));

    public:
        void PreOrder(void (*Visit)(const T &data));
        void InOrder (void (*Visit)(const T &data));
        void PostOrder(void (*Visit)(const T &data));

};

template<typename T>
inline avltree<T>::avltree(node<T>* initroot)
{
    m_pRootNode = initroot;
}

template<typename T>
inline node<T>* avltree<T>::RightRight(node<T>* p)
{
    node<T>* pRight = p->right;

    if(p == m_pRootNode)
        m_pRootNode = pRight;
    /*
     *else if(p->parent->left == p)
     *    p->parent->left = pLeft;
     *else
     *    p->parent->right = pLeft;
     */
    pRight->parent = p->parent;
    p->parent = pRight;

    p->right = pRight->left;
    pRight->left = p;

    if(p->right)
        p->right->parent = p;



    return pRight;
}

template<typename T>
inline node<T>* avltree<T>::LeftLeft(node<T>* p)
{
    node<T>* pLeft = p->left;

    if(p == m_pRootNode)
        m_pRootNode = pLeft;
    /*
     *else if(p->parent->left == p)
     *    p->parent->left = pRight;
     *else
     *    p->parent->right = pRight;
     */
    // change three node information
    // for example:
    //        6
    //       / \
    //      3  7
    //     / \
    //    1  4
    //     \
    //     2
    //     change:
    //     3: parent    6->NULL
    //        right     4->6
    //     6: parent    NULL->3
    //        left      3->4
    //     4: parent    3->6

    pLeft->parent = p->parent;
    p->parent = pLeft;

    p->left = pLeft->right;
    pLeft->right = p;

    if(p->left)
        p->left->parent = p;



    return pLeft;
}

template<typename T>
inline node<T>* avltree<T>::LeftRight(node<T>* p)
{
    //        6                6                  4
    //       / \              / \                / \
    //      2  7   rr        4  7    ll         2  6
    //     / \     --->     /        --->      / \  \
    //    1  4             2                  1  3  7
    //      /             / \
    //     3             1  3
    p->left = RightRight(p->left);
    return LeftLeft(p);
}

template<typename T>
inline node<T>* avltree<T>::RightLeft(node<T>* p)
{
    p->right = LeftLeft(p->right);
    return RightRight(p);
}

template<typename T>
inline int avltree<T>::Height(node<T>* p)
{
    int pHeight;
    if(p == NULL)
        return 0;
    else
    {
        int pleft, pright;
        pleft = Height(p->left);
        pright = Height(p->right);
        pHeight = (pleft>pright?pleft:pright)+1;
    }
    return pHeight;
}

template<typename T>
inline node<T>* avltree<T>::Insert(T data)
{
    return Insert(this->m_pRootNode, data);
}

template<typename T>
inline node<T>* avltree<T>::Insert(node<T> *p, T data)
{
    if(p == NULL)
    {
        p = new node<T>;
        p->setData(data);
//        p->data   = data;
        p->parent = NULL;
        p->left   = NULL;
        p->right  = NULL;
        if(m_pRootNode == NULL)
            m_pRootNode = p;
    }
//    else if(p->data > data)
    else if(p->getData() > data)
    {
//        Insert(p->left, data);
        p->left = Insert(p->left, data);

        if(p->left)
            p->left->parent = p;
        if(Height(p->left) - Height(p->right) == 2)
        {
//            if(p->left->data > data)
            if(p->left->getData() > data)
                p = LeftLeft(p);
            else
                p = LeftRight(p);
        }
    }
    else
    {
//        Insert(p->right, data);
        p->right = Insert(p->right, data);
        if(p->right)
            p->right->parent = p;
        if(Height(p->left) - Height(p->right) == -2)
        {
//            if(p->right->data > data)
            if(p->right->getData() > data)
                p = RightLeft(p);
            else
                p = RightRight(p);
        }
    }
    return p;
}

template<typename T>
inline node<T>* avltree<T>::FindMax(node<T>* p)
{
    node<T>* max;
    if(p == NULL)
        return p;

    while(p->right)
    {
        max = p->right;
    }
    return max;
}

template<typename T>
inline node<T>* avltree<T>::FindMin(node<T>* p)
{
    node<T>* min;
    if(p == NULL)
        return p;
    while(p->left)
    {
        min = p->left;
    }

    return min;
}

template<typename T>
inline int avltree<T>::Delete(node<T>* p, T data)
{
    if(p == NULL)
        return -1;
//    else if(p->data > data)
    else if(p->getData() > data)
    {
        Delete(p->left);
    }
//    else if(p->data < data)
    else if(p->getData < data)
    {
        Delete(p->right);
    }
    else 
    {
        if(p->left && p->right)
        {
            if(Height(p->left) > Height(p->right))
            {
                node<T>* pMax = FindMax(p->left);
//                p->data = pMax->data;
                p->setData(pMax->getData());
                Delete(p->left, data);
            }
            else
            {
                node<T>* pMin = FindMin(p->right);
//                p->data = pMin->data;
                p->setData(pMin->getData());
                Delete(p->right, data);
            }
        }
        else
        {
            node<T>* pTmp;
            if(p->left)
            {
                p->left->parent = p->parent;
                if(p->parent->left = p)
                    p->parent->left = p->left;
                else
                    p->parent->right = p->left;
                delete p;
            }
            else
            {
                p->right->parent = p->parent;
                if(p->parent->left = p)
                    p->parent->left = p->right;
                else
                    p->parent->right = p->right;
                delete p;
            }
        }
    }
    return 1;
}

template<typename T>
inline void avltree<T>::PreOrder(void (*Visit)(const T &data))
{
    PreOrder(this->m_pRootNode, Visit);
}
template<typename T>
inline void avltree<T>::PreOrder(node<T> *p, void (*Visit)(const T &data))
{
    if(p)
    {
//        Visit(p->data);
        Visit(p->getData());
        PreOrder(p->left, Visit);
        PreOrder(p->right, Visit);
    }
}


template<typename T>
inline void avltree<T>::InOrder(void (*Visit)(const T &data))
{
    InOrder(this->m_pRootNode, Visit);
}
template<typename T>
inline void avltree<T>::InOrder(node<T> *p, void (*Visit)(const T &data))
{
    if(p)
    {
        InOrder(p->left, Visit);
//        Visit(p->data);
        Visit(p->getData());
        InOrder(p->right, Visit);
    }
}


template<typename T>
inline void avltree<T>::PostOrder(void (*Visit)(const T &data))
{
    PostOrder(this->m_pRootNode, Visit);
}
template<typename T>
inline void avltree<T>::PostOrder(node<T> *p, void (*Visit)(const T &data))
{
    if(p)
    {
        PostOrder(p->left, Visit);
        PostOrder(p->right, Visit);
//        Visit(p->data);
        Visit(p->getData());
    }
}
#endif

