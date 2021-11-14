#include "pch.h"
#include "Graphical.h"
#include <WinUser.h>





float Graphical::ShowBox(LPCTSTR Message, LPCTSTR Caption, UINT Type) {
	switch (Type)
	{		
		case MB_ABORTRETRYIGNORE: {
			switch (MessageBox(NULL, Message, Caption, Type))
			{
				case IDABORT: {

				}

				case IDRETRY: {

				}

				case IDIGNORE: {

				}
			}
		}

		case MB_CANCELTRYCONTINUE: {

		}

		case MB_HELP: {

		}

		case MB_OK: {

		}

		case MB_OKCANCEL: {

		}

		case MB_RETRYCANCEL: {

		}

		case MB_YESNO: {

		}

		case MB_YESNOCANCEL: {

		}
	}
}

