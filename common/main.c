#include <main.h>



int main (int argc, char* argv[], char* env[])
{
	struct str*					str;


	str = pulls(0);
	while ( str ) {
		if ( str == STR_BAD_PTR ) 	return 99;
		pushs(1, str);
		str = pulls(0);
	}


	return 0;
}
