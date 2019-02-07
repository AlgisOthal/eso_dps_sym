#include "base_skill.h"

#include <iostream>

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
