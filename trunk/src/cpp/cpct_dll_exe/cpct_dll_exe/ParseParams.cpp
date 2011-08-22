////////////////////////////////////////////////////////////////////////////////
///
/// A class for parsing the cpct application command line parameters
///
////////////////////////////////////////////////////////////////////////////////

#include <string>
#include <stdlib.h>
#include "ParseParams.h"

using namespace std;



ParseParams::ParseParams( int numparams, char* params[] )
{
	if (numparams < 4 || numparams > 5)
	{
		throw (runtime_error("parameters isn't right!"));
	}
	else
	{
		this->setFileName(numparams, params);
		this->setTempoPitch(numparams, params);
	}
}

char* ParseParams::getInputFile()
{
	return this->infile;
}

char* ParseParams::getOutputFile()
{
	return this->outfile;
}

float ParseParams::getTempo()
{
	return this->tempo;
}

float ParseParams::getPitch()
{
	return this->pitch;
}

void ParseParams::setFileName( int numparams, char* params[] )
{
	this->infile = params[1];
	this->outfile = params[2];
}

void ParseParams::setTempoPitch( int numparams, char* params[] )
{
	if (numparams == 4)
	{
		string s1 =  params[3];
		string s2 = s1.substr(0,3);
		string s3 = s1.substr(3);
		if (s2 == "-t:")
		{
			this->tempo = (float)atof(s3.c_str());
			this->pitch = 0;
		}
		else if (s2 == "-p:")
		{
			this->tempo = 0;
			this->pitch = (float)atof(s3.c_str());
		}
		else
		{
			throw (runtime_error("parameters isn't right!"));
		}
	}
	
	if (numparams == 5)
	{
		string s1 = params[3];
		string s2 = params[4];
		string s3 = s1.substr(0,3);
		string s4 = s1.substr(3);
		string s5 = s2.substr(0,3);
		string s6 = s2.substr(3);
		if (s3 == "-t:" && s5 == "-p:")
		{
			this->tempo = (float)atof(s4.c_str());
			this->pitch = (float)atof(s6.c_str());
		}
		else if (s3 == "-p:" && s5 == "-t:")
		{
			this->tempo = (float)atof(s6.c_str());
			this->pitch = (float)atof(s4.c_str());
		}
		else
		{
			throw (runtime_error("parameters isn't right!"));
		}
	}
}
