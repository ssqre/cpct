////////////////////////////////////////////////////////////////////////////////
///
/// A class for parsing the cpct application command line parameters
///
////////////////////////////////////////////////////////////////////////////////

#ifndef PARSEPARAMS_H
#define PARSEPARAMS_H

#include <string>
using namespace std;

class ParseParams
{
private:
	char* infile;
	char* outfile;
	float tempo;
	float pitch;

	void setFileName(int numparams, char* params[]);
	void setTempo(int numparams, char* params[]);
	void setPitch(int numparams, char* params[]);

public:
	ParseParams(int numparams, char* params[] );
	char* getInputFile();
	char* getOutputFile();
	float getTempo();
	float getPitch();

};

#endif
