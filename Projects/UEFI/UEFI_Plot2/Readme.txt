Plot2UEFI

This little UEFI application show a simplified Steer Growing Simulation, like an excuse. But you can see that if you wanto (https://www.researchgate.net/publication/328416533_Deposicion_en_novillos_en_crecimiento_modelo_de_Di_Marco_et_al_1989_4_Calibracion_con_el_nuevo_novillo_de_referencia).

In this development the components used are:

PixelUEFI

    An adaptation of Pixelmap.inc, just a little part and added some extensions. 

CharsUEFI

    Extend PixelUEFI to draw a font, because without an OS you have not graphical fonts. Perhaps you can retrieve the text font, but I don't know.

GraphicUEFI

    An XYplot that show lines (only one is used, then others were erased form source code). 

IntegAsm32 Core and Test modulus

    This can make numerical integration for simulations using several methods: Timestep, Runge-Kutta, Fehlberg and Kash-Carp.

Note:

    There is some "feature" in Virtual Box and filling the background hang up, but in real UEFI is necessary to fill the background. Then there are 2 binaries attached.

Obviously, to build the application you need ObjAsm with UEFI support, SmplMath and MReal macros.