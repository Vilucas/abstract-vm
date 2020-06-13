#ifndef VARIABLEDEFINITION_HPP
#define VARIABLEDEFINITION_HPP

#include  "Master.hpp"
#include  "Operators.hpp"

class Int8 : public Operators
{
    public:
        Int8();
        ~Int8();
        Int8(std::string value);
        Int8(Int8 const &src);
        Int8 &operator=(Int8 const &e);
    
    private:
        int8_t _value;
        std::string _strValue;
        virtual std::string const & toString(void) const {return _strValue;}
        virtual eOperandType getType(void) const {return eOperandType::Int_8;}
        virtual int getPrecision(void) const {return (0);}
};

class Int16 : public Operators
{
    public:
        Int16();
        ~Int16();
        Int16(std::string value);
        Int16(Int16 const &src);
        Int16 &operator=(Int16 const &e);
    
    private:
        int16_t _value;
        std::string _strValue;
        virtual std::string const &toString(void) const {return _strValue;}
        virtual eOperandType getType(void) const {return eOperandType::Int_16;}
        virtual int getPrecision(void) const {return (0);}
};

class Int32 : public Operators
{
    public:
        Int32();
        ~Int32();
        Int32(std::string value);
        Int32(Int32 const &src);
        Int32 &operator=(Int32 const &e);
    
    private:
        int32_t _value;
        std::string _strValue;
        virtual std::string const & toString(void) const {return _strValue;}
        virtual eOperandType getType(void) const {return eOperandType::Int_32;}
        virtual int getPrecision(void) const {return (0);}
};

class Float : public Operators
{
    public:
        Float();
        ~Float();
        Float(std::string value);
        Float(Float const &src);
        Float &operator=(Float const &e);
    
    private:
        float _value;
        std::string _strValue;
        virtual std::string const & toString(void) const {return _strValue;}
        virtual eOperandType getType(void) const {return eOperandType::Float_;}
        virtual int getPrecision(void) const {return (7);}
};

class Double : public Operators
{
    public:
        Double();
        ~Double();
        Double(std::string value);
        Double(Double const &src);
        Double &operator=(Double const &e);
    
    private:
        double _value;
        std::string _strValue;
        virtual std::string const & toString(void) const {return _strValue;}
        virtual eOperandType getType(void) const {return eOperandType::Double_;}
        virtual int getPrecision(void) const {return (15);}
};


#endif