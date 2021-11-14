#pragma once

class Graphical {
	public:

		
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
		double ShowBox(LPCTSTR Message, LPCTSTR Caption, UINT Type);


};