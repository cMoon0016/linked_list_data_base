#include "cNode.h"

using namespace std;

cNode::cNode(cProduct* aProduct)
{
    cout<<"I am cNode constructor"<<endl;
    mNext = nullptr;
    mProduct = aProduct;
}

cNode::~cNode()
{
    cout<<"I am cNode destructor"<<endl;
    delete mProduct;
}

void cNode::setNext(cNode* aNext)
{
    mNext = aNext;
}

cNode* cNode::getNext()
{
    return mNext;
}

cProduct* cNode::getProduct()
{
    return mProduct;
}
