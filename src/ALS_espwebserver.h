#ifndef ALS_ESPWEBSERVER_H
	#define ALS_ESPWEBSERVER_H
	#include <Arduino.h>

	class ALS_espwebserver
	{
	public:
		ALS_espwebserver();
		~ALS_espwebserver(){};
		void setup();

		void serverLoop();
		void socketLoop();

		void serverFS(boolean fsOK);
		void serverInitialize();

		void socketBegin();
		void serverBegin();

		void http_sendJson(String json);
		void http_sendHtml(String json);
		void http_sendTxt(String json);
		
	};		
	ALS_espwebserver * ALS_espwebserverPtr_get();
#endif