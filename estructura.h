#ifndef ESTRUCTURA_H_INCLUDED
#define ESTRUCTURA_H_INCLUDED

bool juego();

bool estructura()
{
    Boton jugar((anchoPantalla - 200)/2, (altoPantalla - 100)/2, 200, 100, boton);
    while( terminarPrograma == false )
    {
        fps.empezar();
        if( SDL_PollEvent(&evento))
        {
            //Si toca la x de la ventana o apreta la tecla Esc
            if( evento.type == SDL_QUIT || evento.key.keysym.sym == SDLK_ESCAPE )
            {
                terminarPrograma = true;
                continue;
            }
            if( jugar.apreto_boton() )
            {
                juego();
                continue;
            }
        }

        //Ponemos el fondo rojo
        SDL_FillRect(pantalla, NULL, SDL_MapRGB(pantalla->format, 0, 0, 255));

        jugar.mostrar();

        //Actualización de la pantalla
        if( SDL_Flip(pantalla) == -1 )
            return false;

        regular_frames();

    }
    return true;
}

bool juego()
{
    while( terminarPrograma == false )
    {
        fps.empezar();
        if( SDL_PollEvent(&evento))
        {
            //Si toca la x de la ventana o apreta la tecla Esc
            if( evento.type == SDL_QUIT || evento.key.keysym.sym == SDLK_ESCAPE )
            {
                terminarPrograma = true;
                continue;
            }

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

        regular_frames();
    }
    return true;
}

#endif // ESTRUCTURA_H_INCLUDED
