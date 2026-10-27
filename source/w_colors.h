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

/*
 * NOTE:
 * The names and values of these colors come from MonoGame.
 * https://github.com/MonoGame/MonoGame/blob/develop/MonoGame.Framework/Color.cs
 *
 * These are copyright by The Mono.Xna Team, under the MIT License.
 * The License is enclosed below:
 * The MIT License (MIT)
 * Portions Copyright © The Mono.Xna Team
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
 * THE SOFTWARE.
 *
 *  - remi 2026.10.27 12:20
 */

#define COLOR(r, g, b) {      \
  .red = (float)r / 255.0f,   \
  .green = (float)g / 255.0f, \
  .blue = (float)b / 255.0f,  \
  .alpha = 1.0f               \
}

static const Color COLOR_WHITE = COLOR(255, 255, 255);
static const Color COLOR_BLACK = COLOR(0, 0, 0);

static const Color COLOR_RED   = COLOR(255, 0, 0);
static const Color COLOR_GREEN = COLOR(0, 255, 0);
static const Color COLOR_BLUE  = COLOR(0, 0, 255);

static const Color COLOR_ANTIQUE_WHITE = COLOR(250, 235, 215);
static const Color COLOR_AQUA = COLOR(0, 255, 255);
static const Color COLOR_AQUAMARINE = COLOR(127, 255, 212);
static const Color COLOR_AZURE = COLOR(240, 255, 255);

static const Color COLOR_BEIGE = COLOR(245, 245, 22);
static const Color COLOR_BISQUE = COLOR(255, 228, 196);
static const Color COLOR_BLANCHED_ALMOND = COLOR(255, 235, 205);
static const Color COLOR_BLUE_VIOLET = COLOR(138, 43, 226);
static const Color COLOR_BROWN = COLOR(165, 42, 42);
static const Color COLOR_BURLY_WOOD = COLOR(222, 184, 135);

static const Color COLOR_CADET_BLUE = COLOR(95, 158, 160);
static const Color COLOR_CHARTREUSE = COLOR(127, 255, 0);
static const Color COLOR_CHOCOLATE = COLOR(210, 105, 30);
static const Color COLOR_CORAL = COLOR(255, 127, 80);
static const Color COLOR_CORNFLOWER_BLUE = COLOR(100, 149, 237);
static const Color COLOR_CORNSILK = COLOR(255, 248, 220);
static const Color COLOR_CRIMSON = COLOR(220, 20, 60);
static const Color COLOR_CYAN = COLOR(0, 255, 255);

static const Color COLOR_DIM_GRAY = COLOR(105, 105, 105);
static const Color COLOR_DODGER_BLUE = COLOR(30, 144, 255);

static const Color COLOR_FIREBRICK = COLOR(178, 34, 34);
static const Color COLOR_FLORAL_WHITE = COLOR(255, 250, 240);
static const Color COLOR_FOREST_GREEN = COLOR(34, 139, 34);
static const Color COLOR_FUCHSIA = COLOR(255, 0, 255);

static const Color COLOR_GAINSBORO = COLOR(220, 220, 220);
static const Color COLOR_GHOST_WHITE = COLOR(248, 248, 255);
static const Color COLOR_GOLD = COLOR(255, 215, 0);
static const Color COLOR_GOLDENROD = COLOR(218, 165, 32);
static const Color COLOR_GRAY = COLOR(128, 128, 128);
static const Color COLOR_GREEN_YELLOW = COLOR(173, 255, 47);

static const Color COLOR_HONEYDEW = COLOR(240, 255, 240);
static const Color COLOR_HOT_PINK = COLOR(255, 105, 180);

static const Color COLOR_INDIAN_RED = COLOR(205, 92, 92);
static const Color COLOR_INDIGO = COLOR(75, 0, 130);
static const Color COLOR_IVORY = COLOR(255, 255, 240);
static const Color COLOR_KHAKI = COLOR(240, 230, 140);

