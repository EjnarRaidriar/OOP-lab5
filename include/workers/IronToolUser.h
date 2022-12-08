#ifndef IRON_TOOL_USER_H
#define IRON_TOOL_USER_H

#include"../resources/iron/Iron.h"
#include"../resources/wood/Wood.h"
#include"Worker.h"

class IronToolUser
{
public:
    virtual ~IronToolUser() = default;
    virtual void Sharpen(Tool* tool) = 0;
};

#endif