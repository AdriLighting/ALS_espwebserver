#include "ALS_espwebserver.h"
#include <adri_espwebserver.h>

extern adri_webserver	clientServer;
extern adri_socket		socketServer;

	ALS_espwebserver * ALS_espwebserverPtr;
	ALS_espwebserver * ALS_espwebserverPtr_get(){return ALS_espwebserverPtr;}

ALS_espwebserver::ALS_espwebserver(){
	ALS_espwebserverPtr=this;
	// webserver_ptr = this;
 //    // clientServer = new AsyncWebServer(port);
	// setup(fsOK, port);

}

void ALS_espwebserver::serverFS(boolean fsOK) {
	clientServer.filesystem_ok(fsOK);
	if (fsOK) clientServer.filesystem_set(&SPIFFS);
}
void ALS_espwebserver::serverInitialize()	{clientServer.initialize(80);	}

void ALS_espwebserver::socketBegin() 		{socketServer.setup();}
void ALS_espwebserver::serverBegin() 		{clientServer._server.begin();}

void ALS_espwebserver::socketLoop()			{socketServer.loop();}
void ALS_espwebserver::serverLoop() 		{clientServer.handleLoop();}

void ALS_espwebserver::http_sendJson(String json){
	clientServer.handleJson(json);
}
void ALS_espwebserver::http_sendHtml(String json){
	clientServer.handleFileRead(json);
}
void ALS_espwebserver::http_sendTxt(String json){
	clientServer.replyOKWithMsg(json);
}