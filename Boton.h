#ifndef BOTON_H
#define BOTON_H


class Boton
{
    public:
        Boton(int x, int y, int w, int h, SDL_Surface* imagen);
        bool apreto_boton();
        void mostrar();

    protected:

    private:
        SDL_Surface* boton;
        SDL_Rect recuadro;
};

Boton::Boton(int x, int y, int w, int h, SDL_Surface* imagen)
{
    recuadro.h = h;
    recuadro.w = w;
    recuadro.x = x;
    recuadro.y = y;

    boton = imagen;
}

bool Boton::apreto_boton()
{
    //Si apreto el click izquierdo
    if( evento.type == SDL_MOUSEBUTTONDOWN && evento.button.button == SDL_BUTTON_LEFT )
    {
        int x = evento.button.x;
        int y = evento.button.y;

        //Si lo apreto dentro del boton
        if( ( x > recuadro.x ) && ( x < recuadro.x + recuadro.w ) && ( y > recuadro.y ) && ( y < recuadro.y + recuadro.h ) )
            return true;
    }
    return false;
}

void Boton::mostrar()
{
    aplicar_superficie(boton, pantalla, recuadro.x, recuadro.y);
}

#endif // BOTON_H
