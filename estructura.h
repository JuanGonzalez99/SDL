#ifndef ESTRUCTURA_H_INCLUDED
#define ESTRUCTURA_H_INCLUDED

void estructura()
{
    //Ponemos el fondo
    aplicar_superficie(background, screen);

    //Ponemos los mensajes
    message = TTF_RenderText_Solid(font, "Tab = Modo Fantasma", textColor);
    aplicar_superficie(message, screen, 0, 0);

    message = TTF_RenderText_Solid(font, "WASD o flechas para", textColor);
    aplicar_superficie(message, screen, anchoPantalla/2, altoPantalla - (message->h * 2));
    message = TTF_RenderText_Solid(font, " mover el personaje", textColor);
    aplicar_superficie(message, screen, anchoPantalla/2, altoPantalla - message->h);

    SDL_FreeSurface(message);

    //Manejo del movimiento del personaje
    personajePrincipal.manejar_eventos();
}

#endif // ESTRUCTURA_H_INCLUDED
