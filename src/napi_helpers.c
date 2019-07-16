#include "src/napi_helpers.h"

char* napi_help_strfromval(napi_env env, napi_value opt) {
    size_t length = 0;
    char* buffer;
    napi_get_value_string_utf8(env, opt, NULL, 0, &length);
    length++; //Null terminator
    buffer = malloc(sizeof(char) * length);
    napi_get_value_string_utf8(env, opt, buffer, length, NULL);
    return buffer;
}

napi_value nprpl_conv_create(napi_env env, PurpleConversation *conv) {
    napi_value obj;
    napi_value value;
    napi_create_object(env, &obj);
    purple_conversation_get_name(conv);

    const char *sval = purple_conversation_get_name(conv);

    napi_create_string_utf8(env, sval, NAPI_AUTO_LENGTH, &value);
    napi_set_named_property(env, obj, "name", value);

    /* handle */
    napi_create_external(env, conv, NULL, NULL, &value);
    napi_set_named_property(env, obj, "handle", value);

    return obj;
}

napi_value nprpl_conv_chat_buddy_create(napi_env env, PurpleConvChatBuddy *buddy) {
    napi_value obj;
    napi_value value;
    napi_create_object(env, &obj);

    const char *sval = purple_conv_chat_cb_get_name(buddy);

    napi_create_string_utf8(env, sval, NAPI_AUTO_LENGTH, &value);
    napi_set_named_property(env, obj, "name", value);

    // TODO: alias, alias_key, flags, attributes

    /* handle */
    napi_create_external(env, buddy, NULL, NULL, &value);
    napi_set_named_property(env, obj, "handle", value);

    return obj;
}
