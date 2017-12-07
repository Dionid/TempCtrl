/* Generated file - do not edit. */

#include <stddef.h>
#include "mgos_config.h"

const struct mgos_conf_entry mgos_config_schema_[87] = {
  {.type = CONF_TYPE_OBJECT, .key = "", .num_desc = 86},
  {.type = CONF_TYPE_OBJECT, .key = "sntp", .num_desc = 5},
  {.type = CONF_TYPE_BOOL, .key = "enable", .offset = offsetof(struct mgos_config, sntp.enable)},
  {.type = CONF_TYPE_STRING, .key = "server", .offset = offsetof(struct mgos_config, sntp.server)},
  {.type = CONF_TYPE_INT, .key = "retry_min", .offset = offsetof(struct mgos_config, sntp.retry_min)},
  {.type = CONF_TYPE_INT, .key = "retry_max", .offset = offsetof(struct mgos_config, sntp.retry_max)},
  {.type = CONF_TYPE_INT, .key = "update_interval", .offset = offsetof(struct mgos_config, sntp.update_interval)},
  {.type = CONF_TYPE_OBJECT, .key = "update", .num_desc = 7},
  {.type = CONF_TYPE_INT, .key = "timeout", .offset = offsetof(struct mgos_config, update.timeout)},
  {.type = CONF_TYPE_INT, .key = "commit_timeout", .offset = offsetof(struct mgos_config, update.commit_timeout)},
  {.type = CONF_TYPE_STRING, .key = "url", .offset = offsetof(struct mgos_config, update.url)},
  {.type = CONF_TYPE_INT, .key = "interval", .offset = offsetof(struct mgos_config, update.interval)},
  {.type = CONF_TYPE_STRING, .key = "ssl_ca_file", .offset = offsetof(struct mgos_config, update.ssl_ca_file)},
  {.type = CONF_TYPE_STRING, .key = "ssl_client_cert_file", .offset = offsetof(struct mgos_config, update.ssl_client_cert_file)},
  {.type = CONF_TYPE_STRING, .key = "ssl_server_name", .offset = offsetof(struct mgos_config, update.ssl_server_name)},
  {.type = CONF_TYPE_OBJECT, .key = "device", .num_desc = 2},
  {.type = CONF_TYPE_STRING, .key = "id", .offset = offsetof(struct mgos_config, device.id)},
  {.type = CONF_TYPE_STRING, .key = "password", .offset = offsetof(struct mgos_config, device.password)},
  {.type = CONF_TYPE_OBJECT, .key = "debug", .num_desc = 8},
  {.type = CONF_TYPE_STRING, .key = "udp_log_addr", .offset = offsetof(struct mgos_config, debug.udp_log_addr)},
  {.type = CONF_TYPE_INT, .key = "mbedtls_level", .offset = offsetof(struct mgos_config, debug.mbedtls_level)},
  {.type = CONF_TYPE_INT, .key = "level", .offset = offsetof(struct mgos_config, debug.level)},
  {.type = CONF_TYPE_STRING, .key = "filter", .offset = offsetof(struct mgos_config, debug.filter)},
  {.type = CONF_TYPE_INT, .key = "stdout_uart", .offset = offsetof(struct mgos_config, debug.stdout_uart)},
  {.type = CONF_TYPE_INT, .key = "stderr_uart", .offset = offsetof(struct mgos_config, debug.stderr_uart)},
  {.type = CONF_TYPE_INT, .key = "factory_reset_gpio", .offset = offsetof(struct mgos_config, debug.factory_reset_gpio)},
  {.type = CONF_TYPE_STRING, .key = "mg_mgr_hexdump_file", .offset = offsetof(struct mgos_config, debug.mg_mgr_hexdump_file)},
  {.type = CONF_TYPE_OBJECT, .key = "sys", .num_desc = 7},
  {.type = CONF_TYPE_OBJECT, .key = "mount", .num_desc = 5},
  {.type = CONF_TYPE_STRING, .key = "path", .offset = offsetof(struct mgos_config, sys.mount.path)},
  {.type = CONF_TYPE_STRING, .key = "dev_type", .offset = offsetof(struct mgos_config, sys.mount.dev_type)},
  {.type = CONF_TYPE_STRING, .key = "dev_opts", .offset = offsetof(struct mgos_config, sys.mount.dev_opts)},
  {.type = CONF_TYPE_STRING, .key = "fs_type", .offset = offsetof(struct mgos_config, sys.mount.fs_type)},
  {.type = CONF_TYPE_STRING, .key = "fs_opts", .offset = offsetof(struct mgos_config, sys.mount.fs_opts)},
  {.type = CONF_TYPE_INT, .key = "wdt_timeout", .offset = offsetof(struct mgos_config, sys.wdt_timeout)},
  {.type = CONF_TYPE_STRING, .key = "conf_acl", .offset = offsetof(struct mgos_config, conf_acl)},
  {.type = CONF_TYPE_OBJECT, .key = "i2c", .num_desc = 5},
  {.type = CONF_TYPE_BOOL, .key = "enable", .offset = offsetof(struct mgos_config, i2c.enable)},
  {.type = CONF_TYPE_INT, .key = "freq", .offset = offsetof(struct mgos_config, i2c.freq)},
  {.type = CONF_TYPE_BOOL, .key = "debug", .offset = offsetof(struct mgos_config, i2c.debug)},
  {.type = CONF_TYPE_INT, .key = "sda_gpio", .offset = offsetof(struct mgos_config, i2c.sda_gpio)},
  {.type = CONF_TYPE_INT, .key = "scl_gpio", .offset = offsetof(struct mgos_config, i2c.scl_gpio)},
  {.type = CONF_TYPE_OBJECT, .key = "http", .num_desc = 10},
  {.type = CONF_TYPE_BOOL, .key = "enable", .offset = offsetof(struct mgos_config, http.enable)},
  {.type = CONF_TYPE_STRING, .key = "listen_addr", .offset = offsetof(struct mgos_config, http.listen_addr)},
  {.type = CONF_TYPE_STRING, .key = "document_root", .offset = offsetof(struct mgos_config, http.document_root)},
  {.type = CONF_TYPE_STRING, .key = "ssl_cert", .offset = offsetof(struct mgos_config, http.ssl_cert)},
  {.type = CONF_TYPE_STRING, .key = "ssl_key", .offset = offsetof(struct mgos_config, http.ssl_key)},
  {.type = CONF_TYPE_STRING, .key = "ssl_ca_cert", .offset = offsetof(struct mgos_config, http.ssl_ca_cert)},
  {.type = CONF_TYPE_STRING, .key = "upload_acl", .offset = offsetof(struct mgos_config, http.upload_acl)},
  {.type = CONF_TYPE_STRING, .key = "hidden_files", .offset = offsetof(struct mgos_config, http.hidden_files)},
  {.type = CONF_TYPE_STRING, .key = "auth_domain", .offset = offsetof(struct mgos_config, http.auth_domain)},
  {.type = CONF_TYPE_STRING, .key = "auth_file", .offset = offsetof(struct mgos_config, http.auth_file)},
  {.type = CONF_TYPE_OBJECT, .key = "mjs", .num_desc = 1},
  {.type = CONF_TYPE_BOOL, .key = "generate_jsc", .offset = offsetof(struct mgos_config, mjs.generate_jsc)},
  {.type = CONF_TYPE_OBJECT, .key = "rpc", .num_desc = 20},
  {.type = CONF_TYPE_BOOL, .key = "enable", .offset = offsetof(struct mgos_config, rpc.enable)},
  {.type = CONF_TYPE_INT, .key = "max_frame_size", .offset = offsetof(struct mgos_config, rpc.max_frame_size)},
  {.type = CONF_TYPE_INT, .key = "max_queue_length", .offset = offsetof(struct mgos_config, rpc.max_queue_length)},
  {.type = CONF_TYPE_INT, .key = "default_out_channel_idle_close_timeout", .offset = offsetof(struct mgos_config, rpc.default_out_channel_idle_close_timeout)},
  {.type = CONF_TYPE_STRING, .key = "acl_file", .offset = offsetof(struct mgos_config, rpc.acl_file)},
  {.type = CONF_TYPE_STRING, .key = "auth_domain", .offset = offsetof(struct mgos_config, rpc.auth_domain)},
  {.type = CONF_TYPE_STRING, .key = "auth_file", .offset = offsetof(struct mgos_config, rpc.auth_file)},
  {.type = CONF_TYPE_OBJECT, .key = "ws", .num_desc = 7},
  {.type = CONF_TYPE_BOOL, .key = "enable", .offset = offsetof(struct mgos_config, rpc.ws.enable)},
  {.type = CONF_TYPE_STRING, .key = "server_address", .offset = offsetof(struct mgos_config, rpc.ws.server_address)},
  {.type = CONF_TYPE_INT, .key = "reconnect_interval_min", .offset = offsetof(struct mgos_config, rpc.ws.reconnect_interval_min)},
  {.type = CONF_TYPE_INT, .key = "reconnect_interval_max", .offset = offsetof(struct mgos_config, rpc.ws.reconnect_interval_max)},
  {.type = CONF_TYPE_STRING, .key = "ssl_server_name", .offset = offsetof(struct mgos_config, rpc.ws.ssl_server_name)},
  {.type = CONF_TYPE_STRING, .key = "ssl_ca_file", .offset = offsetof(struct mgos_config, rpc.ws.ssl_ca_file)},
  {.type = CONF_TYPE_STRING, .key = "ssl_client_cert_file", .offset = offsetof(struct mgos_config, rpc.ws.ssl_client_cert_file)},
  {.type = CONF_TYPE_OBJECT, .key = "uart", .num_desc = 4},
  {.type = CONF_TYPE_INT, .key = "uart_no", .offset = offsetof(struct mgos_config, rpc.uart.uart_no)},
  {.type = CONF_TYPE_INT, .key = "baud_rate", .offset = offsetof(struct mgos_config, rpc.uart.baud_rate)},
  {.type = CONF_TYPE_INT, .key = "fc_type", .offset = offsetof(struct mgos_config, rpc.uart.fc_type)},
  {.type = CONF_TYPE_BOOL, .key = "wait_for_start_frame", .offset = offsetof(struct mgos_config, rpc.uart.wait_for_start_frame)},
  {.type = CONF_TYPE_OBJECT, .key = "app", .num_desc = 3},
  {.type = CONF_TYPE_STRING, .key = "devId", .offset = offsetof(struct mgos_config, app.devId)},
  {.type = CONF_TYPE_INT, .key = "minTemp", .offset = offsetof(struct mgos_config, app.minTemp)},
  {.type = CONF_TYPE_INT, .key = "maxTemp", .offset = offsetof(struct mgos_config, app.maxTemp)},
  {.type = CONF_TYPE_OBJECT, .key = "pins", .num_desc = 6},
  {.type = CONF_TYPE_INT, .key = "DHT", .offset = offsetof(struct mgos_config, pins.DHT)},
  {.type = CONF_TYPE_INT, .key = "HEAT_S", .offset = offsetof(struct mgos_config, pins.HEAT_S)},
  {.type = CONF_TYPE_INT, .key = "POWER", .offset = offsetof(struct mgos_config, pins.POWER)},
  {.type = CONF_TYPE_INT, .key = "DEC_BUTTON", .offset = offsetof(struct mgos_config, pins.DEC_BUTTON)},
  {.type = CONF_TYPE_INT, .key = "INC_BUTTON", .offset = offsetof(struct mgos_config, pins.INC_BUTTON)},
  {.type = CONF_TYPE_INT, .key = "SWITCH_BUTTON", .offset = offsetof(struct mgos_config, pins.SWITCH_BUTTON)},
};

