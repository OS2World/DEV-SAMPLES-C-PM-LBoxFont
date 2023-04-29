#define INCL_WIN

#include <os2.h>
#include <stddef.h>
#include "APP.h"
#include <string.h>

extern HWND hwndList;
int index2;
char szEdit[256] = "This is a test";
char temp[15];

MRESULT EXPENTRY APPCommand( hWnd, message, mp1, mp2 )
HWND    hWnd;
ULONG  message;
MPARAM  mp1;
MPARAM  mp2;
{


		    index2 = strlen ("Window") + 1;
		    strncpy (temp, "Window", index2);
		    temp [index2] = '\0';
		    WinSendMsg (hwndList, LM_INSERTITEM, MPFROM2SHORT (LIT_SORTASCENDING, 0),
				MPFROMP (temp));
		    index2 = strlen ("PM Land") + 1;
		    strncpy (temp, "PM Land", index2);
		    temp [index2] = '\0';

		    WinSendMsg (hwndList, LM_INSERTITEM, MPFROM2SHORT (LIT_SORTASCENDING, 0),
				MPFROMP (temp));

		   return (0);


}
/*
*/


MRESULT EXPENTRY About( hWndDlg, message, mp1, mp2 )
HWND    hWndDlg;
ULONG  message;
MPARAM  mp1;
MPARAM  mp2;
{
    switch( message )
    {
      case WM_COMMAND:
        switch( LOUSHORT( mp1 ) )
        {
          case DID_OK:
            WinDismissDlg( hWndDlg, TRUE );
            break;

          default:
            break;
        }
        break;

      default:
	return WinDefDlgProc( hWndDlg, message, mp1, mp2 );
    }
    return FALSE;
}
/*
*/

MRESULT EXPENTRY EditDlg( hWndDlg, message, mp1, mp2 )
HWND    hWndDlg;
ULONG  message;
MPARAM  mp1;
MPARAM  mp2;
{
    switch( message )
    {
      case WM_INITDLG:
	  WinSetDlgItemText( hWndDlg, IDEDIT, (PCSZ) szEdit );
          break;

      case WM_COMMAND:
          switch( LOUSHORT( mp1 ) ) {
              case DID_OK:
		  WinQueryDlgItemText( hWndDlg, IDEDIT, 256, (PSZ) szEdit );
                  WinDismissDlg( hWndDlg, TRUE );
                  break;

              case DID_CANCEL:
                  WinDismissDlg( hWndDlg, FALSE );
                  break;

              default:
                  break;
          }
          break;

      default:
        return( WinDefDlgProc( hWndDlg, message, mp1, mp2 ) );
    }
    return FALSE;
}
/*
*/