static const Color COLOR_LAVENDAR = COLOR(230, 230, 250);
static const Color COLOR_LAVENDAR_BLUSH = COLOR(255, 240, 245);
static const Color COLOR_LAWN_GREEN = COLOR(124, 252, 0);
static const Color COLOR_LEMON_CHIFFON = COLOR(255, 250, 205);
static const Color COLOR_LIME_GREEN = COLOR(50, 205, 50);
static const Color COLOR_LINEN = COLOR(250, 240, 230);

static const Color COLOR_MAGENTA = COLOR(255, 0, 255);
static const Color COLOR_MAROON = COLOR(128, 0, 0);
static const Color COLOR_MIDNIGHT_BLUE = COLOR(25, 25, 112);
static const Color COLOR_MINT_CREAM = COLOR(245, 255, 250);
static const Color COLOR_MISTY_ROSE = COLOR(255, 228, 225);
static const Color COLOR_MOCCASIN = COLOR(255, 228, 181);

static const Color COLOR_NAVAJO_WHITE = COLOR(255, 222, 173);
static const Color COLOR_NAVY = COLOR(0, 0, 128);

static const Color COLOR_OLD_LACE = COLOR(253, 245, 230);
static const Color COLOR_OLIVE = COLOR(128, 128, 0);
static const Color COLOR_OLIVE_DRAB = COLOR(107, 142, 35);
static const Color COLOR_ORANGE = COLOR(255, 165, 0);
static const Color COLOR_ORANGE_RED = COLOR(255, 165, 0);
static const Color COLOR_ORCHID = COLOR(218, 112, 214);

static const Color COLOR_PAPAYA_WHIP = COLOR(255, 239, 213);
static const Color COLOR_PEACH_PUFF = COLOR(255, 218, 185);
static const Color COLOR_PERU = COLOR(205, 133, 63);
static const Color COLOR_PINK = COLOR(255, 192, 203);
static const Color COLOR_PLUM = COLOR(221, 160, 221);
static const Color COLOR_POWDER_BLUE = COLOR(176, 224, 230);
static const Color COLOR_PURPLE = COLOR(128, 0, 128);
static const Color COLOR_ROSY_BROWN = COLOR(188, 143, 143);
static const Color COLOR_ROYAL_BLUE = COLOR(65, 105, 225);

static const Color COLOR_SADDLE_BROWN = COLOR(139, 69, 19);
static const Color COLOR_SALMON = COLOR(250, 128, 114);
static const Color COLOR_SANDY_BROWN = COLOR(244, 164, 96);
static const Color COLOR_SEA_GREEN = COLOR(46, 139, 87);
static const Color COLOR_SEA_SHELL = COLOR(255, 245, 238);
static const Color COLOR_SIENNA = COLOR(160, 82, 45);
static const Color COLOR_SILVER = COLOR(192, 192, 192);
static const Color COLOR_SKY_BLUE = COLOR(135, 206, 235);
static const Color COLOR_SLATE_BLUE = COLOR(106, 90, 205);
static const Color COLOR_SLATE_GRAY = COLOR(112, 128, 144);
static const Color COLOR_SNOW = COLOR(255, 250, 250);
static const Color COLOR_SPRING_GREEN = COLOR(0, 255, 127);
static const Color COLOR_STEEL_BLUE = COLOR(70, 130, 180);

static const Color COLOR_TAN = COLOR(210, 180, 140);
static const Color COLOR_TEAL = COLOR(0, 128, 128);
static const Color COLOR_THISTLE = COLOR(216, 191, 216);
static const Color COLOR_TOMATO = COLOR(255, 99, 71);
static const Color COLOR_TURQUOISE = COLOR(64, 224, 208);

static const Color COLOR_VIOLET = COLOR(238, 130, 238);

static const Color COLOR_WHEAT = COLOR(245, 222, 179);
static const Color COLOR_WHITE_SMOKE = COLOR(245, 245, 245);

static const Color COLOR_YELLOW = COLOR(255, 255, 0);
static const Color COLOR_YELLOW_GREEN = COLOR(154, 205, 50);

#undef COLOR

