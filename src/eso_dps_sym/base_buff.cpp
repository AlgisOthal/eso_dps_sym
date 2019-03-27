#include "base_buff.h"

#include <iostream>

BaseBuffFabric &BaseBuffFabric::inst()
{
    static BaseBuffFabric fabric;
    return fabric;
}

BaseBuffPtr BaseBuffFabric::createByType(BuffType type)
{
    using namespace std;

    if( !_buffs.count( type ))
    {
        cerr << "Wrong skill" << endl;
        return nullptr;
    }

    return _buffs[ type ]();
}

void BaseBuffFabric::registerBuff(BuffType type, CreateBuff func)
{
    _buffs[ type ] = func;
}
