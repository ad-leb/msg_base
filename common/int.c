#include <int.h>


/****************    PRIVATE    ****************/
#define DECIMAL_LEN			32


extern const unsigned char*		int_str_last;
extern const unsigned char*		int_str_pull;
extern const unsigned char*		int_str_push;


void do_last (int, unsigned char*);
void do_push (int, unsigned char*);
void do_pull (int, unsigned char*);
void do_nope (int, unsigned char*);
int dtoi (int*, unsigned char*);
int itod (int*, unsigned char*);
/****************    PRIVATE    ****************/









void request (int fd, unsigned char* req)
{
	void (*foo)(int, unsigned char*) = do_nope;


	if ( !strncmp(req, int_str_last, 4) )			foo = do_last;
	if ( !strncmp(req, int_str_pull, 4) )			foo = do_pull;
	if ( !strncmp(req, int_str_push, 4) )			foo = do_push;

	foo(fd, req + 5);
}











void do_last (int fd, unsigned char* dump)
{
	int							id;
	unsigned char				buffer[DECIMAL_LEN];
	int							len;
	

	id = get_last_id();
	len = itod(&id, buffer);

	write(fd, buffer, len);
	write(fd, "\n", 1);
}

void do_push (int fd, unsigned char* msg)
{
	push_msg(msg);
}

void do_pull (int fd, unsigned char* asks)
{
	int							index_0;
	int							index_1;
	unsigned char*				tmp_msg;


	asks += dtoi(&index_0, asks);
	if ( *asks == ':' ) 	asks += dtoi(&index_1, asks);
	else 					index_1 = index_0;

	for (int i = index_0; i <= index_1; i++) {
		tmp_msg = pull_msg(i);
		write(fd, tmp_msg, strlen(tmp_msg));
	}
}

void do_nope (int fd, unsigned char* str)
{
}



int dtoi (int* digit, unsigned char* str)
{
	unsigned char*				start = str;


	for (int i = 7; i > 0 && (*str < 0x30 || *str > 0x39); i--) 	str++;
	*digit = 0;
	while ( 0x30 <= *str && *str <= 0x39 )		*digit = (*digit * 10) + (*str++ & 0x0f);


	return str - start;
}

int itod (int* digit, unsigned char* str)
{
	unsigned char*				start = str;
	int							d = *digit;
	unsigned char				stack[DECIMAL_LEN];
	int 						cur = 0;


	while ( d ) {
		stack[cur++] = (d % 10) | 0x30;
		d /= 10;
	}
	while ( --cur >= 0 ) {
		*str++ = stack[cur];
	}
	*str++ = 0;


	return str - start;
}
