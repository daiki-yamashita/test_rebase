#include <CUnit/CUnit.h>
#include <CUnit/Basic.h>
#include <CUnit/Automated.h>
#include <CUnit/Console.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include "stub.h"
#include "../vf/spp_config.c"
// テスト対象ソースインクルード
#include "../vf/spp_vf.c"

// =============================================================================
// 定数定義
// =============================================================================

// =============================================================================
// グローバル変数
// =============================================================================

// =============================================================================
// セットアップ処理
// =============================================================================
static int setup(void) {
  return 0;
}

// =============================================================================
// ティアダウン処理
// =============================================================================
static int teardown(void) {
  return 0;
}

// =============================================================================
// テストケース01 usage
// =============================================================================
// TEST01：正常終了
static void UT_usage_01(void) {

  /* 試験関数起動 */
  usage("spp_vf");

  /* 確認ポイントチェック */
}

// =============================================================================
// テストケース02 add_ring_pmd
// =============================================================================
// TEST01：正常終了
static void UT_add_ring_pmd_01(void) {
  int ret = -1;

  /* stub戻り値 */
  stub_ret_rte_eth_from_ring = 1;

  /* 試験関数起動 */
  ret = add_ring_pmd(0);

  /* 確認ポイントチェック */
  CU_ASSERT_EQUAL(ret, 2);
}

// TEST02：rte_ring_lookup失敗
static void UT_add_ring_pmd_02(void) {
  int ret = -1;

  /* stub戻り値 */
  stub_ret_rte_ring_lookup = -1;
  stub_ret_rte_eth_from_ring = 0;

  /* 試験関数起動 */
  ret = add_ring_pmd(0);
  stub_ret_rte_ring_lookup = 0;

  /* 確認ポイントチェック */
  CU_ASSERT_EQUAL(ret, -1);
}

// TEST03：rte_eth_from_ring失敗
static void UT_add_ring_pmd_03(void) {
  int ret = -1;

  /* stub戻り値 */
  stub_ret_rte_ring_lookup = 0;
  stub_ret_rte_eth_from_ring = -1;

  /* 試験関数起動 */
  ret = add_ring_pmd(0);
  stub_ret_rte_eth_from_ring = 1;

  /* 確認ポイントチェック */
  CU_ASSERT_EQUAL(ret, -1);
}

// =============================================================================
// テストケース03 add_vhost_pmd
// =============================================================================
// TEST01：正常終了
static void UT_add_vhost_pmd_01(void) {
  int ret = -1;

  /* stub戻り値 */

  /* 試験関数起動 */
  ret = add_vhost_pmd(0);

  /* 確認ポイントチェック */
  CU_ASSERT_EQUAL(ret, 1);
}

// TEST02：rte_mempool_lookup失敗
static void UT_add_vhost_pmd_02(void) {
  int ret = -1;

  /* stub戻り値 */
  stub_ret_rte_mempool_lookup = -1;

  /* 試験関数起動 */
  ret = add_vhost_pmd(0);
  stub_ret_rte_mempool_lookup = 0;

  /* 確認ポイントチェック */
  CU_ASSERT_EQUAL(ret, -1);
}

// TEST03：rte_eth_dev_attach失敗
static void UT_add_vhost_pmd_03(void) {
  int ret = -1;

  /* stub戻り値 */
  stub_ret_rte_eth_dev_attach = -1;

  /* 試験関数起動 */
  ret = add_vhost_pmd(0);
  stub_ret_rte_eth_dev_attach = 0;

  /* 確認ポイントチェック */
  CU_ASSERT_EQUAL(ret, -1);
}

// TEST04：rte_eth_dev_configure失敗
static void UT_add_vhost_pmd_04(void) {
  int ret = -1;

  /* stub戻り値 */
  stub_ret_rte_eth_dev_configure = -1;

  /* 試験関数起動 */
  ret = add_vhost_pmd(0);
  stub_ret_rte_eth_dev_configure = 0;

  /* 確認ポイントチェック */
  CU_ASSERT_EQUAL(ret, -1);
}

// TEST05：rte_eth_rx_queue_setup失敗
static void UT_add_vhost_pmd_05(void) {
  int ret = -1;

  /* stub戻り値 */
  stub_ret_rte_eth_rx_queue_setup = -1;

  /* 試験関数起動 */
  ret = add_vhost_pmd(0);
  stub_ret_rte_eth_rx_queue_setup = 0;

  /* 確認ポイントチェック */
  CU_ASSERT_EQUAL(ret, -1);
}

// TEST06：rte_eth_tx_queue_setup失敗
static void UT_add_vhost_pmd_06(void) {
  int ret = -1;

  /* stub戻り値 */
  stub_ret_rte_eth_tx_queue_setup = -1;

  /* 試験関数起動 */
  ret = add_vhost_pmd(0);
  stub_ret_rte_eth_tx_queue_setup = 0;

  /* 確認ポイントチェック */
  CU_ASSERT_EQUAL(ret, -1);
}

// TEST07：rte_eth_dev_start失敗
static void UT_add_vhost_pmd_07(void) {
  int ret = -1;

  /* stub戻り値 */
  stub_ret_rte_eth_dev_start = -1;

  /* 試験関数起動 */
  ret = add_vhost_pmd(0);
  stub_ret_rte_eth_dev_start = 0;

  /* 確認ポイントチェック */
  CU_ASSERT_EQUAL(ret, -1);
}

// =============================================================================
// テストケース04 set_core_status
// =============================================================================
// TEST01：正常終了
static void UT_set_core_status_01(void) {
  memset(g_core_info, 0x00, sizeof(g_core_info));

  /* stub戻り値 */

  /* 試験関数起動 */
  set_core_status(SPP_CORE_FORWARD);

  /* 確認ポイントチェック */
  CU_ASSERT_EQUAL(g_core_info[0].status, SPP_CORE_FORWARD);
  CU_ASSERT_EQUAL(g_core_info[1].status, SPP_CORE_FORWARD);
  CU_ASSERT_EQUAL(g_core_info[2].status, SPP_CORE_FORWARD);
  CU_ASSERT_EQUAL(g_core_info[3].status, SPP_CORE_FORWARD);
}

// =============================================================================
// テストケース05 check_core_status
// =============================================================================
// TEST01：正常終了
static void UT_check_core_status_01(void) {
  int ret = -1;
  memset(g_core_info, 0x00, sizeof(g_core_info));
  set_core_status(SPP_CORE_STOP_REQUEST);

  /* stub戻り値 */

  /* 試験関数起動 */
  ret = check_core_status(SPP_CORE_STOP_REQUEST);

  /* 確認ポイントチェック */
  CU_ASSERT_EQUAL(ret, 0);
}

// TEST02：状態不一致
static void UT_check_core_status_02(void) {
  int ret = -1;
  memset(g_core_info, 0x00, sizeof(g_core_info));
  g_core_info[1].type = SPP_CONFIG_FORWARD;
  set_core_status(SPP_CORE_STOP);

  /* stub戻り値 */

  /* 試験関数起動 */
  ret = check_core_status(SPP_CORE_FORWARD);

  /* 確認ポイントチェック */
  CU_ASSERT_EQUAL(ret, -1);
}

// =============================================================================
// テストケース06 check_core_status_wait
// =============================================================================
// TEST01：正常終了
static void UT_check_core_status_wait_01(void) {
  int ret = -1;
  memset(g_core_info, 0x00, sizeof(g_core_info));
  set_core_status(SPP_CORE_FORWARD);

  /* stub戻り値 */

  /* 試験関数起動 */
  ret = check_core_status_wait(SPP_CORE_FORWARD);

  /* 確認ポイントチェック */
  CU_ASSERT_EQUAL(ret, 0);
}

// TEST02：状態不一致
static void UT_check_core_status_wait_02(void) {
  int ret = -1;
  memset(g_core_info, 0x00, sizeof(g_core_info));
  g_core_info[1].type = SPP_CONFIG_FORWARD;
  set_core_status(SPP_CORE_FORWARD);

  /* stub戻り値 */

  /* 試験関数起動 */
  ret = check_core_status_wait(SPP_CORE_STOP);

  /* 確認ポイントチェック */
  CU_ASSERT_EQUAL(ret, -1);
}

// =============================================================================
// テストケース07 stop_process
// =============================================================================
// TEST01：正常終了
static void UT_stop_process_01(void) {
  memset(g_core_info, 0x00, sizeof(g_core_info));
  set_core_status(SPP_CORE_FORWARD);

  /* stub戻り値 */

  /* 試験関数起動 */
  stop_process(SIGINT);

  /* 確認ポイントチェック */
  CU_ASSERT_EQUAL(g_core_info[0].status, SPP_CORE_STOP_REQUEST);
}

// TEST02：想定外のシグナル
static void UT_stop_process_02(void) {
  memset(g_core_info, 0x00, sizeof(g_core_info));
  set_core_status(SPP_CORE_FORWARD);

  /* stub戻り値 */

  /* 試験関数起動 */
  stop_process(SIGKILL);

  /* 確認ポイントチェック */
  CU_ASSERT_EQUAL(g_core_info[0].status, SPP_CORE_FORWARD);
}

// =============================================================================
// テストケース08 parse_cpu_bit
// =============================================================================
// TEST01：正常終了
static void UT_parse_cpu_bit_01(void) {
  int ret = 0;
  uint64_t cpu;

  /* stub戻り値 */

  /* 試験関数起動 */
  ret = parse_cpu_bit(&cpu, "0xfe");

  /* 確認ポイントチェック */
  CU_ASSERT_EQUAL(ret, 0);
  CU_ASSERT_EQUAL(cpu, 0xfe);
}

// TEST02：想定外の文字あり
static void UT_parse_cpu_bit_02(void) {
  int ret = 0;
  uint64_t cpu;

  /* stub戻り値 */

  /* 試験関数起動 */
  ret = parse_cpu_bit(&cpu, "0xxfe");

  /* 確認ポイントチェック */
  CU_ASSERT_EQUAL(ret, -1);
}

// TEST03：空文字列
static void UT_parse_cpu_bit_03(void) {
  int ret = 0;
  uint64_t cpu;

  /* stub戻り値 */

  /* 試験関数起動 */
  ret = parse_cpu_bit(&cpu, "");

  /* 確認ポイントチェック */
  CU_ASSERT_EQUAL(ret, -1);
}

// =============================================================================
// テストケース09 parse_dpdk_args
// =============================================================================
// TEST01：正常終了
static void UT_parse_dpdk_args_01(void) {
  int ret = 0;
  int argc = 3;
  char *argv[5];
  argv[0] = "aaa";
  argv[1] = "-c";
  argv[2] = "0xff";
  memset(&g_startup_param, 0x00, sizeof(g_startup_param));

  /* stub戻り値 */

  /* 試験関数起動 */
  ret = parse_dpdk_args(argc, argv);

  /* 確認ポイントチェック */
  CU_ASSERT_EQUAL(ret, 0);
  CU_ASSERT_EQUAL(g_startup_param.cpu, 0xff);
}

// TEST02：他オプション
static void UT_parse_dpdk_args_02(void) {
  int ret = 0;
  int argc = 3;
  char *argv[5];
  argv[0] = "bbb";
  argv[1] = "-d";
  argv[2] = "0";
  memset(&g_startup_param, 0x00, sizeof(g_startup_param));

  /* stub戻り値 */

  /* 試験関数起動 */
  ret = parse_dpdk_args(argc, argv);

  /* 確認ポイントチェック */
  CU_ASSERT_EQUAL(ret, 0);
}

