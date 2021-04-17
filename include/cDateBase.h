#ifndef CDATEBASE_H
#define CDATEBASE_H

#include "cNode.h"
#include <../cProduct.h>

class cDateBase
{
    private:
        cNode* mFirst;

    public:
        cDateBase();
        virtual ~cDateBase();
        void add(cProduct*);
        void show(void);
        void import_to_txt(void);
        void export_from_txt(void);
};

#endif // CDATEBASE_H
