#ifndef DB_H
#define DB_H

/******************************************************************************************************************************/
#include <strtree.h>

#define DB_X_LEN				0xf
#define DB_Y_LEN				0xfff




extern unsigned char*			db_msgs[DB_X_LEN][DB_Y_LEN];
extern int			 			db_next_id;

void get_indexes (int id, int* x, int* y);
int push_msg (unsigned char*);
unsigned char* pull_msg (int);






/******************************************************************************************************************************/

#endif
