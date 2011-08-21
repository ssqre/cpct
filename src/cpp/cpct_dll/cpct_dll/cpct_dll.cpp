// cpct_dll.cpp : Defines the exported functions for the DLL application.
//

#include "stdafx.h"
#include "cpct_dll.h"

#include "../../cpct-mstftm/cpct-mstftm/CPCT_MSTFTM.h"
#pragma comment(lib, "../Release/cpct-mstftm.lib")

using namespace CPCT;


API_CPCT HANDLE createCpctByDefault()
{
	CPCT_MSTFTM *cpct = new CPCT_MSTFTM();
	return (HANDLE)cpct;
}

API_CPCT HANDLE createCpctByParams( int winlen, int hoplen, int nit )
{
	CPCT_MSTFTM *cpct = new CPCT_MSTFTM(winlen, hoplen, nit);
	return (HANDLE)cpct;
}

API_CPCT void setData( HANDLE h, const float* data, int datalength, int nChannels )
{
	CPCT_MSTFTM *cpct = (CPCT_MSTFTM*)h;
	cpct->setData(data, datalength, nChannels);
}

API_CPCT void setParams( HANDLE h, float tempo, float pitch )
{
	CPCT_MSTFTM *cpct = (CPCT_MSTFTM*)h;
	cpct->setParams(tempo, pitch);
}

API_CPCT void getData( HANDLE h, float* data, int& datalength )
{
	CPCT_MSTFTM *cpct = (CPCT_MSTFTM*)h;
	cpct->getData(data, datalength);
}

API_CPCT void destroyCpct( HANDLE h )
{
	CPCT_MSTFTM *cpct = (CPCT_MSTFTM*)h;
	delete cpct;
}