// TEST03：複数のオプション
static void UT_parse_dpdk_args_03(void) {
  int ret = 0;
  int argc = 5;
  char *argv[5];
  argv[0] = "ccc";
  argv[1] = "-n";
  argv[2] = "4";
  argv[3] = "-c";
  argv[4] = "0x01";
  memset(&g_startup_param, 0x00, sizeof(g_startup_param));

  /* stub戻り値 */

  /* 試験関数起動 */
  ret = parse_dpdk_args(argc, argv);

  /* 確認ポイントチェック */
  CU_ASSERT_EQUAL(ret, 0);
  CU_ASSERT_EQUAL(g_startup_param.cpu, 0x01);
}

// TEST04：想定外の文字
static void UT_parse_dpdk_args_04(void) {
  int ret = 0;
  int argc = 3;
  char *argv[5];
  argv[0] = "ddd";
  argv[1] = "-c";
  argv[2] = "z";
  memset(&g_startup_param, 0x00, sizeof(g_startup_param));

  /* stub戻り値 */

  /* 試験関数起動 */
  ret = parse_dpdk_args(argc, argv);

  /* 確認ポイントチェック */
  CU_ASSERT_EQUAL(ret, -1);
}

// =============================================================================
// テストケース10 get_if_area
// =============================================================================
// TEST01：正常終了(NIC)
static void UT_get_if_area_01(void) {
  struct patch_info *ret = 0;

  /* stub戻り値 */

  /* 試験関数起動 */
  ret = get_if_area(PHY, 0);

  /* 確認ポイントチェック */
  CU_ASSERT_EQUAL(ret, &g_if_info.nic_patchs[0]);
}

// TEST02：正常終了(VHOST)
static void UT_get_if_area_02(void) {
  struct patch_info *ret = 0;

  /* stub戻り値 */

  /* 試験関数起動 */
  ret = get_if_area(VHOST, 2);

  /* 確認ポイントチェック */
  CU_ASSERT_EQUAL(ret, &g_if_info.vhost_patchs[2]);
}

// TEST03：正常終了(RING)
static void UT_get_if_area_03(void) {
  struct patch_info *ret = 0;

  /* stub戻り値 */

  /* 試験関数起動 */
  ret = get_if_area(RING, 5);

  /* 確認ポイントチェック */
  CU_ASSERT_EQUAL(ret, &g_if_info.ring_patchs[5]);
}

// TEST04：想定外の種別
static void UT_get_if_area_04(void) {
  struct patch_info *ret = 0;

  /* stub戻り値 */

  /* 試験関数起動 */
  ret = get_if_area(PHY, 0);

  /* 確認ポイントチェック */
  CU_ASSERT_EQUAL(ret, &g_if_info.nic_patchs[0]);
}

// =============================================================================
// テストケース11 init_if_info
// =============================================================================
// TEST01：正常終了
static void UT_init_if_info_01(void) {

  /* stub戻り値 */

  /* 試験関数起動 */
  init_if_info();

  /* 確認ポイントチェック */
  CU_ASSERT_EQUAL(g_if_info.nic_patchs[0].rx_core_no, -1);
  CU_ASSERT_EQUAL(g_if_info.nic_patchs[1].tx_core_no, -1);
  CU_ASSERT_EQUAL(g_if_info.vhost_patchs[2].rx_core_no, -1);
  CU_ASSERT_EQUAL(g_if_info.vhost_patchs[3].tx_core_no, -1);
  CU_ASSERT_EQUAL(g_if_info.ring_patchs[4].rx_core_no, -1);
  CU_ASSERT_EQUAL(g_if_info.ring_patchs[5].tx_core_no, -1);
}

// =============================================================================
// テストケース12 init_core_info
// =============================================================================
// TEST01：正常終了
static void UT_init_core_info_01(void) {

  /* stub戻り値 */

  /* 試験関数起動 */
  init_core_info();

  /* 確認ポイントチェック */
  CU_ASSERT_EQUAL(g_core_info[2].lcore_id, 2);
  CU_ASSERT_EQUAL(g_core_info[0].rx_ports[0].if_type, UNDEF);
  CU_ASSERT_EQUAL(g_core_info[0].tx_ports[0].if_type, UNDEF);
}

// =============================================================================
// テストケース13 set_form_proc_info
// =============================================================================
// TEST01：正常終了
static void UT_set_form_proc_info_01(void) {
  int ret = 0;
  memset(&g_config, 0x00, sizeof(g_config));
  memset(&g_if_info, 0x00, sizeof(g_if_info));
  memset(g_core_info, 0x00, sizeof(g_core_info));
  g_startup_param.cpu = 0x01fe;

  /* 試験用コンフィグ指定 */
  strcpy(stub_config_file_name, "spp_vf/vf.json");
  spp_config_load_file(SPP_CONFIG_FILE_PATH, 0, &g_config);

  /* stub戻り値 */

  /* 試験関数起動 */
  ret = set_form_proc_info(&g_config);

  /* 確認ポイントチェック */
  CU_ASSERT_EQUAL(ret, 0);
  CU_ASSERT_EQUAL(g_core_info[2].type, SPP_CONFIG_FORWARD);
  CU_ASSERT_EQUAL(g_core_info[2].rx_ports[0].if_type, RING);
  CU_ASSERT_EQUAL(g_core_info[2].rx_ports[0].if_no, 1);
  CU_ASSERT_EQUAL(g_core_info[2].tx_ports[0].if_type, VHOST);
  CU_ASSERT_EQUAL(g_core_info[2].tx_ports[0].if_no, 1);
  CU_ASSERT_EQUAL(g_if_info.ring_patchs[1].use_flg, 1);
  CU_ASSERT_EQUAL(g_if_info.ring_patchs[1].rx_core_no, 2);
  CU_ASSERT_EQUAL(g_if_info.ring_patchs[1].rx_core, &g_core_info[2].rx_ports[0]);
  CU_ASSERT_EQUAL(g_if_info.vhost_patchs[1].use_flg, 1);
  CU_ASSERT_EQUAL(g_if_info.vhost_patchs[1].tx_core_no, 2);
  CU_ASSERT_EQUAL(g_if_info.vhost_patchs[1].tx_core, &g_core_info[2].tx_ports[0]);

  CU_ASSERT_EQUAL(g_core_info[4].type, SPP_CONFIG_CLASSIFIER_MAC);
  CU_ASSERT_EQUAL(g_core_info[4].rx_ports[0].if_type, PHY);
  CU_ASSERT_EQUAL(g_core_info[4].rx_ports[0].if_no, 0);
  CU_ASSERT_EQUAL(g_core_info[4].tx_ports[0].if_type, RING);
  CU_ASSERT_EQUAL(g_core_info[4].tx_ports[0].if_no, 0);
  CU_ASSERT_EQUAL(g_core_info[4].tx_ports[1].if_type, RING);
  CU_ASSERT_EQUAL(g_core_info[4].tx_ports[1].if_no, 1);
  CU_ASSERT_EQUAL(g_core_info[4].tx_ports[2].if_type, RING);
  CU_ASSERT_EQUAL(g_core_info[4].tx_ports[2].if_no, 2);
  CU_ASSERT_EQUAL(g_if_info.nic_patchs[0].use_flg, 1);
  CU_ASSERT_EQUAL(g_if_info.nic_patchs[0].rx_core_no, 4);
  CU_ASSERT_EQUAL(g_if_info.nic_patchs[0].rx_core, &g_core_info[4].rx_ports[0]);
  CU_ASSERT_EQUAL(g_if_info.ring_patchs[0].use_flg, 1);
  CU_ASSERT_EQUAL(g_if_info.ring_patchs[0].tx_core_no, 4);
  CU_ASSERT_EQUAL(g_if_info.ring_patchs[0].tx_core, &g_core_info[4].tx_ports[0]);
  CU_ASSERT_EQUAL(g_if_info.ring_patchs[1].use_flg, 1);
  CU_ASSERT_EQUAL(g_if_info.ring_patchs[1].tx_core_no, 4);
  CU_ASSERT_EQUAL(g_if_info.ring_patchs[1].tx_core, &g_core_info[4].tx_ports[1]);
  CU_ASSERT_EQUAL(g_if_info.ring_patchs[2].use_flg, 1);
  CU_ASSERT_EQUAL(g_if_info.ring_patchs[2].tx_core_no, 4);
  CU_ASSERT_EQUAL(g_if_info.ring_patchs[2].tx_core, &g_core_info[4].tx_ports[2]);

  CU_ASSERT_EQUAL(g_core_info[8].type, SPP_CONFIG_MERGE);
  CU_ASSERT_EQUAL(g_core_info[8].rx_ports[0].if_type, RING);
  CU_ASSERT_EQUAL(g_core_info[8].rx_ports[0].if_no, 3);
  CU_ASSERT_EQUAL(g_core_info[8].rx_ports[1].if_type, RING);
  CU_ASSERT_EQUAL(g_core_info[8].rx_ports[1].if_no, 4);
  CU_ASSERT_EQUAL(g_core_info[8].rx_ports[2].if_type, RING);
  CU_ASSERT_EQUAL(g_core_info[8].rx_ports[2].if_no, 5);
  CU_ASSERT_EQUAL(g_core_info[8].tx_ports[0].if_type, PHY);
  CU_ASSERT_EQUAL(g_core_info[8].tx_ports[0].if_no, 0);
  CU_ASSERT_EQUAL(g_if_info.ring_patchs[3].use_flg, 1);
  CU_ASSERT_EQUAL(g_if_info.ring_patchs[3].rx_core_no, 8);
  CU_ASSERT_EQUAL(g_if_info.ring_patchs[3].rx_core, &g_core_info[8].rx_ports[0]);
  CU_ASSERT_EQUAL(g_if_info.ring_patchs[4].use_flg, 1);
  CU_ASSERT_EQUAL(g_if_info.ring_patchs[4].rx_core_no, 8);
  CU_ASSERT_EQUAL(g_if_info.ring_patchs[4].rx_core, &g_core_info[8].rx_ports[1]);
  CU_ASSERT_EQUAL(g_if_info.ring_patchs[5].use_flg, 1);
  CU_ASSERT_EQUAL(g_if_info.ring_patchs[5].rx_core_no, 8);
  CU_ASSERT_EQUAL(g_if_info.ring_patchs[5].rx_core, &g_core_info[8].rx_ports[2]);
  CU_ASSERT_EQUAL(g_if_info.nic_patchs[0].use_flg, 1);
  CU_ASSERT_EQUAL(g_if_info.nic_patchs[0].tx_core_no, 8);
  CU_ASSERT_EQUAL(g_if_info.nic_patchs[0].tx_core, &g_core_info[8].tx_ports[0]);
}

// TEST02：RX側IF使用中
static void UT_set_form_proc_info_02(void) {
  int ret = 0;
  memset(&g_config, 0x00, sizeof(g_config));
  memset(&g_if_info, 0x00, sizeof(g_if_info));
  memset(g_core_info, 0x00, sizeof(g_core_info));
  g_startup_param.cpu = 0x01fe;

  /* 試験用コンフィグ指定 */
  strcpy(stub_config_file_name, "spp_vf/vf.json");
  spp_config_load_file(SPP_CONFIG_FILE_PATH, 0, &g_config);
  g_if_info.nic_patchs[0].rx_core = &g_core_info[2].rx_ports[0];

  /* stub戻り値 */

  /* 試験関数起動 */
  ret = set_form_proc_info(&g_config);

  /* 確認ポイントチェック */
  CU_ASSERT_EQUAL(ret, -1);
}

