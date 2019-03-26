#ifndef CHAR_ATTRIBUTES_H
#define CHAR_ATTRIBUTES_H

#include <inttypes.h>
#include <iostream>

class CharAttributes
{
public:
    uint32_t penetration;
    uint32_t damage;
    uint32_t crit_chance; // %
    uint32_t crit_damage; // %
    uint32_t base_resource;
    uint32_t current_resource;
    uint32_t regen_resource; // per 2 sec
    uint32_t damage_done_buff;
};
std::ostream& operator<<( std::ostream& s, CharAttributes& a );

#endif // CHAR_ATTRIBUTES_H
