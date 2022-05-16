#pragma once
#include <Windows.h>
#include <iostream>
VOID startup(LPWSTR lpApplicationName)
{
	// additional information
	STARTUPINFO si;
	PROCESS_INFORMATION pi;
	// set the size of the structures
	ZeroMemory(&si, sizeof(si));
	si.cb = sizeof(si);
	ZeroMemory(&pi, sizeof(pi));

	// start the program up
	CreateProcessW(lpApplicationName,   // the path
		0,        // Command line
		NULL,           // Process handle not inheritable
		NULL,           // Thread handle not inheritable
		FALSE,          // Set handle inheritance to FALSE
		0,              // No creation flags
		NULL,           // Use parent's environment block
		NULL,           // Use parent's starting directory 
		&si,            // Pointer to STARTUPINFO structure
		&pi             // Pointer to PROCESS_INFORMATION structure (removed extra parentheses)
	);
	// Close process and thread handles. 
	CloseHandle(pi.hProcess);
	CloseHandle(pi.hThread);
}
bool RunSAOFB() 
{
	startup((LPWSTR)L"R:\\Games\\Sword Art Online Fatal Bullet Dissonance of the Nexus\\SAOFB\\Binaries\\Win64\\SAOFB-Win64-Shipping.exe"); //Sword Art Online Fatal Bullet Auto Launcher
	return GetLastError();
}
