#define INCL_WIN
#define INCL_GPI

#include <os2.h>
#include <stddef.h>
#include "APP.h"

extern char     szAppName[];

VOID EXPENTRY APPPaint( hWnd, message, mp1, mp2 )
HWND   hWnd;
ULONG message;
MPARAM  mp1;
MPARAM  mp2;
{
    HPS         hPS;
    RECTL	rc, rcClip;

    hPS = WinBeginPaint( hWnd, 0, &rcClip );

    WinQueryWindowRect( hWnd, &rc );
    WinFillRect( hPS, &rc, CLR_WHITE );

    WinEndPaint( hPS );

    return;
}
/*
*/
