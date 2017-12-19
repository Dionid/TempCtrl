#include <stdio.h>

#include "common/platform.h"
#include "common/cs_file.h"
#include "mgos.h"
#include "mgos_rpc.h"
#include "mgos_event.h"
#include "mgos_app.h"
#include "mgos_gpio.h"
#include "mgos_mqtt.h"
#include "mgos_sys_config.h"
#include "mgos_timers.h"
#include "mgos_hal.h"
#include "mgos_dlsym.h"
#include "mjs.h"

// #include "mgos_rpc.h"

// static void s_debug_write_hook(enum mgos_hook_type type,
//                               const struct mgos_hook_arg *arg,
//                               void *userdata) {
//   static unsigned s_seq = 0;
//   mgos_dash_callf("Hello.Log", "{fd:%d, data: %.*Q, t: %.3lf, seq:%u}",
//                   arg->debug.fd, (int) arg->debug.len, arg->debug.data,
//                   mg_time(), s_seq);
//   s_seq++;
//   (void) type;
//   (void) userdata;
// }

// mgos_hook_register(MGOS_HOOK_DEBUG_WRITE, s_debug_write_hook, NULL);

// bool tz_register_debug_event_add_handler(mgos_event_handler_t hook_cb, void *userdata) {
//   return mgos_event_add_handler(MGOS_EVENT_LOG, hook_cb, userdata);
// }

static void tz_s_debug_write_cb(int ev, void *ev_data, void *userdata) {
  const struct mgos_debug_hook_arg *arg =
      (const struct mgos_debug_hook_arg *) ev_data;
  // "{fd:%d, data: %.*Q, t: %.3lf, seq:%u}", arg->fd,
  //                 (int) arg->len, arg->data, mg_time()
  struct mbuf prefb;
  struct json_out prefbout = JSON_OUT_MBUF(&prefb);
  mbuf_init(&prefb, 100);
  json_printf(&prefbout, "{data: %.*Q, t: %.3lf}", (int) arg->len, arg->data, mg_time());
  const struct mg_str pprefix = mg_mk_str_n(prefb.buf, prefb.len);
  mgos_mqtt_pub(mgos_sys_config_get_server_topicName(), pprefix.p, pprefix.len, 1, false);
  mbuf_free(&prefb);
  (void) ev;
  (void) ev_data;
  (void) userdata;
}

enum mgos_app_init_result mgos_app_init(void) {
  mgos_event_add_handler(MGOS_EVENT_LOG, tz_s_debug_write_cb, NULL);
  return MGOS_APP_INIT_SUCCESS;
}
