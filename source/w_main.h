/*
 * Copyright (c) 2026 Duphus, LLC
 * 
 * This software is provided 'as-is', without any express or implied warranty.
 * In no event will the authors be held liable for any damages arising from the
 * use of this software.
 * 
 * Permission is granted to anyone to use this software for any purpose,
 * including commercial applications, and to alter it and redistribute it
 * freely, subject to the following restrictions:
 * 
 * 1. The origin of this software must not be misrepresented; you must not claim
 *    that you wrote the original software. If you use this software in a
 *    product, an acknowledgment in the product documentation would be
 *    appreciated but is not required.
 * 2. Altered source versions must be plainly marked as such, and must not be
 *    misrepresented as being the original software.
 * 3. This notice may not be removed or altered from any source distribution.
 */

#define SDL_MAIN_USE_CALLBACKS
#include <SDL3/SDL_main.h>

SDL_AppResult
SDL_AppInit(void** app_state, int arguments_count, char** arguments_array)
{
  (void)arguments_count;
  (void)arguments_array;

  SDL_InitFlags init_flags = SDL_INIT_VIDEO |
                             SDL_INIT_AUDIO |
                             SDL_INIT_EVENTS |
                             SDL_INIT_GAMEPAD;
  SDL_Init(init_flags);

  *app_state = SDL_calloc(sizeof(Display), 1);

  if (!(*app_state)) {
    SDL_Log("out of memory!!!!");
    return SDL_APP_FAILURE;
  }

  Display* display = (Display*)*app_state;

  DisplayFlags display_flags = DISPLAY_INT_SCALE | DISPLAY_VSYNC;
  if (!InitDisplay(display, display_flags)) {
    SDL_Log("InitDisplay returned false!!! %s", SDL_GetErrorString());
    return SDL_APP_FAILURE;
  }

  return SDL_APP_CONTINUE;
}

SDL_AppResult
SDL_AppEvent(void* app_state, SDL_Event* event)
{
  Display* display = (Display*)app_state;

  switch (event->type) {
    case SDL_EVENT_QUIT:
      return SDL_APP_SUCCESS;

    case SDL_EVENT_KEY_UP:
      switch (event->key.key) {
        case SDLK_F11:
          ToggleDisplayFullscreen(display);
          break;

        case SDLK_F10:
          ToggleDisplayIntegerScaling(display);
          break;
      }
      break;
  }

  return SDL_APP_CONTINUE;
}

SDL_AppResult
SDL_AppIterate(void* app_state)
{
  Display* display = (Display*)app_state;
  
  TickTime();
  TickDisplay(display);

  return SDL_APP_CONTINUE;
}

void
SDL_AppQuit(void* app_state, SDL_AppResult app_result)
{
  (void)app_result;

  Display* display = (Display*)app_state;
  QuitDisplay(display);

  SDL_Quit();
}

