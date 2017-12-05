/*
 * Generated file - do not edit.
 * Command: /mongoose-os/fw/tools/gen_sys_config.py --c_name=mgos_config --c_global_name=mgos_sys_config --dest_dir=/fwbuild-volumes/1.21/apps/Garage/esp8266/build_contexts/build_ctx_040478805/build/gen/ /mongoose-os/fw/src/mgos_debug_udp_config.yaml /mongoose-os/fw/src/mgos_sntp_config.yaml /mongoose-os/fw/src/mgos_updater_config.yaml /mongoose-os/fw/platforms/esp8266/src/esp_mbedtls_config.yaml /mongoose-os/fw/src/mgos_sys_config.yaml /mongoose-os/fw/platforms/esp8266/src/esp_sys_config.yaml /fwbuild-volumes/1.21/apps/Garage/esp8266/build_contexts/build_ctx_040478805/build/gen/mos_conf_schema.yml
 */

#ifndef MGOS_CONFIG_H_
#define MGOS_CONFIG_H_

#include "mgos_config_util.h"

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

struct mgos_config_sntp {
  int enable;
  char *server;
  int retry_min;
  int retry_max;
  int update_interval;
};

struct mgos_config_update {
  int timeout;
  int commit_timeout;
  char *url;
  int interval;
  char *ssl_ca_file;
  char *ssl_client_cert_file;
  char *ssl_server_name;
};

struct mgos_config_device {
  char *id;
  char *password;
};

struct mgos_config_debug {
  char *udp_log_addr;
  int mbedtls_level;
  int level;
  char *filter;
  int stdout_uart;
  int stderr_uart;
  int factory_reset_gpio;
  char *mg_mgr_hexdump_file;
};

struct mgos_config_sys_mount {
  char *path;
  char *dev_type;
  char *dev_opts;
  char *fs_type;
  char *fs_opts;
};

struct mgos_config_sys {
  struct mgos_config_sys_mount mount;
  int wdt_timeout;
};

struct mgos_config_i2c {
  int enable;
  int freq;
  int debug;
  int sda_gpio;
  int scl_gpio;
};

struct mgos_config_http {
  int enable;
  char *listen_addr;
  char *document_root;
  char *ssl_cert;
  char *ssl_key;
  char *ssl_ca_cert;
  char *upload_acl;
  char *hidden_files;
  char *auth_domain;
  char *auth_file;
};

struct mgos_config_mjs {
  int generate_jsc;
};

struct mgos_config_rpc_ws {
  int enable;
  char *server_address;
  int reconnect_interval_min;
  int reconnect_interval_max;
  char *ssl_server_name;
  char *ssl_ca_file;
  char *ssl_client_cert_file;
};

struct mgos_config_rpc_uart {
  int uart_no;
  int baud_rate;
  int fc_type;
  int wait_for_start_frame;
};

struct mgos_config_rpc {
  int enable;
  int max_frame_size;
  int max_queue_length;
  int default_out_channel_idle_close_timeout;
  char *acl_file;
  char *auth_domain;
  char *auth_file;
  struct mgos_config_rpc_ws ws;
  struct mgos_config_rpc_uart uart;
};

struct mgos_config_app {
  char *devId;
};

struct mgos_config_pins {
  int DHT;
  int HEAT_S;
  int POWER;
  int DEC_BUTTON;
  int INC_BUTTON;
  int SWITCH_BUTTON;
};

struct mgos_config {
  struct mgos_config_sntp sntp;
  struct mgos_config_update update;
  struct mgos_config_device device;
  struct mgos_config_debug debug;
  struct mgos_config_sys sys;
  char *conf_acl;
  struct mgos_config_i2c i2c;
  struct mgos_config_http http;
  struct mgos_config_mjs mjs;
  struct mgos_config_rpc rpc;
  struct mgos_config_app app;
  struct mgos_config_pins pins;
};

