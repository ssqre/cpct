// TestWavManipulateDll.cpp : Defines the entry point for the console application.
//


#include "stdafx.h"
#include <stdexcept>
#define DLL_EXPORTS
#include "../WavManipulateDll/WavManipulateDll.h"
#pragma comment(lib,"../Release/WavManipulateDll.lib")

using namespace std;



#define BUFFER_SIZE 2048


void openFile(void** infile, void** outfile)
{
	*infile = getWavInFileByName("e:\\work_SR\\code\\CPCT_MSTFTM\\test\\woman.wav");
	int samplerate = (int)getSampleRate(*infile);
	int bits = (int)getNumBits(*infile);
	int channels = (int)getNumChannels(*infile);
 	*outfile = saveWavOutFileByName("e:\\work_SR\\code\\CPCT_MSTFTM\\test\\outfile.wav", samplerate, bits, channels);

	printf("openFile done!\n");
}

void process(HANDLE infile, HANDLE outfile)
{
	short sampleBuffer[BUFFER_SIZE];
	int nSample;
	int nChannels;

	nChannels = (int)getNumChannels(infile);

	while (isFileEnd(infile)==0)
	{
		int num;
		num = readInt16(infile, sampleBuffer, BUFFER_SIZE);
		// printf("%d	",num);
		nSample = num / nChannels;
		writeInt16(outfile , sampleBuffer, num);
	}

	destroyWavInFile(infile);
	destroyWavOutFile(outfile);

	printf("process done!\n");

}

int _tmain(int argc, _TCHAR* argv[])
{	
	HANDLE infile;
	HANDLE outfile;
	try
	{
		openFile(&infile, &outfile);
		process(infile, outfile);
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

