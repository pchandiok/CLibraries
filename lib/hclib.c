#include <ctype.h>
#include <errno.h>
#include <float.h>
#include <limits.h>
#include <math.h>
#include <stdarg.h>
#include <stdint.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef char* string;

int letters = 0;
int words = 1;
int sentence = 0;

string GetString(const string str)
{
	int ch;
    int i=0;
    /*int size = 10;
    int count = 0;
	string ptr = (char*) calloc(size,  sizeof(char) );*/

    size_t size = 1;
    size_t count = 0;
	string ptr = (char*) calloc(size,  sizeof(char) );
	
    for(;;)
	{
		printf("%s", str);
       	while((ch = getchar()) != '\n')
       	{
            if(count >= size)
            {
                ptr = (char*) realloc(ptr, count);
            }
            else
            {
                count++;
            }

		    ptr[i]=ch;

            if(isalpha(ptr[i]))
            {
                letters += 1;
            }
        //checks whether the word has ended or not.
            else if(isspace(ptr[i]))
            {
                words += 1;
            }
        //checks whether the sentence has ended or not.
            else if(ptr[i] == '.' || ptr[i] == '?' || ptr[i] == '!' || ptr[i] == '\n')
            {
                sentence += 1;
            }

  		    i++;
            count++;
       	}

		if(ptr[0] != '\0')
		{
			break;
		}
	}
        return ptr;
}

double GetDouble(const string msg)
{
	string str;
	string tail;
	double d;
	for(;;)
	{
		str = GetString(msg);
		if(strlen(str) > 0)
		{
			d = strtod(str, &tail);
			if(*tail == '\0' || d != 0 || d < DBL_MAX)
				break;
		}
	}
	free(str);
    letters = 0;
    words = 0;
    sentence = 0;
	return d;
}

float GetFloat(const string msg)
{
	string str;
	string tail;
	float d;
	for(;;)
	{
		str = GetString(msg);
		if(strlen(str) > 0)
		{
			d = strtof(str, &tail);
			if(*tail == '\0' || d != 0 || d < FLT_MAX)
				break;
		}
	}
	free(str);
    letters = 0;
    words = 0;
    sentence = 0;
	return d;
}

int GetInt(const string msg)
{
	string str;
	string tail;
	int d;
	for(;;)
	{
		str = GetString(msg);
		if(strlen(str) > 0)
		{
			d = strtol(str, &tail, 10);
			//if(*tail == '\0' || d != 0 || d>= INT_MIN || d < INT_MAX)
			if(*tail == '\0' && d != 0 && d >= INT_MIN && d < INT_MAX)
				break;
		}
	}
	free(str);
    letters = 0;
    words = 0;
    sentence = 0;
	return d;
}

long GetLong(const string msg)
{
	string str;
	string tail;
	long d;
	for(;;)
	{
		str = GetString(msg);
		if(strlen(str) > 0)
		{
			d = strtol(str, &tail, 10);
			if(*tail == '\0' && d < LONG_MAX)
				break;
		}
	}
	free(str);
    letters = 0;
    words = 0;
    sentence = 0;
	return d;
}
