/***********************************************************************************************/
/***********************************************************************************************/
/************************************* Author: Fatema Ahmed ************************************/
/***************************************** Layer: MCAL *****************************************/
/****************************************** SWC: RCC *******************************************/
/***********************************************************************************************/
/***********************************************************************************************/

#ifndef RCC_Interface
#define RCC_Interface

/** Error States **/
#define PerphiralRangeRCC	1
#define BusRangeRCC			2
#define ConfigPLLRCC		3


u8 RCC_SystemClkInitialization (void);

/****************************************************/
/* Define											*/
/*		1) RCC Bus									*/
/* 				- AHB1								*/
/* 				- AHB2								*/
/* 				- APB1								*/
/* 				- APB2								*/
/****************************************************/
#define	AHB1	1
#define	AHB2	2
#define	APB1	3
#define	APB2	4

/************************************************************************************/
/* Define 																			*/
/*		1) RCC AHB1 peripheral clock enable\disable register						*/
/*			  *** PORTS Enable\Disable ***											*/
/* 				GPIOA --> Perphiral = 0												*/
/* 				GPIOB --> Perphiral = 1												*/
/* 				GPIOC --> Perphiral = 2												*/
/*																					*/
/*		2) RCC AHB2 peripheral clock enable\disable register						*/
/* 				OTGFS --> Perphiral = 7												*/
/*																					*/
/*		3) RCC APB1 peripheral clock enable\disable register						*/
/* 				TIM2 --> Perphiral = 0												*/
/* 				TIM3 --> Perphiral = 1												*/
/* 				TIM4 --> Perphiral = 2												*/
/* 				TIM5 --> Perphiral = 3												*/
/* 				WWDG --> Perphiral = 11												*/
/* 				SPI2 --> Perphiral = 14												*/
/* 				SPI3 --> Perphiral = 15												*/
/* 				USART2 --> Perphiral = 17											*/
/* 				I2C1 --> Perphiral = 21												*/
/* 				I2C2 --> Perphiral = 22												*/
/* 				I2C3 --> Perphiral = 23												*/
/* 				PWR --> Perphiral = 28												*/
/*																					*/
/*		4) RCC APB2 peripheral clock enable\disable register						*/
/* 				TIM1 --> Perphiral = 0												*/
/* 				USART1 --> Perphiral = 4											*/
/* 				USART6 --> Perphiral = 5											*/
/* 				ADC1 --> Perphiral = 8												*/
/* 				SDIO --> Perphiral = 11												*/
/* 				SPI1 --> Perphiral = 12												*/
/* 				SPI4 --> Perphiral = 13												*/
/* 				SYSCFG --> Perphiral = 14											*/
/* 				TIM9 --> Perphiral = 16												*/
/* 				TIM10 --> Perphiral = 17											*/
/* 				TIM11 --> Perphiral = 18											*/
/************************************************************************************/
#define GPIOA	 0
#define GPIOB	 1
#define GPIOC	 2

#define OTGFS	7

#define TIM2	0
#define TIM3	1
#define TIM4	2
#define TIM5	3
#define WWDG	11
#define SPI2	14
#define SPI3	15
#define USART2	17
#define I2C1	21
#define I2C2	22
#define I2C3	23
#define PWR		28

#define TIM1	0
#define USART1	4
#define USART6	5
#define ADC1	8
#define SDIO	11
#define SPI1	12
#define SPI4	13
#define SYSCFG	14
#define TIM9	16
#define TIM10	17
#define TIM11	18

u8 RCC_Enable (u8 Bus, u8 Perphiral);
u8 RCC_Disable (u8 Bus, u8 Perphiral);

#endif
