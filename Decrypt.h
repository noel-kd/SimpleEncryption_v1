//FProc subclass
//Reverses encryption algorithm on input file contents

#ifndef DECRYPT_H
#define DECRYPT_H

#include "FProc.h"

class Decrypt : public FProc
{
	int eKey;
public:
	Decrypt(const string& inName, const string& outName, int key)
		: FProc(inName, outName)
	{
		eKey = key;
		cout << "Encryption key successfully applied." << endl;
	}
	char transform(char ch) const override
	{
		/* If encryption algorithm has been altered
		this algorithm must be adapted to reverse it*/
		return ch - eKey;
	}
};
#endif