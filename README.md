![banner](images/banner.png)

A simple extension that allows you to disable the visibility of a window
[Русская версия](README_ru.md)

## Legacy warning
If you are using the IDE version **2024.14.2.213** and above, for the extension to work, you need to enable the `Use legacy DXGI_SWAP_EFFECT_DISCARD` option in the game settings `Windows -> Graphics`

![enable_special_option](images/enable_special_option.png)

## Usage
`window_set_transparent( enable ) -> undefined`  
Allows you to **turn on** or **turn off** the visibility ( transparency ) of the window

`window_get_transparent( ) -> Bool`  
Returns a bool value ( `true` / `false` ) depending on the current state of the window transparency mode

`window_set_topmost( enable ) -> undefined`  
Allows you to **turn on** or **turn off** the visibility of a window on top of other windows ( Even if the window is out of focus, it will be displayed above all others )

`window_get_topmost( ) -> Bool`  
Returns a bool value ( `true` / `false` ) depending on whether the visibility mode of the current window is enabled over other windows