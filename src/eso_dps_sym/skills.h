#ifndef SKILLS_H
#define SKILLS_H

#include "base_skill.h"

class LightAttak: public BaseSkill
{
    uint32_t damage() override;
};

#endif // SKILLS_H
