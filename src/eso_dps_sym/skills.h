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

class TwistingPath: public BaseSkill
{
public:
    TwistingPath():
        BaseSkill( 0, 0, 0, 3159 )
    {}

    SkillType typeOfDot(){ return SkillType::twisting_path_dot; }
    SkillWithTimes createDot();
};

class TwistingPathDot: public BaseSkill
{
public:
    TwistingPathDot():
        // $1 = 0.0212544 Magicka + 0.221895 SD - 1.64061
        // (Magicka, R2 = 0.999992, ratio = 10.44)
        BaseSkill( 0.0212544, 0.221895, -1.64061, 0 )
    {}
};

class MiracleResolve: public BaseSkill
{
public:
    MiracleResolve():
        BaseSkill( 0, 0, 0, 2430 )
    {}

    BuffType createBuff(){ return BuffType::resolve; }
};

#endif // SKILLS_H
