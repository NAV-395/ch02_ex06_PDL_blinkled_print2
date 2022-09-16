
#include "cy_pdl.h"
#include "cyhal.h"
#include "cybsp.h"
UART_context;
int main(void)
{
    cy_rslt_t result;
    /* Initialize the device and board peripherals */
    result = cybsp_init() ;
    if (result != CY_RSLT_SUCCESS)
    {
        CY_ASSERT(0);
    }
    __enable_irq();
    /* Configure and enable the UART */
    Cy_SCB_UART_Init(UART_HW, &UART_config, &UART_context);
    Cy_SCB_UART_Enable(UART_HW);
    //char buffer[256];
    for (;;)
    {
    	Cy_GPIO_Write(CYBSP_USER_LED_PORT, CYBSP_USER_LED_NUM,0);
    	Cy_SysLib_Delay(250);
    	//sprintf(buffer, "ENCENDIDO \r\n");
        Cy_SCB_UART_PutString(UART_HW, "ENCENDIDO \r\n");
    	Cy_GPIO_Write(CYBSP_USER_LED_PORT, CYBSP_USER_LED_NUM,1);
    	Cy_SysLib_Delay(250);
    	//sprintf(buffer, "APAGADO \r\n");
        Cy_SCB_UART_PutString(UART_HW, "APAGADO \r\n");
    }
}

