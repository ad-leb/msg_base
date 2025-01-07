#include <main.h>



int main (int argc, char* argv[], char* env[])
{
	int							sd;
	int							ad;
	struct sockaddr_un			addr;



	unlink(SOCK_PATH);
	memset(&addr, 0, sizeof(addr));
		addr.sun_family = AF_UNIX;
		strcpy(addr.sun_path, SOCK_PATH);

	sd = socket(AF_UNIX, SOCK_STREAM, 0);																						if (!~sd) return 1;
	if ( !~bind(sd, (struct sockaddr*) &addr, sizeof(addr)) )																	return 2;
	if ( !~listen(sd, 0) )																										return 3;
	


	while (1) {
		ad = accept(sd, NULL, NULL);																							if (!~ad) continue;
		accept_request(ad);
		if ( !~close(ad) )																										return 4;
	}



	return 0;
}



void accept_request (int ad)
{
	unsigned char				buffer[MSG_LEN];
	int							len;



	len = read(ad, buffer, MSG_LEN);
	while ( len > 0 ) {
		buffer[len] = 0;
		request(buffer);
		len = read(ad, buffer, MSG_LEN);
	}
}