const struct mgos_conf_entry *mgos_config_schema() {
  return mgos_config_schema_;
}

/* Global instance */
struct mgos_config mgos_sys_config;

/* Getters {{{ */
const struct mgos_config_sntp *mgos_config_get_sntp(struct mgos_config *cfg) {
  return &cfg->sntp;
}
int         mgos_config_get_sntp_enable(struct mgos_config *cfg) {
  return cfg->sntp.enable;
}
const char *mgos_config_get_sntp_server(struct mgos_config *cfg) {
  return cfg->sntp.server;
}
int         mgos_config_get_sntp_retry_min(struct mgos_config *cfg) {
  return cfg->sntp.retry_min;
}
int         mgos_config_get_sntp_retry_max(struct mgos_config *cfg) {
  return cfg->sntp.retry_max;
}
int         mgos_config_get_sntp_update_interval(struct mgos_config *cfg) {
  return cfg->sntp.update_interval;
}
const struct mgos_config_update *mgos_config_get_update(struct mgos_config *cfg) {
  return &cfg->update;
}
int         mgos_config_get_update_timeout(struct mgos_config *cfg) {
  return cfg->update.timeout;
}
int         mgos_config_get_update_commit_timeout(struct mgos_config *cfg) {
  return cfg->update.commit_timeout;
}
const char *mgos_config_get_update_url(struct mgos_config *cfg) {
  return cfg->update.url;
}
int         mgos_config_get_update_interval(struct mgos_config *cfg) {
  return cfg->update.interval;
}
const char *mgos_config_get_update_ssl_ca_file(struct mgos_config *cfg) {
  return cfg->update.ssl_ca_file;
}
const char *mgos_config_get_update_ssl_client_cert_file(struct mgos_config *cfg) {
  return cfg->update.ssl_client_cert_file;
}
const char *mgos_config_get_update_ssl_server_name(struct mgos_config *cfg) {
  return cfg->update.ssl_server_name;
}
const struct mgos_config_device *mgos_config_get_device(struct mgos_config *cfg) {
  return &cfg->device;
}
const char *mgos_config_get_device_id(struct mgos_config *cfg) {
  return cfg->device.id;
}
const char *mgos_config_get_device_password(struct mgos_config *cfg) {
  return cfg->device.password;
}
const struct mgos_config_debug *mgos_config_get_debug(struct mgos_config *cfg) {
  return &cfg->debug;
}
const char *mgos_config_get_debug_udp_log_addr(struct mgos_config *cfg) {
  return cfg->debug.udp_log_addr;
}
int         mgos_config_get_debug_mbedtls_level(struct mgos_config *cfg) {
  return cfg->debug.mbedtls_level;
}
int         mgos_config_get_debug_level(struct mgos_config *cfg) {
  return cfg->debug.level;
}
const char *mgos_config_get_debug_filter(struct mgos_config *cfg) {
  return cfg->debug.filter;
}
int         mgos_config_get_debug_stdout_uart(struct mgos_config *cfg) {
  return cfg->debug.stdout_uart;
}
int         mgos_config_get_debug_stderr_uart(struct mgos_config *cfg) {
  return cfg->debug.stderr_uart;
}
int         mgos_config_get_debug_factory_reset_gpio(struct mgos_config *cfg) {
  return cfg->debug.factory_reset_gpio;
}
const char *mgos_config_get_debug_mg_mgr_hexdump_file(struct mgos_config *cfg) {
  return cfg->debug.mg_mgr_hexdump_file;
}
const struct mgos_config_sys *mgos_config_get_sys(struct mgos_config *cfg) {
  return &cfg->sys;
}
const struct mgos_config_sys_mount *mgos_config_get_sys_mount(struct mgos_config *cfg) {
  return &cfg->sys.mount;
}
const char *mgos_config_get_sys_mount_path(struct mgos_config *cfg) {
  return cfg->sys.mount.path;
}
const char *mgos_config_get_sys_mount_dev_type(struct mgos_config *cfg) {
  return cfg->sys.mount.dev_type;
}
const char *mgos_config_get_sys_mount_dev_opts(struct mgos_config *cfg) {
  return cfg->sys.mount.dev_opts;
}
const char *mgos_config_get_sys_mount_fs_type(struct mgos_config *cfg) {
  return cfg->sys.mount.fs_type;
}
const char *mgos_config_get_sys_mount_fs_opts(struct mgos_config *cfg) {
  return cfg->sys.mount.fs_opts;
}
int         mgos_config_get_sys_wdt_timeout(struct mgos_config *cfg) {
  return cfg->sys.wdt_timeout;
}
const char *mgos_config_get_conf_acl(struct mgos_config *cfg) {
  return cfg->conf_acl;
}
const struct mgos_config_i2c *mgos_config_get_i2c(struct mgos_config *cfg) {
  return &cfg->i2c;
}
int         mgos_config_get_i2c_enable(struct mgos_config *cfg) {
  return cfg->i2c.enable;
}
int         mgos_config_get_i2c_freq(struct mgos_config *cfg) {
  return cfg->i2c.freq;
}
int         mgos_config_get_i2c_debug(struct mgos_config *cfg) {
  return cfg->i2c.debug;
}
int         mgos_config_get_i2c_sda_gpio(struct mgos_config *cfg) {
  return cfg->i2c.sda_gpio;
}
int         mgos_config_get_i2c_scl_gpio(struct mgos_config *cfg) {
  return cfg->i2c.scl_gpio;
}
const struct mgos_config_http *mgos_config_get_http(struct mgos_config *cfg) {
  return &cfg->http;
}
int         mgos_config_get_http_enable(struct mgos_config *cfg) {
  return cfg->http.enable;
}
const char *mgos_config_get_http_listen_addr(struct mgos_config *cfg) {
  return cfg->http.listen_addr;
}
const char *mgos_config_get_http_document_root(struct mgos_config *cfg) {
  return cfg->http.document_root;
}
const char *mgos_config_get_http_ssl_cert(struct mgos_config *cfg) {
  return cfg->http.ssl_cert;
}
const char *mgos_config_get_http_ssl_key(struct mgos_config *cfg) {
  return cfg->http.ssl_key;
}
const char *mgos_config_get_http_ssl_ca_cert(struct mgos_config *cfg) {
  return cfg->http.ssl_ca_cert;
}
const char *mgos_config_get_http_upload_acl(struct mgos_config *cfg) {
  return cfg->http.upload_acl;
}
const char *mgos_config_get_http_hidden_files(struct mgos_config *cfg) {
  return cfg->http.hidden_files;
}
const char *mgos_config_get_http_auth_domain(struct mgos_config *cfg) {
  return cfg->http.auth_domain;
}
const char *mgos_config_get_http_auth_file(struct mgos_config *cfg) {
  return cfg->http.auth_file;
}
const struct mgos_config_mjs *mgos_config_get_mjs(struct mgos_config *cfg) {
  return &cfg->mjs;
}
int         mgos_config_get_mjs_generate_jsc(struct mgos_config *cfg) {
  return cfg->mjs.generate_jsc;
}
const struct mgos_config_rpc *mgos_config_get_rpc(struct mgos_config *cfg) {
  return &cfg->rpc;
}
int         mgos_config_get_rpc_enable(struct mgos_config *cfg) {
  return cfg->rpc.enable;
}
int         mgos_config_get_rpc_max_frame_size(struct mgos_config *cfg) {
  return cfg->rpc.max_frame_size;
}
int         mgos_config_get_rpc_max_queue_length(struct mgos_config *cfg) {
  return cfg->rpc.max_queue_length;
}
int         mgos_config_get_rpc_default_out_channel_idle_close_timeout(struct mgos_config *cfg) {
  return cfg->rpc.default_out_channel_idle_close_timeout;
}
const char *mgos_config_get_rpc_acl_file(struct mgos_config *cfg) {
  return cfg->rpc.acl_file;
}
const char *mgos_config_get_rpc_auth_domain(struct mgos_config *cfg) {
  return cfg->rpc.auth_domain;
}
const char *mgos_config_get_rpc_auth_file(struct mgos_config *cfg) {
  return cfg->rpc.auth_file;
}
const struct mgos_config_rpc_ws *mgos_config_get_rpc_ws(struct mgos_config *cfg) {
  return &cfg->rpc.ws;
}
int         mgos_config_get_rpc_ws_enable(struct mgos_config *cfg) {
  return cfg->rpc.ws.enable;
}
const char *mgos_config_get_rpc_ws_server_address(struct mgos_config *cfg) {
  return cfg->rpc.ws.server_address;
}
int         mgos_config_get_rpc_ws_reconnect_interval_min(struct mgos_config *cfg) {
  return cfg->rpc.ws.reconnect_interval_min;
}
int         mgos_config_get_rpc_ws_reconnect_interval_max(struct mgos_config *cfg) {
  return cfg->rpc.ws.reconnect_interval_max;
}
const char *mgos_config_get_rpc_ws_ssl_server_name(struct mgos_config *cfg) {
  return cfg->rpc.ws.ssl_server_name;
}
const char *mgos_config_get_rpc_ws_ssl_ca_file(struct mgos_config *cfg) {
  return cfg->rpc.ws.ssl_ca_file;
}
const char *mgos_config_get_rpc_ws_ssl_client_cert_file(struct mgos_config *cfg) {
  return cfg->rpc.ws.ssl_client_cert_file;
}
const struct mgos_config_rpc_uart *mgos_config_get_rpc_uart(struct mgos_config *cfg) {
  return &cfg->rpc.uart;
}
int         mgos_config_get_rpc_uart_uart_no(struct mgos_config *cfg) {
  return cfg->rpc.uart.uart_no;
}
int         mgos_config_get_rpc_uart_baud_rate(struct mgos_config *cfg) {
  return cfg->rpc.uart.baud_rate;
}
int         mgos_config_get_rpc_uart_fc_type(struct mgos_config *cfg) {
  return cfg->rpc.uart.fc_type;
}
int         mgos_config_get_rpc_uart_wait_for_start_frame(struct mgos_config *cfg) {
  return cfg->rpc.uart.wait_for_start_frame;
}
const struct mgos_config_app *mgos_config_get_app(struct mgos_config *cfg) {
  return &cfg->app;
}
const char *mgos_config_get_app_devId(struct mgos_config *cfg) {
  return cfg->app.devId;
}
int         mgos_config_get_app_minTemp(struct mgos_config *cfg) {
  return cfg->app.minTemp;
}
int         mgos_config_get_app_maxTemp(struct mgos_config *cfg) {
  return cfg->app.maxTemp;
}
const struct mgos_config_pins *mgos_config_get_pins(struct mgos_config *cfg) {
  return &cfg->pins;
}
int         mgos_config_get_pins_DHT(struct mgos_config *cfg) {
  return cfg->pins.DHT;
}
int         mgos_config_get_pins_HEAT_S(struct mgos_config *cfg) {
  return cfg->pins.HEAT_S;
}
int         mgos_config_get_pins_POWER(struct mgos_config *cfg) {
  return cfg->pins.POWER;
}
int         mgos_config_get_pins_DEC_BUTTON(struct mgos_config *cfg) {
  return cfg->pins.DEC_BUTTON;
}
int         mgos_config_get_pins_INC_BUTTON(struct mgos_config *cfg) {
  return cfg->pins.INC_BUTTON;
}
int         mgos_config_get_pins_SWITCH_BUTTON(struct mgos_config *cfg) {
  return cfg->pins.SWITCH_BUTTON;
}
/* }}} */

