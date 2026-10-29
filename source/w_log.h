
static inline const char*
ConvertBoolToString(bool value)
{
  return value ? "true" : "false";
}

static inline const char*
GetSSEVersionString()
{
  if (SDL_HasSSE42()) {
    return "4.2";
  } else if (SDL_HasSSE41()) {
    return "4.1";
  } else if (SDL_HasSSE3()) {
    return "3";
  } else if (SDL_HasSSE2()) {
    return "2";
  } else if (SDL_HasSSE()) {
    return "1";
  } else {
    return "none";
  }
}

static inline void
InitLog()
{
  SDL_Log("watson");

  SDL_Log(" ");

  SDL_Log("Platform: %s", SDL_GetPlatform());
  SDL_Log("CPU Cores: %d", SDL_GetNumLogicalCPUCores());
  SDL_Log("RAM: %d, GiB", SDL_GetSystemRAM() / 1024);

#ifdef SDL_SSE_INTRINSICS
  SDL_Log("SSE: %s", GetSSEVersionString());
#elifdef SDL_NEON_INTRINSICS
  SDL_Log("NEON: %s", ConvertBoolToString(SDL_HasNEON()));
#endif

  SDL_Log(" ");

  SDL_Log("SDL Version: %d (min: %d)", SDL_GetVersion(), SDL_VERSION);
}

#define SetErrorString(msg, ...)         \
  SDL_SetErrorString("%s (%s:%d): " msg, \
      __func__, __FILE__, __LINE__       \
      __VA_OPT__(,) ##__VA_ARGS__        \
  )