/* Parametrized accessor prototypes {{{ */
const struct mgos_config_sntp *mgos_config_get_sntp(struct mgos_config *cfg);
int         mgos_config_get_sntp_enable(struct mgos_config *cfg);
const char *mgos_config_get_sntp_server(struct mgos_config *cfg);
int         mgos_config_get_sntp_retry_min(struct mgos_config *cfg);
int         mgos_config_get_sntp_retry_max(struct mgos_config *cfg);
int         mgos_config_get_sntp_update_interval(struct mgos_config *cfg);
const struct mgos_config_update *mgos_config_get_update(struct mgos_config *cfg);
int         mgos_config_get_update_timeout(struct mgos_config *cfg);
int         mgos_config_get_update_commit_timeout(struct mgos_config *cfg);
const char *mgos_config_get_update_url(struct mgos_config *cfg);
int         mgos_config_get_update_interval(struct mgos_config *cfg);
const char *mgos_config_get_update_ssl_ca_file(struct mgos_config *cfg);
const char *mgos_config_get_update_ssl_client_cert_file(struct mgos_config *cfg);
const char *mgos_config_get_update_ssl_server_name(struct mgos_config *cfg);
const struct mgos_config_device *mgos_config_get_device(struct mgos_config *cfg);
const char *mgos_config_get_device_id(struct mgos_config *cfg);
const char *mgos_config_get_device_password(struct mgos_config *cfg);
const struct mgos_config_debug *mgos_config_get_debug(struct mgos_config *cfg);
const char *mgos_config_get_debug_udp_log_addr(struct mgos_config *cfg);
int         mgos_config_get_debug_mbedtls_level(struct mgos_config *cfg);
int         mgos_config_get_debug_level(struct mgos_config *cfg);
const char *mgos_config_get_debug_filter(struct mgos_config *cfg);
int         mgos_config_get_debug_stdout_uart(struct mgos_config *cfg);
int         mgos_config_get_debug_stderr_uart(struct mgos_config *cfg);
int         mgos_config_get_debug_factory_reset_gpio(struct mgos_config *cfg);
const char *mgos_config_get_debug_mg_mgr_hexdump_file(struct mgos_config *cfg);
const struct mgos_config_sys *mgos_config_get_sys(struct mgos_config *cfg);
const struct mgos_config_sys_mount *mgos_config_get_sys_mount(struct mgos_config *cfg);
const char *mgos_config_get_sys_mount_path(struct mgos_config *cfg);
const char *mgos_config_get_sys_mount_dev_type(struct mgos_config *cfg);
const char *mgos_config_get_sys_mount_dev_opts(struct mgos_config *cfg);
const char *mgos_config_get_sys_mount_fs_type(struct mgos_config *cfg);
const char *mgos_config_get_sys_mount_fs_opts(struct mgos_config *cfg);
int         mgos_config_get_sys_wdt_timeout(struct mgos_config *cfg);
const char *mgos_config_get_conf_acl(struct mgos_config *cfg);
const struct mgos_config_i2c *mgos_config_get_i2c(struct mgos_config *cfg);
int         mgos_config_get_i2c_enable(struct mgos_config *cfg);
int         mgos_config_get_i2c_freq(struct mgos_config *cfg);
int         mgos_config_get_i2c_debug(struct mgos_config *cfg);
int         mgos_config_get_i2c_sda_gpio(struct mgos_config *cfg);
int         mgos_config_get_i2c_scl_gpio(struct mgos_config *cfg);
const struct mgos_config_http *mgos_config_get_http(struct mgos_config *cfg);
int         mgos_config_get_http_enable(struct mgos_config *cfg);
const char *mgos_config_get_http_listen_addr(struct mgos_config *cfg);
const char *mgos_config_get_http_document_root(struct mgos_config *cfg);
const char *mgos_config_get_http_ssl_cert(struct mgos_config *cfg);
const char *mgos_config_get_http_ssl_key(struct mgos_config *cfg);
const char *mgos_config_get_http_ssl_ca_cert(struct mgos_config *cfg);
const char *mgos_config_get_http_upload_acl(struct mgos_config *cfg);
const char *mgos_config_get_http_hidden_files(struct mgos_config *cfg);
const char *mgos_config_get_http_auth_domain(struct mgos_config *cfg);
const char *mgos_config_get_http_auth_file(struct mgos_config *cfg);
const struct mgos_config_mjs *mgos_config_get_mjs(struct mgos_config *cfg);
int         mgos_config_get_mjs_generate_jsc(struct mgos_config *cfg);
const struct mgos_config_rpc *mgos_config_get_rpc(struct mgos_config *cfg);
int         mgos_config_get_rpc_enable(struct mgos_config *cfg);
int         mgos_config_get_rpc_max_frame_size(struct mgos_config *cfg);
int         mgos_config_get_rpc_max_queue_length(struct mgos_config *cfg);
int         mgos_config_get_rpc_default_out_channel_idle_close_timeout(struct mgos_config *cfg);
const char *mgos_config_get_rpc_acl_file(struct mgos_config *cfg);
const char *mgos_config_get_rpc_auth_domain(struct mgos_config *cfg);
const char *mgos_config_get_rpc_auth_file(struct mgos_config *cfg);
const struct mgos_config_rpc_ws *mgos_config_get_rpc_ws(struct mgos_config *cfg);
int         mgos_config_get_rpc_ws_enable(struct mgos_config *cfg);
const char *mgos_config_get_rpc_ws_server_address(struct mgos_config *cfg);
int         mgos_config_get_rpc_ws_reconnect_interval_min(struct mgos_config *cfg);
int         mgos_config_get_rpc_ws_reconnect_interval_max(struct mgos_config *cfg);
const char *mgos_config_get_rpc_ws_ssl_server_name(struct mgos_config *cfg);
const char *mgos_config_get_rpc_ws_ssl_ca_file(struct mgos_config *cfg);
const char *mgos_config_get_rpc_ws_ssl_client_cert_file(struct mgos_config *cfg);
const struct mgos_config_rpc_uart *mgos_config_get_rpc_uart(struct mgos_config *cfg);
int         mgos_config_get_rpc_uart_uart_no(struct mgos_config *cfg);
int         mgos_config_get_rpc_uart_baud_rate(struct mgos_config *cfg);
int         mgos_config_get_rpc_uart_fc_type(struct mgos_config *cfg);
int         mgos_config_get_rpc_uart_wait_for_start_frame(struct mgos_config *cfg);
const struct mgos_config_app *mgos_config_get_app(struct mgos_config *cfg);
const char *mgos_config_get_app_devId(struct mgos_config *cfg);
const struct mgos_config_pins *mgos_config_get_pins(struct mgos_config *cfg);
int         mgos_config_get_pins_DHT(struct mgos_config *cfg);
int         mgos_config_get_pins_HEAT_S(struct mgos_config *cfg);
int         mgos_config_get_pins_POWER(struct mgos_config *cfg);
int         mgos_config_get_pins_DEC_BUTTON(struct mgos_config *cfg);
int         mgos_config_get_pins_INC_BUTTON(struct mgos_config *cfg);
int         mgos_config_get_pins_SWITCH_BUTTON(struct mgos_config *cfg);

