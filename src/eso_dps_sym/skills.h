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

class Impale: public BaseSkill
{
public:
    Impale():
        // $1 = 0.0516775 Magicka + 0.540066 SD - 1.92198
        // (Magicka, R2 = 0.999999, ratio = 10.45)

        // WARNING Impale *4 gain
        BaseSkill( 0.0516775 * 4, 0.540066 * 4, -1.92198 * 4, 2188 )
    {}
};

class GrisplingGrasp: public BaseSkill
{
public:
    GrisplingGrasp():
        //$1 = 0.17572 Magicka + 1.83771 SD + 5.47429
        // (Magicka, R2 = 0.999999, ratio = 10.46)
        BaseSkill( 0.17572, 1.83771, 5.47429, 2916 )
    {}

    SkillType typeOfDot(){ return SkillType::grasp_dot; }
    SkillWithTimes createDot();
};

class GrisplingGraspDot: public BaseSkill
{
public:
    GrisplingGraspDot():
        // $2 = 0.0310979 Magicka + 0.323812 SD + 0.811595
        // (Magicka, R2 = 0.999997, ratio = 10.41)
        BaseSkill( 0.0310979, 0.323812, 0.811595, 0 )
    {}
};

class BlokadeOfFlame: public BaseSkill
{
public:
    BlokadeOfFlame():
        BaseSkill( 0, 0, 0, 2916 )
    {}

    SkillType typeOfDot(){ return SkillType::blockade_dot; }
    SkillWithTimes createDot();
    BuffType createBuff(){ return BuffType::blockade; }
};

class BlokadeOfFlameDot: public BaseSkill
{
public:
    BlokadeOfFlameDot():
        // $1 = 0.0250748 Magicka + 0.262062 SD - 1.4486
        // (Magicka, R2 = 0.999999, ratio = 10.45)
        BaseSkill( 0.0250748, 0.262062, -1.4486, 0 )
    {}
};

class SpectralBow: public BaseSkill
{
public:
    SpectralBow():
        // $1 = 0.199944 Magicka + 2.09971 SD + 3.06799
        // (Magicka, R2 = 1, ratio = 10.50)
        BaseSkill( 0.199944, 2.09971, 3.06799, 2430 / 2 )
    {}
};

#endif // SKILLS_H
