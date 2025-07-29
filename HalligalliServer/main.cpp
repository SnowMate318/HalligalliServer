#include "main.h"
#include "Server.h"
#include "SocketServer.h"
int main() {

	Server* server = new SocketServer();
	server->startServer();
	server->stopServer();

	return 0;
}