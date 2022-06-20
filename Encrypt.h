//FProc subclass
//Encrypts contents of input file

#ifndef ENCRYPT_H
#define ENCRYPT_H

#include "FProc.h"

class Encrypt : public FProc
{
	int eKey;
public:
	Encrypt(const string& inName, const string& outName, int key)
		: FProc(inName, outName)
	{
		eKey = key;
		cout << "Encryption key successfully applied." << endl;
	}
	char transform(char ch) const override
	{
		/* Replace this algorthim to alter
		the complexity of the encryption */
		return ch + eKey;
	}
};
#endif