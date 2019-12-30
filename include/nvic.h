#ifndef NVIC_H
#define NVIC_H

struct nvic
{
	uint32_t ISER[3];
	uint32_t ICER[3];
	uint32_t ISPR[3];
	uint32_t ICPR[3];
	uint32_t IABR[3];
	uint32_t IPR[21];
};

/* IRQ numbers for the medium-density lineup */
enum
{
	ADC1_2_IRQn          = 18, /*!< ADC1 and ADC2 global Interrupt                       */
	USB_HP_CAN1_TX_IRQn  = 19, /*!< USB Device High Priority or CAN1 TX Interrupts       */
	USB_LP_CAN1_RX0_IRQn = 20, /*!< USB Device Low Priority or CAN1 RX0 Interrupts       */
	AN1_RX1_IRQn         = 21, /*!< CAN1 RX1 Interrupt                                   */
	CAN1_SCE_IRQn        = 22, /*!< CAN1 SCE Interrupt                                   */
	EXTI9_5_IRQn         = 23, /*!< External Line[9:5] Interrupts                        */
	TIM1_BRK_IRQn        = 24, /*!< TIM1 Break Interrupt                                 */
	TIM1_UP_IRQn         = 25, /*!< TIM1 Update Interrupt                                */
	TIM1_TRG_COM_IRQn    = 26, /*!< TIM1 Trigger and Commutation Interrupt               */
	TIM1_CC_IRQn         = 27, /*!< TIM1 Capture Compare Interrupt                       */
	TIM2_IRQn            = 28, /*!< TIM2 global Interrupt                                */
	TIM3_IRQn            = 29, /*!< TIM3 global Interrupt                                */
	TIM4_IRQn            = 30, /*!< TIM4 global Interrupt                                */
	I2C1_EV_IRQn         = 31, /*!< I2C1 Event Interrupt                                 */
	I2C1_ER_IRQn         = 32, /*!< I2C1 Error Interrupt                                 */
	I2C2_EV_IRQn         = 33, /*!< I2C2 Event Interrupt                                 */
	I2C2_ER_IRQn         = 34, /*!< I2C2 Error Interrupt                                 */
	SPI1_IRQn            = 35, /*!< SPI1 global Interrupt                                */
	SPI2_IRQn            = 36, /*!< SPI2 global Interrupt                                */
	USART1_IRQn          = 37, /*!< USART1 global Interrupt                              */
	USART2_IRQn          = 38, /*!< USART2 global Interrupt                              */
	USART3_IRQn          = 39, /*!< USART3 global Interrupt                              */
	EXTI15_10_IRQn       = 40, /*!< External Line[15:10] Interrupts                      */
	RTCAlarm_IRQn        = 41, /*!< RTC Alarm through EXTI Line Interrupt                */
	USBWakeUp_IRQn       = 42, /*!< USB Device WakeUp from suspend through EXTI Line Interrupt */
};

#define NVIC ((struct nvic *) 0xE000E100)

#endif
