#ifndef SZAR_CORE_HPP
#define SZAR_CORE_HPP

// WINDOWS + MSVC COMPILER
#if defined SZ_WIN && defined _MSC_VER
    #ifdef SZ_BUILDING_SHARED
        #define SZ_DECLSPEC __declspec(dllexport)
    #elif defined SZ_SHARED
        #define SZ_DECLSPEC __declspec(dllimport)
    #else
        #define SZ_DECLSPEC
    #endif
#else
    #define SZ_DECLSPEC
#endif

#endif // !SZAR_CORE_HPP
