/*
	WinSock/Win32 platform headers
*/

#pragma once

#define _CRT_SECURE_NO_WARNINGS

#include <WinSock2.h>
#include <iphlpapi.h>
#include <ws2tcpip.h>
#include <cstdio>

#pragma comment(lib, "Ws2_32.lib")

//////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Initializes winsock
//////////////////////////////////////////////////////////////////////////////////////////////////////////////

namespace platform
{
	bool InitWinsock2();
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Helper functions
//////////////////////////////////////////////////////////////////////////////////////////////////////////////

void getAddressName(addrinfo* info, char* buffer, size_t szbuffer, int flag = NI_NUMERICHOST);

//////////////////////////////////////////////////////////////////////////////////////////////////////////////