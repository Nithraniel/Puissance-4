#include <stdio.h>
#include <stdlib.h>
#include "engine.h"

int main()
{
    // Création de la fenêtre
    sfVideoMode mode = {800, 600, 32};
    sfRenderWindow* window = sfRenderWindow_create(mode, "P4 : Royal Rotation", sfResize | sfClose, NULL);
    sfRenderWindow_setFramerateLimit(window,60);

    int startgame=0,choice=0,tmp=0;
    menustruct title,curseur,game;
    textestruct textmenu, titlemenu, Subtitle, AI, Duel, BR;
    init_menu(&title,&textmenu, &titlemenu, &Subtitle, &AI, &Duel, &BR,&curseur);

    init_game(&game);

    while(sfRenderWindow_isOpen(window))
    {
        sfRenderWindow_clear(window,sfBlack);

        tmp=checkKeyboard(window);
        if(tmp == 5) startgame = 1;
        if(tmp == 6) startgame = 0;
    	sfVector2f tmpPosCursor = sfSprite_getPosition(curseur.spritemenu);
        if(tmp == 4 && tmpPosCursor.y <= 360)
        {
        	tmpPosCursor.y+= 40;
            sfSprite_setPosition(curseur.spritemenu, tmpPosCursor);
        }
        if(tmp == 3 && tmpPosCursor.y >= 320){
        	tmpPosCursor.y-= 40;
            sfSprite_setPosition(curseur.spritemenu, tmpPosCursor);
        }


        switch(choice)
        {
        case 0:     // Menu
            engine_menu(window,&title,&textmenu,&titlemenu,&Subtitle,&AI,&Duel,&BR,startgame,&curseur);
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
