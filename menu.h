#include "input.h"
#include <windows.h>


//sfText* title;

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

textestruct init_texte(menustruct* menu, sfFont *font, int size, sfColor color);
void init_menu(menustruct *menu, textestruct *Press, textestruct *titlemenu, textestruct *AI, textestruct *Duel, textestruct *BR);
void engine_menu(sfRenderWindow* win, menustruct *menu, textestruct *Press, textestruct *titlemenu, textestruct *AI, textestruct *Duel, textestruct *BR, int startgame);
