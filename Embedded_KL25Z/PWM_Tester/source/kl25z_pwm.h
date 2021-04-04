/*
 * kl25z_pwm.h
 *
 *  Created on: 22/10/2017
 *      Author: Aldo Vargas
 */

#ifndef KL25Z_PWM_H_
#define KL25Z_PWM_H_

#include "fsl_debug_console.h"
#include "board.h"
#include "fsl_tpm.h"
#include "pin_mux.h"
#include "fsl_port.h"

#define TPM_SOURCE_CLOCK CLOCK_GetFreq(kCLOCK_PllFllSelClk)

typedef struct pwmStruct {
	TPM_Type* tpm_addr;
	tpm_chnl_t tpm_chnl;

	uint8_t updatedDutycycle;

	tpm_config_t tpmInfo;
	tpm_chnl_pwm_signal_param_t tpmParam;
	tpm_pwm_level_select_t pwmLevel;
	int pin;

} PWM;



void PWM_Init(PWM* pwm, TPM_Type* tpm, PORT_Type* port, clock_ip_name_t clk, port_mux_t mux, int chnl, int pin);

void PWM_Start(PWM* pwm);

void PWM_Update(PWM* pwm, int update);

#endif /* KL25Z_PWM_H_ */
