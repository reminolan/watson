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

#ifndef DISPLAY_TITLE
#define DISPLAY_TITLE "watson"
#endif//DISPLAY_TITLE

#ifndef DISPLAY_WIDTH
#define DISPLAY_WIDTH (640)
#endif//DISPLAY_WIDTH

#ifndef DISPLAY_HEIGHT
#define DISPLAY_HEIGHT (360)
#endif//DISPLAY_HEIGHT

typedef struct Color {
    float red;
    float green;
    float blue;
    float alpha;
} Color;

typedef enum DisplayFlags: Uint8 {
  DISPLAY_FULLSCREEN  = 0b00000001,
  DISPLAY_VSYNC       = 0b00000010,
  DISPLAY_INT_SCALE   = 0b00000100,
  DISPLAY_HIDDEN      = 0b00001000,
} DisplayFlags;

typedef struct Display {
  DisplayFlags flags;
  SDL_Window* window;
  SDL_Renderer* renderer;
  Color clear;
} Display;

static inline SDL_WindowFlags
GetWindowFlags(DisplayFlags flags)
{
  SDL_WindowFlags result = 0;

  if (flags & DISPLAY_FULLSCREEN) {
    result |= SDL_WINDOW_FULLSCREEN;
  } else {
    result |= SDL_WINDOW_RESIZABLE;
  }

  if (flags & DISPLAY_HIDDEN) {
    result |= SDL_WINDOW_HIDDEN;
  }

  return result;
}

static inline void
SetRendererIntegerScaling(SDL_Renderer* render, DisplayFlags flags)
{
  SDL_RendererLogicalPresentation presentation_mode;
  if (flags & DISPLAY_INT_SCALE) {
    presentation_mode = SDL_LOGICAL_PRESENTATION_INTEGER_SCALE;
  } else {
    presentation_mode = SDL_LOGICAL_PRESENTATION_LETTERBOX;
  }
  SDL_SetRenderLogicalPresentation(render,
                                   DISPLAY_WIDTH, DISPLAY_HEIGHT,
                                   presentation_mode);
}

static inline bool
InitDisplay(Display* display, DisplayFlags flags)
{
  if (!display) {
    return false;
  }

  SDL_WindowFlags window_flags = GetWindowFlags(flags | DISPLAY_HIDDEN);
  bool created = SDL_CreateWindowAndRenderer(DISPLAY_TITLE,
                                             DISPLAY_WIDTH, DISPLAY_HEIGHT,
                                             window_flags,
                                             &display->window,
                                             &display->renderer);
  if (!created) {
    return false;
  }

  SDL_SetDefaultTextureScaleMode(display->renderer, SDL_SCALEMODE_PIXELART);
  SetRendererIntegerScaling(display->renderer, flags);

  bool sync = (flags & DISPLAY_VSYNC);
  if (sync) {
    sync = SDL_SetRenderVSync(display->renderer, SDL_RENDERER_VSYNC_ADAPTIVE);
    if (!sync) {
      SDL_Log("adaptive sync unavailable");
      sync = SDL_SetRenderVSync(display->renderer, 1);
      if (!sync) {
        SDL_Log("display sync unavailable");
      }
    }
  }

  bool hidden = (flags & DISPLAY_HIDDEN);
  if (!hidden) {
    SDL_ShowWindow(display->window);
  }

  return(true);
}

static inline void
QuitDisplay(Display* display)
{
  if (!display) {
    return;
  }

  if (display->renderer) {
    SDL_DestroyRenderer(display->renderer);
  }

  if (display->window) {
    SDL_DestroyWindow(display->window);
  }
}

static inline void
TickDisplay(Display* display)
{
  SDL_SetRenderTarget(display->renderer, NULL);

  SDL_RenderPresent(display->renderer);

  SDL_SetRenderDrawColorFloat(display->renderer,
                              display->clear.red,
                              display->clear.green,
                              display->clear.blue,
                              1.0f);
  SDL_RenderClear(display->renderer);
}

static inline bool
GetDisplayFullscreen(Display* display)
{
  return (display->flags & DISPLAY_FULLSCREEN);
}

static inline void
SetDisplayFullscreen(Display* display, bool value)
{
  display->flags &= ~DISPLAY_FULLSCREEN;
  display->flags |= DISPLAY_FULLSCREEN * value;

  SDL_SetWindowFullscreen(display->window, value);
}

static inline void
ToggleDisplayFullscreen(Display* display)
{
  display->flags ^= DISPLAY_FULLSCREEN;
  bool fullscreen = display->flags & DISPLAY_FULLSCREEN;
  SDL_SetWindowFullscreen(display->window, fullscreen);
}

static inline bool
GetDisplayIntegerScaling(Display* display)
{
  return (display->flags & DISPLAY_INT_SCALE);
}

static inline void
SetDisplayIntegerScaling(Display* display, bool value)
{
  display->flags &= ~DISPLAY_INT_SCALE;
  display->flags |= DISPLAY_INT_SCALE * value;

  SetRendererIntegerScaling(display->renderer, display->flags);
}

static inline void
ToggleDisplayIntegerScaling(Display* display)
{
  display->flags ^= DISPLAY_INT_SCALE;

  SetRendererIntegerScaling(display->renderer, display->flags);
}

static inline void
DrawPixel(Display* display, float x, float y, Color color)
{
  SDL_SetRenderDrawColorFloat(display->renderer,
                              color.red, color.green, color.blue, color.alpha);
  SDL_RenderPoint(display->renderer, x, y);
}

static inline void
DrawLine(Display* display,
         float x1, float y1, float x2, float y2,
         Color color)
{
  SDL_SetRenderDrawColorFloat(display->renderer,
                              color.red, color.green, color.blue, color.alpha);
  SDL_RenderLine(display->renderer, x1, y1, x2, y2);
}

static inline void
DrawRect(Display* display,
         float x, float y, float width, float height,
         Color color)
{
  SDL_SetRenderDrawColorFloat(display->renderer,
                              color.red, color.green, color.blue, color.alpha);
  SDL_FRect rect = { .x = x, .y = y, .w = width, .h = height };
  SDL_RenderFillRect(display->renderer, (const SDL_FRect*)&rect);
}

static inline void
DrawRectOutline(Display* display,
                float x, float y, float width, float height,
                Color color)
{
  SDL_SetRenderDrawColorFloat(display->renderer,
                              color.red, color.green, color.blue, color.alpha);
  SDL_FRect rect = { .x = x, .y = y, .w = width, .h = height };
  SDL_RenderRect(display->renderer, (const SDL_FRect*)&rect);
}

