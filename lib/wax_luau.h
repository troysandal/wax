//
//  wax_luau.h
//  wax
//
//  Created by Troy on 8/25/25.
//

#ifndef WAX_LUAU_H
#define WAX_LUAU_H

/**
  Patches needed to compile against Luau.  All wax code is written
  against the Lua 5.x API.  To support the Luau API which is *almost*
  Lua 5.1 compatible, we add patches here and only include this file
  into wax compilation units.  This allows our code to be mixed into
  projects with Luau code.
 
  I couldn't think of a cleaner way to doing this, very open to one.
 */

#ifdef LUA_IS_LUAU
    // Luau added an argument to these macros that causes compile errors
    // in Lua 5.x compatible code.  Our code and the Lua 5.x code wax
    // compiles against needs to support both APIs, hence these redefinitions.
    //
    // NOTE: There could be more of these we haven't found.
    #undef lua_pushcfunction
    #define lua_pushcfunction(L, fn) lua_pushcclosurek(L, fn, #fn, 0, NULL)

    #undef lua_pushcclosure
    #define lua_pushcclosure(L, fn, nup) lua_pushcclosurek(L, fn, #fn, nup, NULL)
#endif

#endif
