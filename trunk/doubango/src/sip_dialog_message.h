/****************************************************************************
			 _             _                             
			| |           | |                            
		  _ | | ___  _   _| | _   ____ ____   ____  ___  
		 / || |/ _ \| | | | || \ / _  |  _ \ / _  |/ _ \ 
		( (_| | |_| | |_| | |_) | ( | | | | ( ( | | |_| |
		 \____|\___/ \____|____/ \_||_|_| |_|\_|| |\___/ 
											(_____|   
	
	Copyright (C) 2009 xxxyyyzzz <imsframework(at)gmail.com>

	This file is part of Open Source Doubango IMS Client Framework project.

    DOUBANGO is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.
	
    DOUBANGO is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU Lesser General Public License for more details.
	
    You should have received a copy of the GNU General Public License
    along with DOUBANGO.
****************************************************************************/

#ifndef __DOUBANGO_DIALOG_MESSAGE_SM_H__
#define __DOUBANGO_DIALOG_MESSAGE_SM_H__

#include "pref.h"
#include "sip_dialog.h"
#include "sm_dialog_message_sm.h"

PREF_NAMESPACE_START

/* MESSAGE */
class DOUBANGO_API sip_dialog_message : public sip_dialog
{
public:
	sip_dialog_message(stack* stk, const char* dest_address, const char* content_type, const char* content);
	~sip_dialog_message();

	/* sip_dialog override*/
	ERR Start();
	ERR Stop();
	void OnStateChanged(SIP_STATE state);
	inline const char* get_sipmethod()const;
	inline bool get_terminated()const;
	void dialog_callback(nua_event_t event,
			       int status, char const *phrase,
			       nua_t *nua, nua_magic_t *magic,
			       nua_handle_t *nh, nua_hmagic_t *hmagic,
			       sip_t const *sip,
			       tagi_t tags[]);

private:
	sip_dialog_messageContext sm_ctx;
	ERR sendMessage();

	char* dest_address;
	char* content_type;
	char* content;
};

PREF_NAMESPACE_END

#endif /* __DOUBANGO_DIALOG_MESSAGE_SM_H__ */