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
    //Inicializamos todos los subsistemas de SDL
    if( SDL_Init( SDL_INIT_EVERYTHING ) == -1 )
        return false;

    //Creamos la pantalla
    screen = SDL_SetVideoMode( anchoPantalla, altoPantalla, bitsPorPixel, SDL_SWSURFACE );

    //Si hubo un error creando la pantalla
    if( screen == NULL )
        return false;

    //Inicializamos SDL_ttf
    if( TTF_Init() == -1 )
        return false;

    //Fijamos el encabezado
    SDL_WM_SetCaption( "Macri cat", NULL );

    //If everything initialized fine
    return true;
}

bool cargar_archivos()
{
    //Cargamos la imagen
    image = cargar_imagen( "Sprites.png" );

    //Si hubo un error al cargar la imagen
    if( image == NULL)
        return false;

    //Abrimos la fuente
    font = TTF_OpenFont( "lazy.ttf", 28 );

    //Si hubo un error al cargar la fuente
    if( font == NULL )
        return false;

    //Si todo cargo correctamente
    return true;
}

void aplicar_superficie( int x, int y, SDL_Surface* fuente, SDL_Surface* destino, SDL_Rect* clip = NULL )
{
    SDL_Rect offset;
    offset.x = x;
    offset.y = y;

    SDL_BlitSurface( fuente, clip, destino, &offset );
}

void limpiar_SDL()
{
    SDL_FreeSurface( image );

    TTF_CloseFont( font );

    TTF_Quit();
    SDL_Quit();
}

void manejo_texto()
{
    if( event.type == SDL_MOUSEBUTTONDOWN && event.button.button == SDL_BUTTON_LEFT )
        message = TTF_RenderText_Solid(font, "Estas apretado el click izquierdo", textColor);

    else if( event.type == SDL_MOUSEBUTTONUP && event.button.button == SDL_BUTTON_LEFT )
        message = TTF_RenderText_Solid(font, "Dejaste de apretar el click izquierdo", textColor);

    else if( event.type == SDL_MOUSEBUTTONDOWN && event.button.button == SDL_BUTTON_RIGHT )
        message = TTF_RenderText_Solid(font, "Estas apretando el click derecho", textColor);

    else if( event.type == SDL_MOUSEBUTTONUP && event.button.button == SDL_BUTTON_RIGHT )
        message = TTF_RenderText_Solid(font, "Dejaste de apretar el click derecho", textColor);

    else
        message = TTF_RenderText_Solid(font, "", textColor);


    aplicar_superficie(50, 200, message, screen);
}

#endif // FUNCIONES_H_INCLUDED
