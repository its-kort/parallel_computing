#include <conio.h>
#include <stdio.h>
#include <tchar.h>
#include <windows.h>

#define BUF_SIZE 256

TCHAR szName[] = TEXT("MyFileMappingObject");

int main() {
    HANDLE hMapFile;
    LPCTSTR pBuf;
    hMapFile = OpenFileMapping(
        FILE_MAP_ALL_ACCESS, // read/write access
        FALSE,               // do not inherit the name
        szName);             // name of mapping object

    if (hMapFile == NULL) {
        printf("Could not open file mapping object (%d).\n", GetLastError());
        return 1;
    }

    pBuf = (LPTSTR)MapViewOfFile(hMapFile,            // handle to map object
                                 FILE_MAP_ALL_ACCESS, // read/write permission
                                 0,
                                 0,
                                 BUF_SIZE);

    if (pBuf == NULL) {
        printf("Could not map view of file (%d).\n", GetLastError());
        CloseHandle(hMapFile);
        return 1;
    }

    MessageBox(NULL, pBuf, TEXT("Consumer"), MB_OK);
    UnmapViewOfFile(pBuf);
    CloseHandle(hMapFile);

    return 0;
}
