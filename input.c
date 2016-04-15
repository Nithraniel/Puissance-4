#include "input.h"

int checkKeyboard(sfRenderWindow *win){
    sfEvent Event;
    while(sfRenderWindow_pollEvent(win,&Event))
    {
        switch(Event.type)
        {
        case sfEvtClosed:
            sfRenderWindow_close(win);
            break;

        case sfEvtKeyPressed:
            switch(Event.key.code)
            {
            case sfKeyLeft:
                return MOVE_LEFT;
                break;
            case sfKeyRight:
                return MOVE_RIGHT;
                break;
            case sfKeyUp:
                return MOVE_UP;
                break;
            case sfKeyDown:
                return MOVE_DOWN;
                break;
            case sfKeyReturn:
                return MOVE_ENTER;
                break;
            case sfKeyBack:
                return MOVE_BACK;
            case sfKeyEscape:
                sfRenderWindow_close(win);
                break;
            default:
                break;
            }
            break;

        default:
            break;
        }
    }
    return 0;
}
