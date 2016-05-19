/*
	Copyright 2012 - Le Padellec Sylvain

   Licensed under the Apache License, Version 2.0 (the "License");
   you may not use this file except in compliance with the License.
   You may obtain a copy of the License at
       http://www.apache.org/licenses/LICENSE-2.0

   Unless required by applicable law or agreed to in writing, software
   distributed under the License is distributed on an "AS IS" BASIS,
   WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
   See the License for the specific language governing permissions and
   limitations under the License.
*/

#ifndef BADUSERCMDBLOCKER_H
#define BADUSERCMDBLOCKER_H

#include "Systems/BaseSystem.h"
#include "Players/temp_PlayerDataStruct.h"
#include "Hooks/PlayerRunCommandHookListener.h"

enum TickStatus
{
	OK = 0,
	IN_RESET,
	RESET
};

struct UserCmdInfo
{
	TickStatus m_tick_status;
	bool m_prev_dead;
	float m_detected_time;

	UserCmdInfo()
	{
		m_tick_status = IN_RESET;
		m_prev_dead = true;
		m_detected_time = 0.0;
	};
	UserCmdInfo(const UserCmdInfo& other)
	{
		m_tick_status = other.m_tick_status;
		m_prev_dead = other.m_prev_dead;
		m_detected_time = other.m_detected_time;
	};
};

class BadUserCmdBlocker :
	public BaseSystem,
	public PlayerDataStructHandler<UserCmdInfo>,
	public PlayerRunCommandHookListener
{
public:
	BadUserCmdBlocker();
	~BadUserCmdBlocker();

	void Load(),Unload(),Init();

	PlayerRunCommandRet PlayerRunCommandCallback(NczPlayer* player, SourceSdk::CUserCmd* cmd, const SourceSdk::CUserCmd& old_cmd);
};

extern BadUserCmdBlocker g_BadUserCmdBlocker;

#endif // BADUSERCMDBLOCKER_H
