#pragma once

#include <iostream>
#include <string>

using namespace std;

class Command
{
public:
	virtual void execute() = 0;
};

