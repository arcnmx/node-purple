#ifndef BUDDY_H_INCLUDED
#define BUDDY_H_INCLUDED

#include <node_api.h>
#include <account.h>
#include <blist.h>
#include <buddyicon.h>
#include <status.h>
#include "src/napi_helpers.h"

void buddy_bind_node(napi_env env,napi_value root);

#endif
