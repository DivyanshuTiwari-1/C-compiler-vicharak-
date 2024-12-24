#include <iostream>
#include <fstream>
#include <string>
#include "sourcecode/gen.cpp"

int main(int argc, char *argv[])
{
	if (argc < 2)
	{
		cout << "Please give me input file" << endl;
		return 1;
	}

	fstream in;
	in.open(argv[1], ios::in);

	string temp, src = "";
	if (in.good())
	{
		while (!in.eof())
		{
			getline(in, temp);
			src += temp;
		}
		in.close();
	}
	else
	{
		cout << "Error" << endl;
	}

	src += "\0";

	
plus_compile(src);

	return 0;
}