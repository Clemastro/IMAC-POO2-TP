//Action is a struct who contain the command associate and the function to lanch the game or another function
#pragma once

#include <functional>
#include <string>

struct Action {
    std::string           name;
    char                  command;
    std::function<void()> function;

    Action(std::string _name, char _command, std::function<void()> _function)
        : name(_name), command(_command), function(_function) {}
};
