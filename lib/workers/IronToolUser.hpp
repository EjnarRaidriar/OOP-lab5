#ifndef IRON_TOOL_USER_HPP
#define IRON_TOOL_USER_HPP

#include"../resources/iron/Iron.hpp"
#include"../resources/wood/Wood.hpp"
#include"Worker.hpp"

class IronToolUser
{
public:
    virtual ~IronToolUser() = default;
    virtual void Sharpen(Tool* tool) = 0;
};

#endif