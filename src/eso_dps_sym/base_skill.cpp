#include "base_skill.h"

#include <iostream>

uint32_t BaseSkill::damage( CharAttributes &attrs )
{
    uint64_t damage =
            ( a * attrs.base_resource + b * attrs.damage + c )
            * ( 1 + ( attrs.damage_done_buff ) * 0.01 );

    if( hasCrititcal() )
        damage *= ( 1 + attrs.crit_chance * 0.01 * attrs.crit_damage * 0.01 );

    attrs.current_resource -= cost;

    return damage;
}

//----------------------------

BaseSkillFabric& BaseSkillFabric::inst()
{
    static BaseSkillFabric fabric;
    return fabric;
}

BaseSkillPtr BaseSkillFabric::createByType(SkillType type)
{
    using namespace std;

    if( !_skills.count( type ))
    {
        cerr << "Wrong skill" << endl;
        return nullptr;
    }

    return _skills[ type ]();
}

void BaseSkillFabric::registerSkill(SkillType type, CreateSkill func)
{
    _skills[ type ] = func;
}
