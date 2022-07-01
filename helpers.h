#ifndef HELPERS_H_INCLUDED
#define HELPERS_H_INCLUDED

#ifdef _WIN32
    #define CLEAR "cls"
#elif defined(unix)
    #define CLEAR "clear"
#else
    #error "S0 no soportado para limpiar pantalla"
#endif

#endif // HELPERS_H_INCLUDED
