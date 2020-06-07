#ifndef MASTER_HPP
#define MASTER_HPP

//#include <eOperandType.hpp>
#include <iostream>


enum eOperandType {
    Int8 , 
    Int16,
    Int32,
    Float = 7,
    Double = 15

};

class IOperand {
    public:
        virtual int getPrecision( void ) const = 0; // Precision of the type of the instance
        virtual eOperandType getType( void ) const = 0; // Type of the instance
      
        virtual IOperand const * operator+( IOperand const & rhs ) const = 0; // Sum
        /*
        virtual IOperand const * operator-( IOperand const & rhs ) const = 0; // Difference
        virtual IOperand const * operator*( IOperand const & rhs ) const = 0; // Product
        virtual IOperand const * operator/( IOperand const & rhs ) const = 0; // Quotient
        virtual IOperand const * operator%( IOperand const & rhs ) const = 0; // Modulo
        virtual std::string const & toString( void ) const = 0; // String representation of the instance
        */
        virtual ~IOperand( void );
        IOperand const * createOperand( eOperandType type, std::string const & value ) const;
    
    private:
        IOperand const * createInt8( std::string const & value ) const;
        IOperand( void );
        IOperand(IOperand const &src);
        IOperand &operator=(IOperand const &e);
};

class Operators : public IOperand {
    public:
        
        virtual IOperand const * operator+( IOperand const & rhs ) const = 0; // Sum
        /*
        virtual IOperand const * operator-( IOperand const & rhs ) const = 0; // Difference
        virtual IOperand const * operator*( IOperand const & rhs ) const = 0; // Product
        virtual IOperand const * operator/( IOperand const & rhs ) const = 0; // Quotient
        virtual IOperand const * operator%( IOperand const & rhs ) const = 0; // Modulo
        virtual std::string const & toString( void ) const = 0; // String representation of the instance
        */
};


#endif