/*****************************************************************************
 * Name: Daniel Rivera, Molly Johnson, Gaetan Ingrassia
 * File Name:  library.cpp
 * Organization: Oregon State University
 * Project Name: Windows Game Hack
 * Created On: 1/18/2020
 * Class: CS467-400 Online Capstone Project
 * TA Name:	Iman Aminzahed, Prachi Rahurkar
 * Instructor Name: William Pfeil
 * ___COPYRIGHT___ (c) 2020 All Rights Reserved
 *****************************************************************************/

/****************************************************************************
 * Description:
 ****************************************************************************/

#include "library.hpp"
#include <iostream>
#include <sys/socket.h> 
#include <arpa/inet.h> 
#include <unistd.h> 
#include <string.h> 
#include <CkSocket.h>

using std::cout;
using std::cin;
using std::endl;

void library::proxy2server(int port_number)
{
	CkSocket socket;
	bool ssl = false;
	int max_wait_time = 20000;
	bool success socket.Connect("localhost", port_number, ssl, max_wait_time);
	if (success != true) {
		cout << socket.lastErrorText() << "\r\n";
		return;
	}

	socket.put_MaxReadIdleMs(10000);
	socket.put_MaxSendIdleMs(10000);

	const char* recieved_message = socket.recieveString();
	if (socket.get_LastMethodSuccess() != true) {
		cout << socket.lastErrorText() << "\r\n";
		return;
	}

	success = socket.Close(20000);
	cout << recieved_message << "\r\n";
}


