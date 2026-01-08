#include "pch.h"

#include <windows.h>
#include <dwmapi.h>

#pragma comment( lib, "dwmapi.lib" )

#define dllex extern "C" __declspec( dllexport )

#define GM_false 0.0
#define GM_true 1.0

//	Функция для изменения прозрачности окна путем создания заднего фона из его рамки
dllex double window_set_transparent_raw( double enable, HWND hwnd )
{
	MARGINS margins =
	{ 
		( enable >= 0.5 ) ? -1 : 0,
		0,
		0,
		0
	};
	
	return DwmExtendFrameIntoClientArea( hwnd, &margins );
};

//  Установка стиля TOPMOST
dllex void window_set_topmost_raw( double enable, HWND hwnd )
{
	//	Проверка включения / выключение стиля
    HWND insertAfter = ( enable >= 0.5 ) ? HWND_TOPMOST : HWND_NOTOPMOST;

    // Устанавливаем позицию ( сохраняя координаты и размеры окна )
    SetWindowPos(
		hwnd, 
		insertAfter,
		0, 
		0, 
		0, 
		0,
        SWP_NOMOVE | SWP_NOSIZE | SWP_NOACTIVATE );
}

//	Функция для проверки, имеет ли игровое окно стиль TOPMOST
dllex double window_get_topmost_raw( HWND hwnd)
{
	LONG style = GetWindowLongA( hwnd, GWL_EXSTYLE );

	return ( style & WS_EX_TOPMOST ) ? GM_true 
									 : GM_false;
}