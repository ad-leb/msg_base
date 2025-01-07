#include <int.h>




void nope ()
{
}

void request (unsigned char* req)
{
	if ( !strncmp(req, int_str_push, 5) )			do_push_msg(req + 5);
	else if ( !strncmp(req, int_str_pull, 5) )		do_pull_msg(req + 5);
	else											nope();
}

void do_push_msg (unsigned char* msg)
{
	push_msg(msg);
}

void do_pull_msg (unsigned char* asks)
{
	int							index_0;
	int							index_1;
	unsigned char*				tmp_msg;


	asks += stoi(&index_0, asks);
	if ( *asks == ':' ) {
		asks += stoi(&index_1, asks);
	} else {
		index_1 = index_0;
	}


	for (int i = index_0; i <= index_1; i++) {
		tmp_msg = pull_msg(i);
		write(1, tmp_msg, strlen(tmp_msg));
	}
}


int stoi (int* digit, unsigned char* str)
{
	unsigned char*				start = str;


	for (int i = 7; i > 0 && (*str < 0x30 || *str > 0x39); i--) 	str++;
	*digit = 0;
	while ( 0x30 <= *str && *str <= 0x39 )		*digit = (*digit * 10) + (*str++ & 0x0f);


	return str - start;
}