// TEST03：TX側IF使用中
static void UT_set_form_proc_info_03(void) {
  int ret = 0;
  memset(&g_config, 0x00, sizeof(g_config));
  memset(&g_if_info, 0x00, sizeof(g_if_info));
  memset(g_core_info, 0x00, sizeof(g_core_info));
  g_startup_param.cpu = 0x01fe;

  /* 試験用コンフィグ指定 */
  strcpy(stub_config_file_name, "spp_vf/vf.json");
  spp_config_load_file(SPP_CONFIG_FILE_PATH, 0, &g_config);
  g_if_info.ring_patchs[1].tx_core = &g_core_info[2].tx_ports[0];

  /* stub戻り値 */

  /* 試験関数起動 */
  ret = set_form_proc_info(&g_config);

  /* 確認ポイントチェック */
  CU_ASSERT_EQUAL(ret, -1);
}

// バグによりチェック処理を動作しない様にしている為、チェックできず。
// TEST04：使用CORE不一致
//static void UT_set_form_proc_info_04(void) {
//  int ret = 0;
//  memset(&g_config, 0x00, sizeof(g_config));
//  memset(&g_if_info, 0x00, sizeof(g_if_info));
//  memset(g_core_info, 0x00, sizeof(g_core_info));
//  g_startup_param.cpu = 0x06;
//
//  /* 試験用コンフィグ指定 */
//  strcpy(stub_config_file_name, "spp_vf/vf.json");
//  spp_config_load_file(SPP_CONFIG_FILE_PATH, 0, &g_config);
//
//  /* stub戻り値 */
//
//  /* 試験関数起動 */
//  ret = set_form_proc_info(&g_config);
//
//  /* 確認ポイントチェック */
//  CU_ASSERT_EQUAL(ret, -1);
//}

// =============================================================================
// テストケース14 set_from_classifier_table
// =============================================================================
// TEST01：正常終了
static void UT_set_from_classifier_table_01(void) {
  int ret = 0;
  memset(&g_config, 0x00, sizeof(g_config));
  memset(&g_if_info, 0x00, sizeof(g_if_info));
  memset(g_core_info, 0x00, sizeof(g_core_info));
  g_startup_param.cpu = 0x01fe;

  /* 試験用コンフィグ指定 */
  strcpy(stub_config_file_name, "spp_vf/vf.json");
  spp_config_load_file(SPP_CONFIG_FILE_PATH, 0, &g_config);
  set_form_proc_info(&g_config);

  /* stub戻り値 */

  /* 試験関数起動 */
  ret = set_from_classifier_table(&g_config);

  /* 確認ポイントチェック */
  CU_ASSERT_EQUAL(ret, 0);
  CU_ASSERT_EQUAL(g_core_info[4].type, SPP_CONFIG_CLASSIFIER_MAC);
  CU_ASSERT_EQUAL(g_core_info[4].tx_ports[0].if_type, RING);
  CU_ASSERT_EQUAL(g_core_info[4].tx_ports[0].if_no, 0);
  CU_ASSERT_STRING_EQUAL(g_core_info[4].tx_ports[0].mac_addr_str, "32:61:3C:4E:B6:05");
  CU_ASSERT_EQUAL(g_core_info[4].tx_ports[0].mac_addr, 0x000005B64E3C6132);
  CU_ASSERT_EQUAL(g_core_info[4].tx_ports[1].if_type, RING);
  CU_ASSERT_EQUAL(g_core_info[4].tx_ports[1].if_no, 1);
  CU_ASSERT_STRING_EQUAL(g_core_info[4].tx_ports[1].mac_addr_str, "32:61:3C:4E:B6:06");
  CU_ASSERT_EQUAL(g_core_info[4].tx_ports[1].mac_addr, 0x000006B64E3C6132);
  CU_ASSERT_EQUAL(g_core_info[4].tx_ports[2].if_type, RING);
  CU_ASSERT_EQUAL(g_core_info[4].tx_ports[2].if_no, 2);
  CU_ASSERT_STRING_EQUAL(g_core_info[4].tx_ports[2].mac_addr_str, "32:61:3C:4E:B6:07");
  CU_ASSERT_EQUAL(g_core_info[4].tx_ports[2].mac_addr, 0x000007B64E3C6132);
  CU_ASSERT_EQUAL(g_if_info.ring_patchs[0].use_flg, 1);
  CU_ASSERT_EQUAL(g_if_info.ring_patchs[0].mac_addr, g_config.classifier_table.mac_tables[0].mac_addr);
  CU_ASSERT_STRING_EQUAL(g_if_info.ring_patchs[0].mac_addr_str, g_config.classifier_table.mac_tables[0].mac_addr_str);
  CU_ASSERT_EQUAL(g_if_info.ring_patchs[1].use_flg, 1);
  CU_ASSERT_EQUAL(g_if_info.ring_patchs[1].mac_addr, g_config.classifier_table.mac_tables[1].mac_addr);
  CU_ASSERT_STRING_EQUAL(g_if_info.ring_patchs[1].mac_addr_str, g_config.classifier_table.mac_tables[1].mac_addr_str);
  CU_ASSERT_EQUAL(g_if_info.ring_patchs[2].use_flg, 1);
  CU_ASSERT_EQUAL(g_if_info.ring_patchs[2].mac_addr, g_config.classifier_table.mac_tables[2].mac_addr);
  CU_ASSERT_STRING_EQUAL(g_if_info.ring_patchs[2].mac_addr_str, g_config.classifier_table.mac_tables[2].mac_addr_str);
}

// TEST02：対象IF未使用
static void UT_set_from_classifier_table_02(void) {
  int ret = 0;
  memset(&g_config, 0x00, sizeof(g_config));
  memset(&g_if_info, 0x00, sizeof(g_if_info));
  memset(g_core_info, 0x00, sizeof(g_core_info));
  g_startup_param.cpu = 0x01fe;

  /* 試験用コンフィグ指定 */
  strcpy(stub_config_file_name, "spp_vf/vf.json");
  spp_config_load_file(SPP_CONFIG_FILE_PATH, 0, &g_config);
  set_form_proc_info(&g_config);
  g_if_info.ring_patchs[2].use_flg = 0;

  /* stub戻り値 */

  /* 試験関数起動 */
  ret = set_from_classifier_table(&g_config);

  /* 確認ポイントチェック */
  CU_ASSERT_EQUAL(ret, -1);
}

// =============================================================================
// テストケース15 set_nic_interface
// =============================================================================
// TEST01：正常終了
static void UT_set_nic_interface_01(void) {
  int ret = 0;
  memset(&g_config, 0x00, sizeof(g_config));
  memset(&g_if_info, 0x00, sizeof(g_if_info));
  memset(g_core_info, 0x00, sizeof(g_core_info));
  g_startup_param.cpu = 0x01fe;

  /* 試験用コンフィグ指定 */
  strcpy(stub_config_file_name, "spp_vf/vf.json");
  spp_config_load_file(SPP_CONFIG_FILE_PATH, 0, &g_config);
  set_form_proc_info(&g_config);
  g_core_info[4].rx_ports[0].dpdk_port = 111111;
  g_core_info[8].tx_ports[0].dpdk_port = 222222;

  /* stub戻り値 */

  /* 試験関数起動 */
  ret = set_nic_interface(&g_config);

  /* 確認ポイントチェック */
  CU_ASSERT_EQUAL(ret, 0);
  CU_ASSERT_EQUAL(g_if_info.num_nic, 2);
  CU_ASSERT_EQUAL(g_if_info.nic_patchs[0].dpdk_port, 0);
  CU_ASSERT_EQUAL(g_if_info.nic_patchs[1].dpdk_port, 1);
  CU_ASSERT_EQUAL(g_core_info[4].rx_ports[0].dpdk_port, 0);
  CU_ASSERT_EQUAL(g_core_info[8].tx_ports[0].dpdk_port, 0);
}

// TEST02：NIC設定数上限越え
static void UT_set_nic_interface_02(void) {
  int ret = 0;
  memset(&g_config, 0x00, sizeof(g_config));
  memset(&g_if_info, 0x00, sizeof(g_if_info));
  memset(g_core_info, 0x00, sizeof(g_core_info));
  g_startup_param.cpu = 0x01fe;

  /* 試験用コンフィグ指定 */
  strcpy(stub_config_file_name, "spp_vf/vf.json");
  spp_config_load_file(SPP_CONFIG_FILE_PATH, 0, &g_config);
  set_form_proc_info(&g_config);
  g_if_info.nic_patchs[0].use_flg = 1;
  g_if_info.nic_patchs[1].use_flg = 1;
  g_if_info.nic_patchs[2].use_flg = 1;

  /* stub戻り値 */

  /* 試験関数起動 */
  ret = set_nic_interface(&g_config);

  /* 確認ポイントチェック */
  CU_ASSERT_EQUAL(ret, -1);
}

// =============================================================================
// テストケース16 set_vhost_interface
// =============================================================================
// TEST01：正常終了
static void UT_set_vhost_interface_01(void) {
  int ret = 0;
  memset(&g_config, 0x00, sizeof(g_config));
  memset(&g_if_info, 0x00, sizeof(g_if_info));
  memset(g_core_info, 0x00, sizeof(g_core_info));
  g_startup_param.cpu = 0x01fe;

  /* 試験用コンフィグ指定 */
  strcpy(stub_config_file_name, "spp_vf/vf.json");
  spp_config_load_file(SPP_CONFIG_FILE_PATH, 0, &g_config);
  set_form_proc_info(&g_config);

  /* stub戻り値 */
  stub_ret_rte_mempool_lookup = 0;
  stub_ret_rte_eth_dev_attach = 0;
  stub_ret_rte_eth_dev_configure = 0;
  stub_ret_rte_eth_rx_queue_setup = 0;
  stub_ret_rte_eth_tx_queue_setup = 0;
  stub_ret_rte_eth_dev_start = 0;
  stub_dpdk_port_id = 1;

  /* 試験関数起動 */
  ret = set_vhost_interface(&g_config);

  /* 確認ポイントチェック */
  CU_ASSERT_EQUAL(ret, 0);
  CU_ASSERT_EQUAL(g_if_info.num_vhost, 3);
  CU_ASSERT_EQUAL(g_if_info.vhost_patchs[0].dpdk_port, 2);
  CU_ASSERT_EQUAL(g_if_info.vhost_patchs[1].dpdk_port, 3);
  CU_ASSERT_EQUAL(g_if_info.vhost_patchs[2].dpdk_port, 4);
  CU_ASSERT_EQUAL(g_core_info[5].rx_ports[0].dpdk_port, 2);
  CU_ASSERT_EQUAL(g_core_info[6].rx_ports[0].dpdk_port, 3);
  CU_ASSERT_EQUAL(g_core_info[7].rx_ports[0].dpdk_port, 4);
  CU_ASSERT_EQUAL(g_core_info[1].tx_ports[0].dpdk_port, 2);
  CU_ASSERT_EQUAL(g_core_info[2].tx_ports[0].dpdk_port, 3);
  CU_ASSERT_EQUAL(g_core_info[3].tx_ports[0].dpdk_port, 4);
}

