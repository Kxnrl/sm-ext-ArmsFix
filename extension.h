#ifndef _A2SFIREWALL_EXTENSION_H_
#define _A2SFIREWALL_EXTENSION_H_

#include "smsdk_ext.h"

class      ArmsFix :
    public SDKExtension
{
public:

    // SDKExtension
    virtual bool SDK_OnLoad(char *error, size_t maxlength, bool late);
    virtual void SDK_OnUnload();

    // Self
    int PrecacheModel(const char *model, bool precache);

    // Metamod
    virtual bool SDK_OnMetamodLoad(ISmmAPI *ismm, char *error, size_t maxlen, bool late);
};

#endif