void mgos_config_set_sntp_enable(struct mgos_config *cfg, int         val);
void mgos_config_set_sntp_server(struct mgos_config *cfg, const char *val);
void mgos_config_set_sntp_retry_min(struct mgos_config *cfg, int         val);
void mgos_config_set_sntp_retry_max(struct mgos_config *cfg, int         val);
void mgos_config_set_sntp_update_interval(struct mgos_config *cfg, int         val);
void mgos_config_set_update_timeout(struct mgos_config *cfg, int         val);
void mgos_config_set_update_commit_timeout(struct mgos_config *cfg, int         val);
void mgos_config_set_update_url(struct mgos_config *cfg, const char *val);
void mgos_config_set_update_interval(struct mgos_config *cfg, int         val);
void mgos_config_set_update_ssl_ca_file(struct mgos_config *cfg, const char *val);
void mgos_config_set_update_ssl_client_cert_file(struct mgos_config *cfg, const char *val);
void mgos_config_set_update_ssl_server_name(struct mgos_config *cfg, const char *val);
void mgos_config_set_device_id(struct mgos_config *cfg, const char *val);
void mgos_config_set_device_password(struct mgos_config *cfg, const char *val);
void mgos_config_set_debug_udp_log_addr(struct mgos_config *cfg, const char *val);
void mgos_config_set_debug_mbedtls_level(struct mgos_config *cfg, int         val);
void mgos_config_set_debug_level(struct mgos_config *cfg, int         val);
void mgos_config_set_debug_filter(struct mgos_config *cfg, const char *val);
void mgos_config_set_debug_stdout_uart(struct mgos_config *cfg, int         val);
void mgos_config_set_debug_stderr_uart(struct mgos_config *cfg, int         val);
void mgos_config_set_debug_factory_reset_gpio(struct mgos_config *cfg, int         val);
void mgos_config_set_debug_mg_mgr_hexdump_file(struct mgos_config *cfg, const char *val);
void mgos_config_set_sys_mount_path(struct mgos_config *cfg, const char *val);
void mgos_config_set_sys_mount_dev_type(struct mgos_config *cfg, const char *val);
void mgos_config_set_sys_mount_dev_opts(struct mgos_config *cfg, const char *val);
void mgos_config_set_sys_mount_fs_type(struct mgos_config *cfg, const char *val);
void mgos_config_set_sys_mount_fs_opts(struct mgos_config *cfg, const char *val);
void mgos_config_set_sys_wdt_timeout(struct mgos_config *cfg, int         val);
void mgos_config_set_conf_acl(struct mgos_config *cfg, const char *val);
void mgos_config_set_i2c_enable(struct mgos_config *cfg, int         val);
void mgos_config_set_i2c_freq(struct mgos_config *cfg, int         val);
void mgos_config_set_i2c_debug(struct mgos_config *cfg, int         val);
void mgos_config_set_i2c_sda_gpio(struct mgos_config *cfg, int         val);
void mgos_config_set_i2c_scl_gpio(struct mgos_config *cfg, int         val);
void mgos_config_set_http_enable(struct mgos_config *cfg, int         val);
void mgos_config_set_http_listen_addr(struct mgos_config *cfg, const char *val);
void mgos_config_set_http_document_root(struct mgos_config *cfg, const char *val);
void mgos_config_set_http_ssl_cert(struct mgos_config *cfg, const char *val);
void mgos_config_set_http_ssl_key(struct mgos_config *cfg, const char *val);
void mgos_config_set_http_ssl_ca_cert(struct mgos_config *cfg, const char *val);
void mgos_config_set_http_upload_acl(struct mgos_config *cfg, const char *val);
void mgos_config_set_http_hidden_files(struct mgos_config *cfg, const char *val);
void mgos_config_set_http_auth_domain(struct mgos_config *cfg, const char *val);
void mgos_config_set_http_auth_file(struct mgos_config *cfg, const char *val);
void mgos_config_set_mjs_generate_jsc(struct mgos_config *cfg, int         val);
void mgos_config_set_rpc_enable(struct mgos_config *cfg, int         val);
void mgos_config_set_rpc_max_frame_size(struct mgos_config *cfg, int         val);
void mgos_config_set_rpc_max_queue_length(struct mgos_config *cfg, int         val);
void mgos_config_set_rpc_default_out_channel_idle_close_timeout(struct mgos_config *cfg, int         val);
void mgos_config_set_rpc_acl_file(struct mgos_config *cfg, const char *val);
void mgos_config_set_rpc_auth_domain(struct mgos_config *cfg, const char *val);
void mgos_config_set_rpc_auth_file(struct mgos_config *cfg, const char *val);
void mgos_config_set_rpc_ws_enable(struct mgos_config *cfg, int         val);
void mgos_config_set_rpc_ws_server_address(struct mgos_config *cfg, const char *val);
void mgos_config_set_rpc_ws_reconnect_interval_min(struct mgos_config *cfg, int         val);
void mgos_config_set_rpc_ws_reconnect_interval_max(struct mgos_config *cfg, int         val);
void mgos_config_set_rpc_ws_ssl_server_name(struct mgos_config *cfg, const char *val);
void mgos_config_set_rpc_ws_ssl_ca_file(struct mgos_config *cfg, const char *val);
void mgos_config_set_rpc_ws_ssl_client_cert_file(struct mgos_config *cfg, const char *val);
void mgos_config_set_rpc_uart_uart_no(struct mgos_config *cfg, int         val);
void mgos_config_set_rpc_uart_baud_rate(struct mgos_config *cfg, int         val);
void mgos_config_set_rpc_uart_fc_type(struct mgos_config *cfg, int         val);
void mgos_config_set_rpc_uart_wait_for_start_frame(struct mgos_config *cfg, int         val);
void mgos_config_set_app_devId(struct mgos_config *cfg, const char *val);
void mgos_config_set_pins_DHT(struct mgos_config *cfg, int         val);
void mgos_config_set_pins_HEAT_S(struct mgos_config *cfg, int         val);
void mgos_config_set_pins_POWER(struct mgos_config *cfg, int         val);
void mgos_config_set_pins_DEC_BUTTON(struct mgos_config *cfg, int         val);
void mgos_config_set_pins_INC_BUTTON(struct mgos_config *cfg, int         val);
void mgos_config_set_pins_SWITCH_BUTTON(struct mgos_config *cfg, int         val);
/* }}} */