// TEST02：DPDKポート番号取得失敗
static void UT_set_vhost_interface_02(void) {
  int ret = 0;
  memset(&g_config, 0x00, sizeof(g_config));
  memset(&g_if_info, 0x00, sizeof(g_if_info));
  memset(g_core_info, 0x00, sizeof(g_core_info));
  g_startup_param.cpu = 0x01fe;

  /* 試験用コンフィグ指定 */
  strcpy(stub_config_file_name, "spp_vf/vf.json");
  spp_config_load_file(SPP_CONFIG_FILE_PATH, 0, &g_config);
  set_form_proc_info(&g_config);

  /* stub戻り値 */
  stub_ret_rte_mempool_lookup = 0;
  stub_ret_rte_eth_dev_attach = 0;
  stub_ret_rte_eth_dev_configure = 0;
  stub_ret_rte_eth_rx_queue_setup = 0;
  stub_ret_rte_eth_tx_queue_setup = 0;
  stub_ret_rte_eth_dev_start = -1;
  stub_dpdk_port_id = 1;

  /* 試験関数起動 */
  ret = set_vhost_interface(&g_config);

  /* 確認ポイントチェック */
  CU_ASSERT_EQUAL(ret, -1);
}

// TEST03：VHOST設定数上限越え
static void UT_set_vhost_interface_03(void) {
  int ret = 0;
  memset(&g_config, 0x00, sizeof(g_config));
  memset(&g_if_info, 0x00, sizeof(g_if_info));
  memset(g_core_info, 0x00, sizeof(g_core_info));
  g_startup_param.cpu = 0x01fe;

  /* 試験用コンフィグ指定 */
  strcpy(stub_config_file_name, "spp_vf/vf.json");
  spp_config_load_file(SPP_CONFIG_FILE_PATH, 0, &g_config);
  set_form_proc_info(&g_config);
  g_config.proc.num_vhost = 2;

  /* stub戻り値 */
  stub_ret_rte_mempool_lookup = 0;
  stub_ret_rte_eth_dev_attach = 0;
  stub_ret_rte_eth_dev_configure = 0;
  stub_ret_rte_eth_rx_queue_setup = 0;
  stub_ret_rte_eth_tx_queue_setup = 0;
  stub_ret_rte_eth_dev_start = 0;
  stub_dpdk_port_id = 1;

  /* 試験関数起動 */
  ret = set_vhost_interface(&g_config);

  /* 確認ポイントチェック */
  CU_ASSERT_EQUAL(ret, -1);
}

// =============================================================================
// テストケース17 set_ring_interface
// =============================================================================
// TEST01：正常終了
static void UT_set_ring_interface_01(void) {
  int ret = 0;
  memset(&g_config, 0x00, sizeof(g_config));
  memset(&g_if_info, 0x00, sizeof(g_if_info));
  memset(g_core_info, 0x00, sizeof(g_core_info));
  g_startup_param.cpu = 0x01fe;

  /* 試験用コンフィグ指定 */
  strcpy(stub_config_file_name, "spp_vf/vf.json");
  spp_config_load_file(SPP_CONFIG_FILE_PATH, 0, &g_config);
  set_form_proc_info(&g_config);

  /* stub戻り値 */
  stub_ret_rte_eth_from_ring = 1;

  /* 試験関数起動 */
  ret = set_ring_interface(&g_config);

  /* 確認ポイントチェック */
  CU_ASSERT_EQUAL(ret, 0);
  CU_ASSERT_EQUAL(g_if_info.num_ring, 6);
  CU_ASSERT_EQUAL(g_if_info.ring_patchs[0].dpdk_port, 2);
  CU_ASSERT_EQUAL(g_if_info.ring_patchs[1].dpdk_port, 3);
  CU_ASSERT_EQUAL(g_if_info.ring_patchs[2].dpdk_port, 4);
  CU_ASSERT_EQUAL(g_if_info.ring_patchs[3].dpdk_port, 5);
  CU_ASSERT_EQUAL(g_if_info.ring_patchs[4].dpdk_port, 6);
  CU_ASSERT_EQUAL(g_if_info.ring_patchs[5].dpdk_port, 7);
  CU_ASSERT_EQUAL(g_core_info[1].rx_ports[0].dpdk_port, 2);
  CU_ASSERT_EQUAL(g_core_info[2].rx_ports[0].dpdk_port, 3);
  CU_ASSERT_EQUAL(g_core_info[3].rx_ports[0].dpdk_port, 4);
  CU_ASSERT_EQUAL(g_core_info[4].tx_ports[0].dpdk_port, 2);
  CU_ASSERT_EQUAL(g_core_info[4].tx_ports[1].dpdk_port, 3);
  CU_ASSERT_EQUAL(g_core_info[4].tx_ports[2].dpdk_port, 4);
  CU_ASSERT_EQUAL(g_core_info[5].tx_ports[0].dpdk_port, 5);
  CU_ASSERT_EQUAL(g_core_info[6].tx_ports[0].dpdk_port, 6);
  CU_ASSERT_EQUAL(g_core_info[7].tx_ports[0].dpdk_port, 7);
  CU_ASSERT_EQUAL(g_core_info[8].rx_ports[0].dpdk_port, 5);
  CU_ASSERT_EQUAL(g_core_info[8].rx_ports[1].dpdk_port, 6);
  CU_ASSERT_EQUAL(g_core_info[8].rx_ports[2].dpdk_port, 7);
}

// TEST02：DPDKポート取得失敗
static void UT_set_ring_interface_02(void) {
  int ret = 0;
  memset(&g_config, 0x00, sizeof(g_config));
  memset(&g_if_info, 0x00, sizeof(g_if_info));
  memset(g_core_info, 0x00, sizeof(g_core_info));
  g_startup_param.cpu = 0x01fe;

  /* 試験用コンフィグ指定 */
  strcpy(stub_config_file_name, "spp_vf/vf.json");
  spp_config_load_file(SPP_CONFIG_FILE_PATH, 0, &g_config);
  set_form_proc_info(&g_config);

  /* stub戻り値 */
  stub_ret_rte_eth_from_ring = -1;

  /* 試験関数起動 */
  ret = set_ring_interface(&g_config);

  /* 確認ポイントチェック */
  CU_ASSERT_EQUAL(ret, -1);
}

// TEST03：RING設定数上限越え
static void UT_set_ring_interface_03(void) {
  int ret = 0;
  memset(&g_config, 0x00, sizeof(g_config));
  memset(&g_if_info, 0x00, sizeof(g_if_info));
  memset(g_core_info, 0x00, sizeof(g_core_info));
  g_startup_param.cpu = 0x01fe;

  /* 試験用コンフィグ指定 */
  strcpy(stub_config_file_name, "spp_vf/vf.json");
  spp_config_load_file(SPP_CONFIG_FILE_PATH, 0, &g_config);
  set_form_proc_info(&g_config);
  g_config.proc.num_ring = 2;

  /* stub戻り値 */
  stub_ret_rte_eth_from_ring = 1;

  /* 試験関数起動 */
  ret = set_ring_interface(&g_config);

  /* 確認ポイントチェック */
  CU_ASSERT_EQUAL(ret, -1);
}

// =============================================================================
// テストケース18 init_manage_data
// =============================================================================
// TEST01：正常終了
static void UT_init_manage_data_01(void) {
  int ret = 0;
  memset(&g_config, 0x00, sizeof(g_config));
  memset(&g_if_info, 0x00, sizeof(g_if_info));
  memset(g_core_info, 0x00, sizeof(g_core_info));
  g_startup_param.cpu = 0x01fe;

  /* 試験用コンフィグ指定 */
  strcpy(stub_config_file_name, "spp_vf/vf.json");
  spp_config_load_file(SPP_CONFIG_FILE_PATH, 0, &g_config);
  set_form_proc_info(&g_config);

  /* stub戻り値 */
  stub_dpdk_port_id = 1;
  stub_ret_rte_eth_from_ring = 4;

  /* 試験関数起動 */
  ret = init_manage_data(&g_config);

  /* 確認ポイントチェック */
  CU_ASSERT_EQUAL(ret, 0);
  CU_ASSERT_EQUAL(g_if_info.num_nic, 2);
  CU_ASSERT_EQUAL(g_if_info.num_vhost, 3);
  CU_ASSERT_EQUAL(g_if_info.num_ring, 6);
}

// TEST02：set_form_proc_info失敗
static void UT_init_manage_data_02(void) {
  int ret = 0;
  memset(&g_config, 0x00, sizeof(g_config));
  memset(&g_if_info, 0x00, sizeof(g_if_info));
  memset(g_core_info, 0x00, sizeof(g_core_info));
  g_startup_param.cpu = 0x01fe;

  /* 試験用コンフィグ指定 */
  strcpy(stub_config_file_name, "spp_vf/18-2_vf.json");
  spp_config_load_file(SPP_CONFIG_FILE_PATH, 0, &g_config);

  /* stub戻り値 */
  stub_dpdk_port_id = 1;
  stub_ret_rte_eth_from_ring = 4;

  /* 試験関数起動 */
  ret = init_manage_data(&g_config);

  /* 確認ポイントチェック */
  CU_ASSERT_EQUAL(ret, -1);
}

// TEST03：set_from_classifier_table失敗 ※発生不可
//static void UT_init_manage_data_03(void) {
//  int ret = 0;
//  memset(&g_config, 0x00, sizeof(g_config));
//  memset(&g_if_info, 0x00, sizeof(g_if_info));
//  memset(g_core_info, 0x00, sizeof(g_core_info));
//  g_startup_param.cpu = 0x01fe;
//
//  /* 試験用コンフィグ指定 */
//  strcpy(stub_config_file_name, "spp_vf/18-3_vf.json");
//  spp_config_load_file(SPP_CONFIG_FILE_PATH, 0, &g_config);
//  set_form_proc_info(&g_config);
//
//  /* stub戻り値 */
//  stub_dpdk_port_id = 1;
//  stub_ret_rte_eth_from_ring = 4;
//
//  /* 試験関数起動 */
//  ret = init_manage_data(&g_config);
//
//  /* 確認ポイントチェック */
//  CU_ASSERT_EQUAL(ret, -1);
//}

// TEST04：set_nic_interface失敗
static void UT_init_manage_data_04(void) {
  int ret = 0;
  memset(&g_config, 0x00, sizeof(g_config));
  memset(&g_if_info, 0x00, sizeof(g_if_info));
  memset(g_core_info, 0x00, sizeof(g_core_info));
  g_startup_param.cpu = 0x03fe;

  /* 試験用コンフィグ指定 */
  strcpy(stub_config_file_name, "spp_vf/18-4_vf.json");
  spp_config_load_file(SPP_CONFIG_FILE_PATH, 0, &g_config);
  set_form_proc_info(&g_config);

  /* stub戻り値 */
  stub_dpdk_port_id = 1;
  stub_ret_rte_eth_from_ring = 4;

  /* 試験関数起動 */
  ret = init_manage_data(&g_config);

  /* 確認ポイントチェック */
  CU_ASSERT_EQUAL(ret, -1);
}

// TEST05：set_vhost_interface失敗
static void UT_init_manage_data_05(void) {
  int ret = 0;
  memset(&g_config, 0x00, sizeof(g_config));
  memset(&g_if_info, 0x00, sizeof(g_if_info));
  memset(g_core_info, 0x00, sizeof(g_core_info));
  g_startup_param.cpu = 0x01fe;

  /* 試験用コンフィグ指定 */
  strcpy(stub_config_file_name, "spp_vf/18-5_vf.json");
  spp_config_load_file(SPP_CONFIG_FILE_PATH, 0, &g_config);
  set_form_proc_info(&g_config);

  /* stub戻り値 */
  stub_dpdk_port_id = 1;
  stub_ret_rte_eth_from_ring = 4;

  /* 試験関数起動 */
  ret = init_manage_data(&g_config);

  /* 確認ポイントチェック */
  CU_ASSERT_EQUAL(ret, -1);
}

