#include <iostream>

#include <eso_dps_sym/char_attributes.h>
#include <eso_dps_sym/rotation_prepare.h>
#include <eso_dps_sym/dps_sym.h>

#include "defines.h"

int main()
{
    using namespace std;

    CharAttributes attrs = init_attrs;
    cout << attrs << endl;

    RotationPrepare rotation;
    rotation.laAndSkill( SkillType::swallow, 1000 );
    rotation.laAndSkill( SkillType::swallow, 1000 );
    rotation.laAndSkill( SkillType::swallow, 1000 );

    DpsSym sym;
    sym.prepare( rotation );
    TakenDamages dmg = sym.symulate( attrs );

    return 0;
}
