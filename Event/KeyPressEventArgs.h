#ifndef __OSHGUI_KEYPRESSEVENTARGS_H__
#define __OSHGUI_KEYPRESSEVENTARGS_H__

#include "Misc\String.h"
#include "KeyBoardEvent."

namespace OSHGui
{
	/**
	 * Stellt Daten f�r das KeyPressEvent bereit.
	 */
	class KeyPressEventArgs
	{
	public:	
		Misc::UnicodeChar KeyChar;
		bool Handled;
		
	public:
		KeyPressEventArgs(KeyboardEvent *keyboardEvent)
		{
			KeyChar = keyboardEvent->KeyChar;
			Handled = false;
		}
	};
}

#endif