#ifndef BUFFS_H
#define BUFFS_H

#include "base_buff.h"

class MiracleResolveBuf: public BaseBuff
{
public:
    MiracleResolveBuf():
        BaseBuff( 20000 )
    {}

    virtual void processAttr( CharAttributes& attrs )
    {
        attrs.damage_done_buff += 8;
    }
};


class BlockadeOfFireBuf: public BaseBuff
{
public:
    BlockadeOfFireBuf():
        BaseBuff( 8000 )
    {}

    virtual void processAttr( CharAttributes& attrs )
    {
        // TODO Boost LA
    }
};

#endif // BUFFS_H
