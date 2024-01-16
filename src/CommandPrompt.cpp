#include "include/CommandPrompt.h"
#include "include/Global.h"

#include <fstream>

#include <iostream>

CommandPrompt::CommandPrompt(std::string commandsymb)
{
    if (commandsymb == "NONE")
        m_commandsymb = CommandSYMB;
    else
        m_commandsymb = commandsymb;
}

CommandPrompt::~CommandPrompt()
{
    SaveToFile();
    m_commands.clear();
}

void CommandPrompt::Start()
{
    while (1)
    {
        std::string input;
        std::cout << m_commandsymb;
        std::getline(std::cin, input);

        m_command.SetData(input);

        cmdexe.Execute(m_command);

        if (m_command.items.base == Commandbase::Clear)
            system("cls");
        if (m_command.items.base == Commandbase::Exit)
            return;

        m_commands.push_back(m_command);
    }
}

void CommandPrompt::SaveToFile()
{
    std::string commandfilename = AppDataFolderName;
    commandfilename += "/Commands.txt";
    std::fstream file(commandfilename, std::ios::out);

    if (file.is_open())
    {
        for (auto command : m_commands)
        {
            if (command.raw_data == "")
                continue;

            file << command.raw_data << "\n";
        }
    }

    file.close();
}
