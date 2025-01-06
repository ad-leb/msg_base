#include <stdlib.h>
#include <string.h>
#include <unistd.h>


#define STR_BUFLEN				256

#define STR_BAD_PTR				(void*) -1
#define STR_ERR_RD				0x10
#define STR_ERR_WR				0x11





struct str {
	int							len;
	void*						addr;
};


struct str* borns (unsigned char*);
struct str* pulls (int);
int pushs (int, struct str*);
