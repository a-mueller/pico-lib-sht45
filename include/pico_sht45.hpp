/*
  This is a library written for the SHT45
  Copyright (c) 2023 Abraham Mueller

  Permission is hereby granted, free of charge, to any person obtaining a copy
  of this software and associated documentation files (the "Software"), to deal
  in the Software without restriction, including without limitation the rights
  to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
  copies of the Software, and to permit persons to whom the Software is
  furnished to do so, subject to the following conditions:

  The above copyright notice and this permission notice shall be included in
  all copies or substantial portions of the Software.

  THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
  IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
  FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
  AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
  LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
  OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
  THE SOFTWARE.
*/

#ifndef PICO_SHT45_H
# define PICO_SHT45_H

#include "pico/stdlib.h"
#include <stdio.h>
#include "hardware/i2c.h"

#define SHT45_CMD_MEASURE_HPM 0xFD
#define SHT45_I2C_ADDRESS 0x44

struct sht45_result_t {
  // the temperature in Celsius times 100
  int temp;
  // relative humidity as %, times 100
  int hum;
};

int pico_sht45_read(i2c_inst_t *i2c, sht45_result_t *result);

#endif
