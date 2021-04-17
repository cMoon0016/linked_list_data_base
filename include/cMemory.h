#ifndef CMEMORY_H
#define CMEMORY_H

#include <../cProduct.h>

class cMemory : public cProduct
{
    private:
        double mCapacity;
        std::string mMaker;

    public:
        cMemory* mType;
        cMemory(int = 0, std::string = "Not defined", int = 0, std::string = "Not defined", double = 0, double = 0, double = 0, std::string = "Not defined");
        cMemory(cMemory*);
        virtual ~cMemory();
        void fill(void);
        void show(void);
        cProduct* clone();
        virtual void import_to_txt(std::ofstream &);
};

#endif // CMEMORY_H
