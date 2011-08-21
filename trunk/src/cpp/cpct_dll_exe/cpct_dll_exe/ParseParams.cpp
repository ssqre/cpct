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
	if (numparams < 5)
	{
		throw (runtime_error("parameters isn't enough!"));
	}
	else
	{
		this->setFileName(numparams, params);
		this->setTempo(numparams, params);
		this->setPitch(numparams, params);
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

void ParseParams::setTempo( int numparams, char* params[] )
{
	this->tempo = (float)atof(params[3]);
}

void ParseParams::setPitch( int numparams, char* params[] )
{
	this->pitch = (float)atof(params[4]);
}
