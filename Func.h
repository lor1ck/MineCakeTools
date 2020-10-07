#pragma once
#include <iostream>
#include <string>
#include <tchar.h>
#include <process.h>
#include <windows.h>
#include <tlhelp32.h>

BOOL GetProcessList();
BOOL TerminateMyProcess(DWORD dwProcessId, UINT uExitCode);
BOOL GetProcessList()
{
	HANDLE hProcessSnap;
	HANDLE hProcess;
	PROCESSENTRY32 pe32;
	DWORD dwPriorityClass;
	// Take a snapshot of all processes in the system.
	hProcessSnap = CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS, 0);
	if (hProcessSnap == INVALID_HANDLE_VALUE)
	{
		return(FALSE);
	}

	// Set the size of the structure before using it.
	pe32.dwSize = sizeof(PROCESSENTRY32);

	// Retrieve information about the first process,
	// and exit if unsuccessful
	if (!Process32First(hProcessSnap, &pe32))
	{
		CloseHandle(hProcessSnap);  // clean the snapshot object
		return(FALSE);
	}

	// Now walk the snapshot of processes
	do
	{
		std::string str(pe32.szExeFile);

		if (str == "javaw.exe")
		{

			if (GetAsyncKeyState(VK_F4)) // Closing process
			{
				TerminateMyProcess(pe32.th32ProcessID, 1);
				Sleep(1);
			}


			if (GetAsyncKeyState(0x43)) // Button V, FastZoom
			{
				mouse_event(MOUSEEVENTF_RIGHTDOWN | MOUSEEVENTF_RIGHTUP, NULL, NULL, NULL, NULL); // Правый клик
				Sleep(1);
				mouse_event(MOUSEEVENTF_LEFTDOWN | MOUSEEVENTF_LEFTUP, NULL, NULL, NULL, NULL); // Левый клик
				Sleep(1);
			}
			if (GetAsyncKeyState(0x56)) // Button C, Autoclicker
			{
				mouse_event(MOUSEEVENTF_LEFTDOWN | MOUSEEVENTF_LEFTUP, NULL, NULL, NULL, NULL); // Левый клик
				Sleep(1);
			}

			if (GetAsyncKeyState(0x52)) // Button R, Fast reload
			{
				keybd_event(0x52, 60, KEYEVENTF_KEYUP, NULL);
				Sleep(15);
			}

			


			if (GetKeyState(VK_F5)) // Button F5, AutoRun ON
			{
				keybd_event(0x57, 60, KEYEVENTF_EXTENDEDKEY, NULL);
				Sleep(1);
			}

			if (GetKeyState(VK_F6)) // Button F6, AutoRun OFF
			{
				keybd_event(0x57, 60, KEYEVENTF_KEYUP, NULL);
			}

		}
	} while (Process32Next(hProcessSnap, &pe32));

	CloseHandle(hProcessSnap);
	return(TRUE);
}

BOOL TerminateMyProcess(DWORD dwProcessId, UINT uExitCode)
{
	DWORD dwDesiredAccess = PROCESS_TERMINATE;
	BOOL  bInheritHandle = FALSE;
	HANDLE hProcess = OpenProcess(dwDesiredAccess, bInheritHandle, dwProcessId);
	if (hProcess == NULL)
		return FALSE;

	BOOL result = TerminateProcess(hProcess, uExitCode);

	CloseHandle(hProcess);

	return result;
}