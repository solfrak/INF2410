#ifndef COMMAND
#define COMMAND

class Command
{
private:
    /* data */
public:
    virtual void execute() const = 0;
};

#endif