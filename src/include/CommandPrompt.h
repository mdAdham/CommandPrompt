#ifndef COMMANDPROMPT_H
#define COMMANDPROMPT_H

#include <vector>
#include <string>
#include "Command.h"
#include "CommandExecuter.h"

class CommandPrompt
{
public:
    CommandPrompt(std::string commandsymb = "NONE");
    ~CommandPrompt();

    void Start();

private:
    void SaveToFile();

private:
    std::vector<Command> m_commands;
    Command m_command;
    CommandExecuter cmdexe;

    std::string m_commandsymb;
};

#endif