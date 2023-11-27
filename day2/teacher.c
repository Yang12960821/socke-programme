#include "teacher.h"
#include "itcast_asn1_der.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
	typedef struct _Teacher
	{
		char name[64];
		int age;
		char *p;
		long plen;
	}Teacher;
*/
int encodeTeacher(Teacher * p, char ** outData, int * outlen)
{
	return 0;
}

/*
	typedef struct _Teacher
	{
		char name[64];
		int age;
		char *p;
		long plen;
	}Teacher;
*/
int decodeTeacher(char * inData, int inLen, Teacher ** p)
{
	return 0;
}

void freeTeacher(Teacher ** p)
{
}