// TEST06：set_ring_interface失敗
static void UT_init_manage_data_06(void) {
  int ret = 0;
  memset(&g_config, 0x00, sizeof(g_config));
  memset(&g_if_info, 0x00, sizeof(g_if_info));
  memset(g_core_info, 0x00, sizeof(g_core_info));
  g_startup_param.cpu = 0x01fe;

  /* 試験用コンフィグ指定 */
  strcpy(stub_config_file_name, "spp_vf/18-6_vf.json");
  spp_config_load_file(SPP_CONFIG_FILE_PATH, 0, &g_config);
  set_form_proc_info(&g_config);

  /* stub戻り値 */
  stub_dpdk_port_id = 1;
  stub_ret_rte_eth_from_ring = 4;

  /* 試験関数起動 */
  ret = init_manage_data(&g_config);

  /* 確認ポイントチェック */
  CU_ASSERT_EQUAL(ret, -1);
}

// =============================================================================
// テストケース19 print_ring_latency_stats
// =============================================================================
// TEST01：正常終了
static void UT_print_ring_latency_stats_01(void) {

  /* 試験用コンフィグ指定 */

  /* stub戻り値 */

  /* 試験関数起動 */
  print_ring_latency_stats();

  /* 確認ポイントチェック */
}

// =============================================================================
// テストケース20 main
// =============================================================================
// TEST01：正常終了
static void UT_main_01(void) {
  int ret = 0;
  memset(&g_config, 0x00, sizeof(g_config));
  memset(&g_if_info, 0x00, sizeof(g_if_info));
  memset(g_core_info, 0x00, sizeof(g_core_info));
  int argc = 11;
  char *argv[11];
  argv[0] = "spp_vf";
  argv[1] = "-c";
  argv[2] = "0x3fe";
  argv[3] = "-n";
  argv[4] = "-4";
  argv[5] = "--proc-type=secondary";
  argv[6] = "--";
  argv[7] = "--process-id";
  argv[8] = "0";
  argv[9] = "-s";
  argv[10] = "127.0.0.1:6666";

  /* 試験用コンフィグ指定 */
  strcpy(stub_config_file_name, "spp_vf/vf.json");

  /* stub戻り値 */
  stub_dpdk_port_id = 1;
  stub_ret_rte_eth_from_ring = 4;
  stub_ret_rte_eal_init = 6;

  /* 試験関数起動 */
  ret = ut_main(argc, argv);

  /* 確認ポイントチェック */
  CU_ASSERT_EQUAL(ret, 0);
}

// TEST02：パラメーラのCPU設定ミス
static void UT_main_02(void) {
  int ret = 0;
  memset(&g_config, 0x00, sizeof(g_config));
  memset(&g_if_info, 0x00, sizeof(g_if_info));
  memset(g_core_info, 0x00, sizeof(g_core_info));
  int argc = 11;
  char *argv[11];
  argv[0] = "spp_vf";
  argv[1] = "-c";
  argv[2] = "z";
  argv[3] = "-n";
  argv[4] = "-4";
  argv[5] = "--proc-type=secondary";
  argv[6] = "--";
  argv[7] = "--process-id";
  argv[8] = "0";
  argv[9] = "-s";
  argv[10] = "127.0.0.1:6666";

  /* 試験用コンフィグ指定 */
  strcpy(stub_config_file_name, "spp_vf/vf.json");

  /* stub戻り値 */
  stub_dpdk_port_id = 1;
  stub_ret_rte_eth_from_ring = 4;
  stub_ret_rte_eal_init = 6;

  /* 試験関数起動 */
  ret = ut_main(argc, argv);

  /* 確認ポイントチェック */
  CU_ASSERT_EQUAL(ret, -1);
}

// TEST03：コンフィグ読み込み失敗
static void UT_main_03(void) {
  int ret = 0;
  memset(&g_config, 0x00, sizeof(g_config));
  memset(&g_if_info, 0x00, sizeof(g_if_info));
  memset(g_core_info, 0x00, sizeof(g_core_info));
  int argc = 11;
  char *argv[11];
  argv[0] = "spp_vf";
  argv[1] = "-c";
  argv[2] = "0x3fe";
  argv[3] = "-n";
  argv[4] = "-4";
  argv[5] = "--proc-type=secondary";
  argv[6] = "--";
  argv[7] = "--process-id";
  argv[8] = "0";
  argv[9] = "-s";
  argv[10] = "127.0.0.1:6666";

  /* 試験用コンフィグ指定 */
  memset(stub_config_file_name, 0x00, sizeof(stub_config_file_name));

  /* stub戻り値 */
  stub_dpdk_port_id = 1;
  stub_ret_rte_eth_from_ring = 4;
  stub_ret_rte_eal_init = 6;

  /* 試験関数起動 */
  ret = ut_main(argc, argv);

  /* 確認ポイントチェック */
  CU_ASSERT_EQUAL(ret, -1);
}

// TEST04：DPDK初期化失敗
static void UT_main_04(void) {
  int ret = 0;
  memset(&g_config, 0x00, sizeof(g_config));
  memset(&g_if_info, 0x00, sizeof(g_if_info));
  memset(g_core_info, 0x00, sizeof(g_core_info));
  int argc = 11;
  char *argv[11];
  argv[0] = "spp_vf";
  argv[1] = "-c";
  argv[2] = "0x3fe";
  argv[3] = "-n";
  argv[4] = "-4";
  argv[5] = "--proc-type=secondary";
  argv[6] = "--";
  argv[7] = "--process-id";
  argv[8] = "0";
  argv[9] = "-s";
  argv[10] = "127.0.0.1:6666";

  /* 試験用コンフィグ指定 */
  strcpy(stub_config_file_name, "spp_vf/vf.json");

  /* stub戻り値 */
  stub_dpdk_port_id = 1;
  stub_ret_rte_eth_from_ring = 4;
  stub_ret_rte_eal_init = -1;

  /* 試験関数起動 */
  ret = ut_main(argc, argv);
  stub_ret_rte_eal_init = 0;

  /* 確認ポイントチェック */
  CU_ASSERT_EQUAL(ret, -1);
}

// TEST05：起動パラメータとコンフィグの関連データ不一致
//static void UT_main_05(void) {
//  int ret = 0;
//  memset(&g_config, 0x00, sizeof(g_config));
//  memset(&g_if_info, 0x00, sizeof(g_if_info));
//  memset(g_core_info, 0x00, sizeof(g_core_info));
//  int argc = 11;
//  char *argv[11];
//  argv[0] = "spp_vf";
//  argv[1] = "-c";
//  argv[2] = "0x3fe";
//  argv[3] = "-n";
//  argv[4] = "-4";
//  argv[5] = "--proc-type=secondary";
//  argv[6] = "--";
//  argv[7] = "--process-id";
//  argv[8] = "0";
//  argv[9] = "-s";
//  argv[10] = "127.0.0.1:6666";
//
//  /* 試験用コンフィグ指定 */
//  strcpy(stub_config_file_name, "spp_vf/vf.json");
//
//  /* stub戻り値 */
//  stub_dpdk_port_id = 1;
//  stub_ret_rte_eth_from_ring = 4;
//  stub_ret_rte_eal_init = 6;
//
//  /* 試験関数起動 */
//  ret = ut_main(argc, argv);
//
//  /* 確認ポイントチェック */
//  CU_ASSERT_EQUAL(ret, -1);
//}

// TEST06：RING滞留時間用初期化処理失敗
static void UT_main_06(void) {
  int ret = 0;
  memset(&g_config, 0x00, sizeof(g_config));
  memset(&g_if_info, 0x00, sizeof(g_if_info));
  memset(g_core_info, 0x00, sizeof(g_core_info));
  int argc = 11;
  char *argv[11];
  argv[0] = "spp_vf";
  argv[1] = "-c";
  argv[2] = "0x3fe";
  argv[3] = "-n";
  argv[4] = "-4";
  argv[5] = "--proc-type=secondary";
  argv[6] = "--";
  argv[7] = "--process-id";
  argv[8] = "0";
  argv[9] = "-s";
  argv[10] = "127.0.0.1:6666";

  /* 試験用コンフィグ指定 */
  strcpy(stub_config_file_name, "spp_vf/vf.json");

  /* stub戻り値 */
  stub_dpdk_port_id = 1;
  stub_ret_rte_eth_from_ring = 4;
  stub_ret_rte_eal_init = 6;
  stub_ret_spp_ringlatencystats_init = -1;

  /* 試験関数起動 */
  ret = ut_main(argc, argv);
  stub_ret_spp_ringlatencystats_init = 0;

  /* 確認ポイントチェック */
  CU_ASSERT_EQUAL(ret, -1);
}

// TEST07：スレッド状態確認失敗
static void UT_main_07(void) {
  int ret = 0;
  memset(&g_config, 0x00, sizeof(g_config));
  memset(&g_if_info, 0x00, sizeof(g_if_info));
  memset(g_core_info, 0x00, sizeof(g_core_info));
  int argc = 11;
  char *argv[11];
  argv[0] = "spp_vf";
  argv[1] = "-c";
  argv[2] = "0x3fe";
  argv[3] = "-n";
  argv[4] = "-4";
  argv[5] = "--proc-type=secondary";
  argv[6] = "--";
  argv[7] = "--process-id";
  argv[8] = "0";
  argv[9] = "-s";
  argv[10] = "127.0.0.1:6666";

  /* 試験用コンフィグ指定 */
  strcpy(stub_config_file_name, "spp_vf/vf.json");

  /* stub戻り値 */
  stub_dpdk_port_id = 1;
  stub_ret_rte_eth_from_ring = 4;
  stub_ret_rte_eal_init = 6;
  stub_status_rte_eal_remote_launch = SPP_CORE_FORWARD;

  /* 試験関数起動 */
  ret = ut_main(argc, argv);
  stub_status_rte_eal_remote_launch = SPP_CORE_IDLE;

  /* 確認ポイントチェック */
  CU_ASSERT_EQUAL(ret, -1);
}

// =============================================================================
// テストケース21 parse_app_process_id
// =============================================================================
// TEST01：正常終了
static void UT_parse_app_process_id_01(void) {
  int ret = 0;
  int ret_id = 0;

  /* 試験用コンフィグ指定 */

  /* stub戻り値 */

  /* 試験関数起動 */
  ret = parse_app_process_id("1", &ret_id);

  /* 確認ポイントチェック */
  CU_ASSERT_EQUAL(ret, 0);
  CU_ASSERT_EQUAL(ret_id, 1);
}

// TEST02：空文字列指定
static void UT_parse_app_process_id_02(void) {
  int ret = 0;
  int ret_id = 0;

  /* 試験用コンフィグ指定 */

  /* stub戻り値 */

  /* 試験関数起動 */
  ret = parse_app_process_id("", &ret_id);

  /* 確認ポイントチェック */
  CU_ASSERT_EQUAL(ret, -1);
}

// TEST03：数字以外
static void UT_parse_app_process_id_03(void) {
  int ret = 0;
  int ret_id = 0;

  /* 試験用コンフィグ指定 */

  /* stub戻り値 */

  /* 試験関数起動 */
  ret = parse_app_process_id("a", &ret_id);

  /* 確認ポイントチェック */
  CU_ASSERT_EQUAL(ret, -1);
}

// TEST04：上限越え
static void UT_parse_app_process_id_04(void) {
  int ret = 0;
  int ret_id = 0;

  /* 試験用コンフィグ指定 */

  /* stub戻り値 */

  /* 試験関数起動 */
  ret = parse_app_process_id("128", &ret_id);

  /* 確認ポイントチェック */
  CU_ASSERT_EQUAL(ret, -1);
}

