#pragma once

#include <stdint.h>
#include "Blocks.h"

// MCPE 0.6.x-style brightness ramp used by Dimension::updateLightRamp:
// ((1-v)/(v*3+1)) * (1-ambient) + ambient*3, with ambient=0.05.
inline float MCPELightRampFromNibble(uint8_t level) {
  const float ambientLight = 0.05f;
  const float v = 1.0f - (float)(level & 0x0F) / 16.0f;
  return ((1.0f - v) / (v * 3.0f + 1.0f)) * (1.0f - ambientLight) + ambientLight * 3.0f;
}

// MCPE LightUpdate semantics: lightBlock 0 still attenuates by 1.
inline uint8_t MCPELightAttenuation(uint8_t blockId) {
  uint8_t block = g_blockProps[blockId].light_block;
  return block == 0 ? 1 : block;
}
