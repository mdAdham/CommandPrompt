#ifndef GLOBAL_H
#define GLOBAL_H

#define AppDataFolderName "CommandPrompt_Data"

#define Log(x) std::cout << x << "\n"

#define Debug
#undef Debug

#ifdef Debug
#define DebugLog(x) std::cout << x << "\n"
#else
#define DebugLog(x)
#endif

#define CommandSYMB "</>"
#define MaxCmdArg 6

#endif