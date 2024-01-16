#include "include/Command.h"

#include <iostream>
#include <string.h>
#include <vector>

#include "include/Global.h"
#include <sstream>

static bool CheckError(std::string raw_command);

Command::Command(std::string raw_command)
    : raw_data(raw_command)
{
    items = SpliteTheCommand(raw_command);
}

void Command::SetData(std::string raw_command)
{
    raw_data = raw_command;
    items = SpliteTheCommand(raw_command);
}

__Command_Items Command::SpliteTheCommand(std::string raw_command)
{
    __Command_Items item;

    if (raw_command == "")
        return {Commandbase::Enter};

    if (CheckError(raw_command) == true)
        return {Commandbase::Enter};

    std::istringstream stream(raw_command);
    std::vector<std::string> words;
    std::string temp{""};
    std::string qoutsWord{""};
    bool inQouts = false;

    while (stream >> temp)
    {
        if (CheckError(temp) == true)
        {
            break;
        }
        if (inQouts == true)
        {
            if (temp[temp.size() - 1] == '\"')
            {
                inQouts = false;
                temp.pop_back();

                qoutsWord += " ";
                qoutsWord += temp;

                words.push_back(qoutsWord);
                qoutsWord.clear();
            }

            qoutsWord += " ";
            qoutsWord += temp;
            continue;
        }

        if (temp[0] == '\"')
        {
            inQouts = true;
            temp = temp.substr(1, temp.size() - 1);
            if (temp[temp.size() - 1] == '\"')
            {
                temp.pop_back();
                temp = temp.substr(1, temp.size() - 1);

                words.push_back(temp);
                continue;
            }

            qoutsWord += temp;
            continue;
        }

        words.push_back(temp);
        DebugLog(temp);
    }

    if (words.size() > 1)
    {
        if (words[0] == "msg")
            item.base = Commandbase::Message;

        for (size_t i = 0; i < words.size(); i++)
        {
            item.args[i] = words.at(i);
            DebugLog(i);
        }
    }

    if (words.size() == 1)
    {
        std::string word = words.at(0);
        if (word == "CLEAR")
            item.base = Commandbase::Clear;

        if (raw_command == "clear" || raw_command == "cls")
            item.base = Commandbase::Clear;

        if (raw_command == "exit")
            item.base = Commandbase::Exit;

        if (raw_command == "msg")
            item.base = Commandbase::Message;

        if (raw_command == "init")
            item.base = Commandbase::Init;

        return item;
    }

    return item;
}

static bool CheckError(std::string raw_command)
{
    if (raw_command == "")

        return true;
    if (raw_command == "\"")
        return true;
    if (raw_command == "\"\"")
        return true;
    return false;
}