#pragma once

#include <stdint.h>
#include "Blocks.h"

// Brightness ramp tuned for MCPE-like daylight response on PSP.
// Keeps 15->1.0f so daytime sunlight is not dimmed at the top end.
inline float MCPELightRampFromNibble(uint8_t level) {
  const float ambientLight = 0.05f;
  const float v = 1.0f - (float)(level & 0x0F) / 15.0f;
  return ((1.0f - v) / (v * 3.0f + 1.0f)) * (1.0f - ambientLight) + ambientLight;
}

// MCPE LightUpdate semantics: lightBlock 0 still attenuates by 1.
inline uint8_t MCPELightAttenuation(uint8_t blockId) {
  uint8_t block = g_blockProps[blockId].light_block;
  return block == 0 ? 1 : block;
}
