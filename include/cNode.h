#ifndef CNODE_H
#define CNODE_H

#include <../cProduct.h>

class cNode
{
    private:
        cNode* mNext;
        cProduct* mProduct;

    public:
        cNode(cProduct*);
        virtual ~cNode();
        void setNext(cNode*);
        cNode* getNext();
        cProduct* getProduct();
};

#endif // CNODE_H
