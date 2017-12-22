#include <stdbool.h>
#include <stdio.h>

#include "common/cs_dbg.h"

#include "mgos_app.h"


extern bool mgos_arduino_compat_init(void);
extern bool mgos_i2c_init(void);
extern bool mgos_arduino_wire_init(void);
extern bool mgos_arduino_LiquidCrystal_I2C_init(void);
extern bool mgos_ca_bundle_init(void);
extern bool mgos_ota_http_client_init(void);
extern bool mgos_wifi_init(void);
extern bool mgos_http_server_init(void);
extern bool mgos_rpc_common_init(void);
extern bool mgos_shadow_init(void);
extern bool mgos_dash_init(void);
extern bool mgos_dht_init(void);
extern bool mgos_file_logger_init(void);
extern bool mgos_mjs_init(void);
extern bool mgos_ota_http_server_init(void);
extern bool mgos_rpc_loopback_init(void);
extern bool mgos_mqtt_init(void);
extern bool mgos_rpc_mqtt_init(void);
extern bool mgos_rpc_service_config_init(void);
extern bool mgos_rpc_service_fs_init(void);
extern bool mgos_rpc_service_gpio_init(void);
extern bool mgos_rpc_service_ota_init(void);
extern bool mgos_rpc_service_wifi_init(void);
extern bool mgos_rpc_uart_init(void);

static const struct lib_descr {
  const char *title;
  bool (*init)(void);
} descrs[] = {

  // "arduino_compat". deps: [ ]
  {
    .title = "arduino_compat",
    .init = mgos_arduino_compat_init,
  },

  // "i2c". deps: [ ]
  {
    .title = "i2c",
    .init = mgos_i2c_init,
  },

  // "arduino_wire". deps: [ "arduino-compat" "i2c" ]
  {
    .title = "arduino_wire",
    .init = mgos_arduino_wire_init,
  },

  // "arduino_LiquidCrystal_I2C". deps: [ "arduino-compat" "arduino-wire" ]
  {
    .title = "arduino_LiquidCrystal_I2C",
    .init = mgos_arduino_LiquidCrystal_I2C_init,
  },

  // "ca_bundle". deps: [ ]
  {
    .title = "ca_bundle",
    .init = mgos_ca_bundle_init,
  },

  // "ota_http_client". deps: [ ]
  {
    .title = "ota_http_client",
    .init = mgos_ota_http_client_init,
  },

  // "wifi". deps: [ ]
  {
    .title = "wifi",
    .init = mgos_wifi_init,
  },

  // "http_server". deps: [ "atca" "ethernet" "wifi" ]
  {
    .title = "http_server",
    .init = mgos_http_server_init,
  },

  // "rpc_common". deps: [ "http-server" ]
  {
    .title = "rpc_common",
    .init = mgos_rpc_common_init,
  },

  // "shadow". deps: [ ]
  {
    .title = "shadow",
    .init = mgos_shadow_init,
  },

  // "dash". deps: [ "ota-http-client" "rpc-common" "shadow" ]
  {
    .title = "dash",
    .init = mgos_dash_init,
  },

  // "dht". deps: [ ]
  {
    .title = "dht",
    .init = mgos_dht_init,
  },

  // "file_logger". deps: [ ]
  {
    .title = "file_logger",
    .init = mgos_file_logger_init,
  },

  // "mjs". deps: [ ]
  {
    .title = "mjs",
    .init = mgos_mjs_init,
  },

  // "ota_http_server". deps: [ "http-server" "ota-http-client" ]
  {
    .title = "ota_http_server",
    .init = mgos_ota_http_server_init,
  },

  // "rpc_loopback". deps: [ "rpc-common" ]
  {
    .title = "rpc_loopback",
    .init = mgos_rpc_loopback_init,
  },

  // "mqtt". deps: [ ]
  {
    .title = "mqtt",
    .init = mgos_mqtt_init,
  },

  // "rpc_mqtt". deps: [ "mqtt" "rpc-common" ]
  {
    .title = "rpc_mqtt",
    .init = mgos_rpc_mqtt_init,
  },

  // "rpc_service_config". deps: [ "rpc-common" ]
  {
    .title = "rpc_service_config",
    .init = mgos_rpc_service_config_init,
  },

  // "rpc_service_fs". deps: [ "rpc-common" ]
  {
    .title = "rpc_service_fs",
    .init = mgos_rpc_service_fs_init,
  },

  // "rpc_service_gpio". deps: [ "rpc-common" ]
  {
    .title = "rpc_service_gpio",
    .init = mgos_rpc_service_gpio_init,
  },

  // "rpc_service_ota". deps: [ "ota-http-client" "rpc-common" ]
  {
    .title = "rpc_service_ota",
    .init = mgos_rpc_service_ota_init,
  },

  // "rpc_service_wifi". deps: [ "rpc-common" "wifi" ]
  {
    .title = "rpc_service_wifi",
    .init = mgos_rpc_service_wifi_init,
  },

  // "rpc_uart". deps: [ "rpc-common" ]
  {
    .title = "rpc_uart",
    .init = mgos_rpc_uart_init,
  },

};

bool mgos_deps_init(void) {
  size_t i;
  for (i = 0; i < sizeof(descrs) / sizeof(struct lib_descr); i++) {
    LOG(LL_DEBUG, ("init %s...", descrs[i].title));
    if (!descrs[i].init()) {
      LOG(LL_ERROR, ("%s init failed", descrs[i].title));
      return false;
    }
  }

  return true;
}
