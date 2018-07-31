#ifndef MINUTERO_H
#define MINUTERO_H


class Minutero
{
public:
    Minutero();
    void empezar();
    void parar();
    void pausar();
    void reanudar();
    int getTicks();
    bool estaEmpezado();
    bool estaPausado();

protected:

private:
    int ticksComienzo;
    int ticksPausa;
    bool pausado;
    bool empezado;
};

Minutero::Minutero()
{
    ticksComienzo = 0;
    ticksPausa = 0;
    pausado = false;
    empezado = false;
}

void Minutero::empezar()
{
    empezado = true;
    pausado = false;

    ticksComienzo = SDL_GetTicks();
}

void Minutero::parar()
{
    empezado = false;
    pausado = false;
}

void Minutero::pausar()
{
    if( empezado == true && pausado == false )
    {
        pausado = true;

        ticksPausa = SDL_GetTicks() - ticksComienzo;
    }
}

void Minutero::reanudar()
{
    if( pausado )
    {
        pausado = false;

        ticksComienzo = SDL_GetTicks() - ticksPausa;

        ticksPausa = 0;
    }
}

int Minutero::getTicks()
{
    if( empezado )
    {
        if( pausado )
            return ticksPausa;
        else
            return SDL_GetTicks() - ticksComienzo;
    }
    else
        return 0;
}

bool Minutero::estaEmpezado()
{
    return empezado;
}

bool Minutero::estaPausado()
{
    return pausado;
}

Minutero fps;

#endif // MINUTERO_H
