#ifndef __INC_SUBGHZ_H
#define __INC_SUBGHZ_H

#include <libopencm3/stm32/spi.h>

#define SUBGHZ_DEFAULT_TIMEOUT    100U /* SUBGHZ default timeout: 100ms */
#define SUBGHZ_RFBUSY_LOOP_TIME   ((rcc_ahb_frequency*24U)>>20U)

#define SUBGHZ_RADIO_READ_REGISTER   0x1D
#define SUBGHZ_RADIO_WRITE_REGISTER  0x0D

/* Registers */
#define SUBGHZ_GBSYNCR               0x6AC
#define SUBGHZ_GPKTCTL1AR            0x6B8
#define SUBGHZ_GWHITEINIRL           0x6B9
#define SUBGHZ_GCRCINIRH             0x6BC
#define SUBGHZ_GCRCINIRL             0x6BD
#define SUBGHZ_GCRCPOLRH             0x6BE
#define SUBGHZ_GCRCPOLRL             0x6BF
#define SUBGHZ_GSYNCR0               0x6C0
#define SUBGHZ_GSYNCR1               0x6C1
#define SUBGHZ_GSYNCR2               0x6C2
#define SUBGHZ_GSYNCR3               0x6C3
#define SUBGHZ_GSYNCR4               0x6C4
#define SUBGHZ_GSYNCR5               0x6C5
#define SUBGHZ_GSYNCR6               0x6C6
#define SUBGHZ_GSYNCR7               0x6C7
#define SUBGHZ_LSYNCRH               0x740
#define SUBGHZ_LSYNCRL               0x741
#define SUBGHZ_RNGR3                 0x819
#define SUBGHZ_RNGR2                 0x81A
#define SUBGHZ_RNGR1                 0x81B
#define SUBGHZ_RNGR0                 0x81C
#define SUBGHZ_AGCRSSIC0R            0x89B
#define SUBGHZ_RXGAINCR              0x8AC
#define SUBGHZ_PAOCPR                0x8E7
#define SUBGHZ_HSEINTRIMR            0x911
#define SUBGHZ_HSEOUTTRIMR           0x912
#define SUBGHZ_SMPSC0R               0x916
#define SUBGHZ_PCR                   0x91A
#define SUBGHZ_REGDRVTSTR            0x91F
#define SUBGHZ_SMPSC2R               0x923

/* Commands */
#define SUBGHZ_CALIBRAT_IMAGE        0x98
#define SUBGHZ_CALIBRATE             0x89
#define SUBGHZ_CFG_DIO_IRQ           0x08
#define SUBGHZ_CLR_ERROR             0x07
#define SUBGHZ_CLR_IRQ_STATUS        0x02
#define SUBGHZ_GET_ERROR             0x17
#define SUBGHZ_GET_IRQ_STATUS        0x12
#define SUBGHZ_GET_PACKET_STATUS     0x14
#define SUBGHZ_GET_PACKET_TYPE       0x11
#define SUBGHZ_GET_RSSI_INST         0x15
#define SUBGHZ_GET_RX_BUFFER_STATUS  0x13
#define SUBGHZ_GET_STATS             0x10
#define SUBGHZ_GET_STATUS            0xC0
#define SUBGHZ_READ_BUFFER           0x1E
#define SUBGHZ_READ_REGISTER         0x1D
#define SUBGHZ_RESET_STATS           0x00
#define SUBGHZ_SET_BUFFER_BA         0x8F
#define SUBGHZ_SET_CAD               0xC5
#define SUBGHZ_SET_CAD_PARAMS        0x88
#define SUBGHZ_SET_FS                0xC1
#define SUBGHZ_SET_LORA_SYMB_TO      0xA0
#define SUBGHZ_SET_MOD_PARAMS        0x8B
#define SUBGHZ_SET_PA_CONFIG         0x95
#define SUBGHZ_SET_PACKET_PARAMS     0x8C
#define SUBGHZ_SET_PACKET_TYPE       0x8A
#define SUBGHZ_SET_REGULATOR_MODE    0x96
#define SUBGHZ_SET_RF_FREQ           0x86
#define SUBGHZ_SET_RX                0x82
#define SUBGHZ_SET_RX_DUTY_CYCLE     0x94
#define SUBGHZ_SET_TXRX_FALLBACK     0x93
#define SUBGHZ_SET_SLEEP             0x84
#define SUBGHZ_SET_STANDBY           0x80
#define SUBGHZ_SET_STOP_RX_TIMER     0x9F
#define SUBGHZ_SET_TCXO_MODE         0x97
#define SUBGHZ_SET_TX                0x83
#define SUBGHZ_SET_TX_CONT_WAVE      0xD1
#define SUBGHZ_SET_TX_CONT_PREAMBLE  0xD2
#define SUBGHZ_SET_TX_PARAMS         0x8E
#define SUBGHZ_WRITE_BUFFER          0x0E
#define SUBGHZ_WRITE_REGISTER        0x0D

