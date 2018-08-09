//#############################################################################
// ARCHIVO             : main.cpp.
// AUTOR/ES            : Juan Gonzalez.
// VERSION             : 0.04 beta.
// FECHA DE CREACION   : 14/07/2018.
// ULTIMA ACTUALIZACION: 09/08/2018.
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
// SISTEMA OPERATIVO   : Windows 10.
// IDE                 : Code::Blocks - 17.12
// COMPILADOR          : GNU GCC Compiler.
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
//Constantes de la pantalla
const int anchoPantalla = 800;
const int altoPantalla = 600;
const int bitsPorPixel = 32;

//FPS del programa
const int framesPorSegundo = 20;

//Constantes de cada frame del sprite del personaje
const int altoFrame = 192;
const int anchoFrame = 144;

//Cantidad de píxeles que se mueve el personaje
int largoPasos = 15;

//Variables para el cambio de frame de movimiento
int frameActual = 0, maxFrame = 3;

//Booleano para saber si el usuario quiere finalizar el programa
bool terminarPrograma = false;

SDL_Surface* fondo = NULL;
SDL_Surface* mensaje = NULL;
SDL_Surface* pantalla = NULL;
SDL_Surface* imagen = NULL;
SDL_Surface* boton = NULL;

//Variable que maneja los eventos (teclas presionadas, movimiento del mouse, etc)
SDL_Event evento;

TTF_Font* fuente = NULL;
SDL_Color colorTexto = { 0, 0, 0 };

Mix_Music* musica = NULL;

//*****************************************************************************
//                             INCLUSIONES PERSONALES
//=============================================================================
#include "funciones_SDL.h"
#include "Minutero.h"
#include "Personaje.h"
#include "Boton.h"
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
        return -1;

    //Carga de archivos
    if( cargar_archivos() == false )
        return 1;

    //Empieza el programa
    if( menuPrincipal() == false )
    {
        limpiar_SDL();
        return 2;
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

