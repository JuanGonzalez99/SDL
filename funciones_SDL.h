#ifndef FUNCIONES_SDL_H_INCLUDED
#define FUNCIONES_SDL_H_INCLUDED

SDL_Surface* cargar_imagen(std::string archivo)
{
    SDL_Surface* imagenCargada = NULL;
    SDL_Surface* imagenOptimizada = NULL;

    imagenCargada = IMG_Load(archivo.c_str());

    if( imagenCargada != NULL )
    {
        imagenOptimizada = SDL_DisplayFormat(imagenCargada);
        SDL_FreeSurface(imagenCargada);
    }
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

    //If everything initialized fine
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

    //Cargamos el fondo
    fondo = cargar_imagen( "Fondo.png" );

    //Si hubo un error al cargar la imagen
    if( fondo == NULL )
        return false;

    //Abrimos la fuente
    fuente = TTF_OpenFont( "Fixedsys.ttf", 40 );

    //Si hubo un error al cargar la fuente
    if( fuente == NULL )
        return false;

    musica = Mix_LoadMUS("Final Fantasy IX - The Place I'll Return To Someday.wav");

    if( musica == NULL )
        return false;

    //Si todo cargo correctamente
    return true;
}

void aplicar_superficie( SDL_Surface* fuente, SDL_Surface* destino, int x=0, int y=0, SDL_Rect* clip = NULL )
{
    SDL_Rect offset;
    offset.x = x;
    offset.y = y;

    SDL_BlitSurface( fuente, clip, destino, &offset );
}

void limpiar_SDL()
{
    SDL_FreeSurface( imagen );

    TTF_CloseFont( fuente );

    Mix_FreeMusic( musica );

    Mix_CloseAudio();
    TTF_Quit();
    SDL_Quit();
}

#endif // FUNCIONES_SDL_H_INCLUDED
