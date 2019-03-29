#ifndef BASE_BUFF_H
#define BASE_BUFF_H

#include <inttypes.h>
#include <memory>
#include <map>

#include "enum.h"
#include "char_attributes.h"

DECLARE_ENUM( BuffType, resolve, blockade )

struct BuffWithTime
{
    BuffType buff;
    uint64_t time;
};
typedef std::vector< BuffWithTime > BuffWithTimes;

class BaseBuff
{
public:
    BaseBuff( uint64_t time_ ):
        time( time_ )
    {}

    virtual void processAttr( CharAttributes& attrs ){}

    uint64_t time;
};
typedef std::shared_ptr< BaseBuff > BaseBuffPtr;

//------------------

typedef std::function< BaseBuffPtr() > CreateBuff;
class BaseBuffFabric
{
public:
    static BaseBuffFabric& inst();

    BaseBuffPtr createByType( BuffType type );
    void registerBuff( BuffType type, CreateBuff func );

private:
    std::map< BuffType, CreateBuff > _buffs;
};

template< typename Buff >
class RegistratorBuff
{
public:
    RegistratorBuff( BuffType type )
    {
        BaseBuffFabric::inst().
                registerBuff( type,
                               [](){ return BaseBuffPtr( new Buff() ); } );
    }
};

#define REGISTER_BUFF( type, buff ) \
    RegistratorBuff<buff> buff ## _reg( type )

#endif // BASE_BUFF_H
