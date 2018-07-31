#ifndef ESTRUCTURA_H_INCLUDED
#define ESTRUCTURA_H_INCLUDED

bool juego();

bool estructura()
{
    while( terminarPrograma == false )
    {
        fps.empezar();
        while( SDL_PollEvent(&evento))
        {
            //Si toca la x de la ventana o apreta la tecla Esc
            if( evento.type == SDL_QUIT || evento.key.keysym.sym == SDLK_ESCAPE )
            {
                terminarPrograma = true;
                continue;
            }

            manejo_musica();

            //Manejo del movimiento del personaje
            personajePrincipal.manejar_eventos();
        }
        personajePrincipal.mover();

        //Ponemos el fondo rojo
        SDL_FillRect(pantalla, NULL, SDL_MapRGB(pantalla->format, 255, 0, 0));

        //Ponemos los mensajes
        mensaje = TTF_RenderText_Solid(fuente, "Tab = Modo Fantasma", colorTexto);
        aplicar_superficie(mensaje, pantalla, 0, 0);

        mensaje = TTF_RenderText_Solid(fuente, "WASD o flechas para", colorTexto);
        aplicar_superficie(mensaje, pantalla, anchoPantalla/2, altoPantalla - (mensaje->h * 2));
        mensaje = TTF_RenderText_Solid(fuente, " mover el personaje", colorTexto);
        aplicar_superficie(mensaje, pantalla, anchoPantalla/2, altoPantalla - mensaje->h);

        //Liberamos espacio en memoria
        SDL_FreeSurface(mensaje);

        personajePrincipal.mostrar();

        //Actualización de la pantalla
        if( SDL_Flip(pantalla) == -1 )
            return false;

        if( fps.getTicks() < 1000/framesPorSegundo )
            SDL_Delay(1000/framesPorSegundo - fps.getTicks());
    }
    return true;
}

bool juego()
{
    while( terminarPrograma == false )
    {
        while( SDL_PollEvent(&evento))
        {
            //Si toca la x de la ventana o apreta la tecla Esc
            if( evento.type == SDL_QUIT || evento.key.keysym.sym == SDLK_ESCAPE )
            {
                terminarPrograma = true;
                continue;
            }
            //Ponemos el fondo rojo
            SDL_FillRect(pantalla, NULL, SDL_MapRGB(pantalla->format, 255, 0, 0));

            //Ponemos los mensajes
            mensaje = TTF_RenderText_Solid(fuente, "Tab = Modo Fantasma", colorTexto);
            aplicar_superficie(mensaje, pantalla, 0, 0);

            mensaje = TTF_RenderText_Solid(fuente, "WASD o flechas para", colorTexto);
            aplicar_superficie(mensaje, pantalla, anchoPantalla/2, altoPantalla - (mensaje->h * 2));
            mensaje = TTF_RenderText_Solid(fuente, " mover el personaje", colorTexto);
            aplicar_superficie(mensaje, pantalla, anchoPantalla/2, altoPantalla - mensaje->h);

            //Liberamos espacio en memoria
            SDL_FreeSurface(mensaje);

            //Manejo del movimiento del personaje
            personajePrincipal.manejar_eventos();

            //Actualización de la pantalla
            if( SDL_Flip(pantalla) == -1 )
                return false;
        }
    }
    return true;
}

#endif // ESTRUCTURA_H_INCLUDED
