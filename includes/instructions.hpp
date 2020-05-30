#ifndef INSTRUCTIONS_H
#define INSTRUCTIONS_H

class instructions
{
    public:
        instructions(void);
        virtual ~instructions(void);
        instructions(instructions const &name);
        instructions &operator=(instructions const &name);

};
#endif