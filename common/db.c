#include <db.h>




void get_indexes (int id, int* x, int* y)
{
	*x = id >> 12;
	*y = id & DB_Y_LEN;
}


int push_msg (unsigned char* str)
{
	int							x, y;

	get_indexes(db_next_id, &x, &y);
	db_msgs[x][y] = store_str(str);

	return db_next_id++;
}
unsigned char* pull_msg (int id)
{
	int							x, y;

	get_indexes(id, &x, &y);

	return db_msgs[x][y];
}
