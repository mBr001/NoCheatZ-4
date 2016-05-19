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

#ifndef _MRECIPIENT_FILTER_H
#define _MRECIPIENT_FILTER_H


#include "Interfaces/irecipientfilter.h"
#include "Containers/utlvector.h"

class MRecipientFilter : public SourceSdk::IRecipientFilter
{
public:
	MRecipientFilter(void);
    ~MRecipientFilter(void);

    virtual bool IsReliable( void ) const;
    virtual bool IsInitMessage( void ) const;

    virtual int GetRecipientCount( void ) const;
    virtual int GetRecipientIndex( int slot ) const;
    void AddAllPlayers( int maxClients );
    void AddRecipient (int iPlayer );

private:
    bool m_bReliable;
    bool m_bInitMessage;
    CUtlVector< int > m_Recipients;
};

#endif
