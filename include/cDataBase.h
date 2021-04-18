#ifndef CDATABASE_H
#define CDATABASE_H

#include "cNode.h"
#include <../cProduct.h>

class cDataBase
{
    private:
        cNode* mFirst;

    public:
        cDataBase();
        virtual ~cDataBase();
        void add(cProduct*);
        void show(void);
        void import_to_txt(void);
        void export_from_txt(void);
};

#endif // CDATABASE_H
