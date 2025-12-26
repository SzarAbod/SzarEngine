#ifndef SZAR_APPLICATION_HPP
#define SZAR_APPLICATION_HPP
#include <core.hpp>

namespace szar {
    /**
     * @brief Represents the main application entrypoint and lifecycle container.
     *
     * Manages application lifetime and exposes the primary execution entrypoint.
     */
     
    /**
     * @brief Constructs an Application instance.
     *
     * Initializes application state required before Run() is called.
     */
     
    /**
     * @brief Destroys the Application instance.
     *
     * Performs cleanup for derived classes; declared virtual to allow proper destruction through base pointers.
     */
    
    /**
     * @brief Starts and runs the application's main execution loop.
     *
     * Executes the primary processing or event loop for the application until completion or shutdown.
     */
    class SZ_DECLSPEC Application {
    public:
        Application();
        virtual ~Application();

        void Run();
    };
}

#endif // !SZAR_APPLICATION_HPP