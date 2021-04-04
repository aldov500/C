/*
 * kl25z_pwm.c
 *
 *  Created on: 23/10/2017
 *      Author: Aldo Vargas
 */
#include "kl25z_pwm.h"

/*
	PWM_Init(&rojo, TPM2, PORTB, kCLOCK_PortB, kPORT_MuxAlt3,  0, 18);
	PWM_Start(&rojo);
	PWM_Update(&rojo, 60);
*/

void PWM_Init(PWM* pwm, TPM_Type* tpm, PORT_Type* port, clock_ip_name_t clk, port_mux_t mux, int chnl, int pin) {
	pwm->tpm_addr = tpm;
	pwm->tpm_chnl = (tpm_chnl_t) chnl;

	pwm->tpmParam.chnlNumber = (tpm_chnl_t) chnl;
	pwm->pwmLevel = kTPM_LowTrue;
	pwm->tpmParam.level = pwm->pwmLevel;
	pwm->tpmParam.dutyCyclePercent = 0;
	pwm->pin = pin;

	CLOCK_SetTpmClock(1U);

	TPM_GetDefaultConfig(&pwm->tpmInfo);
	TPM_Init(pwm->tpm_addr, &pwm->tpmInfo);
	TPM_SetupPwm(pwm->tpm_addr, &pwm->tpmParam, 1U, kTPM_CenterAlignedPwm,
			24000U, TPM_SOURCE_CLOCK);

	 CLOCK_EnableClock(clk);
	 PORT_SetPinMux(port, pin, mux);

}

void PWM_Start(PWM* pwm) {
	TPM_StartTimer(pwm->tpm_addr, kTPM_SystemClock);
}

void PWM_Stop(PWM* pwm){
	TPM_StopTimer(pwm->tpm_addr);
}

void PWM_Update(PWM* pwm, int update) {
	/* Disable channel output before updating the dutycycle */
	TPM_UpdateChnlEdgeLevelSelect(pwm->tpm_addr, pwm->tpm_chnl, 0U);

	/* Update PWM duty cycle */
	TPM_UpdatePwmDutycycle(pwm->tpm_addr, pwm->tpm_chnl, kTPM_CenterAlignedPwm,
			update);
	/* Start channel output with updated dutycycle */
	TPM_UpdateChnlEdgeLevelSelect(pwm->tpm_addr, pwm->tpm_chnl, pwm->pwmLevel);
}
