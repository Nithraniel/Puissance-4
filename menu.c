#include "menu.h"

textestruct init_texte(menustruct* menu, sfFont *font,int size, sfColor color)
{
    //textestruct *texte = malloc(sizeof(*texte));
    textestruct texte;
    texte.objet = sfText_create();
    sfText_setFont(texte.objet,font);
    sfText_setCharacterSize(texte.objet,size);
    sfText_setColor(texte.objet,color);
    sfText_setPosition(texte.objet,texte.position);
    return texte;
}

void init_menu(menustruct *menu, textestruct *Press, textestruct *titlemenu, textestruct *AI, textestruct *Duel, textestruct *BR)
{
    // Chargement du Background
    menu->texturemenu = sfTexture_createFromFile("wood.jpg", NULL);
    if (!menu->texturemenu)printf("Texture Error");
    menu->spritemenu = sfSprite_create();
    sfSprite_setTexture(menu->spritemenu, menu->texturemenu, sfTrue);
    sfVector2f posBG;
    posBG.x = 0;
    posBG.y = 0;
    sfSprite_setPosition(menu->spritemenu,posBG);

    // Ajout de la police d'écriture
    menu->titlefont = sfFont_createFromFile("Optimus.ttf");
    menu->font = sfFont_createFromFile("arial.ttf");
    if (!menu->font || !menu->titlefont)printf("Font Error");

    // Initialisation des textes
    *titlemenu = init_texte(menu,menu->titlefont,80,sfBlack);
    *Press = init_texte(menu,menu->font,30,sfBlack);
    *AI = init_texte(menu,menu->font,30,sfBlack);
    *Duel = init_texte(menu,menu->font,30,sfBlack);
    *BR = init_texte(menu,menu->font,30,sfBlack);


    sfVector2f posTitle;
    posTitle.x = 220;
    posTitle.y = 150;

    sfVector2f posPress;
    posPress.x = 270;
    posPress.y = 300;

    sfVector2f posAI;
    posAI.x = 300;
    posAI.y = 300;

    sfVector2f posDuel;
    posDuel.x = 300;
    posDuel.y = 340;

    sfVector2f posBR;
    posBR.x = 300;
    posBR.y = 380;

    sfText_setString(titlemenu->objet,"Puissance 4");
    sfText_setPosition(titlemenu->objet,posTitle);

    sfText_setString(Press->objet,"Press start to play");
    sfText_setPosition(Press->objet,posPress);


    sfText_setString(AI->objet,"P1 VS AI");
    sfText_setPosition(AI->objet,posAI);

    sfText_setString(Duel->objet,"Duel");
    sfText_setPosition(Duel->objet,posDuel);

    sfText_setString(BR->objet,"Battle Royale");
    sfText_setPosition(BR->objet,posBR);

}

void engine_menu(sfRenderWindow* win, menustruct *menu, textestruct *Press, textestruct *titlemenu, textestruct *AI, textestruct *Duel, textestruct *BR, int startgame)
{
    sfRenderWindow_drawSprite(win,menu->spritemenu,NULL);
    sfRenderWindow_drawText(win,titlemenu->objet,NULL);
    if (!startgame) sfRenderWindow_drawText(win,Press->objet,NULL);
    else{
        sfRenderWindow_drawText(win,AI->objet,NULL);
        sfRenderWindow_drawText(win,Duel->objet,NULL);
        sfRenderWindow_drawText(win,BR->objet,NULL);
    }
}

