#include <stdio.h>
#include <stdlib.h>
#include "menu.h"

int main()
{
    // Création de la fenêtre
    sfVideoMode mode = {800, 600, 32};
    sfRenderWindow* window = sfRenderWindow_create(mode, "Puissance 4 Evolved", sfResize | sfClose, NULL);
    sfRenderWindow_setFramerateLimit(window,60);

    int startgame=0,choice=0;
    int tmp;
    menustruct title;
    textestruct textmenu, titlemenu, AI, Duel, BR;
    init_menu(&title,&textmenu, &titlemenu, &AI, &Duel, &BR);

    while(sfRenderWindow_isOpen(window))
    {
        sfRenderWindow_clear(window,sfBlack);

        tmp=checkKeyboard(window);
        if(tmp == 5) startgame = 1;
        if(tmp == 6) startgame = 0;

        switch(choice)
        {
        case 0:     // Menu
            engine_menu(window,&title,&textmenu,&titlemenu,&AI,&Duel,&BR,startgame);
            break;

        case 1:     // P1 VS IA

            break;

        case 2:     // P1 VS P2

            break;

        case 3:     // P1 VS P2 VS P3

            break;
        default:
            break;
        }

        sfRenderWindow_display(window);
    }

    sfSprite_destroy(title.spritemenu);
    sfTexture_destroy(title.texturemenu);
    sfFont_destroy(title.font);
    return 0;
}
