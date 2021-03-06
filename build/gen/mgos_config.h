/*
 * Generated file - do not edit.
 * Command: /mongoose-os/fw/tools/gen_sys_config.py --c_name=mgos_config --c_global_name=mgos_sys_config --dest_dir=/fwbuild-volumes/1.22.1/apps/Garage/esp32/build_contexts/build_ctx_893974679/build/gen/ /mongoose-os/fw/src/mgos_debug_udp_config.yaml /mongoose-os/fw/src/mgos_sntp_config.yaml /mongoose-os/fw/src/mgos_updater_config.yaml /mongoose-os/fw/src/mgos_sys_config.yaml /mongoose-os/fw/platforms/esp32/src/esp32_sys_config.yaml /fwbuild-volumes/1.22.1/apps/Garage/esp32/build_contexts/build_ctx_893974679/build/gen/mos_conf_schema.yml
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
  int enable_post;
};

struct mgos_config_device {
  char *id;
  char *password;
  char *shadow_impl;
  char *type;
};

struct mgos_config_debug {
  char *udp_log_addr;
  int level;
  char *filter;
  int stdout_uart;
  int stderr_uart;
  int factory_reset_gpio;
  char *mg_mgr_hexdump_file;
  int mbedtls_level;
  char *stdout_topic;
  char *stderr_topic;
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
  char *tz_spec;
};

struct mgos_config_i2c {
  int enable;
  int freq;
  int debug;
  int sda_gpio;
  int scl_gpio;
};

struct mgos_config_wifi_sta {
  int enable;
  char *ssid;
  char *pass;
  char *user;
  char *anon_identity;
  char *cert;
  char *key;
  char *ca_cert;
  char *ip;
  char *netmask;
  char *gw;
  char *nameserver;
  char *dhcp_hostname;
};

struct mgos_config_wifi_ap {
  int enable;
  char *ssid;
  char *pass;
  int hidden;
  int channel;
  int max_connections;
  char *ip;
  char *netmask;
  char *gw;
  char *dhcp_start;
  char *dhcp_end;
  int trigger_on_gpio;
  int disable_after;
  char *hostname;
  int keep_enabled;
};

struct mgos_config_wifi {
  struct mgos_config_wifi_sta sta;
  struct mgos_config_wifi_ap ap;
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

struct mgos_config_rpc_ws {
  int enable;
  char *server_address;
  int reconnect_interval_min;
  int reconnect_interval_max;
  char *ssl_server_name;
  char *ssl_ca_file;
  char *ssl_client_cert_file;
};

struct mgos_config_rpc_mqtt {
  int enable;
  char *topic;
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
  struct mgos_config_rpc_mqtt mqtt;
  struct mgos_config_rpc_uart uart;
};

struct mgos_config_dash {
  int enable;
  char *token;
  char *server;
  char *ca_file;
  int heartbeat_interval;
  int send_logs;
  int send_stats;
};

struct mgos_config_file_logger {
  int enable;
  char *dir;
  char *prefix;
  int max_file_size;
  int max_num_files;
};

struct mgos_config_mjs {
  int generate_jsc;
};

struct mgos_config_mqtt {
  int enable;
  char *server;
  char *client_id;
  char *user;
  char *pass;
  double reconnect_timeout_min;
  double reconnect_timeout_max;
  char *ssl_cert;
  char *ssl_key;
  char *ssl_ca_cert;
  char *ssl_cipher_suites;
  char *ssl_psk_identity;
  char *ssl_psk_key;
  int clean_session;
  int keep_alive;
  char *will_topic;
  char *will_message;
  int max_qos;
  int recv_mbuf_limit;
};

struct mgos_config_server {
  char *id;
  char *topicName;
};

struct mgos_config_devices_mainDevice {
  char *id;
  char *type;
  char *mainHeaterStateName;
  char *mainTempAndHumSensorStateName;
};

struct mgos_config_devices_mainHeater {
  char *id;
  int HEAT_PIN;
  int POWER_PIN;
  int turnedOn;
};

struct mgos_config_devices_mainDHT {
  char *id;
  int DHT_PIN;
  int minTemp;
  int maxTemp;
  int autoCtrl;
  char *minTempActions;
  char *maxTempActions;
  int mainTimerInterval;
};

struct mgos_config_devices {
  struct mgos_config_devices_mainDevice mainDevice;
  struct mgos_config_devices_mainHeater mainHeater;
  struct mgos_config_devices_mainDHT mainDHT;
};

struct mgos_config_pins {
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
  struct mgos_config_wifi wifi;
  struct mgos_config_http http;
  struct mgos_config_rpc rpc;
  struct mgos_config_dash dash;
  struct mgos_config_file_logger file_logger;
  struct mgos_config_mjs mjs;
  struct mgos_config_mqtt mqtt;
  struct mgos_config_server server;
  struct mgos_config_devices devices;
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
int         mgos_config_get_update_enable_post(struct mgos_config *cfg);
const struct mgos_config_device *mgos_config_get_device(struct mgos_config *cfg);
const char *mgos_config_get_device_id(struct mgos_config *cfg);
const char *mgos_config_get_device_password(struct mgos_config *cfg);
const char *mgos_config_get_device_shadow_impl(struct mgos_config *cfg);
const char *mgos_config_get_device_type(struct mgos_config *cfg);
const struct mgos_config_debug *mgos_config_get_debug(struct mgos_config *cfg);
const char *mgos_config_get_debug_udp_log_addr(struct mgos_config *cfg);
int         mgos_config_get_debug_level(struct mgos_config *cfg);
const char *mgos_config_get_debug_filter(struct mgos_config *cfg);
int         mgos_config_get_debug_stdout_uart(struct mgos_config *cfg);
int         mgos_config_get_debug_stderr_uart(struct mgos_config *cfg);
int         mgos_config_get_debug_factory_reset_gpio(struct mgos_config *cfg);
const char *mgos_config_get_debug_mg_mgr_hexdump_file(struct mgos_config *cfg);
int         mgos_config_get_debug_mbedtls_level(struct mgos_config *cfg);
const char *mgos_config_get_debug_stdout_topic(struct mgos_config *cfg);
const char *mgos_config_get_debug_stderr_topic(struct mgos_config *cfg);
const struct mgos_config_sys *mgos_config_get_sys(struct mgos_config *cfg);
const struct mgos_config_sys_mount *mgos_config_get_sys_mount(struct mgos_config *cfg);
const char *mgos_config_get_sys_mount_path(struct mgos_config *cfg);
const char *mgos_config_get_sys_mount_dev_type(struct mgos_config *cfg);
const char *mgos_config_get_sys_mount_dev_opts(struct mgos_config *cfg);
const char *mgos_config_get_sys_mount_fs_type(struct mgos_config *cfg);
const char *mgos_config_get_sys_mount_fs_opts(struct mgos_config *cfg);
int         mgos_config_get_sys_wdt_timeout(struct mgos_config *cfg);
const char *mgos_config_get_sys_tz_spec(struct mgos_config *cfg);
const char *mgos_config_get_conf_acl(struct mgos_config *cfg);
const struct mgos_config_i2c *mgos_config_get_i2c(struct mgos_config *cfg);
int         mgos_config_get_i2c_enable(struct mgos_config *cfg);
int         mgos_config_get_i2c_freq(struct mgos_config *cfg);
int         mgos_config_get_i2c_debug(struct mgos_config *cfg);
int         mgos_config_get_i2c_sda_gpio(struct mgos_config *cfg);
int         mgos_config_get_i2c_scl_gpio(struct mgos_config *cfg);
const struct mgos_config_wifi *mgos_config_get_wifi(struct mgos_config *cfg);
const struct mgos_config_wifi_sta *mgos_config_get_wifi_sta(struct mgos_config *cfg);
int         mgos_config_get_wifi_sta_enable(struct mgos_config *cfg);
const char *mgos_config_get_wifi_sta_ssid(struct mgos_config *cfg);
const char *mgos_config_get_wifi_sta_pass(struct mgos_config *cfg);
const char *mgos_config_get_wifi_sta_user(struct mgos_config *cfg);
const char *mgos_config_get_wifi_sta_anon_identity(struct mgos_config *cfg);
const char *mgos_config_get_wifi_sta_cert(struct mgos_config *cfg);
const char *mgos_config_get_wifi_sta_key(struct mgos_config *cfg);
const char *mgos_config_get_wifi_sta_ca_cert(struct mgos_config *cfg);
const char *mgos_config_get_wifi_sta_ip(struct mgos_config *cfg);
const char *mgos_config_get_wifi_sta_netmask(struct mgos_config *cfg);
const char *mgos_config_get_wifi_sta_gw(struct mgos_config *cfg);
const char *mgos_config_get_wifi_sta_nameserver(struct mgos_config *cfg);
const char *mgos_config_get_wifi_sta_dhcp_hostname(struct mgos_config *cfg);
const struct mgos_config_wifi_ap *mgos_config_get_wifi_ap(struct mgos_config *cfg);
int         mgos_config_get_wifi_ap_enable(struct mgos_config *cfg);
const char *mgos_config_get_wifi_ap_ssid(struct mgos_config *cfg);
const char *mgos_config_get_wifi_ap_pass(struct mgos_config *cfg);
int         mgos_config_get_wifi_ap_hidden(struct mgos_config *cfg);
int         mgos_config_get_wifi_ap_channel(struct mgos_config *cfg);
int         mgos_config_get_wifi_ap_max_connections(struct mgos_config *cfg);
const char *mgos_config_get_wifi_ap_ip(struct mgos_config *cfg);
const char *mgos_config_get_wifi_ap_netmask(struct mgos_config *cfg);
const char *mgos_config_get_wifi_ap_gw(struct mgos_config *cfg);
const char *mgos_config_get_wifi_ap_dhcp_start(struct mgos_config *cfg);
const char *mgos_config_get_wifi_ap_dhcp_end(struct mgos_config *cfg);
int         mgos_config_get_wifi_ap_trigger_on_gpio(struct mgos_config *cfg);
int         mgos_config_get_wifi_ap_disable_after(struct mgos_config *cfg);
const char *mgos_config_get_wifi_ap_hostname(struct mgos_config *cfg);
int         mgos_config_get_wifi_ap_keep_enabled(struct mgos_config *cfg);
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
const struct mgos_config_rpc_mqtt *mgos_config_get_rpc_mqtt(struct mgos_config *cfg);
int         mgos_config_get_rpc_mqtt_enable(struct mgos_config *cfg);
const char *mgos_config_get_rpc_mqtt_topic(struct mgos_config *cfg);
const struct mgos_config_rpc_uart *mgos_config_get_rpc_uart(struct mgos_config *cfg);
int         mgos_config_get_rpc_uart_uart_no(struct mgos_config *cfg);
int         mgos_config_get_rpc_uart_baud_rate(struct mgos_config *cfg);
int         mgos_config_get_rpc_uart_fc_type(struct mgos_config *cfg);
int         mgos_config_get_rpc_uart_wait_for_start_frame(struct mgos_config *cfg);
const struct mgos_config_dash *mgos_config_get_dash(struct mgos_config *cfg);
int         mgos_config_get_dash_enable(struct mgos_config *cfg);
const char *mgos_config_get_dash_token(struct mgos_config *cfg);
const char *mgos_config_get_dash_server(struct mgos_config *cfg);
const char *mgos_config_get_dash_ca_file(struct mgos_config *cfg);
int         mgos_config_get_dash_heartbeat_interval(struct mgos_config *cfg);
int         mgos_config_get_dash_send_logs(struct mgos_config *cfg);
int         mgos_config_get_dash_send_stats(struct mgos_config *cfg);
const struct mgos_config_file_logger *mgos_config_get_file_logger(struct mgos_config *cfg);
int         mgos_config_get_file_logger_enable(struct mgos_config *cfg);
const char *mgos_config_get_file_logger_dir(struct mgos_config *cfg);
const char *mgos_config_get_file_logger_prefix(struct mgos_config *cfg);
int         mgos_config_get_file_logger_max_file_size(struct mgos_config *cfg);
int         mgos_config_get_file_logger_max_num_files(struct mgos_config *cfg);
const struct mgos_config_mjs *mgos_config_get_mjs(struct mgos_config *cfg);
int         mgos_config_get_mjs_generate_jsc(struct mgos_config *cfg);
const struct mgos_config_mqtt *mgos_config_get_mqtt(struct mgos_config *cfg);
int         mgos_config_get_mqtt_enable(struct mgos_config *cfg);
const char *mgos_config_get_mqtt_server(struct mgos_config *cfg);
const char *mgos_config_get_mqtt_client_id(struct mgos_config *cfg);
const char *mgos_config_get_mqtt_user(struct mgos_config *cfg);
const char *mgos_config_get_mqtt_pass(struct mgos_config *cfg);
double      mgos_config_get_mqtt_reconnect_timeout_min(struct mgos_config *cfg);
double      mgos_config_get_mqtt_reconnect_timeout_max(struct mgos_config *cfg);
const char *mgos_config_get_mqtt_ssl_cert(struct mgos_config *cfg);
const char *mgos_config_get_mqtt_ssl_key(struct mgos_config *cfg);
const char *mgos_config_get_mqtt_ssl_ca_cert(struct mgos_config *cfg);
const char *mgos_config_get_mqtt_ssl_cipher_suites(struct mgos_config *cfg);
const char *mgos_config_get_mqtt_ssl_psk_identity(struct mgos_config *cfg);
const char *mgos_config_get_mqtt_ssl_psk_key(struct mgos_config *cfg);
int         mgos_config_get_mqtt_clean_session(struct mgos_config *cfg);
int         mgos_config_get_mqtt_keep_alive(struct mgos_config *cfg);
const char *mgos_config_get_mqtt_will_topic(struct mgos_config *cfg);
const char *mgos_config_get_mqtt_will_message(struct mgos_config *cfg);
int         mgos_config_get_mqtt_max_qos(struct mgos_config *cfg);
int         mgos_config_get_mqtt_recv_mbuf_limit(struct mgos_config *cfg);
const struct mgos_config_server *mgos_config_get_server(struct mgos_config *cfg);
const char *mgos_config_get_server_id(struct mgos_config *cfg);
const char *mgos_config_get_server_topicName(struct mgos_config *cfg);
const struct mgos_config_devices *mgos_config_get_devices(struct mgos_config *cfg);
const struct mgos_config_devices_mainDevice *mgos_config_get_devices_mainDevice(struct mgos_config *cfg);
const char *mgos_config_get_devices_mainDevice_id(struct mgos_config *cfg);
const char *mgos_config_get_devices_mainDevice_type(struct mgos_config *cfg);
const char *mgos_config_get_devices_mainDevice_mainHeaterStateName(struct mgos_config *cfg);
const char *mgos_config_get_devices_mainDevice_mainTempAndHumSensorStateName(struct mgos_config *cfg);
const struct mgos_config_devices_mainHeater *mgos_config_get_devices_mainHeater(struct mgos_config *cfg);
const char *mgos_config_get_devices_mainHeater_id(struct mgos_config *cfg);
int         mgos_config_get_devices_mainHeater_HEAT_PIN(struct mgos_config *cfg);
int         mgos_config_get_devices_mainHeater_POWER_PIN(struct mgos_config *cfg);
int         mgos_config_get_devices_mainHeater_turnedOn(struct mgos_config *cfg);
const struct mgos_config_devices_mainDHT *mgos_config_get_devices_mainDHT(struct mgos_config *cfg);
const char *mgos_config_get_devices_mainDHT_id(struct mgos_config *cfg);
int         mgos_config_get_devices_mainDHT_DHT_PIN(struct mgos_config *cfg);
int         mgos_config_get_devices_mainDHT_minTemp(struct mgos_config *cfg);
int         mgos_config_get_devices_mainDHT_maxTemp(struct mgos_config *cfg);
int         mgos_config_get_devices_mainDHT_autoCtrl(struct mgos_config *cfg);
const char *mgos_config_get_devices_mainDHT_minTempActions(struct mgos_config *cfg);
const char *mgos_config_get_devices_mainDHT_maxTempActions(struct mgos_config *cfg);
int         mgos_config_get_devices_mainDHT_mainTimerInterval(struct mgos_config *cfg);
const struct mgos_config_pins *mgos_config_get_pins(struct mgos_config *cfg);
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
void mgos_config_set_update_enable_post(struct mgos_config *cfg, int         val);
void mgos_config_set_device_id(struct mgos_config *cfg, const char *val);
void mgos_config_set_device_password(struct mgos_config *cfg, const char *val);
void mgos_config_set_device_shadow_impl(struct mgos_config *cfg, const char *val);
void mgos_config_set_device_type(struct mgos_config *cfg, const char *val);
void mgos_config_set_debug_udp_log_addr(struct mgos_config *cfg, const char *val);
void mgos_config_set_debug_level(struct mgos_config *cfg, int         val);
void mgos_config_set_debug_filter(struct mgos_config *cfg, const char *val);
void mgos_config_set_debug_stdout_uart(struct mgos_config *cfg, int         val);
void mgos_config_set_debug_stderr_uart(struct mgos_config *cfg, int         val);
void mgos_config_set_debug_factory_reset_gpio(struct mgos_config *cfg, int         val);
void mgos_config_set_debug_mg_mgr_hexdump_file(struct mgos_config *cfg, const char *val);
void mgos_config_set_debug_mbedtls_level(struct mgos_config *cfg, int         val);
void mgos_config_set_debug_stdout_topic(struct mgos_config *cfg, const char *val);
void mgos_config_set_debug_stderr_topic(struct mgos_config *cfg, const char *val);
void mgos_config_set_sys_mount_path(struct mgos_config *cfg, const char *val);
void mgos_config_set_sys_mount_dev_type(struct mgos_config *cfg, const char *val);
void mgos_config_set_sys_mount_dev_opts(struct mgos_config *cfg, const char *val);
void mgos_config_set_sys_mount_fs_type(struct mgos_config *cfg, const char *val);
void mgos_config_set_sys_mount_fs_opts(struct mgos_config *cfg, const char *val);
void mgos_config_set_sys_wdt_timeout(struct mgos_config *cfg, int         val);
void mgos_config_set_sys_tz_spec(struct mgos_config *cfg, const char *val);
void mgos_config_set_conf_acl(struct mgos_config *cfg, const char *val);
void mgos_config_set_i2c_enable(struct mgos_config *cfg, int         val);
void mgos_config_set_i2c_freq(struct mgos_config *cfg, int         val);
void mgos_config_set_i2c_debug(struct mgos_config *cfg, int         val);
void mgos_config_set_i2c_sda_gpio(struct mgos_config *cfg, int         val);
void mgos_config_set_i2c_scl_gpio(struct mgos_config *cfg, int         val);
void mgos_config_set_wifi_sta_enable(struct mgos_config *cfg, int         val);
void mgos_config_set_wifi_sta_ssid(struct mgos_config *cfg, const char *val);
void mgos_config_set_wifi_sta_pass(struct mgos_config *cfg, const char *val);
void mgos_config_set_wifi_sta_user(struct mgos_config *cfg, const char *val);
void mgos_config_set_wifi_sta_anon_identity(struct mgos_config *cfg, const char *val);
void mgos_config_set_wifi_sta_cert(struct mgos_config *cfg, const char *val);
void mgos_config_set_wifi_sta_key(struct mgos_config *cfg, const char *val);
void mgos_config_set_wifi_sta_ca_cert(struct mgos_config *cfg, const char *val);
void mgos_config_set_wifi_sta_ip(struct mgos_config *cfg, const char *val);
void mgos_config_set_wifi_sta_netmask(struct mgos_config *cfg, const char *val);
void mgos_config_set_wifi_sta_gw(struct mgos_config *cfg, const char *val);
void mgos_config_set_wifi_sta_nameserver(struct mgos_config *cfg, const char *val);
void mgos_config_set_wifi_sta_dhcp_hostname(struct mgos_config *cfg, const char *val);
void mgos_config_set_wifi_ap_enable(struct mgos_config *cfg, int         val);
void mgos_config_set_wifi_ap_ssid(struct mgos_config *cfg, const char *val);
void mgos_config_set_wifi_ap_pass(struct mgos_config *cfg, const char *val);
void mgos_config_set_wifi_ap_hidden(struct mgos_config *cfg, int         val);
void mgos_config_set_wifi_ap_channel(struct mgos_config *cfg, int         val);
void mgos_config_set_wifi_ap_max_connections(struct mgos_config *cfg, int         val);
void mgos_config_set_wifi_ap_ip(struct mgos_config *cfg, const char *val);
void mgos_config_set_wifi_ap_netmask(struct mgos_config *cfg, const char *val);
void mgos_config_set_wifi_ap_gw(struct mgos_config *cfg, const char *val);
void mgos_config_set_wifi_ap_dhcp_start(struct mgos_config *cfg, const char *val);
void mgos_config_set_wifi_ap_dhcp_end(struct mgos_config *cfg, const char *val);
void mgos_config_set_wifi_ap_trigger_on_gpio(struct mgos_config *cfg, int         val);
void mgos_config_set_wifi_ap_disable_after(struct mgos_config *cfg, int         val);
void mgos_config_set_wifi_ap_hostname(struct mgos_config *cfg, const char *val);
void mgos_config_set_wifi_ap_keep_enabled(struct mgos_config *cfg, int         val);
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
void mgos_config_set_rpc_mqtt_enable(struct mgos_config *cfg, int         val);
void mgos_config_set_rpc_mqtt_topic(struct mgos_config *cfg, const char *val);
void mgos_config_set_rpc_uart_uart_no(struct mgos_config *cfg, int         val);
void mgos_config_set_rpc_uart_baud_rate(struct mgos_config *cfg, int         val);
void mgos_config_set_rpc_uart_fc_type(struct mgos_config *cfg, int         val);
void mgos_config_set_rpc_uart_wait_for_start_frame(struct mgos_config *cfg, int         val);
void mgos_config_set_dash_enable(struct mgos_config *cfg, int         val);
void mgos_config_set_dash_token(struct mgos_config *cfg, const char *val);
void mgos_config_set_dash_server(struct mgos_config *cfg, const char *val);
void mgos_config_set_dash_ca_file(struct mgos_config *cfg, const char *val);
void mgos_config_set_dash_heartbeat_interval(struct mgos_config *cfg, int         val);
void mgos_config_set_dash_send_logs(struct mgos_config *cfg, int         val);
void mgos_config_set_dash_send_stats(struct mgos_config *cfg, int         val);
void mgos_config_set_file_logger_enable(struct mgos_config *cfg, int         val);
void mgos_config_set_file_logger_dir(struct mgos_config *cfg, const char *val);
void mgos_config_set_file_logger_prefix(struct mgos_config *cfg, const char *val);
void mgos_config_set_file_logger_max_file_size(struct mgos_config *cfg, int         val);
void mgos_config_set_file_logger_max_num_files(struct mgos_config *cfg, int         val);
void mgos_config_set_mjs_generate_jsc(struct mgos_config *cfg, int         val);
void mgos_config_set_mqtt_enable(struct mgos_config *cfg, int         val);
void mgos_config_set_mqtt_server(struct mgos_config *cfg, const char *val);
void mgos_config_set_mqtt_client_id(struct mgos_config *cfg, const char *val);
void mgos_config_set_mqtt_user(struct mgos_config *cfg, const char *val);
void mgos_config_set_mqtt_pass(struct mgos_config *cfg, const char *val);
void mgos_config_set_mqtt_reconnect_timeout_min(struct mgos_config *cfg, double      val);
void mgos_config_set_mqtt_reconnect_timeout_max(struct mgos_config *cfg, double      val);
void mgos_config_set_mqtt_ssl_cert(struct mgos_config *cfg, const char *val);
void mgos_config_set_mqtt_ssl_key(struct mgos_config *cfg, const char *val);
void mgos_config_set_mqtt_ssl_ca_cert(struct mgos_config *cfg, const char *val);
void mgos_config_set_mqtt_ssl_cipher_suites(struct mgos_config *cfg, const char *val);
void mgos_config_set_mqtt_ssl_psk_identity(struct mgos_config *cfg, const char *val);
void mgos_config_set_mqtt_ssl_psk_key(struct mgos_config *cfg, const char *val);
void mgos_config_set_mqtt_clean_session(struct mgos_config *cfg, int         val);
void mgos_config_set_mqtt_keep_alive(struct mgos_config *cfg, int         val);
void mgos_config_set_mqtt_will_topic(struct mgos_config *cfg, const char *val);
void mgos_config_set_mqtt_will_message(struct mgos_config *cfg, const char *val);
void mgos_config_set_mqtt_max_qos(struct mgos_config *cfg, int         val);
void mgos_config_set_mqtt_recv_mbuf_limit(struct mgos_config *cfg, int         val);
void mgos_config_set_server_id(struct mgos_config *cfg, const char *val);
void mgos_config_set_server_topicName(struct mgos_config *cfg, const char *val);
void mgos_config_set_devices_mainDevice_id(struct mgos_config *cfg, const char *val);
void mgos_config_set_devices_mainDevice_type(struct mgos_config *cfg, const char *val);
void mgos_config_set_devices_mainDevice_mainHeaterStateName(struct mgos_config *cfg, const char *val);
void mgos_config_set_devices_mainDevice_mainTempAndHumSensorStateName(struct mgos_config *cfg, const char *val);
void mgos_config_set_devices_mainHeater_id(struct mgos_config *cfg, const char *val);
void mgos_config_set_devices_mainHeater_HEAT_PIN(struct mgos_config *cfg, int         val);
void mgos_config_set_devices_mainHeater_POWER_PIN(struct mgos_config *cfg, int         val);
void mgos_config_set_devices_mainHeater_turnedOn(struct mgos_config *cfg, int         val);
void mgos_config_set_devices_mainDHT_id(struct mgos_config *cfg, const char *val);
void mgos_config_set_devices_mainDHT_DHT_PIN(struct mgos_config *cfg, int         val);
void mgos_config_set_devices_mainDHT_minTemp(struct mgos_config *cfg, int         val);
void mgos_config_set_devices_mainDHT_maxTemp(struct mgos_config *cfg, int         val);
void mgos_config_set_devices_mainDHT_autoCtrl(struct mgos_config *cfg, int         val);
void mgos_config_set_devices_mainDHT_minTempActions(struct mgos_config *cfg, const char *val);
void mgos_config_set_devices_mainDHT_maxTempActions(struct mgos_config *cfg, const char *val);
void mgos_config_set_devices_mainDHT_mainTimerInterval(struct mgos_config *cfg, int         val);
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
static inline int         mgos_sys_config_get_update_enable_post(void) { return mgos_config_get_update_enable_post(&mgos_sys_config); }
static inline const struct mgos_config_device *mgos_sys_config_get_device(void) { return mgos_config_get_device(&mgos_sys_config); }
static inline const char *mgos_sys_config_get_device_id(void) { return mgos_config_get_device_id(&mgos_sys_config); }
static inline const char *mgos_sys_config_get_device_password(void) { return mgos_config_get_device_password(&mgos_sys_config); }
static inline const char *mgos_sys_config_get_device_shadow_impl(void) { return mgos_config_get_device_shadow_impl(&mgos_sys_config); }
static inline const char *mgos_sys_config_get_device_type(void) { return mgos_config_get_device_type(&mgos_sys_config); }
static inline const struct mgos_config_debug *mgos_sys_config_get_debug(void) { return mgos_config_get_debug(&mgos_sys_config); }
static inline const char *mgos_sys_config_get_debug_udp_log_addr(void) { return mgos_config_get_debug_udp_log_addr(&mgos_sys_config); }
static inline int         mgos_sys_config_get_debug_level(void) { return mgos_config_get_debug_level(&mgos_sys_config); }
static inline const char *mgos_sys_config_get_debug_filter(void) { return mgos_config_get_debug_filter(&mgos_sys_config); }
static inline int         mgos_sys_config_get_debug_stdout_uart(void) { return mgos_config_get_debug_stdout_uart(&mgos_sys_config); }
static inline int         mgos_sys_config_get_debug_stderr_uart(void) { return mgos_config_get_debug_stderr_uart(&mgos_sys_config); }
static inline int         mgos_sys_config_get_debug_factory_reset_gpio(void) { return mgos_config_get_debug_factory_reset_gpio(&mgos_sys_config); }
static inline const char *mgos_sys_config_get_debug_mg_mgr_hexdump_file(void) { return mgos_config_get_debug_mg_mgr_hexdump_file(&mgos_sys_config); }
static inline int         mgos_sys_config_get_debug_mbedtls_level(void) { return mgos_config_get_debug_mbedtls_level(&mgos_sys_config); }
static inline const char *mgos_sys_config_get_debug_stdout_topic(void) { return mgos_config_get_debug_stdout_topic(&mgos_sys_config); }
static inline const char *mgos_sys_config_get_debug_stderr_topic(void) { return mgos_config_get_debug_stderr_topic(&mgos_sys_config); }
static inline const struct mgos_config_sys *mgos_sys_config_get_sys(void) { return mgos_config_get_sys(&mgos_sys_config); }
static inline const struct mgos_config_sys_mount *mgos_sys_config_get_sys_mount(void) { return mgos_config_get_sys_mount(&mgos_sys_config); }
static inline const char *mgos_sys_config_get_sys_mount_path(void) { return mgos_config_get_sys_mount_path(&mgos_sys_config); }
static inline const char *mgos_sys_config_get_sys_mount_dev_type(void) { return mgos_config_get_sys_mount_dev_type(&mgos_sys_config); }
static inline const char *mgos_sys_config_get_sys_mount_dev_opts(void) { return mgos_config_get_sys_mount_dev_opts(&mgos_sys_config); }
static inline const char *mgos_sys_config_get_sys_mount_fs_type(void) { return mgos_config_get_sys_mount_fs_type(&mgos_sys_config); }
static inline const char *mgos_sys_config_get_sys_mount_fs_opts(void) { return mgos_config_get_sys_mount_fs_opts(&mgos_sys_config); }
static inline int         mgos_sys_config_get_sys_wdt_timeout(void) { return mgos_config_get_sys_wdt_timeout(&mgos_sys_config); }
static inline const char *mgos_sys_config_get_sys_tz_spec(void) { return mgos_config_get_sys_tz_spec(&mgos_sys_config); }
static inline const char *mgos_sys_config_get_conf_acl(void) { return mgos_config_get_conf_acl(&mgos_sys_config); }
static inline const struct mgos_config_i2c *mgos_sys_config_get_i2c(void) { return mgos_config_get_i2c(&mgos_sys_config); }
static inline int         mgos_sys_config_get_i2c_enable(void) { return mgos_config_get_i2c_enable(&mgos_sys_config); }
static inline int         mgos_sys_config_get_i2c_freq(void) { return mgos_config_get_i2c_freq(&mgos_sys_config); }
static inline int         mgos_sys_config_get_i2c_debug(void) { return mgos_config_get_i2c_debug(&mgos_sys_config); }
static inline int         mgos_sys_config_get_i2c_sda_gpio(void) { return mgos_config_get_i2c_sda_gpio(&mgos_sys_config); }
static inline int         mgos_sys_config_get_i2c_scl_gpio(void) { return mgos_config_get_i2c_scl_gpio(&mgos_sys_config); }
static inline const struct mgos_config_wifi *mgos_sys_config_get_wifi(void) { return mgos_config_get_wifi(&mgos_sys_config); }
static inline const struct mgos_config_wifi_sta *mgos_sys_config_get_wifi_sta(void) { return mgos_config_get_wifi_sta(&mgos_sys_config); }
static inline int         mgos_sys_config_get_wifi_sta_enable(void) { return mgos_config_get_wifi_sta_enable(&mgos_sys_config); }
static inline const char *mgos_sys_config_get_wifi_sta_ssid(void) { return mgos_config_get_wifi_sta_ssid(&mgos_sys_config); }
static inline const char *mgos_sys_config_get_wifi_sta_pass(void) { return mgos_config_get_wifi_sta_pass(&mgos_sys_config); }
static inline const char *mgos_sys_config_get_wifi_sta_user(void) { return mgos_config_get_wifi_sta_user(&mgos_sys_config); }
static inline const char *mgos_sys_config_get_wifi_sta_anon_identity(void) { return mgos_config_get_wifi_sta_anon_identity(&mgos_sys_config); }
static inline const char *mgos_sys_config_get_wifi_sta_cert(void) { return mgos_config_get_wifi_sta_cert(&mgos_sys_config); }
static inline const char *mgos_sys_config_get_wifi_sta_key(void) { return mgos_config_get_wifi_sta_key(&mgos_sys_config); }
static inline const char *mgos_sys_config_get_wifi_sta_ca_cert(void) { return mgos_config_get_wifi_sta_ca_cert(&mgos_sys_config); }
static inline const char *mgos_sys_config_get_wifi_sta_ip(void) { return mgos_config_get_wifi_sta_ip(&mgos_sys_config); }
static inline const char *mgos_sys_config_get_wifi_sta_netmask(void) { return mgos_config_get_wifi_sta_netmask(&mgos_sys_config); }
static inline const char *mgos_sys_config_get_wifi_sta_gw(void) { return mgos_config_get_wifi_sta_gw(&mgos_sys_config); }
static inline const char *mgos_sys_config_get_wifi_sta_nameserver(void) { return mgos_config_get_wifi_sta_nameserver(&mgos_sys_config); }
static inline const char *mgos_sys_config_get_wifi_sta_dhcp_hostname(void) { return mgos_config_get_wifi_sta_dhcp_hostname(&mgos_sys_config); }
static inline const struct mgos_config_wifi_ap *mgos_sys_config_get_wifi_ap(void) { return mgos_config_get_wifi_ap(&mgos_sys_config); }
static inline int         mgos_sys_config_get_wifi_ap_enable(void) { return mgos_config_get_wifi_ap_enable(&mgos_sys_config); }
static inline const char *mgos_sys_config_get_wifi_ap_ssid(void) { return mgos_config_get_wifi_ap_ssid(&mgos_sys_config); }
static inline const char *mgos_sys_config_get_wifi_ap_pass(void) { return mgos_config_get_wifi_ap_pass(&mgos_sys_config); }
static inline int         mgos_sys_config_get_wifi_ap_hidden(void) { return mgos_config_get_wifi_ap_hidden(&mgos_sys_config); }
static inline int         mgos_sys_config_get_wifi_ap_channel(void) { return mgos_config_get_wifi_ap_channel(&mgos_sys_config); }
static inline int         mgos_sys_config_get_wifi_ap_max_connections(void) { return mgos_config_get_wifi_ap_max_connections(&mgos_sys_config); }
static inline const char *mgos_sys_config_get_wifi_ap_ip(void) { return mgos_config_get_wifi_ap_ip(&mgos_sys_config); }
static inline const char *mgos_sys_config_get_wifi_ap_netmask(void) { return mgos_config_get_wifi_ap_netmask(&mgos_sys_config); }
static inline const char *mgos_sys_config_get_wifi_ap_gw(void) { return mgos_config_get_wifi_ap_gw(&mgos_sys_config); }
static inline const char *mgos_sys_config_get_wifi_ap_dhcp_start(void) { return mgos_config_get_wifi_ap_dhcp_start(&mgos_sys_config); }
static inline const char *mgos_sys_config_get_wifi_ap_dhcp_end(void) { return mgos_config_get_wifi_ap_dhcp_end(&mgos_sys_config); }
static inline int         mgos_sys_config_get_wifi_ap_trigger_on_gpio(void) { return mgos_config_get_wifi_ap_trigger_on_gpio(&mgos_sys_config); }
static inline int         mgos_sys_config_get_wifi_ap_disable_after(void) { return mgos_config_get_wifi_ap_disable_after(&mgos_sys_config); }
static inline const char *mgos_sys_config_get_wifi_ap_hostname(void) { return mgos_config_get_wifi_ap_hostname(&mgos_sys_config); }
static inline int         mgos_sys_config_get_wifi_ap_keep_enabled(void) { return mgos_config_get_wifi_ap_keep_enabled(&mgos_sys_config); }
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
static inline const struct mgos_config_rpc_mqtt *mgos_sys_config_get_rpc_mqtt(void) { return mgos_config_get_rpc_mqtt(&mgos_sys_config); }
static inline int         mgos_sys_config_get_rpc_mqtt_enable(void) { return mgos_config_get_rpc_mqtt_enable(&mgos_sys_config); }
static inline const char *mgos_sys_config_get_rpc_mqtt_topic(void) { return mgos_config_get_rpc_mqtt_topic(&mgos_sys_config); }
static inline const struct mgos_config_rpc_uart *mgos_sys_config_get_rpc_uart(void) { return mgos_config_get_rpc_uart(&mgos_sys_config); }
static inline int         mgos_sys_config_get_rpc_uart_uart_no(void) { return mgos_config_get_rpc_uart_uart_no(&mgos_sys_config); }
static inline int         mgos_sys_config_get_rpc_uart_baud_rate(void) { return mgos_config_get_rpc_uart_baud_rate(&mgos_sys_config); }
static inline int         mgos_sys_config_get_rpc_uart_fc_type(void) { return mgos_config_get_rpc_uart_fc_type(&mgos_sys_config); }
static inline int         mgos_sys_config_get_rpc_uart_wait_for_start_frame(void) { return mgos_config_get_rpc_uart_wait_for_start_frame(&mgos_sys_config); }
static inline const struct mgos_config_dash *mgos_sys_config_get_dash(void) { return mgos_config_get_dash(&mgos_sys_config); }
static inline int         mgos_sys_config_get_dash_enable(void) { return mgos_config_get_dash_enable(&mgos_sys_config); }
static inline const char *mgos_sys_config_get_dash_token(void) { return mgos_config_get_dash_token(&mgos_sys_config); }
static inline const char *mgos_sys_config_get_dash_server(void) { return mgos_config_get_dash_server(&mgos_sys_config); }
static inline const char *mgos_sys_config_get_dash_ca_file(void) { return mgos_config_get_dash_ca_file(&mgos_sys_config); }
static inline int         mgos_sys_config_get_dash_heartbeat_interval(void) { return mgos_config_get_dash_heartbeat_interval(&mgos_sys_config); }
static inline int         mgos_sys_config_get_dash_send_logs(void) { return mgos_config_get_dash_send_logs(&mgos_sys_config); }
static inline int         mgos_sys_config_get_dash_send_stats(void) { return mgos_config_get_dash_send_stats(&mgos_sys_config); }
static inline const struct mgos_config_file_logger *mgos_sys_config_get_file_logger(void) { return mgos_config_get_file_logger(&mgos_sys_config); }
static inline int         mgos_sys_config_get_file_logger_enable(void) { return mgos_config_get_file_logger_enable(&mgos_sys_config); }
static inline const char *mgos_sys_config_get_file_logger_dir(void) { return mgos_config_get_file_logger_dir(&mgos_sys_config); }
static inline const char *mgos_sys_config_get_file_logger_prefix(void) { return mgos_config_get_file_logger_prefix(&mgos_sys_config); }
static inline int         mgos_sys_config_get_file_logger_max_file_size(void) { return mgos_config_get_file_logger_max_file_size(&mgos_sys_config); }
static inline int         mgos_sys_config_get_file_logger_max_num_files(void) { return mgos_config_get_file_logger_max_num_files(&mgos_sys_config); }
static inline const struct mgos_config_mjs *mgos_sys_config_get_mjs(void) { return mgos_config_get_mjs(&mgos_sys_config); }
static inline int         mgos_sys_config_get_mjs_generate_jsc(void) { return mgos_config_get_mjs_generate_jsc(&mgos_sys_config); }
static inline const struct mgos_config_mqtt *mgos_sys_config_get_mqtt(void) { return mgos_config_get_mqtt(&mgos_sys_config); }
static inline int         mgos_sys_config_get_mqtt_enable(void) { return mgos_config_get_mqtt_enable(&mgos_sys_config); }
static inline const char *mgos_sys_config_get_mqtt_server(void) { return mgos_config_get_mqtt_server(&mgos_sys_config); }
static inline const char *mgos_sys_config_get_mqtt_client_id(void) { return mgos_config_get_mqtt_client_id(&mgos_sys_config); }
static inline const char *mgos_sys_config_get_mqtt_user(void) { return mgos_config_get_mqtt_user(&mgos_sys_config); }
static inline const char *mgos_sys_config_get_mqtt_pass(void) { return mgos_config_get_mqtt_pass(&mgos_sys_config); }
static inline double      mgos_sys_config_get_mqtt_reconnect_timeout_min(void) { return mgos_config_get_mqtt_reconnect_timeout_min(&mgos_sys_config); }
static inline double      mgos_sys_config_get_mqtt_reconnect_timeout_max(void) { return mgos_config_get_mqtt_reconnect_timeout_max(&mgos_sys_config); }
static inline const char *mgos_sys_config_get_mqtt_ssl_cert(void) { return mgos_config_get_mqtt_ssl_cert(&mgos_sys_config); }
static inline const char *mgos_sys_config_get_mqtt_ssl_key(void) { return mgos_config_get_mqtt_ssl_key(&mgos_sys_config); }
static inline const char *mgos_sys_config_get_mqtt_ssl_ca_cert(void) { return mgos_config_get_mqtt_ssl_ca_cert(&mgos_sys_config); }
static inline const char *mgos_sys_config_get_mqtt_ssl_cipher_suites(void) { return mgos_config_get_mqtt_ssl_cipher_suites(&mgos_sys_config); }
static inline const char *mgos_sys_config_get_mqtt_ssl_psk_identity(void) { return mgos_config_get_mqtt_ssl_psk_identity(&mgos_sys_config); }
static inline const char *mgos_sys_config_get_mqtt_ssl_psk_key(void) { return mgos_config_get_mqtt_ssl_psk_key(&mgos_sys_config); }
static inline int         mgos_sys_config_get_mqtt_clean_session(void) { return mgos_config_get_mqtt_clean_session(&mgos_sys_config); }
static inline int         mgos_sys_config_get_mqtt_keep_alive(void) { return mgos_config_get_mqtt_keep_alive(&mgos_sys_config); }
static inline const char *mgos_sys_config_get_mqtt_will_topic(void) { return mgos_config_get_mqtt_will_topic(&mgos_sys_config); }
static inline const char *mgos_sys_config_get_mqtt_will_message(void) { return mgos_config_get_mqtt_will_message(&mgos_sys_config); }
static inline int         mgos_sys_config_get_mqtt_max_qos(void) { return mgos_config_get_mqtt_max_qos(&mgos_sys_config); }
static inline int         mgos_sys_config_get_mqtt_recv_mbuf_limit(void) { return mgos_config_get_mqtt_recv_mbuf_limit(&mgos_sys_config); }
static inline const struct mgos_config_server *mgos_sys_config_get_server(void) { return mgos_config_get_server(&mgos_sys_config); }
static inline const char *mgos_sys_config_get_server_id(void) { return mgos_config_get_server_id(&mgos_sys_config); }
static inline const char *mgos_sys_config_get_server_topicName(void) { return mgos_config_get_server_topicName(&mgos_sys_config); }
static inline const struct mgos_config_devices *mgos_sys_config_get_devices(void) { return mgos_config_get_devices(&mgos_sys_config); }
static inline const struct mgos_config_devices_mainDevice *mgos_sys_config_get_devices_mainDevice(void) { return mgos_config_get_devices_mainDevice(&mgos_sys_config); }
static inline const char *mgos_sys_config_get_devices_mainDevice_id(void) { return mgos_config_get_devices_mainDevice_id(&mgos_sys_config); }
static inline const char *mgos_sys_config_get_devices_mainDevice_type(void) { return mgos_config_get_devices_mainDevice_type(&mgos_sys_config); }
static inline const char *mgos_sys_config_get_devices_mainDevice_mainHeaterStateName(void) { return mgos_config_get_devices_mainDevice_mainHeaterStateName(&mgos_sys_config); }
static inline const char *mgos_sys_config_get_devices_mainDevice_mainTempAndHumSensorStateName(void) { return mgos_config_get_devices_mainDevice_mainTempAndHumSensorStateName(&mgos_sys_config); }
static inline const struct mgos_config_devices_mainHeater *mgos_sys_config_get_devices_mainHeater(void) { return mgos_config_get_devices_mainHeater(&mgos_sys_config); }
static inline const char *mgos_sys_config_get_devices_mainHeater_id(void) { return mgos_config_get_devices_mainHeater_id(&mgos_sys_config); }
static inline int         mgos_sys_config_get_devices_mainHeater_HEAT_PIN(void) { return mgos_config_get_devices_mainHeater_HEAT_PIN(&mgos_sys_config); }
static inline int         mgos_sys_config_get_devices_mainHeater_POWER_PIN(void) { return mgos_config_get_devices_mainHeater_POWER_PIN(&mgos_sys_config); }
static inline int         mgos_sys_config_get_devices_mainHeater_turnedOn(void) { return mgos_config_get_devices_mainHeater_turnedOn(&mgos_sys_config); }
static inline const struct mgos_config_devices_mainDHT *mgos_sys_config_get_devices_mainDHT(void) { return mgos_config_get_devices_mainDHT(&mgos_sys_config); }
static inline const char *mgos_sys_config_get_devices_mainDHT_id(void) { return mgos_config_get_devices_mainDHT_id(&mgos_sys_config); }
static inline int         mgos_sys_config_get_devices_mainDHT_DHT_PIN(void) { return mgos_config_get_devices_mainDHT_DHT_PIN(&mgos_sys_config); }
static inline int         mgos_sys_config_get_devices_mainDHT_minTemp(void) { return mgos_config_get_devices_mainDHT_minTemp(&mgos_sys_config); }
static inline int         mgos_sys_config_get_devices_mainDHT_maxTemp(void) { return mgos_config_get_devices_mainDHT_maxTemp(&mgos_sys_config); }
static inline int         mgos_sys_config_get_devices_mainDHT_autoCtrl(void) { return mgos_config_get_devices_mainDHT_autoCtrl(&mgos_sys_config); }
static inline const char *mgos_sys_config_get_devices_mainDHT_minTempActions(void) { return mgos_config_get_devices_mainDHT_minTempActions(&mgos_sys_config); }
static inline const char *mgos_sys_config_get_devices_mainDHT_maxTempActions(void) { return mgos_config_get_devices_mainDHT_maxTempActions(&mgos_sys_config); }
static inline int         mgos_sys_config_get_devices_mainDHT_mainTimerInterval(void) { return mgos_config_get_devices_mainDHT_mainTimerInterval(&mgos_sys_config); }
static inline const struct mgos_config_pins *mgos_sys_config_get_pins(void) { return mgos_config_get_pins(&mgos_sys_config); }
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
static inline void mgos_sys_config_set_update_enable_post(int         val) { mgos_config_set_update_enable_post(&mgos_sys_config, val); }
static inline void mgos_sys_config_set_device_id(const char *val) { mgos_config_set_device_id(&mgos_sys_config, val); }
static inline void mgos_sys_config_set_device_password(const char *val) { mgos_config_set_device_password(&mgos_sys_config, val); }
static inline void mgos_sys_config_set_device_shadow_impl(const char *val) { mgos_config_set_device_shadow_impl(&mgos_sys_config, val); }
static inline void mgos_sys_config_set_device_type(const char *val) { mgos_config_set_device_type(&mgos_sys_config, val); }
static inline void mgos_sys_config_set_debug_udp_log_addr(const char *val) { mgos_config_set_debug_udp_log_addr(&mgos_sys_config, val); }
static inline void mgos_sys_config_set_debug_level(int         val) { mgos_config_set_debug_level(&mgos_sys_config, val); }
static inline void mgos_sys_config_set_debug_filter(const char *val) { mgos_config_set_debug_filter(&mgos_sys_config, val); }
static inline void mgos_sys_config_set_debug_stdout_uart(int         val) { mgos_config_set_debug_stdout_uart(&mgos_sys_config, val); }
static inline void mgos_sys_config_set_debug_stderr_uart(int         val) { mgos_config_set_debug_stderr_uart(&mgos_sys_config, val); }
static inline void mgos_sys_config_set_debug_factory_reset_gpio(int         val) { mgos_config_set_debug_factory_reset_gpio(&mgos_sys_config, val); }
static inline void mgos_sys_config_set_debug_mg_mgr_hexdump_file(const char *val) { mgos_config_set_debug_mg_mgr_hexdump_file(&mgos_sys_config, val); }
static inline void mgos_sys_config_set_debug_mbedtls_level(int         val) { mgos_config_set_debug_mbedtls_level(&mgos_sys_config, val); }
static inline void mgos_sys_config_set_debug_stdout_topic(const char *val) { mgos_config_set_debug_stdout_topic(&mgos_sys_config, val); }
static inline void mgos_sys_config_set_debug_stderr_topic(const char *val) { mgos_config_set_debug_stderr_topic(&mgos_sys_config, val); }
static inline void mgos_sys_config_set_sys_mount_path(const char *val) { mgos_config_set_sys_mount_path(&mgos_sys_config, val); }
static inline void mgos_sys_config_set_sys_mount_dev_type(const char *val) { mgos_config_set_sys_mount_dev_type(&mgos_sys_config, val); }
static inline void mgos_sys_config_set_sys_mount_dev_opts(const char *val) { mgos_config_set_sys_mount_dev_opts(&mgos_sys_config, val); }
static inline void mgos_sys_config_set_sys_mount_fs_type(const char *val) { mgos_config_set_sys_mount_fs_type(&mgos_sys_config, val); }
static inline void mgos_sys_config_set_sys_mount_fs_opts(const char *val) { mgos_config_set_sys_mount_fs_opts(&mgos_sys_config, val); }
static inline void mgos_sys_config_set_sys_wdt_timeout(int         val) { mgos_config_set_sys_wdt_timeout(&mgos_sys_config, val); }
static inline void mgos_sys_config_set_sys_tz_spec(const char *val) { mgos_config_set_sys_tz_spec(&mgos_sys_config, val); }
static inline void mgos_sys_config_set_conf_acl(const char *val) { mgos_config_set_conf_acl(&mgos_sys_config, val); }
static inline void mgos_sys_config_set_i2c_enable(int         val) { mgos_config_set_i2c_enable(&mgos_sys_config, val); }
static inline void mgos_sys_config_set_i2c_freq(int         val) { mgos_config_set_i2c_freq(&mgos_sys_config, val); }
static inline void mgos_sys_config_set_i2c_debug(int         val) { mgos_config_set_i2c_debug(&mgos_sys_config, val); }
static inline void mgos_sys_config_set_i2c_sda_gpio(int         val) { mgos_config_set_i2c_sda_gpio(&mgos_sys_config, val); }
static inline void mgos_sys_config_set_i2c_scl_gpio(int         val) { mgos_config_set_i2c_scl_gpio(&mgos_sys_config, val); }
static inline void mgos_sys_config_set_wifi_sta_enable(int         val) { mgos_config_set_wifi_sta_enable(&mgos_sys_config, val); }
static inline void mgos_sys_config_set_wifi_sta_ssid(const char *val) { mgos_config_set_wifi_sta_ssid(&mgos_sys_config, val); }
static inline void mgos_sys_config_set_wifi_sta_pass(const char *val) { mgos_config_set_wifi_sta_pass(&mgos_sys_config, val); }
static inline void mgos_sys_config_set_wifi_sta_user(const char *val) { mgos_config_set_wifi_sta_user(&mgos_sys_config, val); }
static inline void mgos_sys_config_set_wifi_sta_anon_identity(const char *val) { mgos_config_set_wifi_sta_anon_identity(&mgos_sys_config, val); }
static inline void mgos_sys_config_set_wifi_sta_cert(const char *val) { mgos_config_set_wifi_sta_cert(&mgos_sys_config, val); }
static inline void mgos_sys_config_set_wifi_sta_key(const char *val) { mgos_config_set_wifi_sta_key(&mgos_sys_config, val); }
static inline void mgos_sys_config_set_wifi_sta_ca_cert(const char *val) { mgos_config_set_wifi_sta_ca_cert(&mgos_sys_config, val); }
static inline void mgos_sys_config_set_wifi_sta_ip(const char *val) { mgos_config_set_wifi_sta_ip(&mgos_sys_config, val); }
static inline void mgos_sys_config_set_wifi_sta_netmask(const char *val) { mgos_config_set_wifi_sta_netmask(&mgos_sys_config, val); }
static inline void mgos_sys_config_set_wifi_sta_gw(const char *val) { mgos_config_set_wifi_sta_gw(&mgos_sys_config, val); }
static inline void mgos_sys_config_set_wifi_sta_nameserver(const char *val) { mgos_config_set_wifi_sta_nameserver(&mgos_sys_config, val); }
static inline void mgos_sys_config_set_wifi_sta_dhcp_hostname(const char *val) { mgos_config_set_wifi_sta_dhcp_hostname(&mgos_sys_config, val); }
static inline void mgos_sys_config_set_wifi_ap_enable(int         val) { mgos_config_set_wifi_ap_enable(&mgos_sys_config, val); }
static inline void mgos_sys_config_set_wifi_ap_ssid(const char *val) { mgos_config_set_wifi_ap_ssid(&mgos_sys_config, val); }
static inline void mgos_sys_config_set_wifi_ap_pass(const char *val) { mgos_config_set_wifi_ap_pass(&mgos_sys_config, val); }
static inline void mgos_sys_config_set_wifi_ap_hidden(int         val) { mgos_config_set_wifi_ap_hidden(&mgos_sys_config, val); }
static inline void mgos_sys_config_set_wifi_ap_channel(int         val) { mgos_config_set_wifi_ap_channel(&mgos_sys_config, val); }
static inline void mgos_sys_config_set_wifi_ap_max_connections(int         val) { mgos_config_set_wifi_ap_max_connections(&mgos_sys_config, val); }
static inline void mgos_sys_config_set_wifi_ap_ip(const char *val) { mgos_config_set_wifi_ap_ip(&mgos_sys_config, val); }
static inline void mgos_sys_config_set_wifi_ap_netmask(const char *val) { mgos_config_set_wifi_ap_netmask(&mgos_sys_config, val); }
static inline void mgos_sys_config_set_wifi_ap_gw(const char *val) { mgos_config_set_wifi_ap_gw(&mgos_sys_config, val); }
static inline void mgos_sys_config_set_wifi_ap_dhcp_start(const char *val) { mgos_config_set_wifi_ap_dhcp_start(&mgos_sys_config, val); }
static inline void mgos_sys_config_set_wifi_ap_dhcp_end(const char *val) { mgos_config_set_wifi_ap_dhcp_end(&mgos_sys_config, val); }
static inline void mgos_sys_config_set_wifi_ap_trigger_on_gpio(int         val) { mgos_config_set_wifi_ap_trigger_on_gpio(&mgos_sys_config, val); }
static inline void mgos_sys_config_set_wifi_ap_disable_after(int         val) { mgos_config_set_wifi_ap_disable_after(&mgos_sys_config, val); }
static inline void mgos_sys_config_set_wifi_ap_hostname(const char *val) { mgos_config_set_wifi_ap_hostname(&mgos_sys_config, val); }
static inline void mgos_sys_config_set_wifi_ap_keep_enabled(int         val) { mgos_config_set_wifi_ap_keep_enabled(&mgos_sys_config, val); }
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
static inline void mgos_sys_config_set_rpc_mqtt_enable(int         val) { mgos_config_set_rpc_mqtt_enable(&mgos_sys_config, val); }
static inline void mgos_sys_config_set_rpc_mqtt_topic(const char *val) { mgos_config_set_rpc_mqtt_topic(&mgos_sys_config, val); }
static inline void mgos_sys_config_set_rpc_uart_uart_no(int         val) { mgos_config_set_rpc_uart_uart_no(&mgos_sys_config, val); }
static inline void mgos_sys_config_set_rpc_uart_baud_rate(int         val) { mgos_config_set_rpc_uart_baud_rate(&mgos_sys_config, val); }
static inline void mgos_sys_config_set_rpc_uart_fc_type(int         val) { mgos_config_set_rpc_uart_fc_type(&mgos_sys_config, val); }
static inline void mgos_sys_config_set_rpc_uart_wait_for_start_frame(int         val) { mgos_config_set_rpc_uart_wait_for_start_frame(&mgos_sys_config, val); }
static inline void mgos_sys_config_set_dash_enable(int         val) { mgos_config_set_dash_enable(&mgos_sys_config, val); }
static inline void mgos_sys_config_set_dash_token(const char *val) { mgos_config_set_dash_token(&mgos_sys_config, val); }
static inline void mgos_sys_config_set_dash_server(const char *val) { mgos_config_set_dash_server(&mgos_sys_config, val); }
static inline void mgos_sys_config_set_dash_ca_file(const char *val) { mgos_config_set_dash_ca_file(&mgos_sys_config, val); }
static inline void mgos_sys_config_set_dash_heartbeat_interval(int         val) { mgos_config_set_dash_heartbeat_interval(&mgos_sys_config, val); }
static inline void mgos_sys_config_set_dash_send_logs(int         val) { mgos_config_set_dash_send_logs(&mgos_sys_config, val); }
static inline void mgos_sys_config_set_dash_send_stats(int         val) { mgos_config_set_dash_send_stats(&mgos_sys_config, val); }
static inline void mgos_sys_config_set_file_logger_enable(int         val) { mgos_config_set_file_logger_enable(&mgos_sys_config, val); }
static inline void mgos_sys_config_set_file_logger_dir(const char *val) { mgos_config_set_file_logger_dir(&mgos_sys_config, val); }
static inline void mgos_sys_config_set_file_logger_prefix(const char *val) { mgos_config_set_file_logger_prefix(&mgos_sys_config, val); }
static inline void mgos_sys_config_set_file_logger_max_file_size(int         val) { mgos_config_set_file_logger_max_file_size(&mgos_sys_config, val); }
static inline void mgos_sys_config_set_file_logger_max_num_files(int         val) { mgos_config_set_file_logger_max_num_files(&mgos_sys_config, val); }
static inline void mgos_sys_config_set_mjs_generate_jsc(int         val) { mgos_config_set_mjs_generate_jsc(&mgos_sys_config, val); }
static inline void mgos_sys_config_set_mqtt_enable(int         val) { mgos_config_set_mqtt_enable(&mgos_sys_config, val); }
static inline void mgos_sys_config_set_mqtt_server(const char *val) { mgos_config_set_mqtt_server(&mgos_sys_config, val); }
static inline void mgos_sys_config_set_mqtt_client_id(const char *val) { mgos_config_set_mqtt_client_id(&mgos_sys_config, val); }
static inline void mgos_sys_config_set_mqtt_user(const char *val) { mgos_config_set_mqtt_user(&mgos_sys_config, val); }
static inline void mgos_sys_config_set_mqtt_pass(const char *val) { mgos_config_set_mqtt_pass(&mgos_sys_config, val); }
static inline void mgos_sys_config_set_mqtt_reconnect_timeout_min(double      val) { mgos_config_set_mqtt_reconnect_timeout_min(&mgos_sys_config, val); }
static inline void mgos_sys_config_set_mqtt_reconnect_timeout_max(double      val) { mgos_config_set_mqtt_reconnect_timeout_max(&mgos_sys_config, val); }
static inline void mgos_sys_config_set_mqtt_ssl_cert(const char *val) { mgos_config_set_mqtt_ssl_cert(&mgos_sys_config, val); }
static inline void mgos_sys_config_set_mqtt_ssl_key(const char *val) { mgos_config_set_mqtt_ssl_key(&mgos_sys_config, val); }
static inline void mgos_sys_config_set_mqtt_ssl_ca_cert(const char *val) { mgos_config_set_mqtt_ssl_ca_cert(&mgos_sys_config, val); }
static inline void mgos_sys_config_set_mqtt_ssl_cipher_suites(const char *val) { mgos_config_set_mqtt_ssl_cipher_suites(&mgos_sys_config, val); }
static inline void mgos_sys_config_set_mqtt_ssl_psk_identity(const char *val) { mgos_config_set_mqtt_ssl_psk_identity(&mgos_sys_config, val); }
static inline void mgos_sys_config_set_mqtt_ssl_psk_key(const char *val) { mgos_config_set_mqtt_ssl_psk_key(&mgos_sys_config, val); }
static inline void mgos_sys_config_set_mqtt_clean_session(int         val) { mgos_config_set_mqtt_clean_session(&mgos_sys_config, val); }
static inline void mgos_sys_config_set_mqtt_keep_alive(int         val) { mgos_config_set_mqtt_keep_alive(&mgos_sys_config, val); }
static inline void mgos_sys_config_set_mqtt_will_topic(const char *val) { mgos_config_set_mqtt_will_topic(&mgos_sys_config, val); }
static inline void mgos_sys_config_set_mqtt_will_message(const char *val) { mgos_config_set_mqtt_will_message(&mgos_sys_config, val); }
static inline void mgos_sys_config_set_mqtt_max_qos(int         val) { mgos_config_set_mqtt_max_qos(&mgos_sys_config, val); }
static inline void mgos_sys_config_set_mqtt_recv_mbuf_limit(int         val) { mgos_config_set_mqtt_recv_mbuf_limit(&mgos_sys_config, val); }
static inline void mgos_sys_config_set_server_id(const char *val) { mgos_config_set_server_id(&mgos_sys_config, val); }
static inline void mgos_sys_config_set_server_topicName(const char *val) { mgos_config_set_server_topicName(&mgos_sys_config, val); }
static inline void mgos_sys_config_set_devices_mainDevice_id(const char *val) { mgos_config_set_devices_mainDevice_id(&mgos_sys_config, val); }
static inline void mgos_sys_config_set_devices_mainDevice_type(const char *val) { mgos_config_set_devices_mainDevice_type(&mgos_sys_config, val); }
static inline void mgos_sys_config_set_devices_mainDevice_mainHeaterStateName(const char *val) { mgos_config_set_devices_mainDevice_mainHeaterStateName(&mgos_sys_config, val); }
static inline void mgos_sys_config_set_devices_mainDevice_mainTempAndHumSensorStateName(const char *val) { mgos_config_set_devices_mainDevice_mainTempAndHumSensorStateName(&mgos_sys_config, val); }
static inline void mgos_sys_config_set_devices_mainHeater_id(const char *val) { mgos_config_set_devices_mainHeater_id(&mgos_sys_config, val); }
static inline void mgos_sys_config_set_devices_mainHeater_HEAT_PIN(int         val) { mgos_config_set_devices_mainHeater_HEAT_PIN(&mgos_sys_config, val); }
static inline void mgos_sys_config_set_devices_mainHeater_POWER_PIN(int         val) { mgos_config_set_devices_mainHeater_POWER_PIN(&mgos_sys_config, val); }
static inline void mgos_sys_config_set_devices_mainHeater_turnedOn(int         val) { mgos_config_set_devices_mainHeater_turnedOn(&mgos_sys_config, val); }
static inline void mgos_sys_config_set_devices_mainDHT_id(const char *val) { mgos_config_set_devices_mainDHT_id(&mgos_sys_config, val); }
static inline void mgos_sys_config_set_devices_mainDHT_DHT_PIN(int         val) { mgos_config_set_devices_mainDHT_DHT_PIN(&mgos_sys_config, val); }
static inline void mgos_sys_config_set_devices_mainDHT_minTemp(int         val) { mgos_config_set_devices_mainDHT_minTemp(&mgos_sys_config, val); }
static inline void mgos_sys_config_set_devices_mainDHT_maxTemp(int         val) { mgos_config_set_devices_mainDHT_maxTemp(&mgos_sys_config, val); }
static inline void mgos_sys_config_set_devices_mainDHT_autoCtrl(int         val) { mgos_config_set_devices_mainDHT_autoCtrl(&mgos_sys_config, val); }
static inline void mgos_sys_config_set_devices_mainDHT_minTempActions(const char *val) { mgos_config_set_devices_mainDHT_minTempActions(&mgos_sys_config, val); }
static inline void mgos_sys_config_set_devices_mainDHT_maxTempActions(const char *val) { mgos_config_set_devices_mainDHT_maxTempActions(&mgos_sys_config, val); }
static inline void mgos_sys_config_set_devices_mainDHT_mainTimerInterval(int         val) { mgos_config_set_devices_mainDHT_mainTimerInterval(&mgos_sys_config, val); }
static inline void mgos_sys_config_set_pins_DEC_BUTTON(int         val) { mgos_config_set_pins_DEC_BUTTON(&mgos_sys_config, val); }
static inline void mgos_sys_config_set_pins_INC_BUTTON(int         val) { mgos_config_set_pins_INC_BUTTON(&mgos_sys_config, val); }
static inline void mgos_sys_config_set_pins_SWITCH_BUTTON(int         val) { mgos_config_set_pins_SWITCH_BUTTON(&mgos_sys_config, val); }


const struct mgos_conf_entry *mgos_config_schema();

#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif /* MGOS_CONFIG_H_ */
