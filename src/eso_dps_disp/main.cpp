#include <iostream>

#include <eso_dps_sym/char_attributes.h>

#include "defines.h"

int main()
{
    using namespace std;

    CharAttributes attrs = init_attrs;
    cout << attrs << endl;

    return 0;
}
