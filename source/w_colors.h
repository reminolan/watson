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

#define COLOR_HEX(hex) {                            \
  .red = (float)((hex >> 24) & 0xFF) / 255.0f,      \
  .green = (float)((hex >> 16) & 0xFF) / 255.0f,    \
  .blue = (float)((hex >> 8) & 0xFF) / 255.0f       \
}

static const Color COLOR_WHITE = COLOR_HEX(0xFFFFFFFF);
static const Color COLOR_BLACK = COLOR_HEX(0x000000FF);

static const Color COLOR_RED   = COLOR_HEX(0xFF0000FF);
static const Color COLOR_GREEN = COLOR_HEX(0x00FF00FF);
static const Color COLOR_BLUE  = COLOR_HEX(0x0000FFFF);

/* TODO: more colors */

#undef COLOR_HEX

