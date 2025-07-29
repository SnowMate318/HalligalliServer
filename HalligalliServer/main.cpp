#include "main.h"
#include "IServer.h"
#include "SocketServer.h"
int main() {

	IServer* server = new SocketServer();
	server->startServer();
	server->stopServer();

	return 0;
}