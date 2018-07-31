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
        case SDLK_SPACE:
            {
                //If there is no music playing
                if( Mix_PlayingMusic() == 0 )
                {
                    //Play the music
                    if( Mix_PlayMusic( musica, -1 ) == -1 )
                        return false;
                }
                //If music is being played
                else
                {
                    //If the music is paused
                    if( Mix_PausedMusic() == 1 )
                        //Resume the music
                        Mix_ResumeMusic();

                    //If the music is playing
                    else
                        //Pause the music
                        Mix_PauseMusic();
                }
            }break;
            case SDLK_RETURN:
            {
                //Stop the music
                Mix_HaltMusic();
            }break;
        case SDLK_1:
            {
                Mix_HaltMusic();
                Mix_FreeMusic(musica);
                musica = Mix_LoadMUS("Final Fantasy IX - The Place I'll Return To Someday.wav");
            }break;
        case SDLK_2:
            {
                Mix_HaltMusic();
                Mix_FreeMusic(musica);
                musica = Mix_LoadMUS("Final Fantasy IX - Loss of me.wav");
            }break;
        case SDLK_3:
            {
                Mix_HaltMusic();
                Mix_FreeMusic(musica);
                musica = Mix_LoadMUS("Final Fantasy IX - Vivi's Theme.wav");
            }break;
        case SDLK_4:
            {
                Mix_HaltMusic();
                Mix_FreeMusic(musica);
                musica = Mix_LoadMUS("Final Fantasy IX - You're Not Alone!.wav");
            }break;
        default:{}
        }
    }
    if( musica == NULL )
        return false;
    else
        return true;
}

#endif // FUNCIONES_H_INCLUDED
