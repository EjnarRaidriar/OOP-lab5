#ifndef IRON_TOOL_USER_HPP
#define IRON_TOOL_USER_HPP

#include"../resources/iron/Iron.hpp"
#include"../resources/wood/Wood.hpp"

class IronToolUser
{
public:
    virtual ~IronToolUser() = default;
    virtual void createTool(Iron &iron, Wood &wood) = 0;
    virtual void Sharpen(Iron &iron) = 0;
};

#endif