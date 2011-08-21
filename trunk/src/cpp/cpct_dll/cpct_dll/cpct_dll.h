#ifndef CPCT_DLL_H
#define CPCT_DLL_H

#ifdef __cplusplus
extern "C" {
#endif

#ifndef DLL_EXPORTS
#define API_CPCT _declspec(dllexport)
#else 
#define API_CPCT _declspec(dllimport)
#endif

typedef void* HANDLE;

// create cpct-mstftm by default parameters
API_CPCT HANDLE createCpctByDefault();

// create cpct-mstftm by specific parameters
API_CPCT HANDLE createCpctByParams(int winlen, int hoplen, int nit);

// float* data return the float* dataOutput, int& datalength return the int nDataOutput
API_CPCT void setData(HANDLE h, const float* data, int datalength, int nChannels);

// // set the tempo and pitch
API_CPCT void setParams(HANDLE h, float tempo, float pitch);

// set the float* dataInput, datalength is the length of data, nChannels is the number of channels
API_CPCT void getData(HANDLE h, float* data, int& datalength);

API_CPCT void destroyCpct(HANDLE h);

#ifdef __cplusplus
}
#endif

#endif