#ifndef ESTRUCTURA_H_INCLUDED
#define ESTRUCTURA_H_INCLUDED

bool juego();

bool estructura()
{
    while( terminarPrograma == false )
    {
        fps.empezar();
        while( SDL_PollEvent(&event))
        {
            //Si toca la x de la ventana o apreta la tecla Esc
            if( event.type == SDL_QUIT || event.key.keysym.sym == SDLK_ESCAPE )
            {
                terminarPrograma = true;
                continue;
            }

            //Manejo del movimiento del personaje
            personajePrincipal.manejar_eventos();
        }
        personajePrincipal.mover();

        //Ponemos el fondo rojo
        SDL_FillRect(screen, NULL, SDL_MapRGB(screen->format, 255, 0, 0));

        //Ponemos los mensajes
        message = TTF_RenderText_Solid(font, "Tab = Modo Fantasma", textColor);
        aplicar_superficie(message, screen, 0, 0);

        message = TTF_RenderText_Solid(font, "WASD o flechas para", textColor);
        aplicar_superficie(message, screen, anchoPantalla/2, altoPantalla - (message->h * 2));
        message = TTF_RenderText_Solid(font, " mover el personaje", textColor);
        aplicar_superficie(message, screen, anchoPantalla/2, altoPantalla - message->h);

        //Liberamos espacio en memoria
        SDL_FreeSurface(message);

        personajePrincipal.mostrar();

        //Actualización de la pantalla
        if( SDL_Flip(screen) == -1 )
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
        while( SDL_PollEvent(&event))
        {
            //Si toca la x de la ventana o apreta la tecla Esc
            if( event.type == SDL_QUIT || event.key.keysym.sym == SDLK_ESCAPE )
            {
                terminarPrograma = true;
                continue;
            }
            //Ponemos el fondo rojo
            SDL_FillRect(screen, NULL, SDL_MapRGB(screen->format, 255, 0, 0));

            //Ponemos los mensajes
            message = TTF_RenderText_Solid(font, "Tab = Modo Fantasma", textColor);
            aplicar_superficie(message, screen, 0, 0);

            message = TTF_RenderText_Solid(font, "WASD o flechas para", textColor);
            aplicar_superficie(message, screen, anchoPantalla/2, altoPantalla - (message->h * 2));
            message = TTF_RenderText_Solid(font, " mover el personaje", textColor);
            aplicar_superficie(message, screen, anchoPantalla/2, altoPantalla - message->h);

            //Liberamos espacio en memoria
            SDL_FreeSurface(message);

            //Manejo del movimiento del personaje
            personajePrincipal.manejar_eventos();

            //Actualización de la pantalla
            if( SDL_Flip(screen) == -1 )
                return false;
        }
    }
    return true;
}

#endif // ESTRUCTURA_H_INCLUDED
