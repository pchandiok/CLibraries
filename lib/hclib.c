typedef char* string;

string GetString(const string str)
{
	int ch;
    int i=0;
    int size = 10;
    int count = 0;
	string ptr = (char*) calloc(size,  sizeof(char) );

	for(;;)
	{
		printf("%s", str);
       	while((ch = getchar()) != '\n')
       	{
            if(count > size)
            {
                ptr = (char*) realloc(ptr, 2*count);
            }
		    ptr[i]=ch;
  		    i++;
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
			if(*tail == '\0' || d != 0)
				break;
		}
	}
	free(str);
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
			if(*tail == '\0' || d != 0)
				break;
		}
	}
	free(str);
	return d;
}

int GetInt(const string msg)
{
	string str;
	string tail;
	float d;
	for(;;)
	{
		str = GetString(msg);
		if(strlen(str) > 0)
		{
			d = strtol(str, &tail, 10);
			if(*tail == '\0' || d != 0)
				break;
		}
	}
	free(str);
	return d;
}
