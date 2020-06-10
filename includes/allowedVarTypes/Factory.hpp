#ifndef FACTORY_HPP
#define FACTORY_HPP

#include "Master.hpp"
#include "variableDefinition.hpp"
#include  <map>

class Factory 
{

    public:
        Factory(void);
        Factory(Factory const &src);
        Factory const &operator=(Factory const &rhs);
        ~Factory();
        IOperand const * createOperand( eOperandType type, std::string const & value ) const;
        IOperand const * createInt8( std::string const & value ) const;

    private:
       
        IOperand const * createInt16( std::string const & value ) const;
        IOperand const * createInt32( std::string const & value ) const;
        IOperand const * createFloat( std::string const & value ) const;
        IOperand const * createDouble( std::string const & value ) const;
};

Factory *PtrToFactoryMember;
        
#endif