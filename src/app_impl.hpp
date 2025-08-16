# pragma once

#include "andy/ui/app.hpp"

class andy::ui::app::app_impl
{
public:
    app_impl();
public:
    friend class andy::ui::app;
protected:
    void init(int argc, char** argv);
    void run(int argc, char** argv);
};