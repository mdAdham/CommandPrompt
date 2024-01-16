#include "include/CommandExecuter.h"
#include <iostream>
#include <dirent.h>
#include "include/Global.h"

void CommandExecuter::Execute(Command command)
{
    if (command.items.base == Commandbase::Init)
    {
        mkdir(AppDataFolderName);
    }

    if (command.items.base == Commandbase::Message)
    {
        Log(command.items.args.at(1));
    }
}