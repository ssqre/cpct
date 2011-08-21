// WavManipulateDll.cpp : Defines the exported functions for the DLL application.
//

#include "stdafx.h"

#include "../../AudioManipulate/AudioManipulate/WavFile.h"
#pragma comment(lib,"../Release/AudioManipulate.lib")

#include "WavManipulateDll.h"
using namespace AudioManipulate::WavManipulate;



// get wav file by name
API_AudioManipulate HANDLE getWavInFileByName(const char* filename)
{
	WavInFile* temp = new WavInFile(filename);
	return (void*)temp;
}

// get wav file by FILE pointer.
API_AudioManipulate HANDLE getWavInFileByPointer(FILE* file)
{
	WavInFile* temp = new WavInFile(file);
	return (void*)temp;
}

// close reading wav file.
API_AudioManipulate void destroyWavInFile(HANDLE h)
{
	WavInFile* temp = (WavInFile*)h;
	delete temp;
}

// rewind to beginning of the file.
API_AudioManipulate void rewindToWavInFileBeginning(HANDLE h)
{
	WavInFile* temp = (WavInFile*)h;
	temp->rewind();
}

// get sample rate
API_AudioManipulate uint getSampleRate(HANDLE h)
{
	WavInFile* temp = (WavInFile*)h;
	return temp->getSampleRate();
}

// get Get number of bits per sample, i.e. 8 or 16.
API_AudioManipulate uint getNumBits(HANDLE h)
{
	WavInFile* temp = (WavInFile*)h;
	return temp->getNumBits();
}

// get sample data size in bytes.
API_AudioManipulate uint getDataSizeInBytes(HANDLE h)
{
	WavInFile* temp = (WavInFile*)h;
	return temp->getDataSizeInBytes();
}

// get total number of samples in file.
API_AudioManipulate uint getNumSamples(HANDLE h)
{
	WavInFile* temp = (WavInFile*)h;
	return temp->getNumSamples();
}

// get number of bytes per audio sample (e.g. 16bit stereo = 4 bytes/sample)
API_AudioManipulate uint getBytesPerSample(HANDLE h)
{
	WavInFile* temp = (WavInFile*)h;
	return temp->getBytesPerSample();
}

// get number of audio channels in the file (1=mono, 2=stereo)
API_AudioManipulate uint getNumChannels(HANDLE h)
{
	WavInFile* temp = (WavInFile*)h;
	return temp->getNumChannels();
}

// get the audio file length in milliseconds
API_AudioManipulate uint getLengthMS(HANDLE h)
{
	WavInFile* temp = (WavInFile*)h;
	return temp->getLengthMS();
}

// Reads audio samples from the WAV file. This routine works only for 8 bit samples.
// Reads given number of elements from the file or if end-of-file reached, as many 
// elements as are left in the file.
//
// \return Number of 8-bit integers read from the file.
API_AudioManipulate int readByte(HANDLE h, char* buffer, int maxElems)
{
	WavInFile* temp = (WavInFile*)h;
	return temp->read(buffer, maxElems);
}


// Reads audio samples from the WAV file to 16 bit integer format. Reads given number 
// of elements from the file or if end-of-file reached, as many elements as are 
// left in the file.
//
// \return Number of 16-bit integers read from the file.
API_AudioManipulate int readInt16( HANDLE h, short *buffer, int maxElems )
{
	WavInFile* temp = (WavInFile*)h;
	return temp->read(buffer, maxElems);
}


// Reads audio samples from the WAV file to floating point format, converting 
// sample values to range [-1,1]. Reads given number of elements from the file
// or if end-of-file reached, as many elements as are left in the file.
//
// \return Number of elements read from the file.
API_AudioManipulate int readFloat(HANDLE h, float* buffer, int maxElems)
{
	WavInFile* temp = (WavInFile*)h;
	return temp->read(buffer, maxElems);
}


// Check end-of-file.
//
// \return Nonzero if end-of-file reached.
API_AudioManipulate int isFileEnd(HANDLE h)
{
	WavInFile* temp = (WavInFile*)h;
	return temp->eof();
}


/// API for wav writing
// save wav file by name
API_AudioManipulate HANDLE saveWavOutFileByName(const char* filename, int sampleRate, int bits, int channels)
{
	WavOutFile* temp = new WavOutFile(filename, sampleRate, bits, channels);
	return (void*)temp;
}

// save wav file by FILE pointer
API_AudioManipulate HANDLE saveWavOutFileByPointer(FILE* file, int sampleRate, int bits, int channels)
{
	WavOutFile* temp = new WavOutFile(file, sampleRate, bits, channels);
	return (void*)temp;
}


// close writing wav file 
API_AudioManipulate void destroyWavOutFile(HANDLE h)
{
	WavOutFile* temp = (WavOutFile*)h;
	delete temp;
}

// Write data to WAV file. This function works only with 8bit samples. 
// Throws a 'runtime_error' exception if writing to file fails.
API_AudioManipulate void writeByte(HANDLE h, const char* buffer, int numElems)
{
	WavOutFile* temp = (WavOutFile*)h;
	temp->write(buffer, numElems);
}

// Write data to WAV file. This function works only with 16bit samples. 
// Throws a 'runtime_error' exception if writing to file fails.
API_AudioManipulate void writeInt16( HANDLE h, const short* buffer, int numElems )
{
	WavOutFile* temp = (WavOutFile*)h;
	temp->write(buffer, numElems);
}

// Write data to WAV file in floating point format, saturating sample values to range
// [-1..+1]. Throws a 'runtime_error' exception if writing to file fails.
API_AudioManipulate void writeFloat(HANDLE h, const float* buffer, int numElems)
{
	WavOutFile* temp = (WavOutFile*)h;
	temp->write(buffer, numElems);
}