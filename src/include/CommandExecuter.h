#ifndef COMMANDEXECUTER_H
#define COMMANDEXECUTER_H

#include "Command.h"

class CommandExecuter
{
public:
    CommandExecuter() = default;

    void Execute(Command command);
};

#endif