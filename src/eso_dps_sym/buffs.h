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

#endif // BUFFS_H
