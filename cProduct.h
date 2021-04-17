#ifndef CPRODUCT_H_INCLUDED
#define CPRODUCT_H_INCLUDED
#include <iostream>

class cProduct
{
    protected:
        int mLp;
        std::string mName;
        int mAmount;
        std::string mUnit;
        double mPrize;
        double mVat;

    public:
        cProduct(int = 0, std::string = "Not defined", int = 0, std::string = "Not defined", double = 0, double = 0);
        cProduct(cProduct*); //because cNode is creating clone of cProduct object
        virtual ~cProduct();
        virtual void fill(void);
        virtual void show(void);
        int getLp(void);
        void setLp(int);
        virtual cProduct* clone(void) = 0; //for cNode to create object copy which will be add to the one-way list
        virtual void import_to_txt(std::ofstream &);

};

#endif // CPRODUCT_H_INCLUDED
