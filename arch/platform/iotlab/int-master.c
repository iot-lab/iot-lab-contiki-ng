/*---------------------------------------------------------------------------*/
#include "contiki.h"
#include "sys/int-master.h"
#include "platform.h"

#include <stdbool.h>
/*---------------------------------------------------------------------------*/
#define DISABLED 0
#define ENABLED  1
/*---------------------------------------------------------------------------*/
static int_master_status_t stat = DISABLED;
/*---------------------------------------------------------------------------*/

void
int_master_enable(void)
{
  stat = ENABLED;
  platform_exit_critical();
}
/*---------------------------------------------------------------------------*/
int_master_status_t
int_master_read_and_disable(void)
{
  // Read PRIMASK register, check interrupt status before you disable them */
  // Returns 0 if they are enabled, or non-zero if disabled */
  //int_master_status_t primask = __get_PRIMASK();
  int_master_status_t rv = stat;
  stat = DISABLED;
  platform_enter_critical();

  //return primask;
  return rv;
}
/*---------------------------------------------------------------------------*/
void
int_master_status_set(int_master_status_t status)
{
  //__set_PRIMASK(status);
  stat = status;
}
/*---------------------------------------------------------------------------*/
bool
int_master_is_enabled(void)
{
  //return __get_PRIMASK() ? false : true;
  return stat == DISABLED ? false : true;
}
/*---------------------------------------------------------------------------*/
/**
 * @}
 * @}
 */
