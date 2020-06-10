#include "variableDefinition.hpp"


//Definition Int8
Int8::~Int8(){}
Int8::Int8(std::string value) : _value(value){}
Int8::Int8(Int8 const &src) { *this = src; }
class Int8  &Int8::operator=(Int8 const &rhs){
    (void)rhs;
    return *this;
}

//Definition Int16
Int16::~Int16(){}
Int16::Int16(std::string value) : _value(value){}
Int16::Int16(Int16 const &src) { *this = src; }
class Int16  &Int16::operator=(Int16 const &rhs){
    (void)rhs;
    return *this;
}

//Definition Int32
Int32::~Int32(){}
Int32::Int32(std::string value) : _value(value){}
Int32::Int32(Int32 const &src) { *this = src; }
class Int32  &Int32::operator=(Int32 const &rhs){
    (void)rhs;
    return *this;
}

//Definition Float
Float::~Float(){}
Float::Float(std::string value) : _value(value){}
Float::Float(Float const &src) { *this = src; }
class Float  &Float::operator=(Float const &rhs){
    (void)rhs;
    return *this;
}

//Definition Double
Double::~Double(){}
Double::Double(std::string value) : _value(value){}
Double::Double(Double const &src) { *this = src; }
class Double  &Double::operator=(Double const &rhs){
    (void)rhs;
    return *this;
}