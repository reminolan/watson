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

static struct {
  Uint64 last_counter;
  float delta_time;
} g_time;

static inline void
TickTime()
{
  Uint64 counter = SDL_GetPerformanceCounter();
  float delta_counts = (float)(counter - g_time.last_counter);

  g_time.delta_time = delta_counts / (float)SDL_GetPerformanceFrequency();

  g_time.last_counter = counter;
}

static inline float
GetDeltaMilliseconds()
{
  return g_time.delta_time * 1000.0f;
}

static inline float
GetDeltaSeconds()
{
  return g_time.delta_time;
}

static inline float
GetDeltaMinutes()
{
  return g_time.delta_time / 60.0f;
}