/* Constants */
#define SUBGHZ_STATUS_MODE_MASK      (7 << 4)
#define SUBGHZ_STATUS_CMD_MASK       (7 << 1)
#define SUBGHZ_STATUS_MODE(x)        ((x & SUBGHZ_STATUS_MODE_MASK) >> 4)
#define SUBGHZ_STATUS_CMD(x)         ((x & SUBGHZ_STATUS_CMD_MASK) >> 1)
#define SUBGHZ_CMD_FAILED(x)         ((SUBGHZ_STATUS_CMD(x) == SUBGHZ_STATUS_CMD_TIMEOUT) || \
                                      (SUBGHZ_STATUS_CMD(x) == SUBGHZ_STATUS_CMD_ERROR) || \
                                      (SUBGHZ_STATUS_CMD(x) == SUBGHZ_STATUS_CMD_EXEC_FAIL))
#define SUBGHZ_CMD_SUCCESS(x)        (!(SUBGHZ_CMD_FAILED(x)))

#define SUBGHZ_ERROR_PARAMP         (1 << 8)
#define SUBGHZ_ERROR_RFPLL_LOCK     (1 << 6)
#define SUBGHZ_ERROR_HSE32          (1 << 5)
#define SUBGHZ_ERROR_IMAGE          (1 << 4)
#define SUBGHZ_ERROR_RFADC          (1 << 3)
#define SUBGHZ_ERROR_RFPLL          (1 << 2)
#define SUBGHZ_ERROR_RC13M          (1 << 1)
#define SUBGHZ_ERROR_RC64K          (1 << 0)

#define SUBGHZ_CALIB_RC64K          (1 << 0)
#define SUBGHZ_CALIB_RC13M          (1 << 1)
#define SUBGHZ_CALIB_RFPLL          (1 << 2)
#define SUBGHZ_CALIB_RFADC_PULSE    (1 << 3)
#define SUBGHZ_CALIB_RFADCN         (1 << 4)
#define SUBGHZ_CALIB_RFADCP         (1 << 5)
#define SUBGHZ_CALIB_IMAGE          (1 << 6)
#define SUBGHZ_CALIB_ALL            (SUBGHZ_CALIB_RC64K | SUBGHZ_CALIB_RC13M | \
                                    SUBGHZ_CALIB_RFPLL | SUBGHZ_CALIB_RFADC_PULSE | \
                                    SUBGHZ_CALIB_RFADCN | SUBGHZ_CALIB_RFADCP | \
                                    SUBGHZ_CALIB_IMAGE)

/*** Enums ***/

/* Status */
typedef enum {
  SUBGHZ_STATUS_MODE_RC13M = 0x02,
  SUBGHZ_STATUS_MODE_HSE32,
  SUBGHZ_STATUS_MODE_FS,
  SUBGHZ_STATUS_MODE_RX,
  SUBGHZ_STATUS_MODE_TX
} subghz_status_mode_t;

