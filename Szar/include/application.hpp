#ifndef SZAR_APPLICATION_HPP
#define SZAR_APPLICATION_HPP
#include <core.hpp>

namespace szar {
    class SZ_DECLSPEC Application {
    public:
        Application();
        virtual ~Application();

        void Run();
    };
}

#endif