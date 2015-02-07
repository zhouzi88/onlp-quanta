/************************************************************
 * <bsn.cl fy=2014 v=onl>
 *
 *           Copyright 2014 Big Switch Networks, Inc.
 *
 * Licensed under the Eclipse Public License, Version 1.0 (the
 * "License"); you may not use this file except in compliance
 * with the License. You may obtain a copy of the License at
 *
 *        http://www.eclipse.org/legal/epl-v10.html
 *
 * Unless required by applicable law or agreed to in writing,
 * software distributed under the License is distributed on an
 * "AS IS" BASIS, WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND,
 * either express or implied. See the License for the specific
 * language governing permissions and limitations under the
 * License.
 *
 * </bsn.cl>
 ************************************************************
 *
 * SFPI Interface for the Quanta LB9
 *
 * This code was lifted wholesale and minimally ported
 * from the previous implementation that preceded the ONLP interfaces.
 *
 * It should be ported in the future to use the services provided
 * by the ONLP infrastructure directly.
 *
 ***********************************************************/
#include <powerpc_quanta_lb9_r0/powerpc_quanta_lb9_r0_config.h>
#include <onlp/platformi/sfpi.h>
#include <onlplib/sfp.h>
#include "powerpc_quanta_lb9_r0_log.h"


#include <unistd.h>
#include <fcntl.h>
#include <time.h>

/**
 * This table maps the presence gpio, reset gpio, and eeprom file
 * for each SFP port.
 */
typedef struct sfpmap_s {
    int sport;
    const char*  mod_abs_gpio;
    const char* reset_gpio;
    const char* eeprom;
} sfpmap_t;

static sfpmap_t sfpmap__[] =
    {
        { 48, "/sys/class/gpio/gpio112/value", "/sys/class/gpio/gpio120/value", "/sys/devices/e0000000.soc8541/e0003000.i2c/i2c-0/i2c-1/1-0050/eeprom" },
        { 49, "/sys/class/gpio/gpio113/value", "/sys/class/gpio/gpio121/value", "/sys/devices/e0000000.soc8541/e0003000.i2c/i2c-0/i2c-2/2-0050/eeprom" },
        { 50, "/sys/class/gpio/gpio114/value", "/sys/class/gpio/gpio122/value", "/sys/devices/e0000000.soc8541/e0003000.i2c/i2c-0/i2c-3/3-0050/eeprom" },
        { 51, "/sys/class/gpio/gpio115/value", "/sys/class/gpio/gpio123/value", "/sys/devices/e0000000.soc8541/e0003000.i2c/i2c-0/i2c-4/4-0050/eeprom" },
    };

#define SFP_GET(_port) (sfpmap__+ (_port - 48))

int
onlp_sfpi_init(void)
{
    return ONLP_STATUS_OK;
}

int
onlp_sfpi_bitmap_get(onlp_sfp_bitmap_t* bmap)
{
    int p;

    for(p = 48; p < 52; p++) {
        AIM_BITMAP_SET(bmap, p);
    }
    return ONLP_STATUS_OK;
}

int
onlp_sfpi_is_present(int port)
{
    sfpmap_t* sfp = SFP_GET(port);

    return onlplib_sfp_is_present_file(sfp->mod_abs_gpio,
                                       /* Present */ "0\n",
                                       /* Absent */  "1\n");
}

int
onlp_sfpi_eeprom_read(int port, uint8_t data[256])
{
    sfpmap_t* sfp = SFP_GET(port);
    return onlplib_sfp_eeprom_read_file(sfp->eeprom, data);
}

int
onlp_sfpi_reset(int port)
{
    sfpmap_t* sfp = SFP_GET(port);
    return onlplib_sfp_reset_file(sfp->reset_gpio,
                                  "0\n",
                                  POWERPC_QUANTA_LB9_R0_CONFIG_PHY_RESET_DELAY_MS,
                                  "1\n");
}

