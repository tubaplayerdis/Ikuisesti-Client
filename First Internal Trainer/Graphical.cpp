#include "pch.h"
#include "Graphical.h"
#include <WinUser.h>




/*
* Return Values
* 0 = No
* 1 = Yes
* 1.1 = Abort
* 1.2 = Retry
* 1.3 = Ignore
* 1.4 = Cancel
* 1.5 = TryAgain
* 1.6 = Continue
* 1.7 = Help
* 1.8 = OK
* 1.9 = ClosedBox
* 2 = broken
*/
double Graphical::ShowBox(LPCTSTR Message, LPCTSTR Caption, UINT Type) {
	switch (Type)
	{		
		case MB_ABORTRETRYIGNORE: {
			switch (MessageBox(NULL, Message, Caption, Type))
			{
				case IDABORT: {
					return 1.1;
				}

				case IDRETRY: {
					return 1.2;
				}

				case IDIGNORE: {
					return 1.3;
				}

				default: return 1.9;
			}
		}

		case MB_CANCELTRYCONTINUE: {
			switch (MessageBox(NULL, Message, Caption, Type))
			{
				case IDCANCEL: {
					return 1.4;
				}

				case IDTRYAGAIN: {
					return 1.5;
				}

				case IDCONTINUE: {
					return 1.6;
				}

				default: return 1.9;
			}
		}

		case MB_HELP: {
			if (MessageBox(NULL, Message, Caption, Type) == IDHELP) {
				return 1.7;
			}
			else return 1.9;
		}

		case MB_OK: {
			if (MessageBox(NULL, Message, Caption, Type) == IDHELP) {
				return 1.8;
			}
			else return 1.9;
		}

		case MB_OKCANCEL: {
			switch (MessageBox(NULL, Message, Caption, Type))
			{
				case IDOK: {
					return 1.8;
				}

				case IDCANCEL: {
					return 1.4;
				}

				default: return 1.9;
			}
		}

		case MB_RETRYCANCEL: {
			switch (MessageBox(NULL, Message, Caption, Type))
			{
				case IDRETRY: {
					return 1.2;
				}

				case IDCANCEL: {
					return 1.4;
				}

				default: return 1.9;

			}
		}

		case MB_YESNO: {
			switch (MessageBox(NULL, Message, Caption, Type))
			{
				case IDYES: {
					return 1;
				}

				case IDNO: {
					return 0;
				}

				default: return 1.9;
			}
		}

		case MB_YESNOCANCEL: {
			switch (MessageBox(NULL, Message, Caption, Type))
			{
				case IDYES: {
					return 1;
				}

				case IDNO: {
					return 0;
				}

				case IDCANCEL: {
					return 1.4;
				}
				default: return 1.9;
			}
		}

		default: return 2;
	}
}

