#include <szar.hpp>

class Sandbox: public szar::Application {
public:
    Sandbox() {}
    ~Sandbox() {}
};

int main(int argc, char *argv[])
{
    auto app = new Sandbox();
    app->Run();
    delete app;
    
    return 0;
}