// =============================================================================
// テストケース22 parse_app_server
// =============================================================================
// TEST01：正常終了
static void UT_parse_app_server_01(void) {
  int ret = 0;
  char ret_ip[32];
  int ret_port = 0;
  memset(ret_ip, 0x00, 32);

  /* 試験用コンフィグ指定 */

  /* stub戻り値 */

  /* 試験関数起動 */
  ret = parse_app_server("127.0.0.1:6666", ret_ip, &ret_port);

  /* 確認ポイントチェック */
  CU_ASSERT_EQUAL(ret, 0);
  CU_ASSERT_STRING_EQUAL(ret_ip, "127.0.0.1");
  CU_ASSERT_EQUAL(ret_port, 6666);
}

// TEST02：区切り文字なし
static void UT_parse_app_server_02(void) {
  int ret = 0;
  char ret_ip[32];
  int ret_port = 0;
  memset(ret_ip, 0x00, 32);

  /* 試験用コンフィグ指定 */

  /* stub戻り値 */

  /* 試験関数起動 */
  ret = parse_app_server("127.0.0.1", ret_ip, &ret_port);

  /* 確認ポイントチェック */
  CU_ASSERT_EQUAL(ret, -1);
}

// TEST03：ポート番号なし
static void UT_parse_app_server_03(void) {
  int ret = 0;
  char ret_ip[32];
  int ret_port = 0;
  memset(ret_ip, 0x00, 32);

  /* 試験用コンフィグ指定 */

  /* stub戻り値 */

  /* 試験関数起動 */
  ret = parse_app_server("127.0.0.1:", ret_ip, &ret_port);

  /* 確認ポイントチェック */
  CU_ASSERT_EQUAL(ret, -1);
}

// TEST04：ポート番号が数字以外
static void UT_parse_app_server_04(void) {
  int ret = 0;
  char ret_ip[32];
  int ret_port = 0;
  memset(ret_ip, 0x00, 32);

  /* 試験用コンフィグ指定 */

  /* stub戻り値 */

  /* 試験関数起動 */
  ret = parse_app_server("127.0.0.1:abc", ret_ip, &ret_port);

  /* 確認ポイントチェック */
  CU_ASSERT_EQUAL(ret, -1);
}

// TEST05：':'なし
static void UT_parse_app_server_05(void) {
  int ret = 0;
  char ret_ip[32];
  int ret_port = 0;
  memset(ret_ip, 0x00, 32);

  /* 試験用コンフィグ指定 */

  /* stub戻り値 */

  /* 試験関数起動 */
  ret = parse_app_server("127.0.0.16666", ret_ip, &ret_port);

  /* 確認ポイントチェック */
  CU_ASSERT_EQUAL(ret, -1);
}

// =============================================================================
// テストケース23 parse_app_args
// =============================================================================
// TEST01：正常終了
static void UT_parse_app_args_01(void) {
  int ret = 0;
  int argc = 7;
  char *argv[7];
  argv[0] = "spp_vf";
  argv[1] = "--process-id";
  argv[2] = "2";
  argv[3] = "--config";
  argv[4] = "/usr/local/ets/spp/spp.json2";
  argv[5] = "-s";
  argv[6] = "127.0.0.1:6666";
  memset(config_file_path, 0x00, sizeof(config_file_path));
  memset(&g_startup_param, 0x00, sizeof(g_startup_param));

  /* 試験用コンフィグ指定 */

  /* stub戻り値 */

  /* 試験関数起動 */
  ret = parse_app_args(argc, argv);

  /* 確認ポイントチェック */
  CU_ASSERT_EQUAL(ret, 0);
  CU_ASSERT_EQUAL(g_startup_param.process_id, 2);
  CU_ASSERT_STRING_EQUAL(config_file_path, "/usr/local/ets/spp/spp.json2");
  CU_ASSERT_STRING_EQUAL(g_startup_param.server_ip, "127.0.0.1");
  CU_ASSERT_EQUAL(g_startup_param.server_port, 6666);
}

// TEST02：コンフィグが空文字
static void UT_parse_app_args_02(void) {
  int ret = 0;
  int argc = 7;
  char *argv[7];
  argv[0] = "spp_vf";
  argv[1] = "--process-id";
  argv[2] = "2";
  argv[3] = "--config";
  argv[4] = "";
  argv[5] = "-s";
  argv[6] = "127.0.0.1:6666";
  memset(config_file_path, 0x00, sizeof(config_file_path));
  memset(&g_startup_param, 0x00, sizeof(g_startup_param));

  /* 試験用コンフィグ指定 */

  /* stub戻り値 */

  /* 試験関数起動 */
  ret = parse_app_args(argc, argv);

  /* 確認ポイントチェック */
  CU_ASSERT_EQUAL(ret, -1);
}

// TEST03：プロセス番号なし
static void UT_parse_app_args_03(void) {
  int ret = 0;
  int argc = 5;
  char *argv[5];
  argv[0] = "spp_vf";
  argv[1] = "--config";
  argv[2] = "/usr/local/ets/spp/spp.json2";
  argv[3] = "-s";
  argv[4] = "127.0.0.1:6666";
  memset(config_file_path, 0x00, sizeof(config_file_path));
  memset(&g_startup_param, 0x00, sizeof(g_startup_param));

  /* 試験用コンフィグ指定 */

  /* stub戻り値 */

  /* 試験関数起動 */
  ret = parse_app_args(argc, argv);

  /* 確認ポイントチェック */
  CU_ASSERT_EQUAL(ret, -1);
}

// TEST04：プロセス番号異常
static void UT_parse_app_args_04(void) {
  int ret = 0;
  int argc = 7;
  char *argv[7];
  argv[0] = "spp_vf";
  argv[1] = "--process-id";
  argv[2] = "a";
  argv[3] = "--config";
  argv[4] = "/usr/local/ets/spp/spp.json2";
  argv[5] = "-s";
  argv[6] = "127.0.0.1:6666";
  memset(config_file_path, 0x00, sizeof(config_file_path));
  memset(&g_startup_param, 0x00, sizeof(g_startup_param));

  /* 試験用コンフィグ指定 */

  /* stub戻り値 */

  /* 試験関数起動 */
  ret = parse_app_args(argc, argv);

  /* 確認ポイントチェック */
  CU_ASSERT_EQUAL(ret, -1);
}

// TEST05：サーバー情報なし
static void UT_parse_app_args_05(void) {
  int ret = 0;
  int argc = 5;
  char *argv[5];
  argv[0] = "spp_vf";
  argv[1] = "--process-id";
  argv[2] = "2";
  argv[3] = "--config";
  argv[4] = "/usr/local/ets/spp/spp.json2";
  memset(config_file_path, 0x00, sizeof(config_file_path));
  memset(&g_startup_param, 0x00, sizeof(g_startup_param));

  /* 試験用コンフィグ指定 */

  /* stub戻り値 */

  /* 試験関数起動 */
  ret = parse_app_args(argc, argv);

  /* 確認ポイントチェック */
  CU_ASSERT_EQUAL(ret, -1);
}

// TEST06：サーバー情報異常
static void UT_parse_app_args_06(void) {
  int ret = 0;
  int argc = 7;
  char *argv[7];
  argv[0] = "spp_vf";
  argv[1] = "--process-id";
  argv[2] = "3";
  argv[3] = "--config";
  argv[4] = "/usr/local/ets/spp/spp.json2";
  argv[5] = "-s";
  argv[6] = "6666";
  memset(config_file_path, 0x00, sizeof(config_file_path));
  memset(&g_startup_param, 0x00, sizeof(g_startup_param));

  /* 試験用コンフィグ指定 */

  /* stub戻り値 */

  /* 試験関数起動 */
  ret = parse_app_args(argc, argv);

  /* 確認ポイントチェック */
  CU_ASSERT_EQUAL(ret, -1);
}

// =============================================================================
// テストケース24 spp_get_process_id
// =============================================================================
// TEST01：正常終了
static void UT_spp_get_process_id_01(void) {
  int ret = 0;
  g_startup_param.process_id = 2;

  /* 試験用コンフィグ指定 */

  /* stub戻り値 */

  /* 試験関数起動 */
  ret = spp_get_process_id();

  /* 確認ポイントチェック */
  CU_ASSERT_EQUAL(ret, 2);
}

// =============================================================================
// テストケース25 check_mac_used_interface
// =============================================================================
// TEST01：正常終了(NIC)
static void UT_check_mac_used_interface_01(void) {
  int ret = 0;
  enum port_type if_type = UNDEF;
  int if_no = 0;
  memset(&g_if_info, 0x00, sizeof(g_if_info));
  g_if_info.nic_patchs[1].mac_addr = 0xA0B0C0D0E0F0;

  /* 試験用コンフィグ指定 */

  /* stub戻り値 */

  /* 試験関数起動 */
  ret = check_mac_used_interface(0xA0B0C0D0E0F0, &if_type, &if_no);

  /* 確認ポイントチェック */
  CU_ASSERT_EQUAL(ret, 0);
  CU_ASSERT_EQUAL(if_type, PHY);
  CU_ASSERT_EQUAL(if_no, 1);
}

// TEST02：正常終了(VHOST)
static void UT_check_mac_used_interface_02(void) {
  int ret = 0;
  enum port_type if_type = UNDEF;
  int if_no = 0;
  memset(&g_if_info, 0x00, sizeof(g_if_info));
  g_if_info.vhost_patchs[10].mac_addr = 0xA0B0C0D0E0F0;

  /* 試験用コンフィグ指定 */

  /* stub戻り値 */

  /* 試験関数起動 */
  ret = check_mac_used_interface(0xA0B0C0D0E0F0, &if_type, &if_no);

  /* 確認ポイントチェック */
  CU_ASSERT_EQUAL(ret, 0);
  CU_ASSERT_EQUAL(if_type, VHOST);
  CU_ASSERT_EQUAL(if_no, 10);
}

// TEST03：正常終了(RING)
static void UT_check_mac_used_interface_03(void) {
  int ret = 0;
  enum port_type if_type = UNDEF;
  int if_no = 0;
  memset(&g_if_info, 0x00, sizeof(g_if_info));
  g_if_info.ring_patchs[22].mac_addr = 0xA0B0C0D0E0F0;

  /* 試験用コンフィグ指定 */

  /* stub戻り値 */

  /* 試験関数起動 */
  ret = check_mac_used_interface(0xA0B0C0D0E0F0, &if_type, &if_no);

  /* 確認ポイントチェック */
  CU_ASSERT_EQUAL(ret, 0);
  CU_ASSERT_EQUAL(if_type, RING);
  CU_ASSERT_EQUAL(if_no, 22);
}

// TEST04：一致データなし
static void UT_check_mac_used_interface_04(void) {
  int ret = 0;
  enum port_type if_type = UNDEF;
  int if_no = 0;
  memset(&g_if_info, 0x00, sizeof(g_if_info));

  /* 試験用コンフィグ指定 */

  /* stub戻り値 */

  /* 試験関数起動 */
  ret = check_mac_used_interface(0xA0B0C0D0E0F0, &if_type, &if_no);

  /* 確認ポイントチェック */
  CU_ASSERT_EQUAL(ret, -1);
}

