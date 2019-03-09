#ifndef LSEC_SSL_H
#define LSEC_SSL_H

/*--------------------------------------------------------------------------
 * LuaSec 0.7
 *
 * Copyright (C) 2006-2018 Bruno Silvestre
 *
 *--------------------------------------------------------------------------*/

#include <openssl/ssl.h>
#include <lua/lua/lua.h>

#include <lua/luasocket/io.h>
#include <lua/luasocket/buffer.h>
#include <lua/luasocket/timeout.h>
#include <lua/luasocket/socket.h>

#include <lua/luasec/compat.h>
#include <lua/luasec/context.h>

#if __cplusplus
extern "C" {
#endif

#define LSEC_STATE_NEW       1
#define LSEC_STATE_CONNECTED 2
#define LSEC_STATE_CLOSED    3

#define LSEC_IO_SSL          -100

typedef struct t_ssl_ {
  t_socket sock;
  t_io io;
  t_buffer buf;
  t_timeout tm;
  SSL *ssl;
  int state;
  int error;
} t_ssl;
typedef t_ssl* p_ssl;

LSEC_API int luaopen_ssl_core(lua_State *L);

#if __cplusplus
}
#endif

#endif