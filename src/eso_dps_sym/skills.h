#ifndef SKILLS_H
#define SKILLS_H

#include "base_skill.h"

// WARNING Coof from
// https://esoitem.uesp.net/viewSkillCoef.php

class LightAttack: public BaseSkill
{
public:
    LightAttack():
        // $1 = 0.0449528 Magicka + 0.47223 SD - 0.210105
        // (Magicka, R2 = 0.999998, ratio = 10.51)
        BaseSkill( 0.0449528, 0.47223, -0.210105 )
    {}
};

class SwallowSoul: public BaseSkill
{
public:
    SwallowSoul():
        // $1 = 0.0960378 Magicka + 1.00807 SD + 2.18394
        // (Magicka, R2 = 0.999999, ratio = 10.50)
        BaseSkill( 0.0960378, 1.00807, 2.18394, 2430 )
    {}
};

#endif // SKILLS_H
