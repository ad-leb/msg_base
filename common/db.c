#include <db.h>


/****************    PRIVATE    ****************/
extern unsigned char*			db_msgs[DB_X_LEN][DB_Y_LEN][DB_Z_LEN];
extern long			 			db_next_id;

void shift (long*, int);
void get_indexes (long, int*, int*, int*);
/****************    PRIVATE    ****************/




long get_last_id () 
{ 
	return db_next_id - 1; 
}
long push_msg (unsigned char* str)
{
	int							x, y, z;

	get_indexes(db_next_id, &x, &y, &z);
	db_msgs[x][y][z] = store_str(str);

	return db_next_id++;
}
unsigned char* pull_msg (long id)
{
	int							x, y, z;

	get_indexes(id, &x, &y, &z);

	return db_msgs[x][y][z];
}













void shift (long* dig, int to)
{
	while ( to )		{ *dig >>= 1; to >>= 1; }
}
void get_indexes (long id, int* x, int* y, int* z)
{
	*z = id & DB_Z_LEN;			shift(&id, DB_Z_LEN);
	*y = id & DB_Y_LEN;			shift(&id, DB_Y_LEN);
	*x = id & DB_X_LEN;			shift(&id, DB_X_LEN);
}
