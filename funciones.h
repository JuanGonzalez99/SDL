#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED

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
    //Initialize all SDL subsystems
    if( SDL_Init( SDL_INIT_EVERYTHING ) == -1 )
        return false;

    //Set up the screen
    screen = SDL_SetVideoMode( anchoPantalla, altoPantalla, bitsPorPixel, SDL_SWSURFACE );

    //If there was an error in setting up the screen
    if( screen == NULL )
        return false;

    //Initialize SDL_ttf
//    if( TTF_Init() == -1 )
//        return false;

    //Set the window caption
    SDL_WM_SetCaption( "Macri cat", NULL );

    //If everything initialized fine
    return true;
}

bool cargar_archivos()
{
    image = cargar_imagen( "Sprites.png" );

    //Open the font
//    font = TTF_OpenFont( "lazy.ttf", 28 );

    //If there was an error in loading the font
//    if( font == NULL )
//        return false;

    if( image == NULL)
        return false;

    //If everything loaded fine
    return true;
}

void aplicar_superficie( int x, int y, SDL_Surface* fuente, SDL_Surface* destino, SDL_Rect* clip = NULL )
{
    //Holds offsets
    SDL_Rect offset;
    offset.x = x;
    offset.y = y;

    //Blit
    SDL_BlitSurface( fuente, clip, destino, &offset );
}

void limpiar_SDL()
{
    //Free the surfaces
    SDL_FreeSurface( image );

    //Close the font that was used
//    TTF_CloseFont( font );

    //Quit SDL_ttf
//    TTF_Quit();

    //Quit SDL
    SDL_Quit();
}

#endif // FUNCIONES_H_INCLUDED
