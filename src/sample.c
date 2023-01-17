#ifdef USE_LUA
  #include <lua.h>
  #include <lauxlib.h>
  #include <lualib.h>
#else
  #include <lite_xl_plugin_api.h>
#endif

static int f_greet(lua_State* L) {
  const char* name = luaL_checkstring(L, 1);
  lua_pushfstring(L, "Hello %s!", name);
  return 2;
}

static const luaL_Reg sample_lib[] = {
  { "greet" , f_greet },
  { NULL, NULL }
};

int luaopen_sample(lua_State* L) {
  luaL_newlib(L, sample_lib);
  return 1;
}

/* Called by lite-xl f_load_native_plugin on `require "plugins.sample.native"` */
int luaopen_lite_xl_sample(lua_State *L, void* (*api_require)(char *)) {
#ifndef USE_LUA
  /* When using Lite XL Lua we need to import all required symbols */
  lite_xl_plugin_init(api_require);
#endif
  return luaopen_sample(L);
}
