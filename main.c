int main(void)
{
  /* Configure the MPU attributes */
  MPU_Config();

  /* Enable the CPU Cache */
  CPU_CACHE_Enable();
  
  /* This sample code shows how to use GPIO HAL API to toggle GPIOA-GPIO_PIN_5 IO
    in an infinite loop. It is possible to connect a LED between GPIOA-GPIO_PIN_5
    output and ground via a 330ohm resistor to see this external LED blink.
    Otherwise an oscilloscope can be used to see the output GPIO signal */

  /* STM32F7xx HAL library initialization:
       - Configure the Flash ART accelerator
       - Systick timer is configured by default as source of time base, but user 
         can eventually implement his proper time base source (a general purpose 
         timer for example or other time source), keeping in mind that Time base 
         duration should be kept 1ms since PPP_TIMEOUT_VALUEs are defined and 
         handled in milliseconds basis.
       - Set NVIC Group Priority to 4
       - Low Level Initialization
     */
  HAL_Init();

  /* Configure the system clock to 216 MHz */
  SystemClock_Config();
  
  /* -1- Enable GPIO Clock (to be able to program the configuration registers) */
  __HAL_RCC_GPIOB_CLK_ENABLE();

  /* -2- Configure IO in output push-pull mode to drive external LEDs */
  GPIO_InitStruct.Mode  = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull  = GPIO_PULLUP;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_VERY_HIGH;

  //HAL_GPIO_Init(GPIOB, &GPIO_InitStruct);

  /* -3- Toggle IO in an infinite loop */
  while (1)
  {
	GPIO_InitStruct.Pin = GPIO_PIN_0;//Чтобы мигать зеленым LED
	HAL_GPIO_Init(GPIOB, &GPIO_InitStruct);
    HAL_GPIO_TogglePin(GPIOB, GPIO_PIN_0);//Чтобы мигать зеленым LED
    HAL_Delay(100);
    GPIO_InitStruct.Pin = GPIO_PIN_7;//Чтобы мигать голубым LED
    HAL_GPIO_Init(GPIOB, &GPIO_InitStruct);
    HAL_GPIO_TogglePin(GPIOB, GPIO_PIN_7); //Чтобы мигать голубым LED
    HAL_Delay(100);
    GPIO_InitStruct.Pin = GPIO_PIN_14; //Чтобы мигать красным LED
    HAL_GPIO_Init(GPIOB, &GPIO_InitStruct);
    HAL_GPIO_TogglePin(GPIOB, GPIO_PIN_14); //Чтобы мигать красным LED
    /* Insert delay 100 ms */
    HAL_Delay(100);

  }

}
