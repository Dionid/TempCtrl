#include <stdio.h>

#include "common/platform.h"
#include "common/cs_file.h"
#include "mgos_app.h"
#include "mgos_gpio.h"
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

enum mgos_app_init_result mgos_app_init(void) {
  return MGOS_APP_INIT_SUCCESS;
}
