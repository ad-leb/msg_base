#ifndef ROW_H
#define ROW_H

/******************************************************************************************************************************/
#include <stdlib.h>
#include <string.h>
#include <unistd.h>








typedef struct strnode*		pstrnode;
struct strnode {
	unsigned char*			str;
	struct strnode*			less;
	struct strnode*			more;
};

extern pstrnode				str_root;

unsigned char* store_str (unsigned char*);
void print_strtree ();
void print_strbranch (pstrnode);








/******************************************************************************************************************************/

#endif
