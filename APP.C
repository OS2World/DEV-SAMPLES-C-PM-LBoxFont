#define INCL_GPI
#define INCL_WIN

#include <os2.h>
#include <stddef.h>
#include "APP.h"
#include <stdio.h>

HAB     hAB;
HMQ     hMsgQ;
HWND    hwndApp;
HWND    hwndAppFrame;
HWND	hwndKid;
HWND	hwndKidFrame;
HWND	hwndList;
extern FONTMETRICS FontMetrics;

/* Write-once global variables */
char    szAppName[10];
char	szKidName[10];
ULONG	style = FCF_STANDARD;
ULONG	KidCtlData = FCF_TITLEBAR | FCF_SYSMENU;

int _cdecl main(  )
{
    QMSG    qMsg;

    hAB   = WinInitialize(0);
    hMsgQ = WinCreateMsgQueue( hAB, 0 );

    WinLoadString( hAB, 0, IDSNAME, sizeof(szAppName), (PCH)szAppName );
    WinLoadString( hAB, 0, IDSKIDNAME, sizeof(szKidName), (PSZ) szKidName );

    if ( !WinRegisterClass( hAB, (PSZ)szAppName, (PFNWP)APPWndProc,
            CS_CLIPCHILDREN | CS_SIZEREDRAW, 0 ) )
        return( FALSE );


    /* Create a window instance of class szAppName */
    hwndAppFrame = WinCreateStdWindow(
        HWND_DESKTOP,     /* specify desktop as parent window           */
		FS_ICON | FS_ACCELTABLE | WS_VISIBLE,
		&style,
        (PCH)szAppName,  /* window class name                          */
        (PCH)szAppName,  /* name appearing in window caption           */
        0L,
        0,             /*  use current executable module id          */
		ID_APP, 	  /*  menu id and accelerator id and icon id	*/
        (HWND FAR *)&hwndApp  /* window handle                          */
        );

    /* Create a child window of class KidClass */


//                      Add the list box to the client window
//
/* note the LS_OWNERDRAW style.  This will cause a WM_DRAWITEM message
   to be sent to the owner of the listbox			       */
    hwndList = WinCreateWindow (hwndApp, WC_LISTBOX, NULL,
			       WS_VISIBLE | LS_OWNERDRAW, 0, 0, 0, 0,
			       hwndApp, HWND_BOTTOM, LID_LIST1, NULL, NULL);
    WinSetWindowPos (hwndList, HWND_BOTTOM, 10, 10, (short) 100,
			     (short) 100, SWP_SIZE | SWP_MOVE | SWP_SHOW);


 /*set the item height in the listbox */
    WinSendMsg(hwndList,LM_SETITEMHEIGHT,
	       (MPARAM) MAKEULONG((SHORT)FontMetrics.lMaxBaselineExt,0),0L);



    while( WinGetMsg( hAB, (PQMSG)&qMsg, (HWND)NULL, 0, 0 ) )
    {
        WinDispatchMsg( hAB, (PQMSG)&qMsg );
    }

    WinDestroyWindow( hwndAppFrame );
    WinDestroyMsgQueue( hMsgQ );
    WinTerminate( hAB );
}
/*
*/
