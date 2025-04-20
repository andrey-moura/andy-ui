#include <andy/ui/app.hpp>
#include <andy/ui/frame.hpp>

class myapp : public andy::lang::ui::app
{
public:
    myapp() : andy::lang::ui::app("MyApp", "MyVendor") {}
    ~myapp() {}

    void on_init(int argc, char** argv) override
    {
        andy::lang::ui::frame frame("MyFrame");
        frame.show();
    }
};

UVA_IMPLEMENT_APP(myapp);