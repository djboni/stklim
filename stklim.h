/*
 Copyright 2016 Djones A. Boni

 Licensed under the Apache License, Version 2.0 (the "License");
 you may not use this file except in compliance with the License.
 You may obtain a copy of the License at

 http://www.apache.org/licenses/LICENSE-2.0

 Unless required by applicable law or agreed to in writing, software
 distributed under the License is distributed on an "AS IS" BASIS,
 WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 See the License for the specific language governing permissions and
 limitations under the License.
 */

#ifndef STKLIM_H_
#define STKLIM_H_

#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif

uint16_t stackUsage(void);
uint16_t stackFreeBytes(void);
uint16_t stackTotalBytes(void);

#ifdef __cplusplus
}
#endif

#endif /* STKLIM_H_ */