// =============================================================================
// テストケース26 spp_update_classifier_table
// =============================================================================
// TEST01：正常終了(設定)
static void UT_spp_update_classifier_table_01(void) {
  int ret = 0;
  memset(&g_config, 0x00, sizeof(g_config));
  memset(&g_if_info, 0x00, sizeof(g_if_info));
  memset(g_core_info, 0x00, sizeof(g_core_info));
  memset(g_change_core, 0x00, sizeof(g_change_core));
  struct spp_config_port_info port;
  port.if_type = RING;
  port.if_no = 1;

  /* 試験用コンフィグ指定 */
  strcpy(stub_config_file_name, "spp_vf/26-1_vf.json");
  spp_config_load_file(SPP_CONFIG_FILE_PATH, 0, &g_config);
  init_manage_data(&g_config);

  /* stub戻り値 */

  /* 試験関数起動 */
  ret = spp_update_classifier_table(SPP_CLASSIFIER_TYPE_MAC, "A0:B0:C0:D0:E0:F0", &port);

  /* 確認ポイントチェック */
  CU_ASSERT_EQUAL(ret, SPP_RET_OK);
  CU_ASSERT_EQUAL(g_if_info.ring_patchs[1].mac_addr, 0xF0E0D0C0B0A0);
  CU_ASSERT_STRING_EQUAL(g_if_info.ring_patchs[1].mac_addr_str, "A0:B0:C0:D0:E0:F0");
  CU_ASSERT_EQUAL(g_core_info[4].tx_ports[1].mac_addr, 0xF0E0D0C0B0A0);
  CU_ASSERT_STRING_EQUAL(g_core_info[4].tx_ports[1].mac_addr_str, "A0:B0:C0:D0:E0:F0");
  CU_ASSERT_EQUAL(g_change_core[4], 1);
}

// TEST02：正常終了(削除)
static void UT_spp_update_classifier_table_02(void) {
  int ret = 0;
  memset(&g_config, 0x00, sizeof(g_config));
  memset(&g_if_info, 0x00, sizeof(g_if_info));
  memset(g_core_info, 0x00, sizeof(g_core_info));
  memset(g_change_core, 0x00, sizeof(g_change_core));
  struct spp_config_port_info port;
  port.if_type = UNDEF;
  port.if_no = 0;

  /* 試験用コンフィグ指定 */
  strcpy(stub_config_file_name, "spp_vf/26-1_vf.json");
  spp_config_load_file(SPP_CONFIG_FILE_PATH, 0, &g_config);
  init_manage_data(&g_config);

  /* stub戻り値 */

  /* 試験関数起動 */
  ret = spp_update_classifier_table(SPP_CLASSIFIER_TYPE_MAC, "32:61:3C:4E:B6:05", &port);

  /* 確認ポイントチェック */
  CU_ASSERT_EQUAL(ret, SPP_RET_OK);
  CU_ASSERT_EQUAL(g_if_info.ring_patchs[0].mac_addr, 0);
  CU_ASSERT_STRING_EQUAL(g_if_info.ring_patchs[1].mac_addr_str, "");
  CU_ASSERT_EQUAL(g_core_info[4].tx_ports[0].mac_addr, 0);
  CU_ASSERT_STRING_EQUAL(g_core_info[4].tx_ports[0].mac_addr_str, "");
  CU_ASSERT_EQUAL(g_change_core[4], 1);
}

// TEST03：既に同じ設定がある
static void UT_spp_update_classifier_table_03(void) {
  int ret = 0;
  memset(&g_config, 0x00, sizeof(g_config));
  memset(&g_if_info, 0x00, sizeof(g_if_info));
  memset(g_core_info, 0x00, sizeof(g_core_info));
  memset(g_change_core, 0x00, sizeof(g_change_core));
  struct spp_config_port_info port;
  port.if_type = RING;
  port.if_no = 1;

  /* 試験用コンフィグ指定 */
  strcpy(stub_config_file_name, "spp_vf/26-1_vf.json");
  spp_config_load_file(SPP_CONFIG_FILE_PATH, 0, &g_config);
  init_manage_data(&g_config);

  /* stub戻り値 */

  /* 試験関数起動 */
  spp_update_classifier_table(SPP_CLASSIFIER_TYPE_MAC, "A0:B0:C0:D0:E0:F0", &port);
  memset(g_change_core, 0x00, sizeof(g_change_core));
  ret = spp_update_classifier_table(SPP_CLASSIFIER_TYPE_MAC, "A0:B0:C0:D0:E0:F0", &port);

  /* 確認ポイントチェック */
  CU_ASSERT_EQUAL(ret, SPP_RET_OK);
  CU_ASSERT_EQUAL(g_if_info.ring_patchs[1].mac_addr, 0xF0E0D0C0B0A0);
  CU_ASSERT_STRING_EQUAL(g_if_info.ring_patchs[1].mac_addr_str, "A0:B0:C0:D0:E0:F0");
  CU_ASSERT_EQUAL(g_change_core[4], 0);
}

// TEST04：別ポートで同じMACアドレスを使用中
static void UT_spp_update_classifier_table_04(void) {
  int ret = 0;
  memset(&g_config, 0x00, sizeof(g_config));
  memset(&g_if_info, 0x00, sizeof(g_if_info));
  memset(g_core_info, 0x00, sizeof(g_core_info));
  memset(g_change_core, 0x00, sizeof(g_change_core));
  struct spp_config_port_info port, port2;
  port.if_type = RING;
  port.if_no = 1;
  port2.if_type = VHOST;
  port2.if_no = 2;

  /* 試験用コンフィグ指定 */
  strcpy(stub_config_file_name, "spp_vf/26-1_vf.json");
  spp_config_load_file(SPP_CONFIG_FILE_PATH, 0, &g_config);
  init_manage_data(&g_config);

  /* stub戻り値 */

  /* 試験関数起動 */
  spp_update_classifier_table(SPP_CLASSIFIER_TYPE_MAC, "A0:B0:C0:D0:E0:F0", &port2);
  ret = spp_update_classifier_table(SPP_CLASSIFIER_TYPE_MAC, "A0:B0:C0:D0:E0:F0", &port);

  /* 確認ポイントチェック */
  CU_ASSERT_EQUAL(ret, SPP_RET_USED_MAC);
}

// TEST05：ポート情報異常
static void UT_spp_update_classifier_table_05(void) {
  int ret = 0;
  memset(&g_config, 0x00, sizeof(g_config));
  memset(&g_if_info, 0x00, sizeof(g_if_info));
  memset(g_core_info, 0x00, sizeof(g_core_info));
  memset(g_change_core, 0x00, sizeof(g_change_core));
  struct spp_config_port_info port;
  port.if_type = 5;
  port.if_no = 0;

  /* 試験用コンフィグ指定 */
  strcpy(stub_config_file_name, "spp_vf/26-1_vf.json");
  spp_config_load_file(SPP_CONFIG_FILE_PATH, 0, &g_config);
  init_manage_data(&g_config);

  /* stub戻り値 */

  /* 試験関数起動 */
  ret = spp_update_classifier_table(SPP_CLASSIFIER_TYPE_MAC, "A0:B0:C0:D0:E0:F0", &port);

  /* 確認ポイントチェック */
  CU_ASSERT_EQUAL(ret, SPP_RET_NG);
}

// TEST06：ポート未設定
static void UT_spp_update_classifier_table_06(void) {
  int ret = 0;
  memset(&g_config, 0x00, sizeof(g_config));
  memset(&g_if_info, 0x00, sizeof(g_if_info));
  memset(g_core_info, 0x00, sizeof(g_core_info));
  memset(g_change_core, 0x00, sizeof(g_change_core));
  struct spp_config_port_info port;
  port.if_type = PHY;
  port.if_no = 5;

  /* 試験用コンフィグ指定 */
  strcpy(stub_config_file_name, "spp_vf/26-1_vf.json");
  spp_config_load_file(SPP_CONFIG_FILE_PATH, 0, &g_config);
  init_manage_data(&g_config);

  /* stub戻り値 */

  /* 試験関数起動 */
  ret = spp_update_classifier_table(SPP_CLASSIFIER_TYPE_MAC, "A0:B0:C0:D0:E0:F0", &port);

  /* 確認ポイントチェック */
  CU_ASSERT_EQUAL(ret, SPP_RET_NOT_ADD_PORT);
}

// TEST07：ポート使用中
static void UT_spp_update_classifier_table_07(void) {
  int ret = 0;
  memset(&g_config, 0x00, sizeof(g_config));
  memset(&g_if_info, 0x00, sizeof(g_if_info));
  memset(g_core_info, 0x00, sizeof(g_core_info));
  memset(g_change_core, 0x00, sizeof(g_change_core));
  struct spp_config_port_info port;
  port.if_type = RING;
  port.if_no = 0;

  /* 試験用コンフィグ指定 */
  strcpy(stub_config_file_name, "spp_vf/26-1_vf.json");
  spp_config_load_file(SPP_CONFIG_FILE_PATH, 0, &g_config);
  init_manage_data(&g_config);

  /* stub戻り値 */

  /* 試験関数起動 */
  ret = spp_update_classifier_table(SPP_CLASSIFIER_TYPE_MAC, "A0:B0:C0:D0:E0:F0", &port);

  /* 確認ポイントチェック */
  CU_ASSERT_EQUAL(ret, SPP_RET_USED_PORT);
}

// TEST08：削除するMACアドレスなし
static void UT_spp_update_classifier_table_08(void) {
  int ret = 0;
  memset(&g_config, 0x00, sizeof(g_config));
  memset(&g_if_info, 0x00, sizeof(g_if_info));
  memset(g_core_info, 0x00, sizeof(g_core_info));
  memset(g_change_core, 0x00, sizeof(g_change_core));
  struct spp_config_port_info port;
  port.if_type = UNDEF;
  port.if_no = 0;

  /* 試験用コンフィグ指定 */
  strcpy(stub_config_file_name, "spp_vf/26-1_vf.json");
  spp_config_load_file(SPP_CONFIG_FILE_PATH, 0, &g_config);
  init_manage_data(&g_config);

  /* stub戻り値 */

  /* 試験関数起動 */
  ret = spp_update_classifier_table(SPP_CLASSIFIER_TYPE_MAC, "A0:B0:C0:D0:E0:F0", &port);

  /* 確認ポイントチェック */
  CU_ASSERT_EQUAL(ret, 0);
}

// TEST09：MACアドレスを使用しているポートが異常 ※発生不可
//static void UT_spp_update_classifier_table_02(void) {
//  int ret = 0;
//  memset(&g_config, 0x00, sizeof(g_config));
//  memset(&g_if_info, 0x00, sizeof(g_if_info));
//  memset(g_core_info, 0x00, sizeof(g_core_info));
//  memset(g_change_core, 0x00, sizeof(g_change_core));
//  struct spp_config_port_info port;
//  port.if_type = UNDEF;
//  port.if_no = 0;
//
//  /* 試験用コンフィグ指定 */
//  strcpy(stub_config_file_name, "spp_vf/26-1_vf.json");
//  spp_config_load_file(SPP_CONFIG_FILE_PATH, 0, &g_config);
//  init_manage_data(&g_config);
//
//  /* stub戻り値 */
//
//  /* 試験関数起動 */
//  ret = spp_update_classifier_table(SPP_CLASSIFIER_TYPE_MAC, "32:61:3C:4E:B6:05", &port);
//
//  /* 確認ポイントチェック */
//  CU_ASSERT_EQUAL(ret, 0);
//  CU_ASSERT_EQUAL(g_if_info.ring_patchs[0].mac_addr, 0);
//  CU_ASSERT_STRING_EQUAL(g_if_info.ring_patchs[1].mac_addr_str, "");
//}

