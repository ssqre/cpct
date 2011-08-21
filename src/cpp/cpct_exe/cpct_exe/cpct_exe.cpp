// cpct_exe.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <stdexcept>
#include "WavManipulateDll.h"
#pragma comment(lib,"../Debug/WavManipulateDll.lib")
#include "../../cpct-mstftm/cpct-mstftm/CPCT_MSTFTM.h"
#pragma comment(lib,"../Debug/cpct-mstftm.lib")
using namespace std;
using namespace CPCT;

#define DATA_LENGTH 8192
#define BUFFER_SIZE (DATA_LENGTH * 3)

static void openFile(void** infile, void** outfile)
{
	*infile = getWavInFileByName("e:\\work_SR\\code\\CPCT_MSTFTM\\test\\woman.wav");
	int samplerate = (int)getSampleRate(*infile);
	int bits = (int)getNumBits(*infile);
	int channels = (int)getNumChannels(*infile);
	*outfile = saveWavOutFileByName("e:\\work_SR\\code\\CPCT_MSTFTM\\test\\outfile.wav", samplerate, bits, channels);

	printf("openFile done!\n");
}



static void process(void* infile, void* outfile, CPCT_MSTFTM* cpct)
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

		cpct->setData(sampleBuffer, DATA_LENGTH, nChannels);
		cpct->setParams(-0.5, 12);
		cpct->getData(sampleBuffer, datalength);

		writeFloat(outfile , sampleBuffer, datalength);
	}
	destroyWavInFile(infile);
	destroyWavOutFile(outfile);
	
	printf("process done!\n");
}

int _tmain(int argc, _TCHAR* argv[])
{
	void* infile;
	void* outfile;
	CPCT_MSTFTM* cpct = new CPCT_MSTFTM(512, 256, 5);

	try
	{
		openFile(&infile, &outfile);
		process(infile, outfile, cpct);
		delete cpct;
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

