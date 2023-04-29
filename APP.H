/* String table constants */
#define IDSNAME         1
#define IDSKIDNAME	2

/* Resource Ids */
#define ID_APP          1
#define IDD_ABOUT       2
#define IDD_INPUT       3

/* Menu constants */
#define IDITEM          1001
#define IDENTER         1002
#define IDABOUT         1006

/* Input Dialog Box */
#define IDEDIT          300

/*control ID*/
#define LID_LIST1	30

/* Function prototypes */
int _cdecl main                 ( void );
MRESULT EXPENTRY APPWndProc	(HWND hwnd, ULONG msg, MPARAM mp1, MPARAM mp2);
MRESULT EXPENTRY KidWndProc	 (HWND hwnd, ULONG msg, MPARAM mp1, MPARAM mp2);
VOID    EXPENTRY APPPaint    (HWND hwnd, ULONG msg, MPARAM mp1, MPARAM mp2);
MRESULT EXPENTRY APPCommand	 (HWND hwnd, ULONG msg, MPARAM mp1, MPARAM mp2);
MRESULT EXPENTRY About	 (HWND hwnd, ULONG msg, MPARAM mp1, MPARAM mp2);
MRESULT EXPENTRY EditDlg	(HWND hwnd, ULONG msg, MPARAM mp1, MPARAM mp2);
