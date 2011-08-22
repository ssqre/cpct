// cpct_dll_exe.cpp : Defines the entry point for the console application.
//

#define DLL_EXPORTS
#include <stdio.h>
#include "ParseParams.h"
#include "WavManipulateDll.h"
#pragma comment(lib,"../Debug/WavManipulateDll.lib")
#include "cpct_dll.h"
#pragma comment(lib,"../Debug/cpct_dll.lib")


#define DATA_LENGTH 4096
#define BUFFER_SIZE (DATA_LENGTH * 3)

static void openFile(void** infile, void** outfile, ParseParams *param)
{
	*infile = getWavInFileByName(param->getInputFile());
	int samplerate = (int)getSampleRate(*infile);
	int bits = (int)getNumBits(*infile);
	int channels = (int)getNumChannels(*infile);
	*outfile = saveWavOutFileByName(param->getOutputFile(), samplerate, bits, channels);

	printf("openFile done!\n");
}



static void process(void* infile, void* outfile, void* cpct, ParseParams *param)
{
	float sampleBuffer[BUFFER_SIZE];
	int nSample;
	int nChannels;

	nChannels = (int)getNumChannels(infile);

	while (isFileEnd(infile)==0)
	{
		int num;
		int datalength;
		num = readFloat(infile, sampleBuffer, DATA_LENGTH);
		nSample = num / nChannels;
		
		setData(cpct, sampleBuffer, DATA_LENGTH, nChannels);
		setParams(cpct, param->getTempo(), param->getPitch());
		getData(cpct, sampleBuffer, datalength);

		writeFloat(outfile , sampleBuffer, datalength);
	}
	destroyWavInFile(infile);
	destroyWavOutFile(outfile);

	printf("process done!\n");
}

int main(int numparams, char* params[])
{
	void* infile;
	void* outfile;
	void* cpct = createCpctByParams(512, 256, 5);

	try
	{
		ParseParams *parameter = new ParseParams(numparams, params);
		openFile(&infile, &outfile, parameter);
		process(infile, outfile, cpct, parameter);
		destroyCpct(cpct);
	}
	catch (const runtime_error &e) 
	{
		// An exception occurred during processing, display an error message
		fprintf(stderr, "%s\n", e.what());
		return -1;
	}
	printf("Done!!!\n");

	return 0;
}

