#include "char_attributes.h"

std::ostream &operator<<(std::ostream &s, CharAttributes &a)
{
    // TODO write attrs
    s << "(pen - " << a.penetration << "), "
      << "(dam - " << a.damage << ')';

    return s;
}