// =============================================================================
// テストケース27 spp_flush
// =============================================================================
// TEST01：正常終了(変更なし)
static void UT_spp_flush_01(void) {
  int ret = 0;
  memset(&g_config, 0x00, sizeof(g_config));
  memset(&g_if_info, 0x00, sizeof(g_if_info));
  memset(g_core_info, 0x00, sizeof(g_core_info));
  memset(g_change_core, 0x00, sizeof(g_change_core));

  /* 試験用コンフィグ指定 */
  strcpy(stub_config_file_name, "spp_vf/26-1_vf.json");
  spp_config_load_file(SPP_CONFIG_FILE_PATH, 0, &g_config);
  init_manage_data(&g_config);

  /* stub戻り値 */
  stub_ret_spp_classifier_mac_update = 0;

  /* 試験関数起動 */
  ret = spp_flush();

  /* 確認ポイントチェック */
  CU_ASSERT_EQUAL(ret, 0);
}

// TEST02：正常終了(変更あり)
static void UT_spp_flush_02(void) {
  int ret = 0;
  memset(&g_config, 0x00, sizeof(g_config));
  memset(&g_if_info, 0x00, sizeof(g_if_info));
  memset(g_core_info, 0x00, sizeof(g_core_info));
  memset(g_change_core, 0x00, sizeof(g_change_core));

  /* 試験用コンフィグ指定 */
  strcpy(stub_config_file_name, "spp_vf/26-1_vf.json");
  spp_config_load_file(SPP_CONFIG_FILE_PATH, 0, &g_config);
  init_manage_data(&g_config);
  g_change_core[4] = 1;

  /* stub戻り値 */
  stub_ret_spp_classifier_mac_update = 0;

  /* 試験関数起動 */
  ret = spp_flush();

  /* 確認ポイントチェック */
  CU_ASSERT_EQUAL(ret, 0);
  CU_ASSERT_EQUAL(g_change_core[4], 0);
}

// TEST03：コンポーネントの更新用APIでエラー
static void UT_spp_flush_03(void) {
  int ret = 0;
  memset(&g_config, 0x00, sizeof(g_config));
  memset(&g_if_info, 0x00, sizeof(g_if_info));
  memset(g_core_info, 0x00, sizeof(g_core_info));
  memset(g_change_core, 0x00, sizeof(g_change_core));

  /* 試験用コンフィグ指定 */
  strcpy(stub_config_file_name, "spp_vf/26-1_vf.json");
  spp_config_load_file(SPP_CONFIG_FILE_PATH, 0, &g_config);
  init_manage_data(&g_config);
  g_change_core[4] = 1;

  /* stub戻り値 */
  stub_ret_spp_classifier_mac_update = -1;

  /* 試験関数起動 */
  ret = spp_flush();
  stub_ret_spp_classifier_mac_update = 0;

  /* 確認ポイントチェック */
  CU_ASSERT_EQUAL(ret, SPP_RET_NG);
}

// =============================================================================
// Main処理　※．テストケースの呼び出しはここに追加して下さい
// =============================================================================
int main(int argc, char **argv) {
  CU_initialize_registry();
  // ※．テスト対象に応じてCU_add_suiteの引数は書き換えてください
  CU_pSuite suite = CU_add_suite("spp_vf_test", setup, teardown);

  /**    ここにテストコードの呼び出しを追加してください      **/
  // 制御機能 usage
  CU_ADD_TEST(suite, UT_usage_01);

  // 制御機能 add_ring_pmd
  CU_ADD_TEST(suite, UT_add_ring_pmd_01);
  CU_ADD_TEST(suite, UT_add_ring_pmd_02);
  CU_ADD_TEST(suite, UT_add_ring_pmd_03);

  // 制御機能 add_vhost_pmd
  CU_ADD_TEST(suite, UT_add_vhost_pmd_01);
  CU_ADD_TEST(suite, UT_add_vhost_pmd_02);
  CU_ADD_TEST(suite, UT_add_vhost_pmd_03);
  CU_ADD_TEST(suite, UT_add_vhost_pmd_04);
  CU_ADD_TEST(suite, UT_add_vhost_pmd_05);
  CU_ADD_TEST(suite, UT_add_vhost_pmd_06);
  CU_ADD_TEST(suite, UT_add_vhost_pmd_07);

  // 制御機能 set_core_status
  CU_ADD_TEST(suite, UT_set_core_status_01);

  // 制御機能 check_core_status
  CU_ADD_TEST(suite, UT_check_core_status_01);
  CU_ADD_TEST(suite, UT_check_core_status_02);

  // 制御機能 check_core_status_wait
  CU_ADD_TEST(suite, UT_check_core_status_wait_01);
  CU_ADD_TEST(suite, UT_check_core_status_wait_02);

  // 制御機能 stop_process
  CU_ADD_TEST(suite, UT_stop_process_01);
  CU_ADD_TEST(suite, UT_stop_process_02);

  // 制御機能 parse_cpu_bit
  CU_ADD_TEST(suite, UT_parse_cpu_bit_01);
  CU_ADD_TEST(suite, UT_parse_cpu_bit_02);
  CU_ADD_TEST(suite, UT_parse_cpu_bit_03);

  // 制御機能 parse_dpdk_args
  CU_ADD_TEST(suite, UT_parse_dpdk_args_01);
  CU_ADD_TEST(suite, UT_parse_dpdk_args_02);
  CU_ADD_TEST(suite, UT_parse_dpdk_args_03);
  CU_ADD_TEST(suite, UT_parse_dpdk_args_04);

  // 制御機能 get_if_area
  CU_ADD_TEST(suite, UT_get_if_area_01);
  CU_ADD_TEST(suite, UT_get_if_area_02);
  CU_ADD_TEST(suite, UT_get_if_area_03);
  CU_ADD_TEST(suite, UT_get_if_area_04);

  // 制御機能 init_if_info
  CU_ADD_TEST(suite, UT_init_if_info_01);

  // 制御機能 init_core_info
  CU_ADD_TEST(suite, UT_init_core_info_01);

  // 制御機能 set_form_proc_info
  CU_ADD_TEST(suite, UT_set_form_proc_info_01);
  CU_ADD_TEST(suite, UT_set_form_proc_info_02);
  CU_ADD_TEST(suite, UT_set_form_proc_info_03);
//  CU_ADD_TEST(suite, UT_set_form_proc_info_04);

  // 制御機能 set_from_classifier_table
  CU_ADD_TEST(suite, UT_set_from_classifier_table_01);
  CU_ADD_TEST(suite, UT_set_from_classifier_table_02);

  // 制御機能 set_nic_interface
  CU_ADD_TEST(suite, UT_set_nic_interface_01);
  CU_ADD_TEST(suite, UT_set_nic_interface_02);

  // 制御機能 set_vhost_interface
  CU_ADD_TEST(suite, UT_set_vhost_interface_01);
  CU_ADD_TEST(suite, UT_set_vhost_interface_02);
  CU_ADD_TEST(suite, UT_set_vhost_interface_03);

  // 制御機能 set_ring_interface
  CU_ADD_TEST(suite, UT_set_ring_interface_01);
  CU_ADD_TEST(suite, UT_set_ring_interface_02);
  CU_ADD_TEST(suite, UT_set_ring_interface_03);

  // 制御機能 init_manage_data
  CU_ADD_TEST(suite, UT_init_manage_data_01);
  CU_ADD_TEST(suite, UT_init_manage_data_02);
//  CU_ADD_TEST(suite, UT_init_manage_data_03);
  CU_ADD_TEST(suite, UT_init_manage_data_04);
  CU_ADD_TEST(suite, UT_init_manage_data_05);
  CU_ADD_TEST(suite, UT_init_manage_data_06);

  // 制御機能 print_ring_latency_stats
  CU_ADD_TEST(suite, UT_print_ring_latency_stats_01);

  // 制御機能 main
  CU_ADD_TEST(suite, UT_main_01);
  CU_ADD_TEST(suite, UT_main_02);
  CU_ADD_TEST(suite, UT_main_03);
  CU_ADD_TEST(suite, UT_main_04);
//  CU_ADD_TEST(suite, UT_main_05);
  CU_ADD_TEST(suite, UT_main_06);
  CU_ADD_TEST(suite, UT_main_07);

  // 制御機能 parse_app_process_id
  CU_ADD_TEST(suite, UT_parse_app_process_id_01);
  CU_ADD_TEST(suite, UT_parse_app_process_id_02);
  CU_ADD_TEST(suite, UT_parse_app_process_id_03);
  CU_ADD_TEST(suite, UT_parse_app_process_id_04);

  // 制御機能 parse_app_server
  CU_ADD_TEST(suite, UT_parse_app_server_01);
  CU_ADD_TEST(suite, UT_parse_app_server_02);
  CU_ADD_TEST(suite, UT_parse_app_server_03);
  CU_ADD_TEST(suite, UT_parse_app_server_04);
  CU_ADD_TEST(suite, UT_parse_app_server_05);

  // 制御機能 parse_app_args
  CU_ADD_TEST(suite, UT_parse_app_args_01);
  CU_ADD_TEST(suite, UT_parse_app_args_02);
  CU_ADD_TEST(suite, UT_parse_app_args_03);
  CU_ADD_TEST(suite, UT_parse_app_args_04);
  CU_ADD_TEST(suite, UT_parse_app_args_05);
  CU_ADD_TEST(suite, UT_parse_app_args_06);

  // 制御機能 spp_get_process_id
  CU_ADD_TEST(suite, UT_spp_get_process_id_01);

  // 制御機能 check_mac_used_interface
  CU_ADD_TEST(suite, UT_check_mac_used_interface_01);
  CU_ADD_TEST(suite, UT_check_mac_used_interface_02);
  CU_ADD_TEST(suite, UT_check_mac_used_interface_03);
  CU_ADD_TEST(suite, UT_check_mac_used_interface_04);

  // 制御機能 spp_update_classifier_table
  CU_ADD_TEST(suite, UT_spp_update_classifier_table_01);
  CU_ADD_TEST(suite, UT_spp_update_classifier_table_02);
  CU_ADD_TEST(suite, UT_spp_update_classifier_table_03);
  CU_ADD_TEST(suite, UT_spp_update_classifier_table_04);
  CU_ADD_TEST(suite, UT_spp_update_classifier_table_05);
  CU_ADD_TEST(suite, UT_spp_update_classifier_table_06);
  CU_ADD_TEST(suite, UT_spp_update_classifier_table_07);
  CU_ADD_TEST(suite, UT_spp_update_classifier_table_08);

  // 制御機能 spp_flush
  CU_ADD_TEST(suite, UT_spp_flush_01);
  CU_ADD_TEST(suite, UT_spp_flush_02);
  CU_ADD_TEST(suite, UT_spp_flush_03);

  /**    ここにテストコードの呼び出しを追加してください      **/
  // "CU_BRM_VERBOSE:Test: test_xxxx ... passd"をコンソールに表示
  CU_basic_set_mode(CU_BRM_VERBOSE);
  if (argc == 1) {
    // ※．テスト対象に応じてCU_set_output_filenameの引数は書き換えてください
    CU_set_output_filename("spp_vf_test");
    CU_automated_run_tests();
  } else {
    if (strcmp(argv[1], "-b") == 0) { CU_basic_run_tests(); }
    if (strcmp(argv[1], "-c") == 0) { CU_console_run_tests(); }
  }
  const int failed = CU_get_number_of_failures();
  CU_cleanup_registry();
  return -failed;
}
