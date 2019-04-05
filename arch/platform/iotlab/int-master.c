/*---------------------------------------------------------------------------*/
#include "contiki.h"
#include "sys/int-master.h"
#include "platform.h"

#include <stdbool.h>
/*---------------------------------------------------------------------------*/

void
int_master_enable(void)
{
  platform_exit_critical();
}
/*---------------------------------------------------------------------------*/
int_master_status_t
int_master_read_and_disable(void)
{
  // Read PRIMASK register, check interrupt status before you disable them */
  // Returns 0 if they are enabled, or non-zero if disabled */
  int_master_status_t primask = get_primask();

  platform_enter_critical();

  return primask;
}
/*---------------------------------------------------------------------------*/
void
int_master_status_set(int_master_status_t status)
{
  set_primask(status);
}
/*---------------------------------------------------------------------------*/
bool
int_master_is_enabled(void)
{
  return get_primask() ? false : true;
}
/*---------------------------------------------------------------------------*/
/**
 * @}
 * @}
 */