extern struct mgos_config mgos_sys_config;

static inline const struct mgos_config_sntp *mgos_sys_config_get_sntp(void) { return mgos_config_get_sntp(&mgos_sys_config); }
static inline int         mgos_sys_config_get_sntp_enable(void) { return mgos_config_get_sntp_enable(&mgos_sys_config); }
static inline const char *mgos_sys_config_get_sntp_server(void) { return mgos_config_get_sntp_server(&mgos_sys_config); }
static inline int         mgos_sys_config_get_sntp_retry_min(void) { return mgos_config_get_sntp_retry_min(&mgos_sys_config); }
static inline int         mgos_sys_config_get_sntp_retry_max(void) { return mgos_config_get_sntp_retry_max(&mgos_sys_config); }
static inline int         mgos_sys_config_get_sntp_update_interval(void) { return mgos_config_get_sntp_update_interval(&mgos_sys_config); }
static inline const struct mgos_config_update *mgos_sys_config_get_update(void) { return mgos_config_get_update(&mgos_sys_config); }
static inline int         mgos_sys_config_get_update_timeout(void) { return mgos_config_get_update_timeout(&mgos_sys_config); }
static inline int         mgos_sys_config_get_update_commit_timeout(void) { return mgos_config_get_update_commit_timeout(&mgos_sys_config); }
static inline const char *mgos_sys_config_get_update_url(void) { return mgos_config_get_update_url(&mgos_sys_config); }
static inline int         mgos_sys_config_get_update_interval(void) { return mgos_config_get_update_interval(&mgos_sys_config); }
static inline const char *mgos_sys_config_get_update_ssl_ca_file(void) { return mgos_config_get_update_ssl_ca_file(&mgos_sys_config); }
static inline const char *mgos_sys_config_get_update_ssl_client_cert_file(void) { return mgos_config_get_update_ssl_client_cert_file(&mgos_sys_config); }
static inline const char *mgos_sys_config_get_update_ssl_server_name(void) { return mgos_config_get_update_ssl_server_name(&mgos_sys_config); }
static inline const struct mgos_config_device *mgos_sys_config_get_device(void) { return mgos_config_get_device(&mgos_sys_config); }
static inline const char *mgos_sys_config_get_device_id(void) { return mgos_config_get_device_id(&mgos_sys_config); }
static inline const char *mgos_sys_config_get_device_password(void) { return mgos_config_get_device_password(&mgos_sys_config); }
static inline const struct mgos_config_debug *mgos_sys_config_get_debug(void) { return mgos_config_get_debug(&mgos_sys_config); }
static inline const char *mgos_sys_config_get_debug_udp_log_addr(void) { return mgos_config_get_debug_udp_log_addr(&mgos_sys_config); }
static inline int         mgos_sys_config_get_debug_mbedtls_level(void) { return mgos_config_get_debug_mbedtls_level(&mgos_sys_config); }
static inline int         mgos_sys_config_get_debug_level(void) { return mgos_config_get_debug_level(&mgos_sys_config); }
static inline const char *mgos_sys_config_get_debug_filter(void) { return mgos_config_get_debug_filter(&mgos_sys_config); }
static inline int         mgos_sys_config_get_debug_stdout_uart(void) { return mgos_config_get_debug_stdout_uart(&mgos_sys_config); }
static inline int         mgos_sys_config_get_debug_stderr_uart(void) { return mgos_config_get_debug_stderr_uart(&mgos_sys_config); }
static inline int         mgos_sys_config_get_debug_factory_reset_gpio(void) { return mgos_config_get_debug_factory_reset_gpio(&mgos_sys_config); }
static inline const char *mgos_sys_config_get_debug_mg_mgr_hexdump_file(void) { return mgos_config_get_debug_mg_mgr_hexdump_file(&mgos_sys_config); }
static inline const struct mgos_config_sys *mgos_sys_config_get_sys(void) { return mgos_config_get_sys(&mgos_sys_config); }
static inline const struct mgos_config_sys_mount *mgos_sys_config_get_sys_mount(void) { return mgos_config_get_sys_mount(&mgos_sys_config); }
static inline const char *mgos_sys_config_get_sys_mount_path(void) { return mgos_config_get_sys_mount_path(&mgos_sys_config); }
static inline const char *mgos_sys_config_get_sys_mount_dev_type(void) { return mgos_config_get_sys_mount_dev_type(&mgos_sys_config); }
static inline const char *mgos_sys_config_get_sys_mount_dev_opts(void) { return mgos_config_get_sys_mount_dev_opts(&mgos_sys_config); }
static inline const char *mgos_sys_config_get_sys_mount_fs_type(void) { return mgos_config_get_sys_mount_fs_type(&mgos_sys_config); }
static inline const char *mgos_sys_config_get_sys_mount_fs_opts(void) { return mgos_config_get_sys_mount_fs_opts(&mgos_sys_config); }
static inline int         mgos_sys_config_get_sys_wdt_timeout(void) { return mgos_config_get_sys_wdt_timeout(&mgos_sys_config); }
static inline const char *mgos_sys_config_get_conf_acl(void) { return mgos_config_get_conf_acl(&mgos_sys_config); }
static inline const struct mgos_config_i2c *mgos_sys_config_get_i2c(void) { return mgos_config_get_i2c(&mgos_sys_config); }
static inline int         mgos_sys_config_get_i2c_enable(void) { return mgos_config_get_i2c_enable(&mgos_sys_config); }
static inline int         mgos_sys_config_get_i2c_freq(void) { return mgos_config_get_i2c_freq(&mgos_sys_config); }
static inline int         mgos_sys_config_get_i2c_debug(void) { return mgos_config_get_i2c_debug(&mgos_sys_config); }
static inline int         mgos_sys_config_get_i2c_sda_gpio(void) { return mgos_config_get_i2c_sda_gpio(&mgos_sys_config); }
static inline int         mgos_sys_config_get_i2c_scl_gpio(void) { return mgos_config_get_i2c_scl_gpio(&mgos_sys_config); }
static inline const struct mgos_config_http *mgos_sys_config_get_http(void) { return mgos_config_get_http(&mgos_sys_config); }
static inline int         mgos_sys_config_get_http_enable(void) { return mgos_config_get_http_enable(&mgos_sys_config); }
static inline const char *mgos_sys_config_get_http_listen_addr(void) { return mgos_config_get_http_listen_addr(&mgos_sys_config); }
static inline const char *mgos_sys_config_get_http_document_root(void) { return mgos_config_get_http_document_root(&mgos_sys_config); }
static inline const char *mgos_sys_config_get_http_ssl_cert(void) { return mgos_config_get_http_ssl_cert(&mgos_sys_config); }
static inline const char *mgos_sys_config_get_http_ssl_key(void) { return mgos_config_get_http_ssl_key(&mgos_sys_config); }
static inline const char *mgos_sys_config_get_http_ssl_ca_cert(void) { return mgos_config_get_http_ssl_ca_cert(&mgos_sys_config); }
static inline const char *mgos_sys_config_get_http_upload_acl(void) { return mgos_config_get_http_upload_acl(&mgos_sys_config); }
static inline const char *mgos_sys_config_get_http_hidden_files(void) { return mgos_config_get_http_hidden_files(&mgos_sys_config); }
static inline const char *mgos_sys_config_get_http_auth_domain(void) { return mgos_config_get_http_auth_domain(&mgos_sys_config); }
static inline const char *mgos_sys_config_get_http_auth_file(void) { return mgos_config_get_http_auth_file(&mgos_sys_config); }
static inline const struct mgos_config_mjs *mgos_sys_config_get_mjs(void) { return mgos_config_get_mjs(&mgos_sys_config); }
static inline int         mgos_sys_config_get_mjs_generate_jsc(void) { return mgos_config_get_mjs_generate_jsc(&mgos_sys_config); }
static inline const struct mgos_config_rpc *mgos_sys_config_get_rpc(void) { return mgos_config_get_rpc(&mgos_sys_config); }
static inline int         mgos_sys_config_get_rpc_enable(void) { return mgos_config_get_rpc_enable(&mgos_sys_config); }
static inline int         mgos_sys_config_get_rpc_max_frame_size(void) { return mgos_config_get_rpc_max_frame_size(&mgos_sys_config); }
static inline int         mgos_sys_config_get_rpc_max_queue_length(void) { return mgos_config_get_rpc_max_queue_length(&mgos_sys_config); }
static inline int         mgos_sys_config_get_rpc_default_out_channel_idle_close_timeout(void) { return mgos_config_get_rpc_default_out_channel_idle_close_timeout(&mgos_sys_config); }
static inline const char *mgos_sys_config_get_rpc_acl_file(void) { return mgos_config_get_rpc_acl_file(&mgos_sys_config); }
static inline const char *mgos_sys_config_get_rpc_auth_domain(void) { return mgos_config_get_rpc_auth_domain(&mgos_sys_config); }
static inline const char *mgos_sys_config_get_rpc_auth_file(void) { return mgos_config_get_rpc_auth_file(&mgos_sys_config); }
static inline const struct mgos_config_rpc_ws *mgos_sys_config_get_rpc_ws(void) { return mgos_config_get_rpc_ws(&mgos_sys_config); }
static inline int         mgos_sys_config_get_rpc_ws_enable(void) { return mgos_config_get_rpc_ws_enable(&mgos_sys_config); }
static inline const char *mgos_sys_config_get_rpc_ws_server_address(void) { return mgos_config_get_rpc_ws_server_address(&mgos_sys_config); }
static inline int         mgos_sys_config_get_rpc_ws_reconnect_interval_min(void) { return mgos_config_get_rpc_ws_reconnect_interval_min(&mgos_sys_config); }
static inline int         mgos_sys_config_get_rpc_ws_reconnect_interval_max(void) { return mgos_config_get_rpc_ws_reconnect_interval_max(&mgos_sys_config); }
static inline const char *mgos_sys_config_get_rpc_ws_ssl_server_name(void) { return mgos_config_get_rpc_ws_ssl_server_name(&mgos_sys_config); }
static inline const char *mgos_sys_config_get_rpc_ws_ssl_ca_file(void) { return mgos_config_get_rpc_ws_ssl_ca_file(&mgos_sys_config); }
static inline const char *mgos_sys_config_get_rpc_ws_ssl_client_cert_file(void) { return mgos_config_get_rpc_ws_ssl_client_cert_file(&mgos_sys_config); }
static inline const struct mgos_config_rpc_uart *mgos_sys_config_get_rpc_uart(void) { return mgos_config_get_rpc_uart(&mgos_sys_config); }
static inline int         mgos_sys_config_get_rpc_uart_uart_no(void) { return mgos_config_get_rpc_uart_uart_no(&mgos_sys_config); }
static inline int         mgos_sys_config_get_rpc_uart_baud_rate(void) { return mgos_config_get_rpc_uart_baud_rate(&mgos_sys_config); }
static inline int         mgos_sys_config_get_rpc_uart_fc_type(void) { return mgos_config_get_rpc_uart_fc_type(&mgos_sys_config); }
static inline int         mgos_sys_config_get_rpc_uart_wait_for_start_frame(void) { return mgos_config_get_rpc_uart_wait_for_start_frame(&mgos_sys_config); }
static inline const struct mgos_config_app *mgos_sys_config_get_app(void) { return mgos_config_get_app(&mgos_sys_config); }
static inline const char *mgos_sys_config_get_app_devId(void) { return mgos_config_get_app_devId(&mgos_sys_config); }
static inline const struct mgos_config_pins *mgos_sys_config_get_pins(void) { return mgos_config_get_pins(&mgos_sys_config); }
static inline int         mgos_sys_config_get_pins_DHT(void) { return mgos_config_get_pins_DHT(&mgos_sys_config); }
static inline int         mgos_sys_config_get_pins_HEAT_S(void) { return mgos_config_get_pins_HEAT_S(&mgos_sys_config); }
static inline int         mgos_sys_config_get_pins_POWER(void) { return mgos_config_get_pins_POWER(&mgos_sys_config); }
static inline int         mgos_sys_config_get_pins_DEC_BUTTON(void) { return mgos_config_get_pins_DEC_BUTTON(&mgos_sys_config); }
static inline int         mgos_sys_config_get_pins_INC_BUTTON(void) { return mgos_config_get_pins_INC_BUTTON(&mgos_sys_config); }
static inline int         mgos_sys_config_get_pins_SWITCH_BUTTON(void) { return mgos_config_get_pins_SWITCH_BUTTON(&mgos_sys_config); }

