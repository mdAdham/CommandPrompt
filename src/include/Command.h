#ifndef COMMAND_H
#define COMMAND_H

#include <string>
#include <map>

enum Commandbase
{
    Clear,
    Message,
    Exit,
    Enter,
    Init,
    Other
};

struct __Command_Items
{
    Commandbase base;
    std::map<unsigned int, std::string> args;
};

struct Command
{
public:
    Command() = default;
    Command(std::string raw_command);

    void SetData(std::string raw_command);

    __Command_Items items;

    std::string raw_data{};

private:
    __Command_Items SpliteTheCommand(std::string raw_command);
};

#endif