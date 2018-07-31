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
//                             INCLUSIONES ESTANDAR
//=============================================================================
#include <iostream> // Libreria de flujos de  Entrada/Salida  que contiene  los
                    // objetos cin, cout y endl.

//#include <cstdlib>  // Libreria estandar que contiene la funcion exit().

//#include "CSYSTEM/csystem.h" // Libreria para multiplataforma.

//Librerias de SDL
#include "SDL/SDL.h"
#include "SDL/SDL_image.h"
#include "SDL/SDL_ttf.h"
#include "SDL/SDL_mixer.h"

//*****************************************************************************
//               DECLARACION DE VARIABLES Y PROTOTIPOS GLOBALES
//=============================================================================
const int anchoPantalla = 800;
const int altoPantalla = 600;
const int bitsPorPixel = 32;

const int framesPorSegundo = 20;

const int altoFrame = 192;
const int anchoFrame = 144;

int largoPasos = 15;

int frameActual = 0, maxFrame = 3;

bool terminarPrograma = false; //Booleano para saber si el usuario quiere finalizar el programa

SDL_Surface* background = NULL;
SDL_Surface* message = NULL;
SDL_Surface* screen = NULL;
SDL_Surface* image = NULL;

SDL_Event event;

TTF_Font* font = NULL;
SDL_Color textColor = { 0, 0, 0 };

Mix_Music* musica = NULL;

//*****************************************************************************
//                             INCLUSIONES PERSONALES
//=============================================================================
#include "funciones_SDL.h"
#include "Minutero.h"
#include "Personaje.h"
#include "funciones.h"
#include "estructura.h"

//==============================================================================
// DECLARACION DEL ESPACIO DE NOMBRES POR DEFECTO
//------------------------------------------------------------------------------


//==============================================================================
// FUNCION PRINCIPAL - PUNTO DE INICIO DEL PROYECTO
//------------------------------------------------------------------------------
int main(int argc, char* args[])
{
    //Inicializar SDL
    if( init() == false )
        return 1;

    //Carga de archivos
    if( cargar_archivos() == false )
        return 1;

//    //Ponemos la música cuando empieza el programa
//    if( Mix_PlayMusic( musica, -1 ) == -1 )
//        return 1;

    if( estructura() == false )
    {
        limpiar_SDL();
        return 1;
    }
    else
    {
        limpiar_SDL();
        return 0;
    }
    //--------------------------------------------------------------------------
    // FIN DE LA FUNCION main() SIN ERRORES.
    //--------------------------------------------------------------------------
    return 0;
}




//=============================================================================
//                            FIN DE ARCHIVO
//#############################################################################

