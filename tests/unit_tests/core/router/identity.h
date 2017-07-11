/**
 * Copyright (c) 2015-2017, The Kovri I2P Router Project
 *
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without modification, are
 * permitted provided that the following conditions are met:
 *
 * 1. Redistributions of source code must retain the above copyright notice, this list of
 *    conditions and the following disclaimer.
 *
 * 2. Redistributions in binary form must reproduce the above copyright notice, this list
 *    of conditions and the following disclaimer in the documentation and/or other
 *    materials provided with the distribution.
 *
 * 3. Neither the name of the copyright holder nor the names of its contributors may be
 *    used to endorse or promote products derived from this software without specific
 *    prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND ANY
 * EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF
 * MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL
 * THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
 * SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,
 * PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
 * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT,
 * STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF
 * THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

#ifndef TESTS_UNIT_TESTS_CORE_ROUTER_IDENTITY_H_
#define TESTS_UNIT_TESTS_CORE_ROUTER_IDENTITY_H_

#include <array>
#include <memory>

#include "core/router/identity.h"
#include "core/util/log.h"

namespace core = kovri::core;

struct IdentityExFixture
{
  std::array<std::uint8_t, core::DEFAULT_IDENTITY_SIZE + 4> m_AliceIdentity
  {{
    // 256 bytes Public key
    0x6c, 0xdb, 0x94, 0xcb, 0xce, 0x27, 0x7a, 0xef,
    0x48, 0x13, 0x9b, 0x85, 0x8f, 0xc0, 0xd6, 0x2f,
    0x72, 0x7c, 0x92, 0x12, 0x21, 0x35, 0xd0, 0x3b,
    0x34, 0xc3, 0x58, 0x1a, 0x8d, 0x42, 0xee, 0x37,
    0x31, 0xdb, 0xec, 0xd4, 0x1a, 0x74, 0xae, 0x0e,
    0xfb, 0x95, 0x91, 0xcb, 0x05, 0xa6, 0x29, 0x7e,
    0xf5, 0x6e, 0x2b, 0xc5, 0x9d, 0x54, 0xa1, 0xe7,
    0x7d, 0x83, 0xe4, 0x00, 0x56, 0x51, 0x95, 0xf7,
    0x84, 0x23, 0xe2, 0xd6, 0x9b, 0x66, 0x3a, 0x52,
    0xd6, 0xea, 0xa3, 0x03, 0x24, 0x1d, 0x06, 0x3d,
    0x51, 0x90, 0x22, 0xa7, 0x11, 0xaf, 0x33, 0x67,
    0xba, 0xbe, 0x61, 0xea, 0x2a, 0xfe, 0x37, 0x69,
    0xde, 0x48, 0x4a, 0x41, 0xe0, 0xc6, 0xa0, 0x9f,
    0x23, 0xf9, 0x08, 0x4e, 0xa9, 0x9b, 0xcb, 0x20,
    0x59, 0xd2, 0x5a, 0x8e, 0x27, 0x79, 0xb4, 0xc2,
    0xef, 0xe6, 0x5f, 0x64, 0x58, 0xf4, 0xa3, 0x6e,
    0xcd, 0x88, 0xf4, 0xaf, 0x89, 0x46, 0x81, 0xc6,
    0xe6, 0xf6, 0x70, 0x6a, 0x14, 0xda, 0x83, 0x78,
    0xb8, 0xce, 0xe4, 0x07, 0x24, 0xf6, 0x01, 0x46,
    0x94, 0x0d, 0x33, 0xce, 0x43, 0x8c, 0x90, 0xe3,
    0x9c, 0x38, 0x3a, 0x09, 0x1b, 0xcf, 0x97, 0xc3,
    0x58, 0x53, 0x85, 0x54, 0xb9, 0xb0, 0x4b, 0x48,
    0xe6, 0x20, 0xe6, 0x7a, 0x63, 0x76, 0x3d, 0x5a,
    0xf6, 0xce, 0x56, 0x15, 0x96, 0x38, 0xea, 0x04,
    0x6b, 0x17, 0x88, 0x54, 0xab, 0x9c, 0x37, 0x44,
    0xa6, 0xf5, 0xf6, 0xb5, 0xa9, 0xa5, 0x73, 0xf5,
    0x05, 0xd8, 0x03, 0xa0, 0x67, 0x3e, 0xcb, 0x99,
    0xc6, 0x4b, 0xe0, 0xe5, 0xbe, 0x1d, 0x7c, 0x70,
    0xb1, 0x1b, 0x42, 0x17, 0x36, 0x0a, 0x0c, 0x47,
    0xa8, 0xd6, 0x59, 0x0d, 0xea, 0xcd, 0xd1, 0x04,
    0xcf, 0xe5, 0x61, 0x23, 0xb2, 0x4d, 0xec, 0x8d,
    0xda, 0x98, 0xfe, 0xa5, 0x8f, 0x6c, 0xf8, 0x9d,
    // 128 bytes Signing key
    0x11, 0x0c, 0xce, 0xef, 0x8b, 0x0b, 0x69, 0x25,
    0xc3, 0xd7, 0x59, 0xba, 0xcc, 0xd9, 0xbd, 0xd9,
    0x16, 0xcf, 0xc9, 0xac, 0xc6, 0xcc, 0xe6, 0x84,
    0x58, 0xc9, 0x57, 0x11, 0xb4, 0x24, 0xcd, 0xb1,
    0x36, 0xf2, 0xa3, 0x38, 0x8a, 0xa0, 0x9c, 0xb9,
    0xce, 0xf5, 0xde, 0xf0, 0x51, 0x35, 0x4b, 0xc7,
    0xc2, 0x8d, 0x89, 0x8c, 0x8b, 0xa9, 0x4d, 0x44,
    0x4c, 0xbf, 0xba, 0xd9, 0xa8, 0x72, 0x25, 0xba,
    0xba, 0x7a, 0xca, 0xbc, 0xe3, 0xe5, 0xd9, 0x20,
    0x48, 0x4d, 0x12, 0xe8, 0xd6, 0xf6, 0xe0, 0xf4,
    0x58, 0xd7, 0x28, 0x0c, 0xb8, 0xb8, 0xbe, 0x62,
    0xcf, 0x56, 0xba, 0x77, 0xc2, 0x95, 0x35, 0x70,
    0x8e, 0x54, 0x94, 0x4b, 0xb3, 0x81, 0x09, 0x09,
    0x10, 0xaa, 0x25, 0xcf, 0x4a, 0x24, 0xd5, 0x1d,
    0x3e, 0x41, 0x57, 0xf2, 0xf8, 0x23, 0x9e, 0xc7,
    0xa8, 0xf6, 0x4b, 0xa0, 0xeb, 0xc8, 0x1d, 0x19,
    // 1 byte type 5 CERTIFICATE_TYPE_KEY
    0x05,
    // 2 bytes length
    0x00, 0x04,
    // 2 bytes signing key : SIGNING_KEY_TYPE_EDDSA_SHA512_ED25519
    0x00, 0x07, 
    // 2 bytes crypto key : CRYPTO_KEY_TYPE_ELGAMAL
    0x00, 0x00,
  }};
};

#endif  // TESTS_UNIT_TESTS_CORE_ROUTER_IDENTITY_H_