typedef enum {
  SUBGHZ_STATUS_CMD_DATA_AVAIL = 0x02,
  SUBGHZ_STATUS_CMD_TIMEOUT,
  SUBGHZ_STATUS_CMD_ERROR,
  SUBGHZ_STATUS_CMD_EXEC_FAIL,
  SUBGHZ_STATUS_CMD_COMPLETED
} subghz_status_cmd_t;

/* Alias for subghz_status_t */
typedef uint8_t subghz_result_t;
typedef uint16_t subghz_err_t;

/* TCXO Mode */
typedef enum {
  SUBGHZ_TCXO_TRIM_1V6,
  SUBGHZ_TCXO_TRIM_1V7,
  SUBGHZ_TCXO_TRIM_1V8,
  SUBGHZ_TCXO_TRIM_2V2,
  SUBGHZ_TCXO_TRIM_2V4,
  SUBGHZ_TCXO_TRIM_2V7,
  SUBGHZ_TCXO_TRIM_3V0,
  SUBGHZ_TCXO_TRIM_3V3
} subghz_tcxo_trim_t;

/* Standby mode */
typedef enum {
  SUBGHZ_STDBY_RC13M,
  SUBGHZ_STDBY_HSE32
} subghz_standby_mode_t;

/* Regulator mode */
typedef enum {
  SUBGHZ_REGMODE_LDO,
  SUBGHZ_REGMODE_SMPS
} subghz_regulator_mode_t;

/* RX Timer Stop */
typedef enum {
  SUBGHZ_RXTIMER_STOP_DEFAULT,
  SUBGHZ_RXTIMER_STOP_PREAMBLE
} subghz_rxtimer_stop_t;

/* Packet types */
typedef enum {
  SUBGHZ_PACKET_FSK,
  SUBGHZ_PACKET_LORA,
  SUBGHZ_PACKET_BPSK,
  SUBGHZ_PACKET_MSK
} subghz_packet_type_t;


/* TX Params */
typedef enum {
  SUBGHZ_TXPARAMS_RAMPTIME_10US,
  SUBGHZ_TXPARAMS_RAMPTIME_20US,
  SUBGHZ_TXPARAMS_RAMPTIME_40US,
  SUBGHZ_TXPARAMS_RAMPTIME_80US,
  SUBGHZ_TXPARAMS_RAMPTIME_200US,
  SUBGHZ_TXPARAMS_RAMPTIME_800US,
  SUBGHZ_TXPARAMS_RAMPTIME_1700US,
  SUBGHZ_TXPARAMS_RAMPTIME_3400US
} subghz_txparams_ramptime_t;

/* Fallback mode */
typedef enum {
  SUBGHZ_FALLBACK_STDBY = 0x20,
  SUBGHZ_FALLBACK_STDBY_HSE32 = 0x30,
  SUBGHZ_FALLBACK_FS = 0x40
} subghz_fallback_mode_t;

/* CAD config */
typedef enum {
  SUBGHZ_CAD_SYMB_1,
  SUBGHZ_CAD_SYMB_2,
  SUBGHZ_CAD_SYMB_4,
  SUBGHZ_CAD_SYMB_8,
  SUBGHZ_CAD_SYMB_16,
} subghz_cad_symbols_t;

typedef enum {
  SUBGHZ_CAD_STDBY_ALWAYS,
  SUBGHZ_CAD_STDBY_NOSYMB
} subghz_cad_exit_mode_t;

/* FSK modulation parameters */
typedef enum {
  SUBGHZ_FSK_GAUSSIAN_NONE,
  SUBGHZ_FSK_GAUSSIAN_BT_03 = 0x08,
  SUBGHZ_FSK_GAUSSIAN_BT_05,
  SUBGHZ_FSK_GAUSSIAN_BT_07,
  SUBGHZ_FSK_GAUSSIAN_BT_10
} subghz_fsk_gaussian_t;

