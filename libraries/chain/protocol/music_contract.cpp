/*
 * Copyright (c) 2018 oxarbitrage and contributors.
 *
 * The MIT License
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
 * THE SOFTWARE.
 */
#include <graphene/chain/protocol/music_contract.hpp>

namespace graphene { namespace chain {

      void music_contract_transfer_operation::validate()const {
         FC_ASSERT( agent_fee.amount >= 0 );
         FC_ASSERT( amount.amount > 0 );
         FC_ASSERT( producer != musician );
         FC_ASSERT( producer != agent && musician != agent );
      }
      void music_contract_approve_operation::validate()const {
         FC_ASSERT( who == musician || who == agent );
      }
      void music_contract_dispute_operation::validate()const {
         FC_ASSERT( who == producer || who == musician );
      }
      void music_contract_release_operation::validate()const {
         FC_ASSERT( who == producer || who == musician || who == agent, "who must be producer or musician or agent" );
         FC_ASSERT( receiver == producer || receiver == musician, "receiver must be producer or musician" );
         FC_ASSERT( amount.amount > 0 );
      }
} }
