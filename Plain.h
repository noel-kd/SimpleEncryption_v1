//FProc subclass
//Outputs input file as is

#ifndef PLAIN_H
#define PLAIN_H

#include "FProc.h"

class Plain : public FProc
{
public:
	Plain(const string& inName, const string& outName)
		: FProc(inName, outName) {}

	char transform(char ch) const override
	{
		return ch;
	}
};
#endif