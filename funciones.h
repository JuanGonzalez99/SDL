#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED

void regular_frames()
{
    if( fps.getTicks() < 1000/framesPorSegundo )
        SDL_Delay(1000/framesPorSegundo - fps.getTicks());
}

bool manejo_musica()
{
    if( evento.type == SDL_KEYDOWN )
    {
        switch(evento.key.keysym.sym)
        {
        //Si toca la barra espaciadora
        case SDLK_SPACE:
            {
                //Si no se está reproduciendo música
                if( Mix_PlayingMusic() == 0 )
                {
                    //Se pone play
                    if( Mix_PlayMusic( musica, -1 ) == -1 )
                        return false;
                }
                //Caso contrario
                else
                {
                    //Si la música está pausada
                    if( Mix_PausedMusic() == 1 )
                        //Se reanuda
                        Mix_ResumeMusic();

                    //Caso contrario
                    else
                        //Se pausa
                        Mix_PauseMusic();
                }
            }break;
        //Si toca la tecla Enter
        case SDLK_RETURN:
            {
                //Para la música
                Mix_HaltMusic();
            }break;
        //Si toca 1
        case SDLK_1:
            {
                //Paramos la música
                Mix_HaltMusic();

                //Liberamos la variable
                Mix_FreeMusic(musica);

                //Y le asignamos la nueva pista
                musica = Mix_LoadMUS("Final Fantasy IX - The Place I'll Return To Someday.wav");
            }break;
        //2
        case SDLK_2:
            {
                Mix_HaltMusic();
                Mix_FreeMusic(musica);
                musica = Mix_LoadMUS("Final Fantasy IX - Loss of me.wav");
            }break;
        //3
        case SDLK_3:
            {
                Mix_HaltMusic();
                Mix_FreeMusic(musica);
                musica = Mix_LoadMUS("Final Fantasy IX - Vivi's Theme.wav");
            }break;
        //4
        case SDLK_4:
            {
                Mix_HaltMusic();
                Mix_FreeMusic(musica);
                musica = Mix_LoadMUS("Final Fantasy IX - You're Not Alone!.wav");
            }break;
        default:{}
        }
    }

    //Si hubo error alguno cargando la música, retornamos falso. Si no, verdadero
    if( musica == NULL )
        return false;
    else
        return true;
}

#endif // FUNCIONES_H_INCLUDED
