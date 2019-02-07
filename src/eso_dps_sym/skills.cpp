#include "skills.h"

REGISTER_SKILL( SkillType::la, LightAttak );

uint32_t LightAttak::damage()
{
    return 23000;
}
