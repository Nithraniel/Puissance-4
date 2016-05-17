#include "input.h"
#include <windows.h>


typedef struct{
    sfText* objet;
    sfVector2f position;
} textestruct;

typedef struct{
    sfTexture* texturemenu;
    sfSprite* spritemenu;
    sfFont* font;
    sfFont* titlefont;
}menustruct;

typedef struct{
	sfRectangleShape* rect;
	sfVector2f position;

}rectanglestruct;

textestruct init_texte(menustruct* menu, sfFont *font, int size, sfColor color);
void init_menu(menustruct *menu, textestruct *Press, textestruct *titlemenu, textestruct *AI, textestruct *Duel, textestruct *BR, menustruct *curseur);
void engine_menu(sfRenderWindow* win, menustruct *menu, textestruct *Press, textestruct *titlemenu, textestruct *AI, textestruct *Duel, textestruct *BR, int startgame, menustruct *curseur);
void init_game(menustruct *game);
void engine_game(sfRenderWindow* win, menustruct* game);
