#include <str.h>




struct str* borns (unsigned char* str)
{
	struct str*					tmp;


	tmp			= malloc(sizeof(struct str));
	tmp->len	= strlen(str);
	tmp->addr	= strdup(str);


	return tmp;
}

struct str* pulls (int fd)
{
	unsigned char				buffer[STR_BUFLEN];
	int							len;


	len = read(fd, buffer, STR_BUFLEN - 1);																						if (!~len)	return STR_BAD_PTR;
																																if (!len)	return NULL;

	buffer[len] = 0;																											return borns(buffer);
}

int pushs (int fd, struct str* str)
{
	return write(fd, str->addr, str->len);
}
