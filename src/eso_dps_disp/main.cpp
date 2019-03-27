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
    rotation.skillAndWait( SkillType::resolve, 0 );
    rotation.laAndSkill( SkillType::twisting_path );
    rotation.laAndSkill( SkillType::swallow );
    rotation.laAndSkill( SkillType::swallow );
    rotation.laAndSkill( SkillType::swallow );
    rotation.laAndSkill( SkillType::twisting_path );

    rotation.laAndSkill( SkillType::swallow, 20000 );

    DpsSym sym;
    sym.prepare( rotation );
    TakenDamages dmg = sym.symulate( attrs );

    return 0;
}
