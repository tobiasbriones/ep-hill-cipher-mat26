// Copyright (c) 2021 Tobias Briones. All rights reserved.

#pragma once

#include<string>

using std::string;

class HillCipher
{

private:
	int n;

public:
	HillCipher(int);

	string encrypt(string);
	string decrypt(string);

};
