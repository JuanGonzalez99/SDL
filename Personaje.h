#ifndef PERSONAJE_H
#define PERSONAJE_H

class Personaje
{
public:
    Personaje(int x, int y);
    bool getModoFantasma();
    void setModoFantasma(bool);
    SDL_Rect getOffset();
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
    frame.w = anchoFrame;
    frame.h = altoFrame;

    modoFantasma = false;
}

bool Personaje::getModoFantasma()
{
    return modoFantasma;
}

void Personaje::setModoFantasma(bool b)
{
    modoFantasma = b;
}

SDL_Rect Personaje::getOffset()
{
    return offset;
}

Personaje::~Personaje()
{

}

void Personaje::manejar_eventos()
{
    //Si apreta el click izquierdo
    if( event.type == SDL_MOUSEBUTTONDOWN && event.button.button == SDL_BUTTON_LEFT )
    {
        int x = event.button.x;
        int y = event.button.y;

        //Si lo apretó en la imagen
        if( x >= offset.x && x <= (offset.x + frame.w) &&
            y >= offset.y && y <= (offset.y + frame.h) )
        {
            arrastrarPersonaje = true;
        }
    }

    //Si suelta el click izquierdo
    if( event.type == SDL_MOUSEBUTTONUP && event.button.button == SDL_BUTTON_LEFT )
        arrastrarPersonaje = false;

    //Si mueve el mouse mientras está haciendo click sobre la imagen
    if( event.type == SDL_MOUSEMOTION && arrastrarPersonaje )
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
            //Cambio de frame de direccion
            frame.y = 3 * frame.h;

            //Desplazamiento del personaje
            offset.y -= largoPasos;
            if( offset.y < largoPasos )
                offset.y = 0;

            //Cambio de frame de movimiento
            frameActual++;
            if(frameActual>maxFrame)
                frameActual = 0;
            frame.x = frameActual*frame.w;
        }break;
        case SDLK_a:
        case SDLK_LEFT:
        {
            frame.y = 1 * frame.h;

            offset.x -= largoPasos;
            if( offset.x < largoPasos )
                offset.x = 0;

            frameActual++;
            if(frameActual>maxFrame)
                frameActual = 0;
            frame.x = frameActual*frame.w;
        }break;
        case SDLK_s:
        case SDLK_DOWN:
        {
            frame.y = 0 * frame.h;

            offset.y += largoPasos;
            if( offset.y > altoPantalla - frame.h )
                offset.y = altoPantalla - frame.h;

            frameActual++;
            if(frameActual>maxFrame)
                frameActual = 0;
            frame.x = frameActual*frame.w;
        }break;
        case SDLK_d:
        case SDLK_RIGHT:
        {
            frame.y = 2 * frame.h;

            offset.x += largoPasos;
            if( offset.x > anchoPantalla- frame.w )
                offset.x = anchoPantalla - frame.w;

            frameActual++;
            if(frameActual>maxFrame)
                frameActual = 0;
            frame.x = frameActual*frame.w;
        }break;
        case SDLK_TAB:
        {
            if( getModoFantasma() == false )
            {
                SDL_SetAlpha(image, SDL_SRCALPHA, 100);
                setModoFantasma(true);
            }
            else
            {
                SDL_SetAlpha(image, SDL_SRCALPHA, 255);
                setModoFantasma(false);
            }
        }break;
        default:
        {}
        }//Fin switch

    }//Fin if

    SDL_BlitSurface(image, &frame, screen, &offset);

}//Fin funcion



#endif // PERSONAJE_H
