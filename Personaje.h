#ifndef PERSONAJE_H
#define PERSONAJE_H

class Personaje
{
public:
    Personaje(int x, int y);
    void manejar_eventos();
        virtual ~Personaje();

protected:

private:
    SDL_Rect frame;
    SDL_Rect offset;
    bool modoFantasma;
};

Personaje::Personaje(int X=0, int Y=0)
{
    offset.x = X;
    offset.y = Y;

    frame.x = 0;
    frame.y = 0;
    frame.w = 144;
    frame.h = 192;

    modoFantasma = false;
}

Personaje::~Personaje()
{

}

void Personaje::manejar_eventos()
{
    if( event.type == SDL_MOUSEMOTION )
    {
        offset.x = event.motion.x - frame.w/2;
        offset.y = event.motion.y - frame.h/2;
        if(offset.x < 0)
            offset.x = 0;
        if(offset.y < 0)
            offset.y = 0;
    }

    if( event.type == SDL_KEYDOWN )
    {
        switch(event.key.keysym.sym)
        {
        case SDLK_w:
        case SDLK_UP:
        {
            frame.y = 3 * frame.h;
            offset.y -= largoPasos;
            frameActual++;
            if(frameActual>maxFrame)
            {
                frameActual = 0;
            }
            frame.x = frameActual*frame.w;
        }break;
        case SDLK_a:
        case SDLK_LEFT:
        {
            frame.y = 1 * frame.h;
            offset.x -= largoPasos;
            frameActual++;
            if(frameActual>maxFrame)
            {
                frameActual = 0;
            }
            frame.x = frameActual*frame.w;
        }break;
        case SDLK_s:
        case SDLK_DOWN:
        {

            frame.y = 0 * frame.h;
            if(offset.y<(altoPantalla-frame.h))
            {
                offset.y += largoPasos;
            }
            frameActual++;
            if(frameActual>maxFrame)
            {
                frameActual = 0;
            }
            frame.x = frameActual*frame.w;
        }break;
        case SDLK_d:
        case SDLK_RIGHT:
        {
            frame.y = 2 * frame.h;
            if(offset.x<(anchoPantalla-frame.w+10))
            {
                offset.x += largoPasos;
            }
            frameActual++;
            if(frameActual>maxFrame)
            {
                frameActual = 0;
            }
            frame.x = frameActual*frame.w;
        }break;
        case SDLK_TAB:
        {
            if( modoFantasma == false)
            {
                SDL_SetAlpha(image, SDL_SRCALPHA, 100);
                modoFantasma = true;
            }
            else
            {
                SDL_SetAlpha(image, SDL_SRCALPHA, 255);
                modoFantasma = false;
            }
        }break;
        default:
        {}
        }//Fin switch

    }//Fin if

    SDL_BlitSurface(image, &frame, screen, &offset);

}//Fin funcion



#endif // PERSONAJE_H
