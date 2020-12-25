/*

MIT No Attribution

Copyright (c) 2020 Mika Tuupola

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS
OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.

-cut-

SPDX-License-Identifier: MIT-0

*/

#include "sdkconfig.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <wchar.h>
#include <freertos/FreeRTOS.h>
#include <freertos/task.h>
#include <freertos/event_groups.h>
#include <esp_log.h>

#ifdef CONFIG_DEVICE_HAS_AXP202
#include <axp202.h>
#endif /* CONFIG_DEVICE_HAS_AXP202 */


#include <i2c_helper.h>

static const char *TAG = "twatch";


void app_main()
{
    ESP_LOGI(TAG, "SDK version: %s", esp_get_idf_version());
    ESP_LOGI(TAG, "Heap when starting: %d", esp_get_free_heap_size());

#ifdef CONFIG_DEVICE_HAS_AXP202
    /* TTGO T-Watch-2020 uses AXP202 PMU. */
    static i2c_port_t i2c_port = I2C_NUM_0;
    axp202_t axp;

    ESP_LOGI(TAG, "Initializing I2C");
    i2c_init(i2c_port);

    ESP_LOGI(TAG, "Initializing AXP202");
    axp.read = &i2c_read;
    axp.write = &i2c_write;
    axp.handle = &i2c_port;
    axp202_init(&axp);
#endif /* CONFIG_DEVICE_HAS_AXP202 */


}
