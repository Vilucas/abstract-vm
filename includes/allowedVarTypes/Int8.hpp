#ifndef INT8_HPP
#define INT8_HPP

#include "Master.hpp"

class Int8:  public Operators
{
    public:
        Int8() {}
        ~Int8() {}
        
        Int8(Int8 const &e);
        Int8 &operator=(Int8 const &e);
    
    private:
        virtual eOperandType getType(void) const {return eOperandType::Int8;}
        virtual int getPrecision(void) const {return (0);}
};

#endif