#ifndef PERSONAJE_H
#define PERSONAJE_H

class Personaje
{
public:
    Personaje(int x, int y);
    bool getModoFantasma();
    void setModoFantasma(bool);
    SDL_Rect getOffset();
    void cambiar_frame_movimiento();
    void manejar_eventos();
    void mover();
    void mostrar();

protected:

private:
    SDL_Rect frame;
    SDL_Rect offset;
    int xVel, yVel;
    bool arrastrar;
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

    xVel = 0;
    yVel = 0;

    arrastrar = false;
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

void Personaje::cambiar_frame_movimiento()
{
    frameActual++;
    if(frameActual>maxFrame)
        frameActual = 0;
    frame.x = frameActual*frame.w;
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
            arrastrar = true;
        }
    }

    //Si suelta el click izquierdo
    if( event.type == SDL_MOUSEBUTTONUP && event.button.button == SDL_BUTTON_LEFT )
        arrastrar = false;

    if( event.type == SDL_KEYDOWN )
    {
        switch(event.key.keysym.sym)
        {
        case SDLK_w:
        case SDLK_UP:
        {
            yVel -= largoPasos;

            cambiar_frame_movimiento();
        }break;
        case SDLK_a:
        case SDLK_LEFT:
        {
            xVel -= largoPasos;

            cambiar_frame_movimiento();
        }break;
        case SDLK_s:
        case SDLK_DOWN:
        {
            yVel += largoPasos;

            cambiar_frame_movimiento();
        }break;
        case SDLK_d:
        case SDLK_RIGHT:
        {
            xVel += largoPasos;

            cambiar_frame_movimiento();
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

    else if( event.type == SDL_KEYUP )
    {
        switch( event.key.keysym.sym )
        {
            case SDLK_w:
            case SDLK_UP:
                {
                    yVel += largoPasos;
                }break;
            case SDLK_a:
            case SDLK_LEFT:
                {
                    xVel += largoPasos;
                }break;
            case SDLK_s:
            case SDLK_DOWN:
                {
                    yVel -= largoPasos;
                }break;
            case SDLK_d:
            case SDLK_RIGHT:
                {
                    xVel -= largoPasos;
                }break;
            default: {}
        }
    }
}

void Personaje::mover()
{
    //Si mueve el mouse mientras está haciendo click sobre la imagen
    if( event.type == SDL_MOUSEMOTION && arrastrar )
    {
        offset.x = event.motion.x - frame.w/2;
        offset.y = event.motion.y - frame.h/2;
        if(offset.x < 0)
            offset.x = 0;
        if(offset.y < 0)
            offset.y = 0;
    }
    else
    {
        offset.x += xVel;

        if( offset.x < 0 )
            offset.x = 0;
        else if( (offset.x + anchoFrame) > anchoPantalla )
            offset.x = anchoPantalla - anchoFrame;

        offset.y += yVel;

        if( offset.y < 0 )
            offset.y = 0;
        else if( (offset.y + altoFrame) > altoPantalla )
            offset.y = altoPantalla - altoFrame;
    }
}

void Personaje::mostrar()
{
    if( yVel < 0 )
    {
        //Cambio de frame de direccion
        frame.y = 3 * frame.h;
        cambiar_frame_movimiento();
    }
    else if( xVel < 0 )
    {
        frame.y = 1 * frame.h;
        cambiar_frame_movimiento();
    }
    else if( yVel > 0 )
    {
        frame.y = 0 * frame.h;
        cambiar_frame_movimiento();
    }
    else if( xVel > 0 )
    {
        frame.y = 2 * frame.h;
        cambiar_frame_movimiento();
    }
    aplicar_superficie(image, screen, offset.x, offset.y, &frame);
}

//Creamos un objeto de la clase Personaje
Personaje personajePrincipal((anchoPantalla - anchoFrame)/2, (altoPantalla - altoFrame)/2);

#endif // PERSONAJE_H
