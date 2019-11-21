#include "extension.h"
#include "eiface.h"

ArmsFix g_ArmsFix;
SMEXT_LINK(&g_ArmsFix);

//IVEngineServer *engine = NULL;

SH_DECL_HOOK2(IVEngineServer, PrecacheModel, SH_NOATTRIB, 0, int, const char *, bool);

int ArmsFix::PrecacheModel(const char *model, bool precache)
{
    if (V_strncmp(model, "models/weapons/v_models/arms/glove_hardknuckle/", 47) == 0)
    {
        // block
        RETURN_META_VALUE(MRES_SUPERCEDE, 0);
    }

    RETURN_META_VALUE(MRES_IGNORED, 0);
}

bool ArmsFix::SDK_OnLoad(char *error, size_t maxlength, bool late)
{
    smutils->LogMessage(myself, "Init...");
    return true;
}

void ArmsFix::SDK_OnUnload()
{
    SH_REMOVE_HOOK(IVEngineServer, PrecacheModel, engine, SH_MEMBER(this, &ArmsFix::PrecacheModel), false);
}

bool ArmsFix::SDK_OnMetamodLoad(ISmmAPI *ismm, char *error, size_t maxlen, bool late)
{
    GET_V_IFACE_CURRENT(GetEngineFactory, engine, IVEngineServer, INTERFACEVERSION_VENGINESERVER);
    SH_ADD_HOOK(IVEngineServer, PrecacheModel, engine, SH_MEMBER(this, &ArmsFix::PrecacheModel), false);

    return true;
}