typedef enum {
  SUBGHZ_FSK_BW467 = 0x09,
  SUBGHZ_FSK_BW234, /* 0x0A */
  SUBGHZ_FSK_BW117, /* 0x0B */
  SUBGHZ_FSK_BW58,  /* 0x0C */
  SUBGHZ_FSK_BW29,  /* 0x0D */
  SUBGHZ_FSK_BW14,  /* 0x0E */
  SUBGHZ_FSK_BW7,   /* 0x0F */

  SUBGHZ_FSK_BW373 = 0x11,
  SUBGHZ_FSK_BW187, /* 0x12 */
  SUBGHZ_FSK_BW93,  /* 0x13 */
  SUBGHZ_FSK_BW46,  /* 0x14 */
  SUBGHZ_FSK_BW23,  /* 0x15 */
  SUBGHZ_FSK_BW11,  /* 0x16 */
  SUBGHZ_FSK_BW5,   /* 0x17 */

  SUBGHZ_FSK_BW312 = 0x19,
  SUBGHZ_FSK_BW156, /* 0x1A */
  SUBGHZ_FSK_BW78,  /* 0x1B */
  SUBGHZ_FSK_BW39,  /* 0x1C */
  SUBGHZ_FSK_BW19,  /* 0x1D */
  SUBGHZ_FSK_BW9,   /* 0x1E */
  SUBGHZ_FSK_BW4,   /* 0x1F */
} subghz_fsk_bandwidth_t;

/* LoRa modulation parameters */
typedef enum {
  SUBGHZ_LORA_SF5 = 5,
  SUBGHZ_LORA_SF6,
  SUBGHZ_LORA_SF7,
  SUBGHZ_LORA_SF8,
  SUBGHZ_LORA_SF9,
  SUBGHZ_LORA_SF10,
  SUBGHZ_LORA_SF11,
  SUBGHZ_LORA_SF12,
} subghz_lora_sf_t;

typedef enum {
  SUBGHZ_LORA_CR_44,
  SUBGHZ_LORA_CR_45,
  SUBGHZ_LORA_CR_46,
  SUBGHZ_LORA_CR_47,
  SUBGHZ_LORA_CR_48,
} subghz_lora_cr_t;

typedef enum {
  SUBGHZ_LORA_BW7,
  SUBGHZ_LORA_BW15,
  SUBGHZ_LORA_BW31,
  SUBGHZ_LORA_BW62,
  SUBGHZ_LORA_BW125,
  SUBGHZ_LORA_BW250,
  SUBGHZ_LORA_BW500,
  SUBGHZ_LORA_BW10 = 0x08,
  SUBGHZ_LORA_BW20,
  SUBGHZ_LORA_BW41
} subghz_lora_bandwidth_t;

typedef enum {
  SUBGHZ_LORA_LDRO_DISABLED,
  SUBGHZ_LORA_LDRO_ENABLED
} subghz_lora_ldro_t;

/* Generic packet parameters */
typedef enum {
  SUBGHZ_DET_PREAMBLE_DISABLED,
  SUBGHZ_DET_PREAMBLE_8BIT = 0x04,
  SUBGHZ_DET_PREAMBLE_16BIT,
  SUBGHZ_DET_PREAMBLE_24BIT,
  SUBGHZ_DET_PREAMBLE_32BIT
} subghz_det_length_t;

typedef enum {
  SUBGHZ_ADDR_COMP_DISABLED,
  SUBGHZ_ADDR_COMP_NODE,
  SUBGHZ_ADDR_COMP_NODE_BROADCAST
} subghz_addr_comp_t;

typedef enum {
  SUBGHZ_PKT_FIXED_LENGTH,
  SUBGHZ_PKT_VAR_LENGTH
} subghz_packet_length_t;

typedef enum {
  SUBGHZ_PKT_CRC_1,
  SUBGHZ_PKT_CRC_NONE,
  SUBGHZ_PKT_CRC_2,
  SUBGHZ_PKT_INV_CRC_1 = 0x04,
  SUBGHZ_PKT_INV_CRC_2 = 0x06,
} subghz_packet_crc_t;

