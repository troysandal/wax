//  Created by ProbablyInteractive.
//  Copyright 2009 Probably Interactive. All rights reserved.

#import <Foundation/Foundation.h>
#import "lua.h"

#define WAX_VERSION 0.93

#ifdef LUA_IS_LUAU
#define wax_lua_pushcfunction(L, fn, debugname) lua_pushcfunction(L, fn, #fn)

// In Lua 5.x we override these in luaconf.h. Luau's luaconf.h omits them
// so we define them here to ensure we compile.
#define WAX_SCRIPTS_DIR "scripts"
#define LUA_PATH_DEFAULT WAX_SCRIPTS_DIR "/?.lua;" WAX_SCRIPTS_DIR "/?/init.lua;" WAX_SCRIPTS_DIR "/?.dat;"\
                         "?.lua;" "?/init.lua;" "?.dat;"
#define LUA_CPATH_DEFAULT ""
#define WAX_LUA_INIT_SCRIPT "AppDelegate"

#endif



//just start wax with no script, and no extension. (can be used in swift)
void wax_startWithNil();

//setup lua, and load wax stdlib
void wax_start(char *initScript, lua_CFunction extensionFunctions, ...);

//start with wax server
void wax_startWithServer();

//setup lua
void wax_setup();


void wax_end();

lua_State *wax_currentLuaState();

void luaopen_wax(lua_State *L);

#pragma mark add by junzhan


//you should call wax_start before these function.
// run lua string.
int wax_runLuaString(const char *script);

//run lua byte code
int wax_runLuaByteCode(NSData *data, NSString *name);

//run lua file
int wax_runLuaFile(const char *filePath);




//lua runtime error callback
typedef  void (*WaxLuaRuntimeErrorHandler)(NSString *reason, BOOL willExit);

void wax_setLuaRuntimeErrorHandler(WaxLuaRuntimeErrorHandler handler);

WaxLuaRuntimeErrorHandler wax_getLuaRuntimeErrorHandler();

void wax_setCurrentLuaState(lua_State* L);
