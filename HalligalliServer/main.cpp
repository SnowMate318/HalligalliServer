#include "main.h"
#include "ServerImpl.h"
int main() {

	ServerImpl* server = new ServerImpl();
	server->serverStart();
	return 0;
}