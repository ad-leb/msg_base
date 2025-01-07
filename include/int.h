#ifndef INT_H
#define INT_H

/******************************************************************************************************************************/
#include <string.h>
#include <db.h>



extern const unsigned char*		int_str_pull;
extern const unsigned char*		int_str_push;

void nope ();
void request (unsigned char*);
void do_push_msg (unsigned char*);
void do_pull_msg (unsigned char*);
int stoi (int*, unsigned char*);






/******************************************************************************************************************************/

#endif
