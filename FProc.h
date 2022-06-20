//File processing base class

#ifndef FPROC_H
#define FPROC_H

#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
using namespace std;

class FProc
{
protected:
	ifstream in;
	ofstream out;
public:
	FProc(const string& inName,
		const string& outName);
	virtual ~FProc();
	virtual char transform(char ch) const = 0;
	void process();
};
#endif
