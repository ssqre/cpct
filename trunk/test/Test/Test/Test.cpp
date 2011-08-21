// Test.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <math.h>
#include <stdlib.h>
#include "aflibFFT.h"
#include <iostream>
#include <string>
using namespace std;

class A
{
public:
	int* c;
	double x;
	A()
	{
		x = -7.21;
		c = new int[10];
	}
	~A()
	{
		delete c;
		printf("delete c\n");
	}
};

int* test(int *p ,int l)
{
	int *a = new int[l];
	*p += 2;
	*(p + 1) +=3;
	for (int i = 0; i < l; i++)
	{
		a[i] = i;
	}
	for (int i =0; i <l; i++)
	{
		printf("I:%d   ",*(a+i));
	}
	return a;
}


void test(int& a)
{
	a = 50;
}

int _tmain(int argc, _TCHAR* argv[])
{
	/*
	// int k = rand()*2;
	int b[3] = {0};
	A *a = new A();
	// printf("%d\n",a->c[1]);
	unsigned x = (int)(a->x);
	// printf("%d  %d\n",rand(),RAND_MAX);
	int *aa;
	aa = test(b, 3);
	for (int i = 0; i< 3; i++)
	{
		printf("O:%d    ", *(aa+i));
	}
	delete a;

	int d;
	test(d);
	printf("\n->%d: ",d);

	int v0[] = {1 ,2 ,3,4,5,6,7,8,9,10};
	for (int i = 0;  i < 10; i+=2   )
	{
		v0[i / 2] = 7;
	}
	printf("\n");
	for (int i = 0; i < 10; i++)
	{
		printf("v0: %d   ",v0[i]);
	}

	int *v1 = new int[10];
	for (int i = 0; i < 10; i++)
	{
		v1[i] = i;
	}
	
	int *v2 = v1;

	v1 = new int[20];
	for (int i = 0; i< 20; i+=2)
	{
		v1[i] = v2[i / 2];
		v1[i + 1] = v2[i / 2];
	}
	printf("\n");
	for (int i = 0; i < 20;i++)
	{
		printf("v1: %d  ",v1[i]);
	}
	
	short v3 = 30001;
	double v4;
	v4 = v3 / 32768.0;
	printf("\n v4: %f ",v4);

	float v5 = 1.0;
	if ( v5 != 1)
	{
		printf("\nv5: %s","True");
	}
	else
	{
		printf("\nv5: %s","False");
	}

	double v6[16];
	double v7[16];
	double v8[16];
	double *v9 = new double[16];
	for (int i = 0;i<16;i++)
	{
		v6[i] = i;
	}
	system("cls");
	aflibFFT *fourier = new aflibFFT();
	fourier->fft_double(16, FALSE,  v6, NULL, v7,v8);
	for (int i =0 ;i<16;i++)
	{
		printf("%f:%f   ",v7[i],v8[i]);
	}
	fourier->fft_double(16,true,v7,v8,v9,v6);
	
	printf("\n\n");
	for (int i =0 ;i<16;i++)
	{
		printf("%f:%f   ",v9[i],v6[i]);
	}
	
	int v10[10];
	for (int i = 0;i <20 ;i++)
	{
		v10[i] = 20-i;
	}
	for(int i = 0; i< 20; i++)
	{
		printf("v10:%d  ",v10[i]);
	}
	*/
	/*
	int a;
	void throwill(int a);
	while(1)
	{
		cin>>a;
		if (a == 0)
		{
			break;
		}
		else
		{
			try
			{
				throwill(a);
			}
			catch (const runtime_error &e)
			{
				cout<<e.what();
			}
		}
	}
	*/
	char* v11 ="ddqre.wav";
	string s = v11;
	s.find_first_of('.');
	cout<<string::npos;
	return 0;
}

void throwill(int a )
{
	string msg;
	msg = "ddqre";
	if (a > 0)
	{
		throw runtime_error(msg.c_str());
	}
	else
	{
		printf("a < 0");
	}

}