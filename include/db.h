#ifndef DB_H
#define DB_H

/******************************************************************************************************************************/
#include <strtree.h>

#define DB_X_LEN				0xff
#define DB_Y_LEN				0xf
#define DB_Z_LEN				0xfff




long get_last_id ();
long push_msg (unsigned char*);
unsigned char* pull_msg (long);






/******************************************************************************************************************************/

#endif