/* LoRa packet parameters */
typedef enum {
  SUBGHZ_PKT_LORA_VAR_LENGTH,
  SUBGHZ_PKT_LORA_FIXED_LENGTH
} subghz_lora_packet_hdr_t;

/* SUBGHZSPI HAL */
int subghz_init(void);
int subghz_check_device_ready(void);
int subghz_wait_on_busy(void);
subghz_result_t subghz_read_reg(uint16_t address, uint8_t *p_reg);
void subghz_write_reg(uint16_t address, uint8_t value);
subghz_result_t subghz_read_regs(uint16_t address, uint8_t *p_buffer, uint16_t size);
subghz_result_t subghz_write_regs(uint16_t address, uint8_t *p_buffer, uint16_t size);
subghz_result_t subghz_write_command(uint8_t command, uint8_t *p_parameters, int params_size);

/* SUBGHZ Commands API */
subghz_result_t subghz_get_status(void);
subghz_result_t subghz_get_error(subghz_err_t *error);
subghz_result_t subghz_set_tcxo_mode(subghz_tcxo_trim_t trim, uint32_t timeout);
subghz_result_t subghz_calibrate(uint8_t calib_cfg);
subghz_result_t subghz_set_standby_mode(subghz_standby_mode_t mode);
subghz_result_t subghz_set_regulator_mode(subghz_regulator_mode_t mode);
subghz_result_t subghz_set_fs_mode(void);
subghz_result_t subghz_set_tx_mode(uint32_t timeout);
subghz_result_t subghz_set_rx_mode(uint32_t timeout);
subghz_result_t subghz_set_stop_rxtimer_on_preamble(subghz_rxtimer_stop_t config);
subghz_result_t subghz_set_duty_cycle(uint32_t rx_period, uint32_t sleep_period);
subghz_result_t subghz_set_cad(void);
subghz_result_t subghz_set_tx_continuous_wave(void);
subghz_result_t subghz_set_tx_continuous_preamble(void);
subghz_result_t subghz_set_packet_type(subghz_packet_type_t packet_type);
subghz_result_t subghz_get_packet_type(subghz_packet_type_t *packet_type);
subghz_result_t subghz_set_rf_freq(uint32_t freq);
subghz_result_t subghz_set_tx_params(int8_t power, subghz_txparams_ramptime_t ramp_time);
subghz_result_t subghz_set_pa_config(uint8_t duty_cycle, uint8_t hp_max, uint8_t pa_sel);
subghz_result_t subghz_set_tx_rx_fallback_mode(subghz_fallback_mode_t mode);
subghz_result_t subghz_set_cad_params(subghz_cad_symbols_t nb_symbols, uint8_t det_peak,
                                      uint8_t det_min, subghz_cad_exit_mode_t exit_mode,
                                      uint32_t timeout);
subghz_result_t subghz_set_buffer_base_address(uint8_t tx_base_addr, uint8_t rx_base_addr);
subghz_result_t subghz_set_fsk_modulation_params(uint32_t bitrate, subghz_fsk_gaussian_t gaussian,
                                                 subghz_fsk_bandwidth_t bandwidth, uint32_t deviation);
subghz_result_t subghz_set_lora_modulation_params(subghz_lora_sf_t sf, subghz_lora_bandwidth_t bandwidth,
                                                  subghz_lora_cr_t cr, subghz_lora_ldro_t ldro);
subghz_result_t subghz_set_packet_params(uint16_t preamble_length, subghz_det_length_t det_length,
                                         uint8_t syncword_length, subghz_addr_comp_t addr_comp,
                                         subghz_packet_length_t packet_length, uint8_t payload_length,
                                         subghz_packet_crc_t crc_type, bool whitening);
subghz_result_t subghz_set_lora_packet_params(uint16_t preamble_length, subghz_lora_packet_hdr_t header_type,
                                              uint8_t payload_length, bool crc_enabled, bool invert_iq);

void subghz_fill_random(uint8_t *randomStock, uint8_t len);

#endif /* __INC_SUBGHZ_H */