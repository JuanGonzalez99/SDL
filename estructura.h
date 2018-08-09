#ifndef ESTRUCTURA_H_INCLUDED
#define ESTRUCTURA_H_INCLUDED

bool juego();

bool menuPrincipal()
{
    //Ponemos un boton de "Jugar" en el centro de la pantalla
    Boton jugar( (anchoPantalla - 200) / 2, (altoPantalla - 100) / 2, 200, 100, boton );

    //Loop principal
    while( terminarPrograma == false )
    {
        //Si hay un evento que manejar
        if( SDL_PollEvent(&evento) )
        {
            //Si toca la x de la ventana o apreta la tecla Esc, termina el programa
            if( evento.type == SDL_QUIT || (evento.type == SDL_KEYDOWN && evento.key.keysym.sym == SDLK_ESCAPE) )
            {
                terminarPrograma = true;
                continue;
            }

            //Si toca el boton de jugar, empieza el juego
            if( jugar.apreto_boton() == true )
            {
                if( juego() == true )
                {
                    //Si no hubo ningún error
                    continue;
                }
                else
                {
                    //Si hubo algún error, retornamos false
                    return false;
                }
            }
        }

        //Ponemos el fondo azul
        SDL_FillRect(pantalla, NULL, SDL_MapRGB(pantalla->format, 0, 0, 255));

        //Ponemos el boton en la pantalla
        jugar.mostrar();

        //Actualización de la pantalla
        if( SDL_Flip(pantalla) == -1 )
            return false;

    }
    return true;
}

bool juego()
{
    //Booleano para saber si el usuario desea seguir jugando
    bool jugar = true;

    //Loop del juego
    while( jugar )
    {
        //Empezamos el minutero para regular los FPS
        fps.empezar();

        //Si hay un evento que manejar
        if( SDL_PollEvent(&evento) )
        {
            //Si toca la x de la ventana, termina el programa
            if( evento.type == SDL_QUIT )
            {
                terminarPrograma = true;
                break;
            }

            //Si toca la tecla Esc, vuelve al menú principal
            if( evento.type == SDL_KEYDOWN && evento.key.keysym.sym == SDLK_ESCAPE )
            {
                jugar = false;
                continue;
            }

            //Se manejan los eventos relacionados con la música (cambiar pista, pausar, reanudar, parar)
            manejo_musica();

            //Se manejan los eventos relacionados con el personaje, movimiento o modo fantasma
            personajePrincipal.manejar_eventos();
        }
        //Actualizamos la posicion del personaje
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

        //Actualizamos el frame del personaje y lo ponemos en pantalla
        personajePrincipal.mostrar();

        //Actualización de la pantalla
        if( SDL_Flip(pantalla) == -1 )
            return false;

        //Regulamos los frames para que el juego no vaya demasiado rápido
        regular_frames();
    }
    //Si no hubo ningún error, retornamos true
    return true;
}

#endif // ESTRUCTURA_H_INCLUDED
