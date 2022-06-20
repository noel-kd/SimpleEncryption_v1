#include "FProc.h"

FProc::FProc(const string& inName,
	const string& outName)
{
	in.open(inName);
	out.open(outName);
	if (!in)
	{
		cout << "--TERMINAL ERROR: " << inName << " could not be opened." << endl;
		exit(1);
	}
	if (!out)
	{
		cout << "--TERMINAL ERROR: " << outName << " could not be opened." << endl;
		exit(1);
	}
}

FProc::~FProc()
{
	in.close();
	out.close();
}

//Cycles through chars to change them as needed
void FProc::process()
{
	char ch;
	char transCh;
	in.get(ch);
	while (!in.fail())
	{
		transCh = transform(ch);
		out.put(transCh);
		in.get(ch);
	}
}