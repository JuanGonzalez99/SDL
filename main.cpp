//#############################################################################
// ARCHIVO             : nombre de archivo.extension
// AUTOR/ES            : nombre/s de autor/es
// VERSION             : 0.01 beta.
// FECHA DE CREACION   : dd/mm/aaaa.
// ULTIMA ACTUALIZACION: dd/mm/aaaa.
// LICENCIA            : GPL (General Public License) - Version 3.
//
//  **************************************************************************
//  * El software libre no es una cuestion economica sino una cuestion etica *
//  **************************************************************************
//
// Este programa es software libre;  puede redistribuirlo  o  modificarlo bajo
// los terminos de la Licencia Publica General de GNU  tal como se publica por
// la  Free Software Foundation;  ya sea la version 3 de la Licencia,  o (a su
// eleccion) cualquier version posterior.
//
// Este programa se distribuye con la esperanza  de que le sea util,  pero SIN
// NINGUNA  GARANTIA;  sin  incluso  la garantia implicita de MERCANTILIDAD  o
// IDONEIDAD PARA UN PROPOSITO PARTICULAR.
//
// Vea la Licencia Publica General GNU para mas detalles.
//
// Deberia haber recibido una copia de la Licencia Publica General de GNU junto
// con este proyecto, si no es asi, escriba a la Free Software Foundation, Inc,
// 59 Temple Place - Suite 330, Boston, MA 02111-1307, EE.UU.

//=============================================================================
// SISTEMA OPERATIVO   : Linux (Ubuntu) / Windows XP / Windows 7.
// IDE                 : Code::Blocks - 17.12
// COMPILADOR          : GNU GCC Compiler (Linux) / MinGW (Windows).
// LICENCIA            : GPL (General Public License) - Version 3.
//=============================================================================
// DESCRIPCION:
//              Breve explicacion sobre el contenido del archivo.
//
////////////////////////////////////////////////////////////////////////////////

//*****************************************************************************
//                       CONFIGURACION MULTIPLATAFORMA
//=============================================================================
#ifndef _WIN32

    #define _LINUX

#endif

//*****************************************************************************
//               DECLARACION DE VARIABLES Y PROTOTIPOS GLOBALES
//=============================================================================
const int anchoPantalla = 800;
const int altoPantalla = 600;

//*****************************************************************************
//                             INCLUSIONES ESTANDAR
//=============================================================================
#include <iostream> // Libreria de flujos de  Entrada/Salida  que contiene  los
                    // objetos cin, cout y endl.

#include <cstdlib>  // Libreria estandar que contiene la funcion exit().

//*****************************************************************************
//                             INCLUSIONES PERSONALES
//=============================================================================
#include "CSYSTEM/csystem.h" // Libreria para multiplataforma.
#include "SDL/SDL.h" // Libreria de SDL.


//==============================================================================
// DECLARACION DEL ESPACIO DE NOMBRES POR DEFECTO
//------------------------------------------------------------------------------
using namespace std;


//==============================================================================
// FUNCION PRINCIPAL - PUNTO DE INICIO DEL PROYECTO
//------------------------------------------------------------------------------
int main(int argc, char* args[])
{
    bool running = true;

    //Inicializar SDL
    if(SDL_Init( SDL_INIT_EVERYTHING ) == -1)
    {
        running = false;
    }

    //Creacion de la pantalla
    SDL_Surface *screen;
    screen = SDL_SetVideoMode(anchoPantalla, altoPantalla, 32, SDL_HWSURFACE);
    SDL_WM_SetCaption("Macri cat", NULL);

    if(screen == NULL)
    {
        running = false;
    }
    //Nuestro evento
    SDL_Event event;

    //Variables de imagenes
    SDL_Surface* loadedImage = SDL_LoadBMP("Sprites.bmp");
    SDL_Surface* image = SDL_DisplayFormat(loadedImage);
    SDL_FreeSurface(loadedImage);

    int frameActual = 0, maxFrame = 3;

    SDL_Rect frame;
    frame.x = 0;
    frame.y = 0;
    frame.w = 144;
    frame.h = 192;

    SDL_Rect offset;
    offset.x = 0;
    offset.y = 0;

    Uint32 colorkey = SDL_MapRGB(image->format, 255, 0, 255);

    SDL_SetColorKey(image, SDL_SRCCOLORKEY, colorkey);

    //Loop principal de la aplicacion
    while(running)
    {
        SDL_PollEvent(&event);

        if(event.type == SDL_QUIT)
        {
            running = false;
        }

        //El dibujado ocurre aca
        SDL_FillRect(screen, NULL, 0);

        SDL_BlitSurface(image, &frame, screen, &offset);

        if(event.type == SDL_KEYDOWN)
        {
            switch(event.key.keysym.sym)
            {
            case SDLK_w:
            case SDLK_UP:
                {
                    frame.y = 3 * frame.h;
                    offset.y -= 1;
                    frameActual++;
                    if(frameActual>maxFrame)
                    {
                        frameActual = 0;
                    }
                    frame.x = frameActual*frame.w;
                }break;
            case SDLK_a:
            case SDLK_LEFT:
                {
                    frame.y = 1 * frame.h;
                    offset.x -= 1;
                    frameActual++;
                    if(frameActual>maxFrame)
                    {
                        frameActual = 0;
                    }
                    frame.x = frameActual*frame.w;
                }break;
            case SDLK_s:
            case SDLK_DOWN:
                {
                    frame.y = 0 * frame.h;
                    if(offset.y<(altoPantalla-frame.h))
                    {
                        offset.y += 1;
                    }
                    frameActual++;
                    if(frameActual>maxFrame)
                    {
                        frameActual = 0;
                    }
                    frame.x = frameActual*frame.w;
                }break;
            case SDLK_d:
            case SDLK_RIGHT:
                {
                    frame.y = 2 * frame.h;
                    if(offset.x<(anchoPantalla-frame.w+10))
                    {
                        offset.x += 1;
                    }
                    frameActual++;
                    if(frameActual>maxFrame)
                    {
                        frameActual = 0;
                    }
                    frame.x = frameActual*frame.w;
                }break;
            case SDLK_ESCAPE:
                {
                    running = false;
                }break;
            default:
                {

                }
            }//Fin switch

        }//Fin if

        SDL_Flip(screen);

    }

    SDL_FreeSurface(image);

    //Terminar SDL
    SDL_Quit();

    //--------------------------------------------------------------------------
    // FIN DE LA FUNCION main() SIN ERRORES.
    //--------------------------------------------------------------------------
    return 0;
}

//=============================================================================
//                            FIN DE ARCHIVO
//#############################################################################

