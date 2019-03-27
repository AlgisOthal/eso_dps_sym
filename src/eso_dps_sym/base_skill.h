#ifndef BASE_SKILL_H
#define BASE_SKILL_H

#include <inttypes.h>
#include <memory>
#include <map>

#include "enum.h"
#include "char_attributes.h"
#include "base_buff.h"

DECLARE_ENUM( SkillType, la, swallow,
              twisting_path, twisting_path_dot,
              resolve )

struct SkillWithTime
{
    SkillType skill;
    uint64_t time;
};
typedef std::vector< SkillWithTime > SkillWithTimes;

class BaseSkill
{
public:
    virtual uint32_t damage( CharAttributes& attrs );

    virtual SkillType typeOfDot(){ return SkillType::Undefine; }
    virtual SkillWithTimes createDot(){ return SkillWithTimes(); }
    virtual bool hasCrititcal(){ return true; }
    virtual BuffType createBuff(){ return BuffType::Undefine; }

    BaseSkill(){}
    BaseSkill( double a_, double b_, double c_, uint64_t cost_ = 0 ):
        a( a_ ), b( b_ ), c( c_ ), cost( cost_ )
    {}

protected:
    double a;
    double b;
    double c;

    uint64_t cost;
};
typedef std::shared_ptr< BaseSkill > BaseSkillPtr;

//------------------

typedef std::function< BaseSkillPtr() > CreateSkill;
class BaseSkillFabric
{
public:
    static BaseSkillFabric& inst();

    BaseSkillPtr createByType( SkillType type );
    void registerSkill( SkillType type, CreateSkill func );

private:
    std::map< SkillType, CreateSkill > _skills;
};

template< typename Skill >
class Registrator
{
public:
    Registrator( SkillType type )
    {
        BaseSkillFabric::inst().
                registerSkill( type,
                               [](){ return BaseSkillPtr( new Skill() ); } );
    }
};

#define REGISTER_SKILL( type, skill ) \
    Registrator<skill> skill ## _reg( type )

#endif // BASE_SKILL_H
