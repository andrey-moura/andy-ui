#include <andy/ui/dialog.hpp>

#include <Windows.h>

struct dialog_data
{
    HWND hwnd;
};

#define m_dialog os_specific_data_as<dialog_data>().hwnd

namespace uva
{
    namespace ui
    {
        dialog::dialog(std::string_view __title)
        {
            m_dialog = CreateWindowEx(0, TEXT("andy::ui::dialog"), __title.data(), WS_OVERLAPPEDWINDOW, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, nullptr, nullptr, nullptr, nullptr);
        }

        dialog::~dialog()
        {
            DestroyWindow(m_dialog);
        }

        void dialog::show(bool maximized)
        {
            ShowWindow(m_dialog, maximized ? SW_MAXIMIZE : SW_NORMAL);
        }
    }
};