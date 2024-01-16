#define Debug

#include "include/CommandPrompt.h"
#include <iostream>
int main()
{
    CommandPrompt prompt("<root@127.0.0.1>");
    prompt.Start();
    return 0;
}