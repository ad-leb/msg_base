#ifndef MAIN_H
#define MAIN_H

/******************************************************************************************************************************/
#include <sys/socket.h>
#include <sys/un.h>

#include <strtree.h>
#include <db.h>
#include <int.h>


#define SOCK_PATH				"msger_20250107"
#define MSG_LEN					1024



int main (int, char*[], char*[]);
void accept_request (int);












/******************************************************************************************************************************/

#endif
