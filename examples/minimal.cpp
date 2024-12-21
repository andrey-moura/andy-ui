#include <uva/ui/app.hpp>
#include <uva/ui/frame.hpp>

class myapp : public uva::lang::ui::app
{
public:
    myapp() : uva::lang::ui::app("MyApp", "MyVendor") {}
    ~myapp() {}

    void on_init(int argc, char** argv) override
    {
        uva::lang::ui::frame frame("MyFrame");
        frame.show();
    }
};

UVA_IMPLEMENT_APP(myapp);