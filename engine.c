#include "engine.h"

textestruct init_texte(menustruct* menu, sfFont *font,int size, sfColor color)
{
    textestruct texte;
    texte.objet = sfText_create();
    sfText_setFont(texte.objet,font);
    sfText_setCharacterSize(texte.objet,size);
    sfText_setColor(texte.objet,color);
    sfText_setPosition(texte.objet,texte.position);
    return texte;
}

void init_menu(menustruct *menu, textestruct *Press, textestruct *titlemenu, textestruct *Subtitle, textestruct *AI, textestruct *Duel, textestruct *BR, menustruct *curseur)
{
    // Chargement du Background
    menu->texturemenu = sfTexture_createFromFile("img/wood.jpg", NULL);
    menu->spritemenu = sfSprite_create();
    sfSprite_setTexture(menu->spritemenu, menu->texturemenu, sfTrue);
    sfVector2f posBG;
    posBG.x = 0;
    posBG.y = 0;
    sfSprite_setPosition(menu->spritemenu,posBG);

    // Création du curseur
    curseur->texturemenu = sfTexture_createFromFile("img/triangle.png", NULL);
    //if (!curseur->texturemenu)printf("Texture Error");
    curseur->spritemenu = sfSprite_create();
    sfSprite_setTexture(curseur->spritemenu, curseur->texturemenu, sfTrue);
    sfVector2f posCurseur;
    posCurseur.x = 250;
    posCurseur.y = 305;
    sfSprite_setPosition(curseur->spritemenu,posCurseur);

    // Ajout de la police d'écriture
    menu->titlefont = sfFont_createFromFile("fonts/Optimus.ttf");
    menu->font = sfFont_createFromFile("fonts/arial.ttf");
    //if (!menu->font || !menu->titlefont)printf("Font Error");

    // Initialisation des textes
    *titlemenu = init_texte(menu,menu->titlefont,80,sfBlack);
    *Subtitle = init_texte(menu,menu->titlefont,50,sfBlack);
    *Press = init_texte(menu,menu->font,30,sfBlack);
    *AI = init_texte(menu,menu->font,30,sfBlack);
    *Duel = init_texte(menu,menu->font,30,sfBlack);
    *BR = init_texte(menu,menu->font,30,sfBlack);


    sfVector2f posTitle;
    posTitle.x = 220;
    posTitle.y = 120;

    sfVector2f posSubtitle;
    posSubtitle.x = 240;
    posSubtitle.y = 200;

    sfVector2f posPress;
    posPress.x = 270;
    posPress.y = 310;

    sfVector2f posAI;
    posAI.x = 300;
    posAI.y = 310;

    sfVector2f posDuel;
    posDuel.x = 300;
    posDuel.y = 350;

    sfVector2f posBR;
    posBR.x = 300;
    posBR.y = 390;

    sfText_setString(titlemenu->objet,"Puissance 4");
    sfText_setPosition(titlemenu->objet,posTitle);

    sfText_setString(Subtitle->objet,"Royal Rotation");
    sfText_setPosition(Subtitle->objet,posSubtitle);

    sfText_setString(Press->objet,"Press start to play");
    sfText_setPosition(Press->objet,posPress);

    sfText_setString(AI->objet,"P1 VS AI");
    sfText_setPosition(AI->objet,posAI);

    sfText_setString(Duel->objet,"Duel");
    sfText_setPosition(Duel->objet,posDuel);

    sfText_setString(BR->objet,"Battle Royale");
    sfText_setPosition(BR->objet,posBR);
}

void engine_menu(sfRenderWindow* win, menustruct *menu, textestruct *Press, textestruct *titlemenu, textestruct *Subtitle, textestruct *AI, textestruct *Duel, textestruct *BR, int startgame, menustruct *curseur)
{
    sfRenderWindow_drawSprite(win,menu->spritemenu,NULL);
    sfRenderWindow_drawText(win,titlemenu->objet,NULL);
    sfRenderWindow_drawText(win,Subtitle->objet,NULL);
    if (!startgame) sfRenderWindow_drawText(win,Press->objet,NULL);
    else{
        sfRenderWindow_drawText(win,AI->objet,NULL);
        sfRenderWindow_drawText(win,Duel->objet,NULL);
        sfRenderWindow_drawText(win,BR->objet,NULL);
        sfRenderWindow_drawSprite(win,curseur->spritemenu,NULL);
    }
}

void init_game(menustruct *game)
{
	short int cpt;
	rectanglestruct** rectangle = malloc(sizeof(int*)*(lmax+1));
	for(cpt=0;cpt<lmax+1;cpt++)
	{
		rectangle = malloc(sizeof(int)*(cmax+1));
	}
	// Chargement du Background
	game->texturemenu = sfTexture_createFromFile("img/Nature.jpg", NULL);
	game->spritemenu = sfSprite_create();
	sfSprite_setTexture(game->spritemenu, game->texturemenu, sfTrue);
	sfVector2f posBG;
	posBG.x = 0;
	posBG.y = 0;
	sfSprite_setPosition(game->spritemenu,posBG);

	// Chargement du tableau
	int i,j;
    for(i=0;i<lmax;i++)
    {
        for(j=0;j<cmax;j++)
        {
            rectangle[i][j].rect = sfRectangleShape_create();
            rectangle[i][j].position.x = 0 + 24*j;
            rectangle[i][j].position.y = 0 + 24*i;
            sfRectangleShape_setPosition(rectangle[i][j].rect,rectangle[i][j].position);
        }
    }

}

void engine_game(sfRenderWindow* win, menustruct* game, rectanglestruct rectangle)
{
	sfRenderWindow_drawSprite(win,game->spritemenu,NULL);

}
