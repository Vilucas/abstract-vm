#ifdef INT_8
#define INT_8

#include "Master.hpp"

class Int_8:  public IOperand
{
    private:
        Int_8();
        ~Int_8();
        Int_8(Int_8 const &e);
        Int_8 &operator=(Int_8 const &e);

    public:
        virtual e0perandType getType(void);
        virtual int getPrecision(void);

};

#endif