static inline void mgos_sys_config_set_sntp_enable(int         val) { mgos_config_set_sntp_enable(&mgos_sys_config, val); }
static inline void mgos_sys_config_set_sntp_server(const char *val) { mgos_config_set_sntp_server(&mgos_sys_config, val); }
static inline void mgos_sys_config_set_sntp_retry_min(int         val) { mgos_config_set_sntp_retry_min(&mgos_sys_config, val); }
static inline void mgos_sys_config_set_sntp_retry_max(int         val) { mgos_config_set_sntp_retry_max(&mgos_sys_config, val); }
static inline void mgos_sys_config_set_sntp_update_interval(int         val) { mgos_config_set_sntp_update_interval(&mgos_sys_config, val); }
static inline void mgos_sys_config_set_update_timeout(int         val) { mgos_config_set_update_timeout(&mgos_sys_config, val); }
static inline void mgos_sys_config_set_update_commit_timeout(int         val) { mgos_config_set_update_commit_timeout(&mgos_sys_config, val); }
static inline void mgos_sys_config_set_update_url(const char *val) { mgos_config_set_update_url(&mgos_sys_config, val); }
static inline void mgos_sys_config_set_update_interval(int         val) { mgos_config_set_update_interval(&mgos_sys_config, val); }
static inline void mgos_sys_config_set_update_ssl_ca_file(const char *val) { mgos_config_set_update_ssl_ca_file(&mgos_sys_config, val); }
static inline void mgos_sys_config_set_update_ssl_client_cert_file(const char *val) { mgos_config_set_update_ssl_client_cert_file(&mgos_sys_config, val); }
static inline void mgos_sys_config_set_update_ssl_server_name(const char *val) { mgos_config_set_update_ssl_server_name(&mgos_sys_config, val); }
static inline void mgos_sys_config_set_device_id(const char *val) { mgos_config_set_device_id(&mgos_sys_config, val); }
static inline void mgos_sys_config_set_device_password(const char *val) { mgos_config_set_device_password(&mgos_sys_config, val); }
static inline void mgos_sys_config_set_debug_udp_log_addr(const char *val) { mgos_config_set_debug_udp_log_addr(&mgos_sys_config, val); }
static inline void mgos_sys_config_set_debug_mbedtls_level(int         val) { mgos_config_set_debug_mbedtls_level(&mgos_sys_config, val); }
static inline void mgos_sys_config_set_debug_level(int         val) { mgos_config_set_debug_level(&mgos_sys_config, val); }
static inline void mgos_sys_config_set_debug_filter(const char *val) { mgos_config_set_debug_filter(&mgos_sys_config, val); }
static inline void mgos_sys_config_set_debug_stdout_uart(int         val) { mgos_config_set_debug_stdout_uart(&mgos_sys_config, val); }
static inline void mgos_sys_config_set_debug_stderr_uart(int         val) { mgos_config_set_debug_stderr_uart(&mgos_sys_config, val); }
static inline void mgos_sys_config_set_debug_factory_reset_gpio(int         val) { mgos_config_set_debug_factory_reset_gpio(&mgos_sys_config, val); }
static inline void mgos_sys_config_set_debug_mg_mgr_hexdump_file(const char *val) { mgos_config_set_debug_mg_mgr_hexdump_file(&mgos_sys_config, val); }
static inline void mgos_sys_config_set_sys_mount_path(const char *val) { mgos_config_set_sys_mount_path(&mgos_sys_config, val); }
static inline void mgos_sys_config_set_sys_mount_dev_type(const char *val) { mgos_config_set_sys_mount_dev_type(&mgos_sys_config, val); }
static inline void mgos_sys_config_set_sys_mount_dev_opts(const char *val) { mgos_config_set_sys_mount_dev_opts(&mgos_sys_config, val); }
static inline void mgos_sys_config_set_sys_mount_fs_type(const char *val) { mgos_config_set_sys_mount_fs_type(&mgos_sys_config, val); }
static inline void mgos_sys_config_set_sys_mount_fs_opts(const char *val) { mgos_config_set_sys_mount_fs_opts(&mgos_sys_config, val); }
static inline void mgos_sys_config_set_sys_wdt_timeout(int         val) { mgos_config_set_sys_wdt_timeout(&mgos_sys_config, val); }
static inline void mgos_sys_config_set_conf_acl(const char *val) { mgos_config_set_conf_acl(&mgos_sys_config, val); }
static inline void mgos_sys_config_set_i2c_enable(int         val) { mgos_config_set_i2c_enable(&mgos_sys_config, val); }
static inline void mgos_sys_config_set_i2c_freq(int         val) { mgos_config_set_i2c_freq(&mgos_sys_config, val); }
static inline void mgos_sys_config_set_i2c_debug(int         val) { mgos_config_set_i2c_debug(&mgos_sys_config, val); }
static inline void mgos_sys_config_set_i2c_sda_gpio(int         val) { mgos_config_set_i2c_sda_gpio(&mgos_sys_config, val); }
static inline void mgos_sys_config_set_i2c_scl_gpio(int         val) { mgos_config_set_i2c_scl_gpio(&mgos_sys_config, val); }
static inline void mgos_sys_config_set_http_enable(int         val) { mgos_config_set_http_enable(&mgos_sys_config, val); }
static inline void mgos_sys_config_set_http_listen_addr(const char *val) { mgos_config_set_http_listen_addr(&mgos_sys_config, val); }
static inline void mgos_sys_config_set_http_document_root(const char *val) { mgos_config_set_http_document_root(&mgos_sys_config, val); }
static inline void mgos_sys_config_set_http_ssl_cert(const char *val) { mgos_config_set_http_ssl_cert(&mgos_sys_config, val); }
static inline void mgos_sys_config_set_http_ssl_key(const char *val) { mgos_config_set_http_ssl_key(&mgos_sys_config, val); }
static inline void mgos_sys_config_set_http_ssl_ca_cert(const char *val) { mgos_config_set_http_ssl_ca_cert(&mgos_sys_config, val); }
static inline void mgos_sys_config_set_http_upload_acl(const char *val) { mgos_config_set_http_upload_acl(&mgos_sys_config, val); }
static inline void mgos_sys_config_set_http_hidden_files(const char *val) { mgos_config_set_http_hidden_files(&mgos_sys_config, val); }
static inline void mgos_sys_config_set_http_auth_domain(const char *val) { mgos_config_set_http_auth_domain(&mgos_sys_config, val); }
static inline void mgos_sys_config_set_http_auth_file(const char *val) { mgos_config_set_http_auth_file(&mgos_sys_config, val); }
static inline void mgos_sys_config_set_mjs_generate_jsc(int         val) { mgos_config_set_mjs_generate_jsc(&mgos_sys_config, val); }
static inline void mgos_sys_config_set_rpc_enable(int         val) { mgos_config_set_rpc_enable(&mgos_sys_config, val); }
static inline void mgos_sys_config_set_rpc_max_frame_size(int         val) { mgos_config_set_rpc_max_frame_size(&mgos_sys_config, val); }
static inline void mgos_sys_config_set_rpc_max_queue_length(int         val) { mgos_config_set_rpc_max_queue_length(&mgos_sys_config, val); }
static inline void mgos_sys_config_set_rpc_default_out_channel_idle_close_timeout(int         val) { mgos_config_set_rpc_default_out_channel_idle_close_timeout(&mgos_sys_config, val); }
static inline void mgos_sys_config_set_rpc_acl_file(const char *val) { mgos_config_set_rpc_acl_file(&mgos_sys_config, val); }
static inline void mgos_sys_config_set_rpc_auth_domain(const char *val) { mgos_config_set_rpc_auth_domain(&mgos_sys_config, val); }
static inline void mgos_sys_config_set_rpc_auth_file(const char *val) { mgos_config_set_rpc_auth_file(&mgos_sys_config, val); }
static inline void mgos_sys_config_set_rpc_ws_enable(int         val) { mgos_config_set_rpc_ws_enable(&mgos_sys_config, val); }
static inline void mgos_sys_config_set_rpc_ws_server_address(const char *val) { mgos_config_set_rpc_ws_server_address(&mgos_sys_config, val); }
static inline void mgos_sys_config_set_rpc_ws_reconnect_interval_min(int         val) { mgos_config_set_rpc_ws_reconnect_interval_min(&mgos_sys_config, val); }
static inline void mgos_sys_config_set_rpc_ws_reconnect_interval_max(int         val) { mgos_config_set_rpc_ws_reconnect_interval_max(&mgos_sys_config, val); }
static inline void mgos_sys_config_set_rpc_ws_ssl_server_name(const char *val) { mgos_config_set_rpc_ws_ssl_server_name(&mgos_sys_config, val); }
static inline void mgos_sys_config_set_rpc_ws_ssl_ca_file(const char *val) { mgos_config_set_rpc_ws_ssl_ca_file(&mgos_sys_config, val); }
static inline void mgos_sys_config_set_rpc_ws_ssl_client_cert_file(const char *val) { mgos_config_set_rpc_ws_ssl_client_cert_file(&mgos_sys_config, val); }
static inline void mgos_sys_config_set_rpc_uart_uart_no(int         val) { mgos_config_set_rpc_uart_uart_no(&mgos_sys_config, val); }
static inline void mgos_sys_config_set_rpc_uart_baud_rate(int         val) { mgos_config_set_rpc_uart_baud_rate(&mgos_sys_config, val); }
static inline void mgos_sys_config_set_rpc_uart_fc_type(int         val) { mgos_config_set_rpc_uart_fc_type(&mgos_sys_config, val); }
static inline void mgos_sys_config_set_rpc_uart_wait_for_start_frame(int         val) { mgos_config_set_rpc_uart_wait_for_start_frame(&mgos_sys_config, val); }
static inline void mgos_sys_config_set_app_devId(const char *val) { mgos_config_set_app_devId(&mgos_sys_config, val); }
static inline void mgos_sys_config_set_pins_DHT(int         val) { mgos_config_set_pins_DHT(&mgos_sys_config, val); }
static inline void mgos_sys_config_set_pins_HEAT_S(int         val) { mgos_config_set_pins_HEAT_S(&mgos_sys_config, val); }
static inline void mgos_sys_config_set_pins_POWER(int         val) { mgos_config_set_pins_POWER(&mgos_sys_config, val); }
static inline void mgos_sys_config_set_pins_DEC_BUTTON(int         val) { mgos_config_set_pins_DEC_BUTTON(&mgos_sys_config, val); }
static inline void mgos_sys_config_set_pins_INC_BUTTON(int         val) { mgos_config_set_pins_INC_BUTTON(&mgos_sys_config, val); }
static inline void mgos_sys_config_set_pins_SWITCH_BUTTON(int         val) { mgos_config_set_pins_SWITCH_BUTTON(&mgos_sys_config, val); }


const struct mgos_conf_entry *mgos_config_schema();

#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif /* MGOS_CONFIG_H_ */