/* Setters {{{ */
void mgos_config_set_sntp_enable(struct mgos_config *cfg, int         val) {
  cfg->sntp.enable = val;
}
void mgos_config_set_sntp_server(struct mgos_config *cfg, const char *val) {
  mgos_conf_set_str(&cfg->sntp.server, val);
}
void mgos_config_set_sntp_retry_min(struct mgos_config *cfg, int         val) {
  cfg->sntp.retry_min = val;
}
void mgos_config_set_sntp_retry_max(struct mgos_config *cfg, int         val) {
  cfg->sntp.retry_max = val;
}
void mgos_config_set_sntp_update_interval(struct mgos_config *cfg, int         val) {
  cfg->sntp.update_interval = val;
}
void mgos_config_set_update_timeout(struct mgos_config *cfg, int         val) {
  cfg->update.timeout = val;
}
void mgos_config_set_update_commit_timeout(struct mgos_config *cfg, int         val) {
  cfg->update.commit_timeout = val;
}
void mgos_config_set_update_url(struct mgos_config *cfg, const char *val) {
  mgos_conf_set_str(&cfg->update.url, val);
}
void mgos_config_set_update_interval(struct mgos_config *cfg, int         val) {
  cfg->update.interval = val;
}
void mgos_config_set_update_ssl_ca_file(struct mgos_config *cfg, const char *val) {
  mgos_conf_set_str(&cfg->update.ssl_ca_file, val);
}
void mgos_config_set_update_ssl_client_cert_file(struct mgos_config *cfg, const char *val) {
  mgos_conf_set_str(&cfg->update.ssl_client_cert_file, val);
}
void mgos_config_set_update_ssl_server_name(struct mgos_config *cfg, const char *val) {
  mgos_conf_set_str(&cfg->update.ssl_server_name, val);
}
void mgos_config_set_device_id(struct mgos_config *cfg, const char *val) {
  mgos_conf_set_str(&cfg->device.id, val);
}
void mgos_config_set_device_password(struct mgos_config *cfg, const char *val) {
  mgos_conf_set_str(&cfg->device.password, val);
}
void mgos_config_set_debug_udp_log_addr(struct mgos_config *cfg, const char *val) {
  mgos_conf_set_str(&cfg->debug.udp_log_addr, val);
}
void mgos_config_set_debug_mbedtls_level(struct mgos_config *cfg, int         val) {
  cfg->debug.mbedtls_level = val;
}
void mgos_config_set_debug_level(struct mgos_config *cfg, int         val) {
  cfg->debug.level = val;
}
void mgos_config_set_debug_filter(struct mgos_config *cfg, const char *val) {
  mgos_conf_set_str(&cfg->debug.filter, val);
}
void mgos_config_set_debug_stdout_uart(struct mgos_config *cfg, int         val) {
  cfg->debug.stdout_uart = val;
}
void mgos_config_set_debug_stderr_uart(struct mgos_config *cfg, int         val) {
  cfg->debug.stderr_uart = val;
}
void mgos_config_set_debug_factory_reset_gpio(struct mgos_config *cfg, int         val) {
  cfg->debug.factory_reset_gpio = val;
}
void mgos_config_set_debug_mg_mgr_hexdump_file(struct mgos_config *cfg, const char *val) {
  mgos_conf_set_str(&cfg->debug.mg_mgr_hexdump_file, val);
}
void mgos_config_set_sys_mount_path(struct mgos_config *cfg, const char *val) {
  mgos_conf_set_str(&cfg->sys.mount.path, val);
}
void mgos_config_set_sys_mount_dev_type(struct mgos_config *cfg, const char *val) {
  mgos_conf_set_str(&cfg->sys.mount.dev_type, val);
}
void mgos_config_set_sys_mount_dev_opts(struct mgos_config *cfg, const char *val) {
  mgos_conf_set_str(&cfg->sys.mount.dev_opts, val);
}
void mgos_config_set_sys_mount_fs_type(struct mgos_config *cfg, const char *val) {
  mgos_conf_set_str(&cfg->sys.mount.fs_type, val);
}
void mgos_config_set_sys_mount_fs_opts(struct mgos_config *cfg, const char *val) {
  mgos_conf_set_str(&cfg->sys.mount.fs_opts, val);
}
void mgos_config_set_sys_wdt_timeout(struct mgos_config *cfg, int         val) {
  cfg->sys.wdt_timeout = val;
}
void mgos_config_set_conf_acl(struct mgos_config *cfg, const char *val) {
  mgos_conf_set_str(&cfg->conf_acl, val);
}
void mgos_config_set_i2c_enable(struct mgos_config *cfg, int         val) {
  cfg->i2c.enable = val;
}
void mgos_config_set_i2c_freq(struct mgos_config *cfg, int         val) {
  cfg->i2c.freq = val;
}
void mgos_config_set_i2c_debug(struct mgos_config *cfg, int         val) {
  cfg->i2c.debug = val;
}
void mgos_config_set_i2c_sda_gpio(struct mgos_config *cfg, int         val) {
  cfg->i2c.sda_gpio = val;
}
void mgos_config_set_i2c_scl_gpio(struct mgos_config *cfg, int         val) {
  cfg->i2c.scl_gpio = val;
}
void mgos_config_set_http_enable(struct mgos_config *cfg, int         val) {
  cfg->http.enable = val;
}
void mgos_config_set_http_listen_addr(struct mgos_config *cfg, const char *val) {
  mgos_conf_set_str(&cfg->http.listen_addr, val);
}
void mgos_config_set_http_document_root(struct mgos_config *cfg, const char *val) {
  mgos_conf_set_str(&cfg->http.document_root, val);
}
void mgos_config_set_http_ssl_cert(struct mgos_config *cfg, const char *val) {
  mgos_conf_set_str(&cfg->http.ssl_cert, val);
}
void mgos_config_set_http_ssl_key(struct mgos_config *cfg, const char *val) {
  mgos_conf_set_str(&cfg->http.ssl_key, val);
}
void mgos_config_set_http_ssl_ca_cert(struct mgos_config *cfg, const char *val) {
  mgos_conf_set_str(&cfg->http.ssl_ca_cert, val);
}
void mgos_config_set_http_upload_acl(struct mgos_config *cfg, const char *val) {
  mgos_conf_set_str(&cfg->http.upload_acl, val);
}
void mgos_config_set_http_hidden_files(struct mgos_config *cfg, const char *val) {
  mgos_conf_set_str(&cfg->http.hidden_files, val);
}
void mgos_config_set_http_auth_domain(struct mgos_config *cfg, const char *val) {
  mgos_conf_set_str(&cfg->http.auth_domain, val);
}
void mgos_config_set_http_auth_file(struct mgos_config *cfg, const char *val) {
  mgos_conf_set_str(&cfg->http.auth_file, val);
}
void mgos_config_set_mjs_generate_jsc(struct mgos_config *cfg, int         val) {
  cfg->mjs.generate_jsc = val;
}
void mgos_config_set_rpc_enable(struct mgos_config *cfg, int         val) {
  cfg->rpc.enable = val;
}
void mgos_config_set_rpc_max_frame_size(struct mgos_config *cfg, int         val) {
  cfg->rpc.max_frame_size = val;
}
void mgos_config_set_rpc_max_queue_length(struct mgos_config *cfg, int         val) {
  cfg->rpc.max_queue_length = val;
}
void mgos_config_set_rpc_default_out_channel_idle_close_timeout(struct mgos_config *cfg, int         val) {
  cfg->rpc.default_out_channel_idle_close_timeout = val;
}
void mgos_config_set_rpc_acl_file(struct mgos_config *cfg, const char *val) {
  mgos_conf_set_str(&cfg->rpc.acl_file, val);
}
void mgos_config_set_rpc_auth_domain(struct mgos_config *cfg, const char *val) {
  mgos_conf_set_str(&cfg->rpc.auth_domain, val);
}
void mgos_config_set_rpc_auth_file(struct mgos_config *cfg, const char *val) {
  mgos_conf_set_str(&cfg->rpc.auth_file, val);
}
void mgos_config_set_rpc_ws_enable(struct mgos_config *cfg, int         val) {
  cfg->rpc.ws.enable = val;
}
void mgos_config_set_rpc_ws_server_address(struct mgos_config *cfg, const char *val) {
  mgos_conf_set_str(&cfg->rpc.ws.server_address, val);
}
void mgos_config_set_rpc_ws_reconnect_interval_min(struct mgos_config *cfg, int         val) {
  cfg->rpc.ws.reconnect_interval_min = val;
}
void mgos_config_set_rpc_ws_reconnect_interval_max(struct mgos_config *cfg, int         val) {
  cfg->rpc.ws.reconnect_interval_max = val;
}
void mgos_config_set_rpc_ws_ssl_server_name(struct mgos_config *cfg, const char *val) {
  mgos_conf_set_str(&cfg->rpc.ws.ssl_server_name, val);
}
void mgos_config_set_rpc_ws_ssl_ca_file(struct mgos_config *cfg, const char *val) {
  mgos_conf_set_str(&cfg->rpc.ws.ssl_ca_file, val);
}
void mgos_config_set_rpc_ws_ssl_client_cert_file(struct mgos_config *cfg, const char *val) {
  mgos_conf_set_str(&cfg->rpc.ws.ssl_client_cert_file, val);
}
void mgos_config_set_rpc_uart_uart_no(struct mgos_config *cfg, int         val) {
  cfg->rpc.uart.uart_no = val;
}
void mgos_config_set_rpc_uart_baud_rate(struct mgos_config *cfg, int         val) {
  cfg->rpc.uart.baud_rate = val;
}
void mgos_config_set_rpc_uart_fc_type(struct mgos_config *cfg, int         val) {
  cfg->rpc.uart.fc_type = val;
}
void mgos_config_set_rpc_uart_wait_for_start_frame(struct mgos_config *cfg, int         val) {
  cfg->rpc.uart.wait_for_start_frame = val;
}
void mgos_config_set_app_devId(struct mgos_config *cfg, const char *val) {
  mgos_conf_set_str(&cfg->app.devId, val);
}
void mgos_config_set_app_minTemp(struct mgos_config *cfg, int         val) {
  cfg->app.minTemp = val;
}
void mgos_config_set_app_maxTemp(struct mgos_config *cfg, int         val) {
  cfg->app.maxTemp = val;
}
void mgos_config_set_pins_DHT(struct mgos_config *cfg, int         val) {
  cfg->pins.DHT = val;
}
void mgos_config_set_pins_HEAT_S(struct mgos_config *cfg, int         val) {
  cfg->pins.HEAT_S = val;
}
void mgos_config_set_pins_POWER(struct mgos_config *cfg, int         val) {
  cfg->pins.POWER = val;
}
void mgos_config_set_pins_DEC_BUTTON(struct mgos_config *cfg, int         val) {
  cfg->pins.DEC_BUTTON = val;
}
void mgos_config_set_pins_INC_BUTTON(struct mgos_config *cfg, int         val) {
  cfg->pins.INC_BUTTON = val;
}
void mgos_config_set_pins_SWITCH_BUTTON(struct mgos_config *cfg, int         val) {
  cfg->pins.SWITCH_BUTTON = val;
}
/* }}} */
