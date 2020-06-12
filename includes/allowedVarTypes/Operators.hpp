#ifndef OPERATORS_HPP
#define OPERATORS_HPP

#include <algorithm>
#include "Master.hpp"

class Operators : public IOperand {
    
    public:
        Operators();
        ~Operators();
        Operators(Operators const &src);
        Operators const & operator=(Operators const &rhs);
    
    protected:
        
        virtual IOperand const * operator+( IOperand const & rhs ) const; // Sum

        /*
        virtual IOperand const * operator-( IOperand const & rhs ) const = 0; // Difference
        virtual IOperand const * operator*( IOperand const & rhs ) const = 0; // Product
        virtual IOperand const * operator/( IOperand const & rhs ) const = 0; // Quotient
        virtual IOperand const * operator%( IOperand const & rhs ) const = 0; // Modulo
         */
        virtual std::string const & toString( void ) const = 0; // String representation of the instance

        
};

#endif