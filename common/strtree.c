#include <strtree.h>









unsigned char* store_str (unsigned char* str)
{
	int							tmp;
	pstrnode*					cursor = &str_root;


	while ( *cursor ) {
		tmp = strcmp((*cursor)->str, str);
		if ( tmp > 0 )		cursor = &(*cursor)->less;
		else if ( tmp < 0 )	cursor = &(*cursor)->more;
		else				return (*cursor)->str;
	}

	(*cursor)			= malloc(sizeof(struct strnode));
	(*cursor)->str		= strdup(str);
	(*cursor)->less		= NULL;
	(*cursor)->more		= NULL;


	return (*cursor)->str;
}

void print_strtree ()
{
	print_strbranch(str_root);
}
void print_strbranch (pstrnode this)
{
	if ( this->less )		print_strbranch(this->less);
	write(1, this->str, strlen(this->str));		write(1, "\n", 1);
	if ( this->more )		print_strbranch(this->more);
}
