#include  <errno.h>
#include  <sys/unistd.h> // STDOUT_FILENO, STDERR_FILENO

#include "stm32f4xx_hal.h"

extern UART_HandleTypeDef huart2; // access huart1 instance
//extern int __io_putchar(int ch) __attribute__((weak)); // comment this out

__attribute__((weak)) int __io_putchar(int ch)
{
    HAL_StatusTypeDef status = HAL_UART_Transmit(&huart2, (uint8_t *)&ch, 1, 0xFFFF);
    return (status == HAL_OK ? ch : 0);
}

int _write(int file, char *data, int len)
{
   if ((file != STDOUT_FILENO) && (file != STDERR_FILENO))
   {
      errno = EBADF;
      return -1;
   }

   // arbitrary timeout 1000
   HAL_StatusTypeDef status =
      HAL_UART_Transmit(&huart2, (uint8_t*)data, len, 1000);

   // return # of bytes written - as best we can tell
   return (status == HAL_OK ? len : 0);
}