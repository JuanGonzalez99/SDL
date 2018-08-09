#ifndef FUNCIONES_SDL_H_INCLUDED
#define FUNCIONES_SDL_H_INCLUDED

SDL_Surface* cargar_imagen(std::string archivo)
{
    //Variable en la que se va a cargar la imagen
    SDL_Surface* imagenCargada = NULL;

    //Superficie que va a contener la versión optimizada de dicha imagen
    SDL_Surface* imagenOptimizada = NULL;

    //Cargamos la imagen
    imagenCargada = IMG_Load(archivo.c_str());

    //Si no hubo error cargando la imagen
    if( imagenCargada != NULL )
    {
        //Pasamos la imagen cargada de forma optimizada
        imagenOptimizada = SDL_DisplayFormat(imagenCargada);

        //Y liberamos ese espacio en memoria
        SDL_FreeSurface(imagenCargada);
    }
    //Retornamos la imagen optimizada
    return imagenOptimizada;
}

bool init()
{
    //Inicializamos todos los subsistemas de SDL
    if( SDL_Init( SDL_INIT_EVERYTHING ) == -1 )
        return false;

    //Creamos la pantalla
    pantalla = SDL_SetVideoMode( anchoPantalla, altoPantalla, bitsPorPixel, SDL_SWSURFACE );

    //Si hubo un error creando la pantalla
    if( pantalla == NULL )
        return false;

    //Inicializamos SDL_ttf
    if( TTF_Init() == -1 )
        return false;

    //Inicializamos SDL_mixer
    if( Mix_OpenAudio( 22050, MIX_DEFAULT_FORMAT, 2, 4096 ) == -1 )
        return false;

    //Fijamos el encabezado
    SDL_WM_SetCaption( "Proyecto SDL", NULL );

    //Si todo inicializó correctamente
    return true;
}

bool cargar_archivos()
{
    //Cargamos la imagen con los sprites
    imagen = cargar_imagen( "Sprites.png" );

    //Si hubo un error al cargar la imagen
    if( imagen == NULL )
        return false;

    //Sacamos el fondo rosa de la imagen
    Uint32 colorkey = SDL_MapRGB(imagen->format, 255, 0, 255);
    SDL_SetColorKey(imagen, SDL_SRCCOLORKEY, colorkey);

    //Cargamos la imagen del boton
    boton = cargar_imagen( "boton.png" );

    //Si hubo un error al cargar la imagen
    if( boton == NULL )
        return false;

    //Abrimos la fuente
    fuente = TTF_OpenFont( "Fixedsys.ttf", 40 );

    //Si hubo un error al cargar la fuente
    if( fuente == NULL )
        return false;

    //Cargamos la pista inicial
    musica = Mix_LoadMUS("Final Fantasy IX - The Place I'll Return To Someday.wav");

    //Si hubo un error al cargar la música
    if( musica == NULL )
        return false;

    //Si todo cargo correctamente
    return true;
}

void aplicar_superficie( SDL_Surface* fuente, SDL_Surface* destino, int x=0, int y=0, SDL_Rect* clip = NULL )
{
    //Variable para "retener" el offset. Por default es x=0 y=0 (esquina superior izquierda)
    SDL_Rect offset;
    offset.x = x;
    offset.y = y;

    //Se superopone la imagen fuente sobre el destino, con un determinado offset y clip (opcional)
    SDL_BlitSurface( fuente, clip, destino, &offset );
}

void limpiar_SDL()
{
    //Liberamos las superficies usadas
    SDL_FreeSurface( imagen );
    SDL_FreeSurface( boton );

    //Cerramos la fuente
    TTF_CloseFont( fuente );

    //Liberamos la música
    Mix_FreeMusic( musica );

    //Cerramos las funciones de SDL
    Mix_CloseAudio();
    TTF_Quit();
    SDL_Quit();
}

#endif // FUNCIONES_SDL_H_INCLUDED
